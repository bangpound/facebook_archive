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
    return parent::view($view_mode, $langcode, $page);
  }
}

