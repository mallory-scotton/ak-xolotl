/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** level
*/

#ifndef LEVEL_H_
    #define LEVEL_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/types.h"
    #include "engine/macros.h"
    #include "engine/dependencies.h"

///////////////////////////////////////////////////////////////////////////////
// Bit Size

    #define B_CHUNK 7
    #define B_ASSET 11
    #define B_POSITION 8
    #define B_ROTATION 9
    #define B_SCALE 4
    #define B_BACKGROUND 1
    #define BITTOBYTE(value) ((int)((value) / 8 + 1))

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \brief Read a specified number of bits from a buffer
///
/// \param buffer  The unsigned character array representing the bitstream
/// \param bpos    Pointer to the current bit position in the bitstream
/// \param bsize   The number of bits to read
///
/// \return        Returns the integer value represented by the read bits
///
///////////////////////////////////////////////////////////////////////////////
int bread(ustring buffer, pint bpos, uint bsize);

///////////////////////////////////////////////////////////////////////////////
/// \brief Write bit inside the buffer
///
/// \param buffer   The string buffer to contain the bits
/// \param bpos     The current bit position
/// \param value    The value to write inside the buffer
/// \param bsize    The size of the value
///
///////////////////////////////////////////////////////////////////////////////
void bwrite(ustring buffer, pint bpos, uint value, uint bsize);

#endif /* !LEVEL_H_ */
