/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** time
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine/time.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Global Time variables
///
/// This variable contain the global engine clock, the delta time calculated
/// between each frames, and the current time of the engine. The delta time
/// is in milliseconds and the current time is a sfTime struct and can be
/// tansformed using TIME_US (microsecond), TIME_MS (millisecond) and
/// TIME_SE (second).
///
///////////////////////////////////////////////////////////////////////////////
system_time_t *Time;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the global Time variable, and all the components linked
///
/// \return The status of the operation, if the operation fail, stop the game
/// engine.
///
///////////////////////////////////////////////////////////////////////////////
status system_init_time(void)
{
    Time = malloc(sizeof(system_time_t));
    if (!Time)
        return (fail);
    Time->clock = sfClock_create();
    if (!Time->clock) {
        free(Time);
        return (fail);
    }
    Time->currentTime = sfClock_getElapsedTime(Time->clock);
    Time->deltaTime = 0.0f;
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Update the Time variable
///
/// This function need to be executed at the start of each frame for the
/// calculation of the deltaTime.
///
/// \return The status of the operation, if the operation fail, it means that
/// the initialization failed, and need to leave the engine.
///
///////////////////////////////////////////////////////////////////////////////
status system_update_time(void)
{
    sfTime current;

    if (!Time)
        return (system_init_time());
    current = sfClock_getElapsedTime(Time->clock);
    Time->deltaTime = TIME_MS(current) - TIME_MS(Time->currentTime);
    Time->currentTime = current;
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the variable and clean the used ressources
///
/// This function will free the memory and destroy the clock to clean
/// the used ressources.
///
/// \return This function could only return a success status.
///
///////////////////////////////////////////////////////////////////////////////
status system_destroy_time(void)
{
    if (!Time)
        return (success);
    if (Time->clock)
        sfClock_destroy(Time->clock);
    free(Time);
    return (success);
}
