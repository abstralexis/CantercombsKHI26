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

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "raylib.h"

#include "cant_weapons.h"
#include "cant_dmg_box.h"

#define CANT_PLAYER_WIDTH  16
#define CANT_PLAYER_HEIGHT 32

typedef struct CantPlayer {
    // Coords
    Rectangle screen_rectangle;
    Rectangle level_rectangle;

    // Physics
    Vector2 acceleration;
    Vector2 velocity;
    bool is_grounded;

    // Weapons
    bool has_cane;
    bool has_skullcandle;
    bool has_oillamp;
    bool is_attacking;

    // Health
    size_t max_health;
    size_t current_health;

    // Player Effect Durations
    cant_wfx_t afflicted_with;
    uint64_t fx_duration;
    bool has_been_hit;
} cant_player_t;

/**
 *  Create the base player struct utility function.
 */
cant_player_t CreatePlayer(void);

/**
 *  This will recalculate the velocity to move the player in based on the acc.
 *  @param p_player pointer to the player to modify. 
 */
void RecalculateVelocity(cant_player_t* p_player);

/**
 *  Apply the physics parameters to the player, changing position and applying
 *  based on whether player is grounded etc.
 *  @param p_player The player pointer.
 */
void ApplyPlayerPhysics(cant_player_t* p_player);

/**
 *  Change the velocity to jump and set `is_grounded` to `false`.
 *  @param p_player Player pointer.
 */
void MakePlayerJump(cant_player_t* p_player);

/**
 *  Enacts damage from collisions to the player, given the hitboxes arr and the n hbs.
 *  Returns `true` if a collision has been detected.
 *
 *  If you do dumb shit with `n` then whatever happens with `hitboxes` is **your fault!**
 * 
 *  @param p_player the player pointer
 *  @param hitboxes the array of pointers to hitboxes.
 *  @param n the number of hitboxes for array access.
 */
bool PlayerDmgCollide(cant_player_t* p_player, cant_dmg_box_t** hitboxes, size_t n);

/**
 *  Enacts damage from collisions to the player, given the colbox arr and the n cbs.
 *  Returns `true` if a collision has been detected.
 *
 *  If you do dumb shit with `n` then whatever happens with `collision_boxes` is **your fault!**
 * 
 *  @param p_player the player pointer
 *  @param collision_boxes the array of pointers to the rectangles for platform collision etc.
 *  @param n the number of hitboxes for array access.
 */
bool PlayerFloorCollide(cant_player_t* p_player, Rectangle** collision_boxes, size_t n);
