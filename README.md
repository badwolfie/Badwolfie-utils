# Badwolfie-utils
Generic utility functions written in C.

### Data-types included
* `pointer` - Generic pointer (`void *`)
* `string` - Character string (`char *`)
* `cstring` - Constant character string (`const char *`)

### Data structures included
* `BdwArray` - Struct that stores an array of elements and its length.

### Functions included
##### String utilities
* `bdw_utils_strconcat` - Function used to concatenate the given strings.
* `bdw_utils_strcopy` - Function that creates a copy of the given string.
* `bdw_utils_strequals` - Function that compares two strings.
* `bdw_utils_strtrim` - Function that trims a string at the first occurrence of a given character.
* `bdw_utils_strappendchr` - Function that appends a character to a given string.
* `bdw_utils_strsplit` - Function used to tokenize (or split) a given string by a given delimiter.

##### Array utilities
* `bdw_utils_nullarraylen` - Function that obtains the length of a NULL-terminated array of elements.
* `bdw_array_new` - Function that creates and initializes a new BdwArray struct.
* `bdw_array_destroy` - Function that destroys and existing BdwArray struct.

##### File utilities
* `bdw_utils_filegetline` - Function that reads a line from a text file.
