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
#ifndef bool
#define bool unsigned char
#endif

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
bool bdw_utils_strequals (const char * arg1, const char * arg2);

/**
 *
 */
void bdw_utils_strchrappend (char * dest, char c);

#endif
