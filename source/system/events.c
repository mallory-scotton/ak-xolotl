/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** events
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Analyze system events
///
/// \note This function should be called within the main loop to handle events.
///
///////////////////////////////////////////////////////////////////////////////
void system_analyse_event(void)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(Window.win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(Window.win);
    }
}
