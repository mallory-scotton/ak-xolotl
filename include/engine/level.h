/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** level
*/

#ifndef LEVEL_H_
    #define LEVEL_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/types.h"
    #include "engine/macros.h"
    #include "engine/dependencies.h"

///////////////////////////////////////////////////////////////////////////////
// Bit Size

    #define B_CHUNK 7
    #define B_ASSET 11
    #define B_POSITION 8
    #define B_ROTATION 9
    #define B_BACKGROUND 1
    #define BITTOBYTE(value) ((int)((value) / 8 + 1))

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Level Config

    #define CHUNK_GRID_X 8
    #define CHUNK_GRID_Y 8
    #define CHUNK_MAX (CHUNK_GRID_X * CHUNK_GRID_Y)
    #define MAX_TILE_IN_CHUNK 2048

///////////////////////////////////////////////////////////////////////////////

// Structure representing a tile in a level
typedef struct {
    uint tileId;
    vec2u position;
    uint rotation;
} level_tile_t;

// Enumeration representing the type of objects in the level
typedef enum {
    object_spawner,
    object_spawnpoint,
    object_trap,
    object_door,
    object_secret
} object_type_e;

// Structure representing an object in the level
typedef struct {
    object_type_e type;
    vec2u position;
} level_object_t;

// Structure representing a chunk of tiles and objects in the level
typedef struct {
    bool visible;
    level_tile_t *tiles[MAX_TILE_IN_CHUNK];
    uint tile_count;
    level_object_t **objects;
    uint object_count;
} level_chunk_t;

// Enumeration representing the type of areas in the level
typedef enum {
    area_hitbox,
    area_viewbox
} area_type_e;

// Structure representing an area in the level
typedef struct {
    area_type_e area_type;
    vec2u size;
    vec2u position;
} level_area_t;

// Enumeration representing different biomes in the level
typedef enum {
    biome_plain,
    biome_junkyard,
    biome_asian,
    biome_aquatic,
    biome_octopus
} level_biome_e;

// Structure representing the overall level
typedef struct {
    level_biome_e biome;
    level_chunk_t *chunks[CHUNK_MAX];
    level_area_t **areas;
} level_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Read a specified number of bits from a buffer
///
/// \param buffer  The unsigned character array representing the bitstream
/// \param bpos    Pointer to the current bit position in the bitstream
/// \param bsize   The number of bits to read
///
/// \return        Returns the integer value represented by the read bits
///
///////////////////////////////////////////////////////////////////////////////
int bread(ustring buffer, pint bpos, uint bsize);

///////////////////////////////////////////////////////////////////////////////
/// \brief Write bit inside the buffer
///
/// \param buffer   The string buffer to contain the bits
/// \param bpos     The current bit position
/// \param value    The value to write inside the buffer
/// \param bsize    The size of the value
///
///////////////////////////////////////////////////////////////////////////////
void bwrite(ustring buffer, pint bpos, uint value, uint bsize);

#endif /* !LEVEL_H_ */
