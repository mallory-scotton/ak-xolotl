/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro to check if a character is a digit
///
/// \param c     The character to check
///
/// \return      Returns true if 'c' is a digit, otherwise false
///////////////////////////////////////////////////////////////////////////////
    #define S_DIGIT(c) ((c) >= '0' && (c) <= '9')

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro for conditional early return
///
/// \param condition  The condition to check
/// \param value      The value to return if the condition is true
///////////////////////////////////////////////////////////////////////////////
    #define RETURN(condition, value) if (condition) return (value)

#endif /* !MACROS_H_ */
