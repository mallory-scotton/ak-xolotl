/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/dependencies.h"
    #include "engine/types.h"

// Enumeration representing the screen state of the window
typedef enum {
    windowed,
    borderless,
    fullscreen
} window_screen_state_t;

    #define DEFAULT_WINDOW_WIDTH 1920
    #define DEFAULT_WINDOW_HEIGHT 1080
    #define DEFAULT_WINDOW_BIT 32
    #define DEFAULT_WINDOW_FPS 60
    #define DEFAULT_WINDOW_CAPED_FPS true
    #define DEFAULT_WINDOW_SCREEN fullscreen
    #define WINDOW_TITLE "ak-xolotl"
    #define WINDOW_STYLE (sfResize | sfClose)
    #define WINDOW_ICON "./ressources/icon.png"

// Structure representing the settings of the window
typedef struct window_setting_s {
    uint width;
    uint height;
    uint bits;
    uint maxfps;
    bool capedfps;
    window_screen_state_t screen;
} window_setting_t;

// Structure representing the window
typedef struct {
    sfRenderWindow *win;
    sfVideoMode mode;
    window_setting_t settings;
} window_t;

// External declaration of the global window instance
extern window_t Window;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the system window
///
/// \return Returns 'success' on successful window initialization, 'fail'
/// otherwise
///
///////////////////////////////////////////////////////////////////////////////
status system_window_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the system window
///
/// \return Returns 'success' after successfully destroying the window
///
///////////////////////////////////////////////////////////////////////////////
status system_window_destroy(void);

#endif /* !WINDOW_H_ */
