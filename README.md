# bdwlib
bdwlib is a general purpose library written in C, it provides some utility 
functions for strings, files and the most commonly used data structures like 
simple and doubly-linked Lists, Stacks and Queues.

It's partially based on the functions offered by [GLib](https://developer.gnome.org/glib).

### Custom data-types
| Symbol | Description |
|:---|:---|
| `pointer` | Definition of the generic pointer data-type (`void *`). |
| `constpointer` | Definition of the generic constant pointer data-type (`const void *`). |
| `string` | Definition of the character string data-type (`char *`). |
| `conststring` | Definition of the constant character string data-type (`const char *`). |

### Custom function-types
| Symbol | Description |
|:---|:---|
|  |  |

### Convenience aliases for existing data-types
| Symbol | Description |
|:---|:---|
| `uchar` | Convenience alias for unsigned char data-type (`unsigned char`). |
| `ushort` | Convenience alias for unsigned short integer data-type (`unsigned short`). |
| `uint` | Convenience alias for unsigned integer data-type (`unsigned int`). |
| `ulong` | Convenience alias for unsigned long integer data-type (`unsigned long`). |
| `uint8` | Convenience alias for unsigned 8 bit integer data-type (`unsigned char`). |
| `uint16` | Convenience alias for unsigned 16 bit integer data-type (`unsigned short`). |
| `uint32` | Convenience alias for unsigned 32 bit integer data-type (`unsigned int`). |
| `uint64` | Convenience alias for unsigned 64 bit integer data-type (`unsigned long`). |
| `int8` | Convenience alias for unsigned 8 bit integer data-type (`signed char`). |
| `int16` | Convenience alias for unsigned 16 bit integer data-type (`signed short`). |
| `int32` | Convenience alias for unsigned 32 bit integer data-type (`signed int`). |
| `int64` | Convenience alias for unsigned 64 bit integer data-type (`signed long`). |
| `byte` | Convenience alias for an unsigned byte (8 bit) data-type (`unsigned char`). |
| `bool` | Convenience alias for a boolean data-type (`unsigned char`). |

### Custom data structures
| Symbol | Description |
|:---|:---|
| `BdwFile` | Struct that stores file data and auxiliary information. |
| `BdwArray` | Struct that stores an array of elements and the number of elements it holds. |
| `BdwByteArray` | Struct that stores an array of bytes and the number of elements it holds. |

### Standard data structures
| Symbol | Description |
|:---|:---|
| `BdwList` | Implementation of a doubly-linked list. |
| `BdwSimpleList` | Implementation of a singly-linked list. |
| `BdwStaticStack` | Implementation of a stack using a static array. |
| `BdwStack` | Implementation of a stack using a dynamic array (list). |
| `BdwStaticQueue` | Implementation of a queue using a static array. |
| `BdwQueue` | Implementation of a queue using a dynamic array (list). |

