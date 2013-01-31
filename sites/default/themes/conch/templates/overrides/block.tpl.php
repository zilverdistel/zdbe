<?php
// $Id: block.tpl.php,v 0.1.1 2009/10/02 22:22:32 symphonythemes Exp $
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="clear-block block block-<?php print $block->module ?> <?php if (function_exists('block_class')) print block_class($block); ?>">

<?php if (!empty($block->subject)): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>

  <div class="content"><?php print $block->content ?></div>
</div>
