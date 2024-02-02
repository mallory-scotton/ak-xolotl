/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** mapset
*/

#ifndef MAPSET_H_
    #define MAPSET_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/dependencies.h"
    #include "engine/types.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure for containing the tiles used in the assets
///
/// \param index            The index of the sprite, for level
/// \param zone_name        The zone name, to load the assets or not
/// \param file_path        The local/absolute assets path
/// \param browser_path     Used for the level editor
/// \param animated         Boolean, is the tiles animated or a tilemap
/// \param preview          Did the animation will play in the editor
/// \param texture          The texture object, when the file is loaded
/// \param mask             The mask used for the animation
/// \param size             The complete size of the image
/// \param grid             The animation grid size, without animation (1,1)
/// \param frame            The size of one frame of the grid
/// \param endframe         The index of the last frame of the animation
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    ulong index;
    string zone_name;
    string file_path;
    string browser_path;
    string class_name;
    bool animated;
    bool preview;
    sfTexture *texture;
    sfIntRect *mask;
    vec2u size;
    vec2u grid;
    vec2u frame;
    uint endframe;
} tile_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to hold the audio used in the game
///
/// \param file_path        The local/absolute path of the audio file
/// \param browser_path     If NULL, we won't show the audio in the editor
/// \param looped           Boolean, set to repeat or not the sound
/// \param canal            Canal id to output the audio
/// \param volume           Relative volume of the sound [0-100]
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    string file_path;
    string browser_path;
    bool looped;
    uint canal;
    uint volume;
} audio_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to hold the animation of a sprite
///
/// \param name             The animation name, used to play the anim
/// \param start            The index of the first frame of the animation
/// \param end              The index of the last frame of the animation
/// \param looped           Boolean to set the animation repeatly
/// \param framerate        If set to DEFAULT, or can be custom, represent
///                         the animation framerate
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    string name;
    uint start;
    uint end;
    bool looped;
    uint framerate;
} animation_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to hold repeated animation
///
/// \param name         The name of the animation sheet
/// \param animations   The animations array
/// \param anim_count   The number of animation in the sheet
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    string name;
    animation_t *animations;
    uint anim_count;
} animation_sheet_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to hold a sprite object
///
/// \param file_path        The local/absolute path of the image
/// \param animated         Boolean if the sprite is using animations
/// \param texture          The texture object to avoid loading the assets
///                         in runtime
/// \param mask             The texture mask for animation
/// \param size             The complete size of the image
/// \param grid             The grid size, represent the number of frame in the
///                         x and y axis
/// \param frame            The frame size, all frame should have the same
///                         size
/// \param animations       Array of animations, use to switch between the
///                         animations.
/// \param animation_count  Keep an eye on the number of animation
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    string file_path;
    bool animated;
    sfTexture *texture;
    sfIntRect *mask;
    vec2u size;
    vec2u grid;
    vec2u frame;
    animation_t *animations;
    ulong animation_count;
} sprite_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Mapset structure to hold every loaded/referenced assets
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    tile_t **tiles;
    ulong tile_count;
    audio_t **audios;
    ulong audio_count;
    sprite_t **sprites;
    ulong sprite_count;
    animation_sheet_t **animations;
    uint animation_count;
    float version;
    uint default_framerate;
    bool use_browser;
    bool in_zone;
    string zone_name;
} mapset_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Assets action to hold the mapset and every possible action
/// on the mapset
///
/// \param mapset       The global mapset to load/unload assets
/// \param init         Init the unzoned assets and allocate the memory
/// \param load         Load a specific zone of assets
/// \param unload       Unload a specific zone of the assets
/// \param destroy      Unload every assets and clear the mapset
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    mapset_t *mapset;
    bool (*init)(void);
    bool (*load)(cstring zone);
    bool (*unload)(cstring zone);
    bool (*destroy)(void);
} assets_action_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
extern assets_action_t Assets;

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
bool mapset_load(string source);

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the assets structures
///
///////////////////////////////////////////////////////////////////////////////
bool init_assets(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse and apply configuration settings from a mapset file line
///
/// \param l  The input line from the mapset configuration file
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_config(string l);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse and handle zone definitions from a mapset file line
///
/// \param l  The input line from the mapset file defining a zone
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_zone(string l);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse and handle mapset tile definitions from a line
///
/// \param l  The input line from the mapset file defining a tile
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_tile(string l);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse an animation line of the mapset
///
/// \param l  The input line from the mapset file defining an animation
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_animation(string l);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse an audio line of the mapset
///
/// \param l  The input line from the mapset file defining an audio
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_audio(string l);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse a sprite of the mapset
///
/// \param l  The input line from the mapset file defining a sprite
///
///////////////////////////////////////////////////////////////////////////////
void mapset_parse_sprite(string l);

#endif /* !MAPSET_H_ */
