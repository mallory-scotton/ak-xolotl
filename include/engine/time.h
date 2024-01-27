/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** time
*/

#ifndef ENGINE_TIME_H_
    #define ENGINE_TIME_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include <SFML/System/Clock.h>
    #include <stdlib.h>
    #include "engine/types.h"

///////////////////////////////////////////////////////////////////////////////
// Macros
///////////////////////////////////////////////////////////////////////////////
    #define TIME_US sfTime_asMicroseconds
    #define TIME_MS sfTime_asMilliseconds
    #define TIME_SE sfTime_asSeconds

///////////////////////////////////////////////////////////////////////////////
/// \brief Constants structure that used for timing
///
/// \param deltaTime    DeltaTime between two frames in milliseconds
/// \param currentTime  Current time of the frame
/// \param clock        Global engine clock
///
///////////////////////////////////////////////////////////////////////////////
typedef struct system_time_s {
    double deltaTime;
    sfTime currentTime;
    sfClock *clock;
} system_time_t;

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
extern system_time_t *Time;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the global Time variable, and all the components linked
///
/// \return The status of the operation, if the operation fail, stop the game
/// engine.
///
///////////////////////////////////////////////////////////////////////////////
status system_init_time(void);

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
status system_update_time(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the variable and clean the used ressources
///
/// This function will free the memory and destroy the clock to clean
/// the used ressources.
///
/// \return This function could only return a success status.
///
///////////////////////////////////////////////////////////////////////////////
status system_destroy_time(void);

#endif /* !ENGINE_TIME_H_ */
