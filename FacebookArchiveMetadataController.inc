<?php

class FacebookArchiveMetadataController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['status'] = array(
      'label' => t("Status"),
      'description' => t("Whether the node is published or unpublished."),
      // Although the status is expected to be boolean, its schema suggests
      // it is an integer, so we follow the schema definition.
      'type' => 'integer',
      'options list' => 'entity_metadata_status_options_list',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer nodes',
      'schema field' => 'status',
    );
    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the node was posted."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer nodes',
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the node was most recently updated."),
    );
    $properties['timestamp'] = array(
      'label' => t("Timestamp"),
      'type' => 'date',
      'schema field' => 'timestamp',
      'description' => t("The date the node was archived."),
    );
    return $info;
  }
}

