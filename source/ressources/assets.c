/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** assets
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the assets counter to 0
///
///////////////////////////////////////////////////////////////////////////////
static void assets_init_counter(void)
{
    Assets.mapset->animation_count = 0;
    Assets.mapset->audio_count = 0;
    Assets.mapset->sprite_count = 0;
    Assets.mapset->tile_count = 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the assets structures
///
///////////////////////////////////////////////////////////////////////////////
bool init_assets(void)
{
    Assets.mapset = malloc(sizeof(mapset_t));
    if (Assets.mapset == NULL)
        return (false);
    assets_init_counter();
    Assets.mapset->in_zone = false;
    Assets.mapset->version = 1.0f;
    Assets.mapset->zone_name = NULL;
    Assets.mapset->default_framerate = 10;
    Assets.mapset->use_browser = true;
    return (true);
}
