<?php

/**
 * @file
 * User page callbacks for the disapprove comment link module.
 */

/**
 * Menu callback; disapprove specified comment.
 *
 * @param integer $cid
 *   A comment identifier.
 */
function disapprove_comment_link_disapprove($cid) {
  if (!isset($_GET['token']) || !drupal_valid_token($_GET['token'], "comment/$cid/disapprove")) {
    return MENU_ACCESS_DENIED;
  }
  if ($comment = comment_load($cid)) {
    $comment->status = COMMENT_NOT_PUBLISHED;
    comment_save($comment);

    drupal_set_message(t('Comment disapproved.'));
    drupal_goto('node/' . $comment->nid);
  }
  return MENU_NOT_FOUND;
}
