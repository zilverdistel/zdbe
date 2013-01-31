<?php
// $Id: views-view-unformatted--blog.tpl.php,v 0.1.1 2009/10/02 22:22:32 symphonythemes Exp $
/**
 * @file views-view-unformatted--blog.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>

