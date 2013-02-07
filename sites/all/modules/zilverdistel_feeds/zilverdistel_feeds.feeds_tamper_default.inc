<?php
/**
 * @file
 * zilverdistel_feeds.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function zilverdistel_feeds_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'feed-xpathparser_5-explode';
  $feeds_tamper->importer = 'feed';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '%s',
    'limit' => '',
    'real_separator' => ' ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode using spaces';
  $export['feed-xpathparser_5-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'feed-xpathparser_5-unique';
  $feeds_tamper->importer = 'feed';
  $feeds_tamper->source = 'xpathparser:5';
  $feeds_tamper->plugin_id = 'unique';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Makes the elements in a multivalued field unique.';
  $export['feed-xpathparser_5-unique'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'feed-xpathparser_7-convert_to_boolean';
  $feeds_tamper->importer = 'feed';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'true_value' => 'yes',
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'false',
    'other_text' => '',
    'no_match_value' => FALSE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['feed-xpathparser_7-convert_to_boolean'] = $feeds_tamper;

  return $export;
}
