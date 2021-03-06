<?php
/**
 * @file
 * zilverdistel_feeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function zilverdistel_feeds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_node_info().
 */
function zilverdistel_feeds_node_info() {
  $items = array(
    'feed_item' => array(
      'name' => t('Feed item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
