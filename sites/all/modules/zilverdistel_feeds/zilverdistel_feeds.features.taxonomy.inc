<?php
/**
 * @file
 * zilverdistel_feeds.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function zilverdistel_feeds_taxonomy_default_vocabularies() {
  return array(
    'vocabulary_2' => array(
      'name' => 'Tags',
      'machine_name' => 'vocabulary_2',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
