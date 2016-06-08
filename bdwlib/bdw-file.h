/* bdw-file.h
 *
 * Copyright (C) 2016 Ian Hernandez <ihernandezs@openmailbox.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef BDW_FILE__H
#define BDW_FILE__H

#include "bdw-types.h"

/**
 * BdwFileMode:
 * @BDW_FILE_MODE_NONE: Undefined opening mode. Placeholder only, not meant for
 *                      real usage.
 * @BDW_FILE_MODE_READ: Open text file for reading. The stream is positioned at
 *                      the beginning of the file.
 * @BDW_FILE_MODE_READ_PLUS: Open for reading and writing. The stream is
 *                           positioned at the beginning of the file.
 * @BDW_FILE_MODE_WRITE: Truncate file to zero length or create text file for
 *                       writing. The stream is positioned at the beginning of
 *                       the file.
 * @BDW_FILE_MODE_WRITE_PLUS: Open for reading and writing. The file is created
 *                            if it does not exist, otherwise it is truncated.
 *                            The stream is positioned at the beginning of the
 *                            file.
 * @BDW_FILE_MODE_APPEND: Open for appending (writing at end of file). The file
 *                        is created if it does not exist. The stream is
 *                        positioned at the end of the file.
 * @BDW_FILE_MODE_APPEND_PLUS: Open for reading and appending (writing at end of
 *                             file). The file is created if it does not exist.
 *                             The initial file position for reading is at the
 *                             beginning of the file, but output is always
 *                             appended to the end of the file.
 *
 * Specifies the opening mode for a #BdwFile.
 **/
typedef enum
{
  BDW_FILE_MODE_NONE,
  BDW_FILE_MODE_READ,
  BDW_FILE_MODE_READ_PLUS,
  BDW_FILE_MODE_WRITE,
  BDW_FILE_MODE_WRITE_PLUS,
  BDW_FILE_MODE_APPEND,
  BDW_FILE_MODE_APPEND_PLUS
} BdwFileMode;

/**
 * BdwFileType:
 * @BDW_FILE_TYPE_NONE: Undefined file type. Placeholder only, not meant for
 *                      real usage.
 * @BDW_FILE_TYPE_BINARY: The opened file is a binary file.
 * @BDW_FILE_TYPE_TEXT: The opened file is a text file.
 *
 * Specifies the opening type for a #BdwFile.
 **/
typedef enum
{
  BDW_FILE_TYPE_NONE,
  BDW_FILE_TYPE_BINARY,
  BDW_FILE_TYPE_TEXT
} BdwFileType;

/**
 * BdwFile:
 * @file: %FILE pointer that stores the file's data.
 * @location: Location of the file in the disk.
 * @mode: Opening mode for a #BdwFile.
 * @type: Opening type for a #BdwFile.
 *
 * The #BdwFile struct that stores a file's data and auxiliary information.
 **/
typedef struct _BdwFile BdwFile;

/**
 * bdw_file_new:
 * @location: Location of the file in the disk.
 *
 * Creates and initializes a new #BdwFile struct.
 *
 * Returns: A pointer to the newly created #BdwFile struct.
 **/
BdwFile * bdw_file_new (conststring location);

/**
 * bdw_file_destroy:
 * @self: Pointer to the #BdwFile struct to be destroyed.
 *
 * Destroys an existing #BdwFile struct.
 **/
void bdw_file_destroy (BdwFile * self);

/**
 * bdw_file_open:
 * @self:
 * @type:
 * @mode:
 *
 *
 * Returns:
 **/
bool bdw_file_open (BdwFile * self, BdwFileType type, BdwFileMode mode);

/**
 * bdw_file_getline:
 * @self: Text file from which the line will be read.
 *
 * Reads a line from a text file.
 *
 * Returns: The line of text that was read from the file.
 **/
string bdw_file_getline (BdwFile * self);

/**
 * bdw_file_getcontent:
 * @self: Text file from which the content will be read.
 *
 * Reads the content from a text file.
 *
 * Returns: The content of the text file.
 **/
string bdw_file_getcontent (BdwFile * self);

#endif /* BDW_FILE__H */

