<?php
/**
 * @file
 * facebook_archive.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function facebook_archive_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "plugins") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function facebook_archive_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_facebook_archive_object_type().
 */
function facebook_archive_default_facebook_archive_object_type() {
  $items = array();
  $items['link'] = entity_import('facebook_archive_object_type', '{ "name" : "link", "label" : "Link", "weight" : "0", "locked" : "0" }');
  $items['photo'] = entity_import('facebook_archive_object_type', '{ "name" : "photo", "label" : "Photo", "weight" : "0", "locked" : "0" }');
  $items['status'] = entity_import('facebook_archive_object_type', '{ "name" : "status", "label" : "Status", "weight" : "0", "locked" : "0" }');
  $items['video'] = entity_import('facebook_archive_object_type', '{ "name" : "video", "label" : "Video", "weight" : "0", "locked" : "0" }');
  return $items;
}
