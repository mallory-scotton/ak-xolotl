/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** strings
*/

#ifndef STRINGS_H_
    #define STRINGS_H_

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
ulong my_strlen(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert all uppercase letters in a string to lowercase
///
/// \param str      The string to convert.
///
/// \return A pointer to the modified string
///
///////////////////////////////////////////////////////////////////////////////
string my_strlwr(string str);

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
string my_strcat(string str, cstring append);

///////////////////////////////////////////////////////////////////////////////
/// \brief Find the first occurrence of a character in a string.
///
/// \param p     Pointer to the string to search.
/// \param ch    The character to search for.
///
/// \return Pointer to the first occurrence of the character in the string,
/// or NULL if not found.
///////////////////////////////////////////////////////////////////////////////
string my_strchr(cstring p, int ch);

///////////////////////////////////////////////////////////////////////////////
/// \brief Set all characters in a string to null ('\0').
///
/// \param str   The string to clear.
///
/// \return      A pointer to the modified string.
///////////////////////////////////////////////////////////////////////////////
string my_strclr(string str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Compare two strings.
///
/// \param s1    The first string to compare.
/// \param s2    The second string to compare.
///
/// \return An integer less than, equal to, or greater than zero if s1
/// is found, respectively, to be less than, to match, or be greater than s2.
///
///////////////////////////////////////////////////////////////////////////////
int my_strcmp(cstring s1, cstring s2);

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the number of words in the string
///
/// \param str  Pointer to the null-derminated string
///
/// \return Return the number of words
///
///////////////////////////////////////////////////////////////////////////////
uint my_wcount(cstring str);

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a word array
///
/// \param str  Pointer to the null-derminated string
///
/// \return Array of words
///
///////////////////////////////////////////////////////////////////////////////
string *my_stowa(string str);

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
int my_strtol(char *s, char **ptr);

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
string my_strdup(cstring str);

#endif /* !STRINGS_H_ */