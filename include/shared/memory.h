/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** memory
*/

#ifndef MEMORY_H_
    #define MEMORY_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/types.h"
    #include "engine/dependencies.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Copy memory area
///
/// This function copies 'n' bytes from the memory area pointed to by 'src' to
/// the memory area pointed to by 'dst'. The copying stops when 'n' bytes are
/// copied or when a null terminator is encountered in the source string.
///
/// \param dst   Pointer to the destination memory area
/// \param src   Pointer to the source memory area
/// \param n     Number of bytes to copy
///
/// \return      Pointer to the destination memory area ('dst')
///
///////////////////////////////////////////////////////////////////////////////
void *my_memcpy(void *dst, const void *src, ulong n);

///////////////////////////////////////////////////////////////////////////////
/// \brief Reallocate memory for a block with a new size and copy the
/// existing data.
///
/// \param ptr   Pointer to the current memory block to be reallocated.
/// \param size  New size of the memory block in bytes.
///
/// \return      Pointer to the reallocated and copied memory block.
///
///////////////////////////////////////////////////////////////////////////////
void *my_realloc(void *ptr, ulong size);

#endif /* !MEMORY_H_ */
