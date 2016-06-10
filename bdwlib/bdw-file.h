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

#include <stdio.h>

#include "bdw-types.h"

/**
 * SECTION:bdw-file
 * @title: File utilities
 * @short_description: File handling and utility functions.
 *
 * The #BdwFile is a data structure designed to hold some basic information of a
 * system file, this structure and its associated functions are meant to make
 * file and directory operations easier to handle and implement.
 **/

/**
 * BdwFile:
 * @file: %FILE pointer that stores the file's data.
 * @location: Location of the file in the disk.
 *
 * The #BdwFile struct that stores a file's data and auxiliary information.
 **/
typedef struct _BdwFile BdwFile;
struct _BdwFile
{
  FILE * file;
  string location;
};


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
  BDW_FILE_MODE_NONE = -1,
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
  BDW_FILE_TYPE_NONE = -1,
  BDW_FILE_TYPE_BINARY,
  BDW_FILE_TYPE_TEXT
} BdwFileType;

/**
 * BdwFileError:
 * @BDW_FILE_ERROR_OK: Result OK, no errors.
 * @BDW_FILE_ERROR_ALREADY_OPENED: The file stream contained in the #BdwFile
 *                                 struct is already opened.
 * @BDW_FILE_ERROR_NOT_INITIALIZED: The #BdwFile struct is not initialized.
 * @BDW_FILE_ERROR_BAD_ARGUMENTS: Either @mode or @type arguments in a #BdwFile
 *                                struct are invalid.
 * @BDW_FILE_ERROR_INVALID_LOCATION: The #BdwFile struct file location is an
 *                                   invalid path, or %NULL.
 * @BDW_FILE_ERROR_FATAL: The file stream contained in the #BdwFile could not be
 *                        opened correctly.
 *
 * Specifies errors occurring during operations on a #BdwFile.
 **/
typedef enum
{
  BDW_FILE_ERROR_OK = 0,
  BDW_FILE_ERROR_ALREADY_OPENED,
  BDW_FILE_ERROR_NOT_INITIALIZED,
  BDW_FILE_ERROR_BAD_ARGUMENTS,
  BDW_FILE_ERROR_INVALID_LOCATION,
  BDW_FILE_ERROR_FATAL
} BdwFileError;


/*    Function prototypes    */
#ifdef __cplusplus /*    C++ support    */
extern "C" {
#endif

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
 * @self: The #BdwFile containing the file stream to be opened.
 * @type: #BdwFileType, representation of the file type.
 * @mode: #BdwFileType, representation of the file opening mode.
 *
 * Used to open the file stream contained in a #BdwFile struct.
 *
 * Returns: %BDW_FILE_ERROR_OK if the file was opened correctly, any other
 * #BdwFileError value otherwise.
 **/
BdwFileError bdw_file_open (BdwFile * self, BdwFileType type, BdwFileMode mode);

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

/**
 * bdw_file_putline:
 * @self: Text file where @line will be written.
 * @line: Line of text to be written to the file.
 *
 * Writes a line to a text file.
 **/
void bdw_file_putline (BdwFile * self, conststring line);

/**
 * bdw_file_putcontent:
 * @self: Text file to set its content.
 * @content: Content to be written to the file.
 *
 * Writes the content of a text file.
 **/
void bdw_file_putcontent (BdwFile * self, conststring content);

#ifdef __cplusplus
}
#endif

#endif /* BDW_FILE__H */

