/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/dependencies.h"
    #include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Misc
///////////////////////////////////////////////////////////////////////////////
    #undef bool
    #undef true
    #undef false

///////////////////////////////////////////////////////////////////////////////
/// \brief C boolean types
///
/// \param false    False value, similar to 0
/// \param true     True value, similar to 1
///
///////////////////////////////////////////////////////////////////////////////
typedef enum {
    false,
    true
} bool;

///////////////////////////////////////////////////////////////////////////////
/// \brief Status type
///
/// \param fail         Fail value, similar to 0
/// \param success      Success value, similar to 1
///
///////////////////////////////////////////////////////////////////////////////
typedef enum {
    fail,
    success
} status;

///////////////////////////////////////////////////////////////////////////////
///  \brief String type
///
///////////////////////////////////////////////////////////////////////////////
typedef char *string;

///////////////////////////////////////////////////////////////////////////////
///  \brief Constant string type
///
///////////////////////////////////////////////////////////////////////////////
typedef const char *cstring;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned string type
///
///////////////////////////////////////////////////////////////////////////////
typedef unsigned char *ustring;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned integer type [0 - 4,294,967,295]
///
///////////////////////////////////////////////////////////////////////////////
typedef unsigned int uint;

///////////////////////////////////////////////////////////////////////////////
/// \brief Pointer to an integer
///
///////////////////////////////////////////////////////////////////////////////
typedef int *pint;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned char type [0 - 255]
///
///////////////////////////////////////////////////////////////////////////////
typedef unsigned char uchar;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned long type [0 - 18,446,744,073,709,551,615]
///
///////////////////////////////////////////////////////////////////////////////
typedef unsigned long ulong;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned long type [0 - 65,535]
///
///////////////////////////////////////////////////////////////////////////////
typedef unsigned short ushort;

///////////////////////////////////////////////////////////////////////////////
/// \brief 2D floating vector
///
/// \param x    Floating point
/// \param y    Floating point
///
///////////////////////////////////////////////////////////////////////////////
typedef sfVector2f vec2f;

///////////////////////////////////////////////////////////////////////////////
/// \brief 2D integer vector
///
/// \param x    Integer point
/// \param y    Integer point
///
///////////////////////////////////////////////////////////////////////////////
typedef sfVector2i vec2i;

///////////////////////////////////////////////////////////////////////////////
/// \brief 2D unsigned integer vector
///
/// \param x    Unsigned integer point
/// \param y    Unsigned integer point
///
///////////////////////////////////////////////////////////////////////////////
typedef sfVector2u vec2u;

///////////////////////////////////////////////////////////////////////////////
/// \brief 3D floating vector
///
/// \param x    Floating point
/// \param y    Floating point
/// \param z    Floating point
///
///////////////////////////////////////////////////////////////////////////////
typedef sfVector3f vec3f;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned char type [0 - 255]
///
///////////////////////////////////////////////////////////////////////////////
typedef uint8_t u8;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned long type [0 - 65,535]
///
///////////////////////////////////////////////////////////////////////////////
typedef uint16_t u16;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned integer type [0 - 4,294,967,295]
///
///////////////////////////////////////////////////////////////////////////////
typedef uint32_t u32;

///////////////////////////////////////////////////////////////////////////////
///  \brief Unsigned long type [0 - 18,446,744,073,709,551,615]
///
///////////////////////////////////////////////////////////////////////////////
typedef uint64_t u64;

#endif /* !TYPES_H_ */
