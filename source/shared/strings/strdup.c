/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** strdup
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Duplicate a string
///
/// This function duplicates the input string 'str' using dynamic memory
/// allocation. It returns a pointer to the newly allocated string.
///
/// \param str   The input string to duplicate
///
/// \return      A pointer to the duplicated string, or NULL if memory
///              allocation fails
///////////////////////////////////////////////////////////////////////////////
string my_strdup(cstring str)
{
    ulong len = my_strlen(str) + 1;
    string copy;

    copy = malloc((uint)len);
    if (!copy)
        return (NULL);
    my_memcpy(copy, str, len);
    return (copy);
}
