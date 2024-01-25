/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** strtol
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a long integer
///
/// This function converts the initial part of the string pointed to by 's' to
/// a long integer representation. It also updates the 'ptr' pointer to point
/// to the first non-converted character in the string.
///
/// \param s     The string to convert
/// \param ptr   A pointer to a pointer to char, which will be updated to point
///              to the first non-converted character
///
/// \return      The converted long integer value
///////////////////////////////////////////////////////////////////////////////
int my_strtol(char *s, char **ptr)
{
    ulong i = 0;
    int n = 0;
    bool sign = false;

    while (s[i] == ' ')
        i++;
    if (s[i] == '-') {
        i++;
        sign = true;
    }
    while (S_DIGIT(s[i])) {
        n = (n * 10) + (s[i] - '0');
        i++;
    }
    (*ptr) = (*ptr + i);
    return (sign ? -n : n);
}
