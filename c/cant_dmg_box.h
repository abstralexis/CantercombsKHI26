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

#include "raylib.h"

typedef struct CantDmgBox {
    int dmg;
    Rectangle hitbox;
} cant_dmg_box_t;
