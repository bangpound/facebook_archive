<?php
/**
 * @file
 * facebook_archive.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function facebook_archive_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'facebook_links';
  $feeds_importer->config = array(
    'name' => 'Facebook links',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsFacebookParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FacebookArchiveProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'created_time',
            'target' => 'changed',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'created_time',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'post_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'post',
            'target' => 'data',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'link',
            'target' => 'field_original_url:url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'name',
            'target' => 'field_original_url:title',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'message',
            'target' => 'field_message',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'picture',
            'target' => 'field_image',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => '1',
        'skip_hash_check' => 0,
        'bundle' => 'link',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['facebook_links'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'facebook_photos';
  $feeds_importer->config = array(
    'name' => 'Facebook photos',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsFacebookParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FacebookArchiveProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'updated_time',
            'target' => 'changed',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'created_time',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'post_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'post',
            'target' => 'data',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'source',
            'target' => 'field_image',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'name',
            'target' => 'field_name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => '2',
        'skip_hash_check' => 0,
        'bundle' => 'photo',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['facebook_photos'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'facebook_statuses';
  $feeds_importer->config = array(
    'name' => 'Facebook statuses',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsFacebookParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FacebookArchiveProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'updated_time',
            'target' => 'changed',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'updated_time',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'post_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'post',
            'target' => 'data',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'message',
            'target' => 'field_message',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => '1',
        'skip_hash_check' => 0,
        'bundle' => 'status',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['facebook_statuses'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'facebook_videos';
  $feeds_importer->config = array(
    'name' => 'Facebook videos',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsFacebookParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FacebookArchiveProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'updated_time',
            'target' => 'changed',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'created_time',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'post_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'post',
            'target' => 'data',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'description',
            'target' => 'field_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'source',
            'target' => 'field_media:remote',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'name',
            'target' => 'field_name',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'picture',
            'target' => 'field_image',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => '1',
        'skip_hash_check' => 0,
        'bundle' => 'video',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['facebook_videos'] = $feeds_importer;

  return $export;
}
