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

#include "cant_player.h"
#include "cant_dmg_box.h"
#include "raylib.h"
#include <string.h>
#include "raymath.h"

cant_player_t CreatePlayer(void) {
    return (cant_player_t) {
        (Rectangle){16.0f, 224.0f - CANT_PLAYER_HEIGHT, CANT_PLAYER_WIDTH, CANT_PLAYER_HEIGHT},
        (Rectangle){16.0f, 224.0f - CANT_PLAYER_HEIGHT, CANT_PLAYER_WIDTH, CANT_PLAYER_HEIGHT},
        (Vector2){0, 2},
        (Vector2){0, 0},
        true,
        true,
        false,
        false,
        false,
        48,
        48,
        CANT_WFX_NONE,
        0,
        false
    };
}

/**
 *  This will recalculate the velocity to move the player in based on the acc.
 *  @param p_player pointer to the player to modify. 
 */
void RecalculateVelocity(cant_player_t* p_player) {
    p_player->velocity = Vector2Add(p_player->acceleration, p_player->acceleration);
}

/**
 *  Apply the physics parameters to the player, changing position and applying
 *  based on whether player is grounded etc.
 *  @param p_player The player pointer.
 */
void ApplyPlayerPhysics(cant_player_t* p_player) {
    //if (!p_player->is_grounded) RecalculateVelocity(p_player);
    p_player->screen_rectangle.x += p_player->velocity.x;
    p_player->screen_rectangle.y += p_player->velocity.y;
}

/**
 *  Change the velocity to jump and set `is_grounded` to `false`.
 *  @param p_player Player pointer.
 */
void MakePlayerJump(cant_player_t* p_player) {
    if (!p_player->is_grounded) return;

    p_player->velocity = Vector2Add(p_player->velocity, (Vector2){0, 5});
    p_player->is_grounded = false;
}


bool PlayerDmgCollide(
    cant_player_t* p_player,
    cant_dmg_box_t** hitboxes,
    size_t n
) {
    size_t p = (size_t)hitboxes;
    Rectangle rect;
    bool collided = false;
    for (int i = 0; i < n; i++) {
        p = (size_t)hitboxes + (i * sizeof(cant_dmg_box_t*));
        rect = ((cant_dmg_box_t*)p)->hitbox;
        collided = collided | CheckCollisionRecs(p_player->level_rectangle, rect); 
    }
    return collided;
}

