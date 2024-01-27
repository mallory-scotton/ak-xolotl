/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** numbers
*/

#ifndef NUMBERS_H_
    #define NUMBERS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/types.h"
    #include "engine/dependencies.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid integer
///
/// \param str  The input string to check for integer representation
///
/// \return Returns true if 'str' represents a valid integer, otherwise
/// false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isint(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid floating-point number
///
/// \param str  The input string to check for floating-point representation
///
/// \return    Returns true if 'str' represents a valid floating-point number,
///            otherwise false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isfloat(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid boolean value
///
/// \param str  The input string to check for boolean representation
///
/// \return    Returns true if 'str' represents a valid boolean value,
///            otherwise false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isbool(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a boolean value
///
/// \param str  The input string to convert to a boolean value
///
/// \return    Returns the boolean value corresponding to 'str',
///            or false if the conversion is not possible
///////////////////////////////////////////////////////////////////////////////
bool my_atob(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to an integer
///
/// \param str  The input string to convert to an integer
///
/// \return    Returns the integer value corresponding to 'str'
///
///////////////////////////////////////////////////////////////////////////////
int my_atoi(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a floating-point number
///
/// \param str  The input string to convert to a floating-point number
///
/// \return    Returns the floating-point value corresponding to 'str'
///
///////////////////////////////////////////////////////////////////////////////
double my_atof(string str);

#endif /* !NUMBERS_H_ */