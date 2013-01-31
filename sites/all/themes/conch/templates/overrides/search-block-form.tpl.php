<?php
// $Id: search-block-form.tpl.php,v 0.1.1 2009/10/02 00:13:31 symphonythemes Exp $
?>
<input type="text" maxlength="128" name="search_block_form_keys" id="edit-search_block_form_keys"  size="20"  value="search..." title="Enter the terms you wish to search for." class="form-text" onfocus="if(this.value=='search...') this.value='';" onblur="if(this.value=='') this.value='search...';" />
<input type="submit" name="op" value="Search" class="search-button" />
<input type="hidden" name="form_id" id="edit-search-block-form" value="search_block_form" />
<input type="hidden" name="form_token" id="a-unique-id" value="<?php print drupal_get_token('search_block_form'); ?>" />
