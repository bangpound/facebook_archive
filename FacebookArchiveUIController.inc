<?php

class FacebookArchiveUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    return $items;
  }

  public function overviewTable($conditions = array()) {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType);

    // Add all conditions to query.
    foreach ($conditions as $key => $value) {
      $query->propertyCondition($key, $value);
    }

    if ($this->overviewPagerLimit) {
      $query->pager($this->overviewPagerLimit);
    }

    $results = $query->execute();

    $ids = isset($results[$this->entityType]) ? array_keys($results[$this->entityType]) : array();
    $entities = $ids ? entity_load($this->entityType, $ids) : array();
    ksort($entities);

    $rows = array();
    foreach ($entities as $entity) {
      $wrapper = entity_metadata_wrapper('facebook_archive_object', $entity);
      $additional_cols = array(
        'type' => $entity->type,
        'status' => $wrapper->status->label(),
        'changed' => format_date($entity->changed, 'short'),
      );
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity, $additional_cols);
    }

    $additional_cols = array(
      'type' => array('data' => t('Type')),
      'status' => array('data' => t('Status')),
      'changed' => array('data' => t('Updated'))
    );

    $render = array(
      '#theme' => 'table',
      '#header' => $this->overviewTableHeaders($conditions, $rows, $additional_cols),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }
}

