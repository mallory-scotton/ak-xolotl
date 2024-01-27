/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** strchr
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine/types.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Find the first occurrence of a character in a string.
///
/// \param p     Pointer to the string to search.
/// \param ch    The character to search for.
///
/// \return Pointer to the first occurrence of the character in the string,
/// or NULL if not found.
///
///////////////////////////////////////////////////////////////////////////////
string my_strchr(cstring p, int ch)
{
    char c = ch;

    for (;; ++p) {
        if (*p == c)
            return ((char *)p);
        if (*p == '\0')
            return (NULL);
    }
}
