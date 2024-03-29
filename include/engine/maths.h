/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** maths
*/

#ifndef MATHS_H_
    #define MATHS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/types.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Linear interpolation between two value
///
/// \param a    The starting value
/// \param b    The ending value
/// \param t    Interpolation value [0, 1] for calculating the value
///
/// \return The linear interpolation based on t for the a and b value.
///
///////////////////////////////////////////////////////////////////////////////
    #define LERP(a, b, t) ((a) * (1 - t) + (b) * (t))


///////////////////////////////////////////////////////////////////////////////
/// \brief Clamp a value to the range [0, 1].
///
/// \param x    The value to be clamped.
///
/// \return The clamped value. If x is less than 0, it returns 0. If x is
///         greater than 1, it returns 1. Otherwise, it returns x.
///
///////////////////////////////////////////////////////////////////////////////
    #define CLAMP01(x) (((x) < 0) ? 0 : (((x) > 1) ? 1 : (x)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Returns the minimum of two values.
///
/// \param a    The first value.
/// \param b    The second value.
///
/// \return The minimum of a and b.
///
///////////////////////////////////////////////////////////////////////////////
    #define MIN(a, b) ((a) < (b) ? (a) : (b))

///////////////////////////////////////////////////////////////////////////////
/// \brief Returns the maximum of two values.
///
/// \param a    The first value.
/// \param b    The second value.
///
/// \return The maximum of a and b.
///
///////////////////////////////////////////////////////////////////////////////
    #define MAX(a, b) ((a) > (b) ? (a) : (b))

///////////////////////////////////////////////////////////////////////////////
/// \brief Returns the absolute value of a number.
///
/// \param x    The input value.
///
/// \return The absolute value of x.
///
///////////////////////////////////////////////////////////////////////////////
    #define ABS(x) ((x) < 0 ? -(x) : (x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Clamps a value to a specified range.
///
/// \param x        The value to be clamped.
/// \param mi       The minimum value in the range.
/// \param ma       The maximum value in the range.
///
/// \return The clamped value. If x is less than minVal, it returns minVal.
///         If x is greater than maxVal, it returns maxVal. Otherwise, it
///         returns x.
///
///////////////////////////////////////////////////////////////////////////////
    #define CLAMP(x, mi, ma) ((x) < (mi) ? (mi) : ((x) > (ma) ? (ma) : (x)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the cube of a number.
///
/// \param x    The input value.
///
/// \return The cube of x.
///
///////////////////////////////////////////////////////////////////////////////
    #define CUBE(x) ((x) * (x) * (x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the square of a number.
///
/// \param x    The input value.
///
/// \return The square of x.
///
///////////////////////////////////////////////////////////////////////////////
    #define SQUARE(x) ((x) * (x))

#endif /* !MATHS_H_ */
