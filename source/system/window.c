/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** window
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

window_t Window = {
    NULL,
    {DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, DEFAULT_WINDOW_BIT},
    {
        DEFAULT_WINDOW_WIDTH,
        DEFAULT_WINDOW_HEIGHT,
        DEFAULT_WINDOW_BIT,
        DEFAULT_WINDOW_FPS,
        DEFAULT_WINDOW_CAPED_FPS,
        DEFAULT_WINDOW_SCREEN
    }
};

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the system window
///
/// This function initializes the system window using the specified video mode,
/// window title, and window style. It also sets the window icon if provided,
/// loading it from the file specified by the WINDOW_ICON macro. The function
/// creates a window using sfRenderWindow_create and sets its icon using
/// sfRenderWindow_setIcon.
///
/// \return Returns 'success' on successful window initialization, 'fail'
/// otherwise
///
///////////////////////////////////////////////////////////////////////////////
status system_window_init(void)
{
    sfImage *icon;
    sfVector2u size;

    Window.win = sfRenderWindow_create(Window.mode, WINDOW_TITLE,
        WINDOW_STYLE, NULL);
    RETURN(Window.win == NULL, fail);
    if (WINDOW_ICON != NULL) {
        icon = sfImage_createFromFile(WINDOW_ICON);
        if (!icon) {
            sfRenderWindow_destroy(Window.win);
            return (fail);
        }
        size = sfImage_getSize(icon);
        sfRenderWindow_setIcon(Window.win, size.x, size.y,
            sfImage_getPixelsPtr(icon));
    }
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the system window
///
/// This function checks if the system window exists and, if so, destroys it
/// using sfRenderWindow_destroy. It is responsible for cleaning up the
/// allocated resources associated with the system window.
///
/// \return Returns 'success' after successfully destroying the window
///
///////////////////////////////////////////////////////////////////////////////
status system_window_destroy(void)
{
    if (Window.win)
        sfRenderWindow_destroy(Window.win);
    return (success);
}
