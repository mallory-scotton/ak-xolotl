/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** loop
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Run the system game loop
///
/// \note This function serves as the core loop for the game and should be
/// called after initializing the system window.
///
///////////////////////////////////////////////////////////////////////////////
void system_game_loop(void)
{
    while (sfRenderWindow_isOpen(Window.win)) {
        system_update_time();
        system_analyse_event();
        sfRenderWindow_clear(Window.win, sfBlack);
        sfRenderWindow_display(Window.win);
    }
}
