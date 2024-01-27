/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** isint
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid integer
///
/// \param str  The input string to check for integer representation
///
/// \return Returns true if 'str' represents a valid integer, otherwise
/// false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isint(string str)
{
    if (*str == '-' || *str == '+')
        str++;
    for (; *str; str++)
        RETURN(!(*str >= '0' && *str <= '9'), false);
    return (true);
}
