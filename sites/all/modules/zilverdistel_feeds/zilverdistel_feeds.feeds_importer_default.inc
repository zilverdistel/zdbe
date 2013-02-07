<?php
/**
 * @file
 * zilverdistel_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function zilverdistel_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feed';
  $feeds_importer->config = array(
    'name' => 'Feed',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => '@description',
          'xpathparser:1' => '@extended',
          'xpathparser:2' => '@time',
          'xpathparser:3' => '@href',
          'xpathparser:4' => '@hash',
          'xpathparser:5' => '@tag',
          'xpathparser:6' => '@shared',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
        ),
        'context' => '/posts/post',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'input_format' => '1',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_original_link:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'parent:uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:5',
            'target' => 'taxonomy_vocabulary_2',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:6',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'authorize' => 0,
        'skip_hash_check' => 0,
        'bundle' => 'feed_item',
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['feed'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'link_file';
  $feeds_importer->config = array(
    'name' => 'Link file',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
        'allowed_extensions' => 'txt csv tsv xml opml',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'input_format' => '1',
        'update_existing' => '2',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'description',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'href',
            'target' => 'field_original_link:url',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'time',
            'target' => 'created',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'extended',
            'target' => 'body',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'tag',
            'target' => 'taxonomy:2',
            'unique' => FALSE,
          ),
        ),
        'author' => '1',
        'bundle' => 'feed_item',
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['link_file'] = $feeds_importer;

  return $export;
}
