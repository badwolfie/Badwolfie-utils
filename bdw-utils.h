/* Copyright (c) 2016 Ian Hernandez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
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
