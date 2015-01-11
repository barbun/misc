INTRODUCTION
------------
Maintainer:
  Roman Barbun (http://drupal.org/user/66894)

OVERVIEW
--------

This small module provides a possibility to disapprove comment by adding a
"disapprove" link (same as "approve" link, but oposite). Views integration is
also provided.

There's also my issue + patch for Drupal 7 core, but since it's not committed to
the HEAD and not released yet, I thought that it would be cool to provide this
solution in a way of module.

Issue : http://drupal.org/node/1545220

SETTING UP
----------
Just install a module and "disapprove" link will appear in comment links ( in a
row with 'delete', 'edit', approve' etc.).
Also, "disapprove" link will appear in Views.

DEPENDENCIES
------------
This module is build on Drupal Core module Comment, that's why Comment module
should be enabled.


NOTE: It would be great to add AJAX processing for "disapprove" link, so I leave
it as TO-DO.
