/*
    Cantercombs is an NES style Castlevania-inspired game made with raylib and C
    for the KentHackIt 2026 Hackathon!
    
    Code Copyright (C) 2026 Alexis Williams <contact at abstralexis dot dev>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/



#include <stdint.h>

#include "raylib.h"
#include "zpl.h"



/**
 *  Weapon Effect for what happens to enemies with the weapon.
 *  This enum contains nothing but the effect internal names, so
 *  most of the implementation is in a different file to this.
 */
typedef enum CantWeaponEffect {
    CANT_WFX_NONE,
    CANT_WFX_SMITE, // CANE
    CANT_WFX_FIRE,  // SKULLCANDLE
    CANT_WFX_OILY,  // OILLAMP
} cant_wfx_t;

/**
 *  The weapon struct. Very generic, a lot of the implementation detail
 *  will be functions that do the actions based on the `cant_wfx_t`.
 */
typedef struct CantWeapon {
    zpl_string name;
    uint64_t damage;

    Image sprite_sheet;
    size_t n_frames;

    Rectangle hitbox;
    Vector2 hitbox_offset_from_char;
    
    cant_wfx_t wfx;
} cant_weapon_t;

cant_weapon_t CantMakeCane(void);
cant_weapon_t CantMakeSkullCandle(void);
cant_weapon_t CantMakeOilLamp(void);
