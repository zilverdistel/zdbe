<?php
// Initialize Theme Settings

global $theme_key, $theme_path;
if (is_null(theme_get_setting('color'))) {  
  $defaults = array(
	'color' => 'default',
	'font_family' => 'Arial, Helvetica, sans-serif',
	'font_size' => '0.9',
	'menu_style' => 0,
	'show_logo_footer' => 1,
	'show_breadcrumb' => 0,	
  );
  variable_set(
    str_replace('/', '_', 'theme_'. $theme_key .'_settings'),
    array_merge($defaults, theme_get_settings($theme_key))
  );

  theme_get_setting('', TRUE);
}
// Javascript Includes
$menu_style = theme_get_setting('menu_style');

if  ($menu_style == 0) {
	drupal_add_js($theme_path . '/menu/cssmenu/cssmenu.js', 'theme');
	drupal_add_css($theme_path . '/menu/cssmenu/cssmenu.css', 'theme');
} 
elseif ($menu_style == 1){
	drupal_add_js($theme_path . '/menu/splitmenu/splitmenu.js', 'theme');
	drupal_add_css($theme_path . '/menu/splitmenu/splitmenu.css', 'theme');
}
else {
	drupal_add_js($theme_path . '/menu/stmenu/stmenu.js', 'theme');
	drupal_add_css($theme_path . '/menu/stmenu/stmenu.css', 'theme');
}

// CSS Includes
$color = theme_get_setting('color');
drupal_add_css($theme_path . '/css/'.$color.'-style.css', 'theme'); 

// Add custom.css file
drupal_add_css($theme_path . '/css/custom.css', 'theme'); 
