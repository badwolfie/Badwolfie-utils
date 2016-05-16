#ifndef UTIL__H
#define UTIL__H

/**  */
#ifndef TRUE
#define TRUE 0x01
#endif

/**  */
#ifndef FALSE
#define FALSE 0x00
#endif

/**  */
typedef unsigned char Bool;

/**  */
typedef void* pointer;

/**
 *
 */
char * bdw_utils_strconcat (const char * arg, ...);

/**
 *
 */
char * bdw_utils_strcopy (const char * arg);

/**
 *
 */
Bool bdw_utils_strequals (const char * arg1, const char * arg2);

/**
 *
 */
void bdw_utils_strchrappend (char * dest, char c);

/**
 *
 */
int bdw_utils_array_len (pointer array);

#endif /* UTIL__H */
