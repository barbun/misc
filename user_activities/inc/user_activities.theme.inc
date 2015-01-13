<?php

function template_preprocess_activity_user_info(&$vars) {
  $vars['userpic'] = '';
  if (variable_get('user_pictures', 0)) {
    $vars['userpic'] = user_get_picture($vars['user'], variable_get('stand_user_block_picture_style', 'image_50x50'), FALSE, array('class' => 'user-info-userpic'));
  }
  $vars['comment_count'] = t('!comments comments placed', array('!comments' => $vars['comment_count']));
  $vars['node_count'] = t('!nodes statements created', array('!nodes' => $vars['node_count']));
  global $user;
  $vars['profile_link'] = '';
  $vars['ignored_link'] = '';
  if ($user->uid) {
    $vars['profile_link'] = l(t('Edit profile'), 'user/' . $vars['user']->uid . '/edit', array('attributes' => array('class' => array('user-info-profile-link', 'button-gray'))));
    $vars['ignored_link'] = l(t('Ignored users'), 'ignore_user/list', array('attributes' => array('class' => array('user-info-ignored-link', 'button-gray'))));
  }
  if (user_access('manage ip addresses')) {
    $vars['profile_ips'] = l(t('User Logs'), 'user/' . $vars['user']->uid . '/ip', array('attributes' => array('class' => array('user-info-access-log', 'button-gray'))));  
  }
}
