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
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

// External libraries
#include "raylib.h"

#define ZPL_IMPLEMENTATION
#include "zpl.h"

#define CUTE_C2_IMPLEMENTATION
#include "cute_c2.h"

// Code!



int main(void) {

    InitWindow(256, 224, "Cantercombs - KentHackit2026 Build");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        
            ClearBackground(BLACK);
            DrawText("Cantercombs Demo Screen", 16, 16, 16, PURPLE);
            
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
