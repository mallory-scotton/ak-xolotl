/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** animations
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Check the validity of a mapset animation
///
/// \param wl  The length of the input string array
/// \param wa  The input string array containing animation information
///
/// \return Returns 'true' if the animation is valid, 'false' otherwise
///
///////////////////////////////////////////////////////////////////////////////
static bool is_mapset_animation_valid(ulong wl, string *wa)
{
    bool result = true;
    uint offset = 0;

    if (wl < 9 || (wl - 4) % 5 != 0 || !my_isint(wa[2]) || !my_isint(wa[3]))
        return (false);
    for (uint i = 0; i < (wl - 4) / 5; i++) {
        offset = 4 + i * 5;
        if (my_strlen(wa[offset]) == 1 || wa[offset][0] != '(' ||
            wa[offset + 4][my_strlen(wa[offset + 4]) - 1] != ')')
            result = false;
        if (!my_isint(wa[offset + 1]) || !my_isint(wa[offset + 2]))
            result = false;
        if (!my_isint(wa[offset + 3]) && my_strcmp(wa[offset + 3], "DEFAULT"))
            result = false;
        if (!my_isbool(wa[offset + 4]))
            result = false;
    }
    return (result);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Reallocate memory for mapset animations
///
/// \return Returns 'success' on successful memory reallocation, 'fail'
/// otherwise
///
///////////////////////////////////////////////////////////////////////////////
static status mapset_animation_realloc(void)
{
    int newSize = sizeof(animation_sheet_t *) *
        (Assets.mapset->animation_count + 1);

    if (Assets.mapset->animation_count == 0)
        Assets.mapset->animations = malloc(sizeof(animation_sheet_t *));
    else
        Assets.mapset->animations = my_realloc(Assets.mapset->animations,
            newSize);
    RETURN(Assets.mapset->animations == NULL, fail);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a new animation sheet
///
/// \param wl  The length of the input string array
/// \param wa  The input string array containing animation information
///
/// \note This function is used internally during mapset parsing
///
/// \return Returns a pointer to the newly created animation sheet
///
///////////////////////////////////////////////////////////////////////////////
static animation_sheet_t *create_new_animation(ulong wl, string *wa)
{
    uint animCount = (wl - 4) / 5;
    uint offset = 0;
    animation_sheet_t *animSheet = malloc(sizeof(animation_sheet_t));

    animSheet->animations = malloc(sizeof(animation_t) * (animCount + 1));
    animSheet->name = my_strdup(wa[1]);
    for (uint i = 0; i < animCount; i++) {
        offset = 4 + i * 5;
        (wa[offset])++;
        animSheet->animations[i].name = my_strdup(wa[offset]);
        animSheet->animations[i].start = my_atoi(wa[offset + 1]);
        animSheet->animations[i].end = my_atoi(wa[offset + 2]);
        animSheet->animations[i].framerate = my_isint(wa[offset + 3]) ?
            (uint)my_atoi(wa[offset + 3]) : Assets.mapset->default_framerate;
        animSheet->animations[i].looped = my_atob(wa[offset + 4]);
    }
    return (animSheet);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse an animation line of the mapset
///
/// \param l  The input line from the mapset file defining an animation
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_animation(string l)
{
    string *wa = my_stowa(l);
    ulong wl = wa ? my_walen(wa) : 0;

    RETURN(wa == NULL, (void)0);
    if (!mapset_animation_realloc() || !is_mapset_animation_valid(wl, wa)) {
        my_watroy(wa);
        return;
    }
    Assets.mapset->animations[Assets.mapset->animation_count] =
        create_new_animation(wl, wa);
    Assets.mapset->animation_count++;
    my_watroy(wa);
}
