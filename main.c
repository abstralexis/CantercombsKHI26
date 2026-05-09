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

// STDLIB stuff
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

// External libraries
#include "raylib.h"

#define RAYMATH_IMPLEMENTATION
#include "raymath.h"

#define ZPL_IMPLEMENTATION
#include "zpl.h"

#define CUTE_C2_IMPLEMENTATION
#include "cute_c2.h"

// Internals
#include "cant_dmg_box.h"

// Code!

int main(void) {
    
    InitWindow(256, 224, "Cantercombs - KentHackit2026 Build");
    SetTargetFPS(60);

    size_t max_hitboxes = 64;
    cant_dmg_box_t** hitboxes = (cant_dmg_box_t**)malloc(sizeof(cant_dmg_box_t) * max_hitboxes);
    
    Image test_bg = LoadImage("./assets/testbg.png");
    Texture2D test_bg_tex = LoadTextureFromImage(test_bg);

    Image test_player_im = LoadImage("./assets/lilguy.png");
    Texture2D test_player_tex = LoadTextureFromImage(test_player_im);

    int player_x = 16;
    int player_y = 224 - 64;
    
    // I am silly
    bool jumping = false;
    bool falling = false;
    int top_of_jump_arc = 224 - 64 - 48;
    

    while (!WindowShouldClose())
    {
        // Epic logic

        if (IsKeyDown(KEY_D)) player_x += 1;
        if (IsKeyDown(KEY_A)) player_x -= 1;

        if (IsKeyPressed(KEY_SPACE)) {
            jumping = true;
            player_y -= 2;
        }

        if ((jumping == true) && (falling == false)) {
            
            if (player_y >= top_of_jump_arc) { player_y -= 2; }
            else { falling = true; }

        } else if (falling == true) {
            if (player_y <= 224 - 64) { player_y += 2; }
            else {
                falling = false;
                jumping = false;
                player_y = 224 - 64;
            }
        }
        
        // Draw!
                
        BeginDrawing();
        
            ClearBackground(BLACK);
            DrawTexture(test_bg_tex, 0, 0, WHITE);
            DrawTexture(test_player_tex, player_x, player_y, WHITE);
            DrawText("Cantercombs Demo Screen", 16, 16, 16, BLACK);
            
        EndDrawing();

    }

    CloseWindow();

    free(hitboxes);
    
    return 0;
}
