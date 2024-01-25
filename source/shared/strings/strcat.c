/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** strcat
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine/types.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Concatenate (append) a null-terminated string to another
/// null-terminated string.
///
/// \param str      Pointer to the destination string.
/// \param append   Pointer to the source string to be appended.
///
/// \return Pointer to the destination string (initial position).
///
///////////////////////////////////////////////////////////////////////////////
string my_strcat(string str, cstring append)
{
    string save = str;

    for (; *str; ++str);
    while (*str && *append) {
        *str = *append;
        str++;
        append++;
    }
    return (save);
}
