<?php

/**
 * @file
 * FacebookArchiveProcessor class.
 */

/**
 * Feeds processor plugin. Create taxonomy terms from feed items.
 */
class FacebookArchiveProcessor extends FeedsProcessor {
  /**
   * Define entity type.
   */
  public function entityType() {
    return 'facebook_archive_object';
  }

  /**
   * Creates a new term in memory and returns it.
   */
  protected function newEntity(FeedsSource $source) {
    $entity = entity_create($this->entityType(), array());
    $entity->type = $this->bundle();
    $entity->timestamp = time();
    return $entity;
  }

  /**
   * Saves a term.
   *
   * We de-array parent fields with only one item.
   * This stops leftandright module from freaking out.
   */
  protected function entitySave($entity) {
    entity_save($this->entityType(), $entity);
  }

  /**
   * Deletes a series of terms.
   */
  protected function entityDeleteMultiple($ids) {
    entity_delete_multiple($this->entityType(), $ids);
  }

  /**
   * Override setTargetElement to operate on a target item that is a node.
   */
  public function setTargetElement(FeedsSource $source, $target_item, $target_element, $value) {
    switch ($target_element) {
      case 'created':
      case 'timestamp':
      case 'changed':
        $target_item->{$target_element} = feeds_to_unixtime($value, REQUEST_TIME);
        break;
      default:
        parent::setTargetElement($source, $target_item, $target_element, $value);
        break;
    }
  }

  public function getMappingTargets() {
    $targets = parent::getMappingTargets();
    $targets += array(
      'data' => array(
        'name' => t('Data'),
        'description' => t('Serialized row'),
      ),
      'created' => array(
        'name' => t('Created date'),
        'description' => t('The created (e. g. joined) data of the user.'),
       ),
      'changed' => array(
        'name' => t('Changed date'),
        'description' => t('The created (e. g. joined) data of the user.'),
       ),
      'timestamp' => array(
        'name' => t('Archive date'),
        'description' => t('The created (e. g. joined) data of the user.'),
       ),
      'status' => array(
        'name' => t('Visibility'),
        'description' => t('Whether a user is active or not. 1 stands for active, 0 for blocked.'),
      ),
    );

    // Let other modules expose mapping targets.
    self::loadMappers();
    $entity_type = $this->entityType();
    $bundle = $this->bundle();
    drupal_alter('feeds_processor_targets', $targets, $entity_type, $bundle);

    return $targets;
  }
}
