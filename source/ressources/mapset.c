/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** mapset
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "engine.h"

assets_action_t Assets = {NULL, NULL, NULL, NULL, NULL};

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse a line from the mapset file
///
/// \param line  The line to be parsed from the mapset file
///
///////////////////////////////////////////////////////////////////////////////
static void mapset_parse_line(string line)
{
    if (line[0] == '#')
        return;
    if (line[0] == 'C')
        mapset_parse_config(line);
    if (line[0] == 'T')
        mapset_parse_tile(line);
    if (line[0] == 'A')
        mapset_parse_audio(line);
    if (line[0] == 'S')
        mapset_parse_sprite(line);
    if (line[0] == 'Z')
        mapset_parse_zone(line);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Load a mapset from a file
///
/// \param source  The path to the mapset file
///
/// \return Returns 'true' on successful mapset loading, 'false' otherwise
///
///////////////////////////////////////////////////////////////////////////////
bool mapset_load(string source)
{
    FILE *f = fopen(source, "r");
    char *l = NULL;
    ulong len = 0;
    long read;

    if (f == NULL || init_assets() == false)
        return (false);
    read = getline(&l, &len, f);
    while (read != -1) {
        if (read > 0 && l[read - 1] == '\n')
            l[read - 1] = '\0';
        mapset_parse_line(l);
        read = getline(&l, &len, f);
    }
    free(l);
    fclose(f);
    return (true);
}
