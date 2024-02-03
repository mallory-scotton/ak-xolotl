/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** splashscreen
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

static void splashscreen_load()
{
    for (uint x = 0; x < 6; x++)
        for (uint i = 0; i < 2147483648; i++);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw an image on the splash screen
///
/// \param window    The SFML render window to draw on
/// \param filename  The path to the image file
/// \param position  The position at which to draw the image
///
///////////////////////////////////////////////////////////////////////////////
static void slpashscreen_draw(sfRenderWindow *window,
    cstring filename, vec2f position)
{
    sfTexture *text = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprt = sfSprite_create();

    sfSprite_setTexture(sprt, text, sfTrue);
    sfSprite_setPosition(sprt, position);
    sfRenderWindow_drawSprite(window, sprt, NULL);
    sfSprite_destroy(sprt);
    sfTexture_destroy(text);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Set the window icon using the specified image file
///
/// \param window  The SFML render window to set the icon for
///
///////////////////////////////////////////////////////////////////////////////
static void splashscreen_icon(sfRenderWindow *window)
{
    sfImage *icon;
    vec2u size;

    if (WINDOW_ICON == NULL)
        return;
    icon = sfImage_createFromFile(WINDOW_ICON);
    size = sfImage_getSize(icon);
    sfRenderWindow_setIcon(window, size.x, size.y, sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Display the splash screen
///
///////////////////////////////////////////////////////////////////////////////
void splashscreen(void)
{
    sfVideoMode screen = sfVideoMode_getDesktopMode();
    sfVideoMode splash = {screen.width / 2,
        (screen.width / 2 * 1080) / 1920, 32};
    sfRenderWindow *window = sfRenderWindow_create(
        (sfVideoMode){1920, 1080, 32}, WINDOW_TITLE, sfNone, NULL);

    splashscreen_icon(window);
    sfRenderWindow_setSize(window, (vec2u){splash.width, splash.height});
    sfRenderWindow_setPosition(window, (vec2i){
        (screen.width - splash.width) / 2, (screen.height - splash.height) / 2});
    slpashscreen_draw(window, "./ressources/cover.jpg", (vec2f){0, 0});
    slpashscreen_draw(window, "./ressources/logo.png", (vec2f){135, 117});
    sfRenderWindow_display(window);
    splashscreen_load();
    sfRenderWindow_destroy(window);
}
