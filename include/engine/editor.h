/*
** EPITECH PROJECT, 2024
** ak-xolotl
** File description:
** editor
*/

#ifndef EDITOR_H_
    #define EDITOR_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "engine/dependencies.h"
    #include "engine/macros.h"
    #include "engine/types.h"
    #include "engine/maths.h"
    #include "engine/mapset.h"
    #include "engine/time.h"

///////////////////////////////////////////////////////////////////////////////
// COLORS

    #define CLR_BLACK sfColor_fromRGB(0, 0, 0)
    #define CLR_BACKGROUND sfColor_fromRGB(21, 21, 21)
    #define CLR_TITLE sfColor_fromRGB(21, 21, 21)
    #define CLR_BORDER sfColor_fromRGB(15, 15, 15)
    #define CLR_FOLDOUT sfColor_fromRGB(15, 15, 15)
    #define CLR_INPUT sfColor_fromRGB(15, 15, 15)
    #define CLR_INPUT_OUTLINE sfColor_fromRGB(56, 56, 56)
    #define CLR_RECESSED sfColor_fromRGB(26, 26, 26)
    #define CLR_PANEL sfColor_fromRGB(36, 36, 36)
    #define CLR_HEADER sfColor_fromRGB(47, 47, 47)
    #define CLR_DROPDOWN sfColor_fromRGB(56, 56, 56)
    #define CLR_DROPDOWN_OUTLINE sfColor_fromRGB(76, 76, 76)
    #define CLR_HOVER sfColor_fromRGB(87, 87, 87)
    #define CLR_HOVER2 sfColor_fromRGB(128, 128, 128)
    #define CLR_WHITE sfColor_fromRGB(255, 255, 255)
    #define CLR_WHITE25 sfColor_fromRGBA(255, 255, 255, 64)
    #define CLR_PRIMARY sfColor_fromRGB(0, 112, 224)

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// SIZE

    #define TOOLBAR_H 70
    #define SIDE_W 390
    #define BROWSER_H 380w

///////////////////////////////////////////////////////////////////////////////

#endif /* !EDITOR_H_ */
