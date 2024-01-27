/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** zones
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse and handle zone definitions from a mapset file line
///
/// \param l  The input line from the mapset file defining a zone
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_zone(string l)
{
    string *wa = my_stowa(l);
    ulong len = wa ? my_walen(wa) : 0;

    RETURN(wa == NULL, (void)0);
    if (len == 1) {
        my_watroy(wa);
        return;
    }
    if (len == 2 && Assets.mapset->in_zone == true &&
        my_strcmp(wa[1], "END") == 0) {
        Assets.mapset->in_zone = false;
        if (Assets.mapset->zone_name != NULL)
            free(Assets.mapset->zone_name);
        Assets.mapset->zone_name = NULL;
    } else if (len == 3 && Assets.mapset->in_zone == false &&
        my_strcmp(wa[1], "START") == 0) {
        Assets.mapset->in_zone = true;
        Assets.mapset->zone_name = my_strdup(wa[2]);
    }
    my_watroy(wa);
}
