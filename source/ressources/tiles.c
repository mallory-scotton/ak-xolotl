/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** tiles
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Validate a mapset tile definition
///
///
/// \param wa  The string array representing a mapset tile definition
/// \param wl  The length of the string array 'wa'
///
/// \return    Returns true if the mapset tile definition is valid, otherwise
///            false
///
///////////////////////////////////////////////////////////////////////////////
static bool is_mapset_tile_valid(string *wa, ulong wl)
{
    RETURN(wl != 4 && wl != 8 && wl != 9 && wl != 5, false);
    RETURN(!my_isbool(wa[3]), false);
    if (wl == 8 || wl == 9) {
        RETURN(my_atob(wa[3]) == false, false);
        RETURN(!my_isint(wa[4]) || !my_isint(wa[5]), false);
        RETURN(!my_isint(wa[6]) || !my_isbool(wa[7]), false);
    }
    if (wl == 4 || wl == 5)
        RETURN(my_atob(wa[3]) == true, false);
    return (true);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse animation details for a mapset tile
///
/// \param wa  The string array representing a mapset tile definition
/// \param wl  The length of the string array 'wa'
/// \param t   Pointer to the tile structure to be updated
///
///////////////////////////////////////////////////////////////////////////////
static void mapset_tile_parse_animation(string *wa, ulong wl, tile_t *t)
{
    t->grid.x = (uint)my_atoi(wa[4]);
    t->grid.y = (uint)my_atoi(wa[5]);
    t->endframe = (uint)my_atoi(wa[6]);
    t->preview = my_atob(wa[7]);
    if (wl == 9)
        t->class_name = my_strdup(wa[8]);
    if (Assets.mapset->in_zone == false) {
        t->frame.x = t->size.x / t->grid.x;
        t->frame.y = t->size.y / t->grid.y;
        t->mask->height = t->frame.y;
        t->mask->width = t->frame.x;
        t->mask->left = 0;
        t->mask->top = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a mapset tile from a string array
///
/// \param wa  The string array representing a mapset tile definition
/// \param wl  The length of the string array 'wa'
///
/// \return    Returns a pointer to the created tile, or NULL on allocation
///            failure
///
///////////////////////////////////////////////////////////////////////////////
static tile_t *mapset_tile_create(string *wa, ulong wl)
{
    tile_t *t = malloc(sizeof(tile_t));

    RETURN(t == NULL, NULL);
    t->index = Assets.mapset->tile_count;
    t->file_path = my_strdup(wa[1]);
    t->browser_path = my_strdup(wa[2]);
    t->animated = my_atob(wa[3]);
    t->zone_name = NULL;
    if (Assets.mapset->in_zone == true) {
        t->zone_name = my_strdup(Assets.mapset->zone_name);
    } else {
        t->texture = sfTexture_createFromFile(t->file_path, NULL);
        t->size = sfTexture_getSize(t->texture);
    }
    if (t->animated == true)
        mapset_tile_parse_animation(wa, wl, t);
    else if (wl == 5)
        t->class_name = my_strdup(wa[4]);
    return (t);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse and handle mapset tile definitions from a line
///
/// \param l  The input line from the mapset file defining a tile
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_tile(string l)
{
    string *wa = my_stowa(l);
    ulong wl = wa ? my_walen(wa) : 0;

    RETURN(wa == NULL, (void)0);
    RETURN(!is_mapset_tile_valid(wa, wl), my_watroy(wa));
    my_realloc(Assets.mapset->tiles, sizeof(tile_t) *
        (Assets.mapset->tile_count + 2));
    Assets.mapset->tiles[Assets.mapset->tile_count] =
        mapset_tile_create(wa, wl);
    Assets.mapset->tile_count++;
    my_watroy(wa);
}
