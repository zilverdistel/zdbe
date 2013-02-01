
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Developers
 * Frequently Asked Questions (FAQ)
 * Known Issues
 * More Information
 * How Can You Contribute?


INTRODUCTION
------------

Current Maintainer: Dave Reid <dave@davereid.net>

Utility module that provides an interface for the legacy custom_url_rewrite()
functions.


INSTALLATION
------------

See http://drupal.org/getting-started/install-contrib for instructions on
how to install or update Drupal modules.


FREQUENTLY ASKED QUESTIONS (FAQ)
--------------------------------

Q: What if I have my own custom_url_rewrite functions in my settings.php?
A: URL alter will not work unless you remove those functions. Luckily, you can
   copy the code inside those functions and paste them into the URL alter
   module settings (admin/settings/url-alter).

Q: Help! I put in invalid PHP code in admin/settings/url-alter!
A: If you add ?url-alter-kill to any URL on your site, it should temporarily
   disable the module. The PHP code will always be prevented from running on
   admin/settings/url-alter so you can always fix your PHP code on that page.


KNOWN ISSUES
------------

- There are no known issues at this time.


MORE INFORMATION
----------------

- To issue any bug reports, feature or support requests, see the module issue
  queue at http://drupal.org/project/issues/url_alter.


HOW CAN YOU CONTRIBUTE?
---------------------

- Write a review for this module at drupalmodules.com.
  http://drupalmodules.com/module/url-alter

- Help translate this module.
  http://localize.drupal.org/translate/projects/url_alter

- Report any bugs, feature requests, etc. in the issue tracker.
  http://drupal.org/project/issues/url_alter

- Contact the maintainer with any comments, questions, or feedback.
  http://davereid.net/contact
