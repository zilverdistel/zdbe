<?php
/**
 * @file
 * zilverdistel_portfolio.features.inc
 */

/**
 * Implements hook_node_info().
 */
function zilverdistel_portfolio_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Projects are shown in the portfolio.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('* Unpublish projects to hide them.
* Promote to front to display a project in a slideshow on the frontpage.'),
    ),
  );
  return $items;
}
