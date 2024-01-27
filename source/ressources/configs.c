/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** configs
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Verify if the configuration is valid or not
///
/// If the configruation is not valid, we free the memory of the arguments
/// if there's one
///
/// \param wa       The list of arguments
/// \param len      The number of arguments
///
/// \return Boolean, true if the arguments is valid, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
static bool is_mapset_config_valid(string *wa, ulong len)
{
    RETURN(len == 3, true);
    RETURN(wa == NULL, false);
    my_watroy(wa);
    return (false);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse and apply configuration settings from a mapset file line
///
/// \param l  The input line from the mapset configuration file
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_config(string l)
{
    string *wa = my_stowa(l);
    ulong len = wa ? my_walen(wa) : 0;

    RETURN(!is_mapset_config_valid(wa, len), (void)0);
    if (my_strcmp(wa[1], "VERSION") == 0 && my_isfloat(wa[2]))
        Assets.mapset->version = my_atof(wa[2]);
    if (my_strcmp(wa[1], "USE_ASSETS_BROWSER") == 0 && my_isbool(wa[2]))
        Assets.mapset->use_browser = my_atob(wa[2]);
    if (my_strcmp(wa[1], "DEFAULT_FRAMERATE") == 0 && my_isint(wa[2]))
        Assets.mapset->default_framerate = my_atoi(wa[2]);
    my_watroy(wa);
}
