<?php

/**
 * @file
 * Implementation of handlers and data for views.
 */

/**
 * Implements hook_views_handlers().
 */
function disapprove_comment_link_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'disapprove_comment_link') . '/includes',
    ),
    'handlers' => array(
      'disapprove_comment_link_handler_comment_link_disapprove' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements of hook_views_data().
 */
function disapprove_comment_link_views_data() {
  $data['comment']['disapprove_comment'] = array(
    'title' => t('Disapprove link'),
    'help' => t('Provide a simple link to disapprove the comment.'),
    'field' => array(
      'handler' => 'disapprove_comment_link_handler_comment_link_disapprove',
    ),
  );

  return $data;
}
