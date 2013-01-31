<?php
function getSubMenu($level) {
  $menu_theme = menu_navigation_links("primary-links", $level);
  if ($menu_theme) {
    $menu = "<ul class='menu'>";
    $i = 0;
    $class = "";
    foreach ($menu_theme as $value) {
      if ($i == 0) $class="first";
      elseif ($i == count($menu_theme) - 1) $class = "last";
      else $class = "";
      $i++;
      $menu .= "<li class=\"" . $class . "\">";
      $menu .= l($value['title'], $value['href']);
      $menu .= "</li>";
    }
  
    $menu .= "</ul>";
  }
  
  return $menu;
}
function getTitleActiveMenu($menu_name) {
  // Don't even bother querying the menu table if no menu is specified.
  if (empty($menu_name)) {
    return array();
  }
  
  // Get the menu hierarchy for the current page.
  $tree = menu_tree_page_data($menu_name);
  $item_level = 1;
  $result = array();
  $flag = 0;
  // Go down the active trail until the right level is reached.
  while ($tree) {
    // Loop through the current level's items until we find one that is in trail.
    while ($item = array_shift($tree)) {
      if ($item['link']['in_active_trail']) {
        if ($item['link']['has_children']) {
          while ($sub_item = array_shift($item['below'])) {
            if ($sub_item['link']['in_active_trail']) {
              $result['title'] = $sub_item['link']['link_title'];
              $item_level = $sub_item['link']['depth'];
              $flag = 1;
            }
          }
        }
        if (!$flag) {
          $result['title'] = $item['link']['link_title'];
          $item_level = $item['link']['depth'];
        }
      }
    }
  }
  $result['submenu'] = getSubMenu($item_level);
  
  return $result;
}