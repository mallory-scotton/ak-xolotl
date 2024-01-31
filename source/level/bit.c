/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** bit
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Write bit inside the buffer
///
/// \param buffer   The string buffer to contain the bits
/// \param bpos     The current bit position
/// \param value    The value to write inside the buffer
/// \param bsize    The size of the value
///
///////////////////////////////////////////////////////////////////////////////
void bwrite(ustring buffer, pint bpos, uint value, uint bsize)
{
    int bit;

    for (uint i = bsize - 1; i >= 0; i--) {
        bit = (value >> i) & 1;
        buffer[*bpos / 8] |= (bit << (*bpos % 8));
        (*bpos)++;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Read a single bit from a buffer
///
/// \param buffer  The unsigned character array representing the bitstream
/// \param bpos    Pointer to the current bit position in the bitstream
///
/// \return        Returns the read bit (0 or 1)
///
///////////////////////////////////////////////////////////////////////////////
static int sbread(ustring buffer, pint bpos)
{
    int bit = (buffer[*bpos / 8] >> (*bpos % 8)) & 1;

    (*bpos)++;
    return (bit);
}

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
int bread(ustring buffer, pint bpos, uint bsize)
{
    int result = 0;

    for (uint i = 0; i < bsize; i++)
        result = (result << 1) | sbread(buffer, bpos);
    return (result);
}
