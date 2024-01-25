/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** stowa
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the number of words in the string
///
/// \param str  Pointer to the null-derminated string
///
/// \return Return the number of words
///
///////////////////////////////////////////////////////////////////////////////
uint my_wcount(cstring str)
{
    uint count = 0;
    bool found = false;

    for (; *str; ++str) {
        if (my_isspace(*str)) {
            found = false;
            continue;
        }
        if (found == false) {
            count++;
            found = true;
        }
    }
    return (count + 1);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a word array
///
/// \param str  Pointer to the null-derminated string
///
/// \return Array of words
///
///////////////////////////////////////////////////////////////////////////////
string *my_stowa(string str)
{
    string *wa = malloc(sizeof(string) * my_wcount(str));
    int wi = 0;
    string lw = str;

    for (; *str; ++str) {
        for (; *str && my_isspace(*str); ++str);
        lw = str;
        for (; *str && !my_isspace(*str); ++str);
        if (*str == '\0') {
            wa[wi] = my_strdup(lw);
            break;
        }
        *str = '\0';
        wa[wi] = my_strdup(lw);
        wi++;
    }
    wa[wi + 1] = NULL;
    return (wa);
}
