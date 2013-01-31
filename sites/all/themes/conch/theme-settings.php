<?php

function phptemplate_settings($saved_settings) {

 $defaults = array(
	'color' => 'default',
	'font_family' => 'Arial, Helvetica, sans-serif',
	'font_size' => '1.0',
	'menu_style' => 0,
	'show_logo_footer' => 1,
	'show_breadcrumb' => 0,
  );
  
  $settings = array_merge($defaults, $saved_settings);
  
  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('Color'),
    '#default_value' => $settings['color'],
    '#options' => array (
      'default' => t('Default'),
      'red' => t('Red'),
	  'blue' => t('Blue'),
    ),
  );
  
  $form['font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font Family'),
    '#default_value' => $settings['font_family'],
    '#options' => array (
      'Arial, Helvetica, sans-serif' => t('Arial, Helvetica, Sans-serif'),
      '"Times New Roman", Times, serif' => t('Times New Roman, Times, Serif'),
	  '"Courier New", Courier, monospace' => t('"Courier New", Courier, Monospace'),
	  'Georgia, "Times New Roman", Times, serif' => t('Georgia, "Times New Roman", Times, Serif'),
      'Verdana, Arial, Helvetica, sans-serif' => t('Verdana, Arial, Helvetica, Sans-serif'),
	  'Geneva, Arial, Helvetica, sans-serif' => t('Geneva, Arial, Helvetica, Sans-serif'),
    ),
  );
  
  $form['font_size'] = array(
    '#type' => 'select',
    '#title' => t('Font Size'),
    '#default_value' => $settings['font_size'],
    '#options' => array (
      '0.7' => t('Smallest'),
	  '0.8' => t('Small'),
	  '1.0' => t('Default'),
	  '1.1' => t('Large'),
	  '1.2' => t('Largest'),	  
    ),
  );
  
  $form['menu_style'] = array(
    '#type' => 'select',
    '#title' => t('Menu Style'),
    '#default_value' => $settings['menu_style'],
    '#options' => array (
      0 => t('CSS menu'),
	  1 => t('Split menu'),
	  2 => t('ST menu'), 
    ),
  );
  
  $form['show_breadcrumb'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Breadcrumbs'),
    '#default_value' => $settings['show_breadcrumb'],
  );
  
  $form['show_logo_footer'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Logo footer'),
    '#default_value' => $settings['show_logo_footer'],
  );
  
  return $form;
}

?>