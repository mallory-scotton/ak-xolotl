/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** strlen
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine/types.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the length of a null-terminated string.
///
/// \param str  Pointer to the null-terminated string.
///
/// \return The length of the string (excluding the null terminator)
///
///////////////////////////////////////////////////////////////////////////////
ulong my_strlen(cstring str)
{
    cstring s;

    for (s = str; *s; ++s);
    return (s - str);
}
