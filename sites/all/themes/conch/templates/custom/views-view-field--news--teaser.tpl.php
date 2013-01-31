<?php
// $Id: views-view-field--news--teaser.tpl.php,v 0.1.1 2009/10/02 22:22:32 symphonythemes Exp $
 /**
  * This template is used to print a single field in a view. It is not
  * actually used in default Views, as this is registered as a theme
  * function which has better performance. For single overrides, the
  * template is perfectly okay.
  *
  * Variables available:
  * - $view: The view object
  * - $field: The field handler object that can process the input
  * - $row: The raw SQL result that can be used
  * - $output: The processed output that will normally be used.
  *
  * When fetching output from the $row, this construct should be used:
  * $data = $row->{$field->field_teaser}
  *
  * The above will guarantee that you'll always get the correct data,
  * regardless of any changes in the aliasing that might happen if
  * the view is modified.
  */
?>
<?php if($row->node_data_field_image_field_image_fid) { ?>
<div class="grid_6 omega"><?php print $output; ?></div>
<?php }else { ?>
<?php print $output; ?>
<?php } ?>