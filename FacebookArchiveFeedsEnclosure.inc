<?php

/**
 * Enclosure element, can be part of the result array.
 */
class FacebookArchiveFeedsEnclosure extends FeedsEnclosure {

  public function getFile($destination) {

    if ($this->getValue()) {
      // Prepare destination directory.
      file_prepare_directory($destination, FILE_MODIFY_PERMISSIONS | FILE_CREATE_DIRECTORY);
      // Copy or save file depending on whether it is remote or local.
      $file           = new stdClass();
      $file->uid      = 0;
      $file->uri      = $this->getValue();
      $file->filemime = $this->mime_type;
      $file->filename = basename($file->uri);

      // If file is not to be copied, check whether file already exists,
      // as file_save() won't do that for us (compare file_copy() and
      // file_save())
      $existing_files = file_load_multiple(array(), array('uri' => $file->uri));
      if (count($existing_files)) {
        $existing = reset($existing_files);
        $file->fid = $existing->fid;
        $file->filename = $existing->filename;
      }
      file_save($file);

      // We couldn't make sense of this enclosure, throw an exception.
      if (!$file) {
        throw new Exception(t('Invalid enclosure %enclosure', array('%enclosure' => $this->getValue())));
      }
    }
    return $file;
  }
}
