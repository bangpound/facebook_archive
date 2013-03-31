<?php

class FacebookArchiveObject extends Entity {

  function defaultLabel() {
    $label = '';

    return $label;
  }

  function defaultUri() {
    return array('path' => 'facebook/post/' . $this->identifier());
  }

  public function view($view_mode = 'full', $langcode = NULL, $page = NULL) {
    $build = parent::view($view_mode, $langcode, $page);
    if (!empty($this->id)) {
      $build['#contextual_links']['facebook_archive_object'] = array('facebook_archive_object', array($this->id));
    }
    return $build;
  }
}

