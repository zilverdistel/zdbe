<?php
function getSubItemsMenu($item,$active_items) {
	$result = "<ul class='menu'>";
	while($item) {
		$count = 0;
		$first_last_class = '';
		$total_items = count($item);
		
		while ($sub_item = array_shift($item)) {
			if(!$sub_item['link']['hidden']) {
				if($count==0) $first_last_class = ' first';
				elseif($count==$total_items-1) $first_last_class = ' last';
				else $first_last_class = '';
				$count++; 
				
				$result .= add_li_tag($sub_item, $first_last_class,$active_items);
				$result .= l($sub_item['link']['title'],$sub_item['link']['href']);
				
				if($sub_item['link']['has_children']) {
					$result .= getSubItemsMenu($sub_item['below'],$active_items);
				}
				$result .= "</li>";
			}
		}
	}
	$result .= "</ul>";

	return $result;
}

function add_li_tag($item, $first_last_class,$active_items) {
	$class = 'leaf';
	$class .= $first_last_class;
	
	$active = check_active($item['link'],$active_items);
	if($item['link']['has_children'] and $item['link']['depth']==1) {
		$class .= ' expanded';
		if($active) $class .= ' active-trail havechild-active';
		else $class .= ' havechild';
	}
	if($item['link']['has_children'] and $item['link']['depth']>1) {
		$class .= ' expanded';
		if($active) $class .= ' active-trail havesubchild-active';
		else $class .= ' havesubchild';
	}
	
	$link = '<li class="'.$class.'">';
	
	return $link;
}

function check_active($item,$active_items) {
	$flag = 0;
	for($i=0;$i<count($active_items);$i++){
		if($active_items[$i]['href']==$item['href']) {
			$flag = 1;
		}
	}
	return $flag;
}
function get_links($menu_name) {
	$tree = menu_tree_all_data($menu_name);
	$active_items = active_items_list($menu_name);
	$result = getSubItemsMenu($tree,$active_items);
	return $result;
}

function active_items_list($menu_name) {
	// Don't even bother querying the menu table if no menu is specified.
	if (empty($menu_name)) {
		return array();
	}
	
	// Get the menu hierarchy for the current page.
	$tree = menu_tree_page_data($menu_name);
	$item_level = 0;
	$result = array();
	$result = get_active_items($tree);

	return $result;
}

function get_active_items($tree) {
	// Go down the active trail until the right level is reached.
	while ($tree) {
		// Loop through the current level's items until we find one that is in trail.
		while ($item = array_shift($tree)) {
			if ($item['link']['in_active_trail']) {
				$result[] = $item['link'];
				
				if($item['link']['has_children']) {
					$abc = get_active_items($item['below']);
					for($i=0;$i<count($abc);$i++) {
						$result[] = $abc[$i];
					}
				}
			}
		}
	}
	
	return $result;
}
