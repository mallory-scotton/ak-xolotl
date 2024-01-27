# 🗂️ MAPSET

## What is a `.mapset` ?

`.mapset` is a file format system to handle a large amount of assets for a game engine. Instead of ___baking___ the assets inside a big .assets file, all the ressources are raw but referenced inside the mapset.

## Why using a mapset ?

### 💾 Levels

All the levels are built using a level editor using a mapset. Then the level is compiled into information and can be opened using the mapset.

Each assets is ___indexed___ inside the mapset so the level only need to reference the index of the used assets.

Then, if the level is too big, it parsed into ___chuncks___ and each assets are splitted into the chuncks. Then we only need to render the visible chunk to save rendering time.

### 🛡️ Is it crash free ?

All the assets still visible, and the `mapset` format is not unreadable and you can modify as wanted the mapset.

But, the mapset contain information about the current mapset version, and the level too.
If the version of the mapset and the level are not the same, the level wont load.

## How to use a mapset ?

### 📋 Comments

To add comments to your mapset you can use:

```ini
# your beautiful comment
```

## 🧭 Zones

Zones are used to defined a specific area of assets that doesn't need to be load automatically. It is used to optimize the memory used by the game.

Using zone doesn't load unused assets but you can load it later using `Assets.load("my_zone_name");` functions.

To create a zone:

```ini
Z START <ZONE_NAME>
# YOUR CONTENT
Z END
```

The zone need a start and an end and everything between the two balise will not be load at the initialization of the mapset.

You can't create children zone.

Exemple:

```ini
# Creating the zone for the second level of my game
Z START LEVEL_2
# If the zone is loaded, it will load my assets
T ./ressources/preview/level2.png preview/level2 FALSE
# Closing my zone
Z END
# But this asset will load anyway
T ./ressources/shared/ui.png shared/ui FALSE
```

Now when my game need to use the assets used in `LEVEL_2` i can use:

```c
// Dummy function to load the second level
int load_level_2(void)
{
  // Loading the assets
  Assets.load("LEVEL_2");
  // Doing something for the level
}
```

### ⛩️ Tiles

Tiles are visible inside the level editor, they don't have all the possibilites of a sprite.

To create a tiles you can use:

```ini
T <FILE_PATH> <BROWSER_PATH> <IS_ANIMATED>
                                 TRUE       [GRID_X] [GRID_Y] [END] [PREVIEW] [CLASS_NAME]
                                 FALSE      [CLASS_NAME]
```

- `FILE_PATH`: the local/absolute filepath (local is safer)
  - _e.g: "./ressources/environment/background.png"_
- `BROWSER_PATH`: the level editor assets browser path and name
  - _e.g: "environment/background"_
- `IS_ANIMATED`: boolean [TRUE/FALSE] to precise if a tile is animated or a tilemap
  - _e.g: "TRUE" or "FALSE"_

If the tile is animated:

- `GRID_X` and `GRID_Y`: The limit of the animation / tilemap, it represents the number of frames in the X and Y axis. The size of each frame is calculate using those value.
- `END`: The animation end index, sometimes, the sprite sheet is not full, we need to cut the animation before reaching the end.
- `PREVIEW`: boolean [TRUE/FALSE] to play the animation inside the level editor, if false, it mean that the tiles is a tilemap and you can access each part of the tile individually. Otherwise, the animation will play at a constant framerate.

Optional:

- `CLASS_NAME`: Class is used to add specific event to assets, for exemple an lever can have the class INTERACTABLE.

Exemple:

```ini
# This line will create a new instance into the mapset of a tile.
# The tile will be located in the assets browser at /environment/.
# And the tile is not animated, it could be a tree
T ./ressources/environment/background.png environment/background FALSE
# Otherwise this line will create an animated tile,
# in this exemple the tile is a fire so we need to preview the
# animation.
# The created animation is based on frames [0 to 9](10) and
# the animation is played.
T ./ressources/environment/background.png environment/background TRUE 10 1 10 TRUE
```

## 🎧 Audios

Audio could be sound effect, music, dialogue or any `.ogg` you could have.

To create a new audio references, simply use:

```ini
A <FILE_PATH> <OUTPUT> <VOLUME> <LOOPED> [BROWSER_PATH]
```

- `FILE_PATH`: The local/absolute path of the `.ogg` audio file (local is safer).
  - _e.g: "./ressources/audio/ping.ogg"_
- `OUTPUT`: Represents the ouput canal used for this audio.
  - The output could be: `SFX`, `DIALOGUE`, `MUSIC`
- `VOLUME`: The relative volume of the audio, it will then be multiplied by the output canal volume.
- `LOOPED`: boolean [TRUE/FALSE], if true the music will only end if an  event precise it, otherwise, once completed, the sound will be removed from the buffer.
- `BROWSER_PATH` (optional): if set, the sound will appear in the editor assets browser, could be used to set ambiant music/sound. You can also just preview the sound inside the level editor.

Exemple:

```ini
# A new audio assets will be created,
# when used, it will be sent to the SFX canal buffer, without
# looping and will be visible in the assets browser of the editor.
A ./ressources/audio/ping.ogg SFX FALSE audio/ping
```

## 🎬 Animation Sheet

Animation sheet is used when multiple sprite are sharing the same animation.
This can be used when a character has multiple variant of his skin.

To create a new animation sheet,

```ini
F <NAME> <GRID_X> <GRID_Y> ([ANIMATION_NAME] [ANIMATION_START] [ANIMATION_END] [FRAMERATE] [LOOP]) (...)
```

- `NAME`: The name of the animation sheet, it will be used later to find the sheet.
- `GRID_X` and `GRID_Y`: The limit of the animation, it represents the number of frames in the X and Y axis. The size of each frame is calculate using those value.

For each animations (all between parenthesis):

- `ANIMATION_NAME`: The name of the animation
- `ANIMATION_START`: The index of the start for the animation
- `ANIMATION_END`: The index of the end for the animation
- `FRAMERATE`: The number of frame each seconds
- `LOOP`: boolean [TRUE/FALSE], if the animation is looped, if not, the animation will stop and reset once completed.

You can repeat the animation between parenthesis for as many animation you have

Exemple:

```ini
# Creating the animation sheet
# Here we are creating 3 animations: idle, walk, jump
F MOVEMENT 10 3 (IDLE 0 9 10 TRUE) (WALK 10 18 10 TRUE) (JUMP 19 27 10 FALSE)
# After creating the animation, we now can use it inside a sprite
# Here we are using the same animation for multiple variant of the sprite
S ./ressources/player/player_red.png TRUE MOVEMENT
S ./ressources/player/player_blue.png TRUE MOVEMENT
S ./ressources/player/player_yellow.png TRUE MOVEMENT
S ./ressources/player/player_green.png TRUE MOVEMENT
```

## 🎬 Sprites

Sprite is the most important assets to be load, it reach: every entity of the game and can handle a complex animation system.

To create a sprite, use this line:

```ini
S <FILE_PATH> <IS_ANIMATED>
                  TRUE      [GRID_X] [GRID_Y] ([ANIMATION_NAME] [ANIMATION_START] [ANIMATION_END] [FRAMERATE] [LOOP]) (...) (...)
                  TRUE      [ANIMATION_SHEET]
                  FALSE
```

- `FILE_PATH`: the local/absolute filepath (local is safer)
  - _e.g: "./ressources/player/deplacement.png"_
- `IS_ANIMATED`: boolean [TRUE/FALSE] to precise if a tile is animated or a tilemap
  - _e.g: "TRUE" or "FALSE"_

If the sprite is animated:

- `GRID_X` and `GRID_Y`: The limit of the animation, it represents the number of frames in the X and Y axis. The size of each frame is calculate using those value.

For each animations (all between parenthesis):

- `ANIMATION_NAME`: The name of the animation
- `ANIMATION_START`: The index of the start for the animation
- `ANIMATION_END`: The index of the end for the animation
- `FRAMERATE`: The number of frame each seconds
- `LOOP`: boolean [TRUE/FALSE], if the animation is looped, if not, the animation will stop and reset once completed.

You can repeat the animation between parenthesis for as many animation you have

Exemple:

```ini
# Create a sprite with 3 different animation
# The sprite will not be displayed on the assets browser for the level editor
S ./ressources/player/deplacement.png TRUE 10 3 (IDLE 0 9 10 TRUE) (WALK 10 18 10 TRUE) (JUMP 19 27 10 FALSE)
# Here there's 3 animations:
# Idle: from [0 - 9] at 10 frames per seconds and looped
# Walk: from [10 - 18] at 10 frames per seconds and looped
# Jump: from [19 - 27] at 10 frames per seconds and not looped
```

```ini
# Create a sprite using an animation sheet
S ./ressources/player/deplacement.png TRUE DEPLACEMENT
# "DEPLACEMENT" represents the name of the animation sheet and need to
# be defined before using it. 
```

# 🍿 Credits

The `.mapset` format and functions has been imagined and created by [Mallow](https://github.com/mallory-scotton).

Feel free to use this system, but beware if you are an EPITECH students, you are not allowed to use this system, and will be considered like cheating.
