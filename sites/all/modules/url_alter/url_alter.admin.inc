<?php

/**
 * @file
 * Administrative page callbacks for the url_alter module.
 */

function url_alter_settings_form() {
  // Legacy function settings.
  $form['legacy'] = array(
    '#type' => 'fieldset',
    '#title' => t('Legacy functions'),
    '#access' => FALSE,
  );
  foreach (array('custom_url_rewrite_inbound', 'custom_url_rewrite_outbound') as $function) {
    $info = url_alter_get_function_info($function);
    $form['legacy']['url_alter_run_' . $function] = array(
      '#type' => 'checkbox',
      '#title' => t('Run the legacy function @function().', array('@function' => $function)),
      '#description' => $info ? t('Found at !location.', array('!location' => $info->location)) : '',
      '#default_value' => 0,
      '#access' => (bool) $info,
    );
    $form['legacy']['#access'] |= (bool) $info;
  }

  // Custom PHP code settings.
  $form['url_alter_inbound'] = array(
    '#type' => 'textarea',
    '#title' => t('PHP code for custom_url_rewrite_inbound()'),
    '#description' => t('The available variables are %variables.', array('%variables' => '&$result, $path, $path_language')),
    '#default_value' => '',
    '#element_validate' => array('url_alter_validate_php_element'),
    '#url_alter_variables' => "\$result = \$path = '';\n\$path_language = 'en';\n",
  );
  $form['url_alter_outbound'] = array(
    '#type' => 'textarea',
    '#title' => t('PHP code for custom_url_rewrite_outbound()'),
    '#description' => t('The available variables are %variables.', array('%variables' => '&$path, &$options, $original_path')),
    '#default_value' => '',
    '#element_validate' => array('url_alter_validate_php_element'),
    '#url_alter_variables' => "\$path = \$original_path = '';\n\$options = array();\n",
  );

  return system_settings_form($form);
}

function url_alter_validate_php_element($form) {
  $result = url_alter_check_php_syntax($form['#url_alter_variables'] . $form['#value']);
  if ($result !== TRUE) {
    form_error($form, t('@function did not validate.', array('@function' => $form['#title'])));
  }
}

/**
 * Validate PHP code syntax.
 *
 * @param $code
 *   A string with PHP code, not including the opening or closing PHP tags.
 * @return
 *   TRUE if the code was valid, otherwise an error message or FALSE.
 */
function url_alter_check_php_syntax($code) {
  if (!strlen($code)) {
    return TRUE;
  }
  elseif (preg_match('/<\?php|\?>/', $code, $matches)) {
    return t('Do not use the PHP tag %code in your code.', array('%code' => $matches[0]));
  }
  else {
    $success = TRUE;
    $code .= "\nreturn " . var_export($success, TRUE) . ";";

    ob_start();
    $result = eval($code);
    ob_end_clean();

    if ($result === $success) {
      return TRUE;
    }
    else {
      return is_string($result) ? $result : FALSE;
    }
  }
}
