# Cantercombs
*Big shoutout to the University of Kent and the team behind KentHackIt 2026!*

## Description
A small NES Castlevania inspired game made for KentHackIt 2026! You are a historian
who has been commissioned to explore the Catacombs under Canterbury Cathedral, but
there's been an infestation of monsters that you must defeat before you can crack
the code in the final atrium... If I ever finish the game! 

## Please be nice :3
~~This is my first proper project that I am fully committing to in C, and also in `raylib`.
Hence, the code is likely to be horrific and leak a lot of memory. Sorry!~~
<br>
I spent about seven hours programming in C and raylib – safe to say I did not get something working.
I do enjoy C and raylib, but I think perhaps a hackathon is not the best learning environment for me
especially for such different things to what I am used to.

## Technical 
~~This will be written in plain C (C99) with `raylib` as the only external dependency
and using SHF libraries like `zpl.h` and `cute_c2.h` for speed purposes.~~
<br> 
I did a fair amount in C, and then found it very difficult to do without adequate planning. 
Lucy is, as of 1726 hours, porting the entire idea to Godot. It's not like I haven't switched to 
Godot a few hours into a jam before - I think I did this in GMTK 2025.

## Building the C
I do not have the time to use a pretty build system so do it yourself. I use:
```zsh
gcc main.c `pkg-config --libs --cflags raylib` -o CantercombDev
```
With `raylib` installed with `brew install raylib` on my M2 Mac.

## KHI Feature Goals
- [ ] Sprite Animations
- [ ] Basic Parallax for Backgrounds
- [ ] Basic Platforming Controls
- [ ] Basic Attacks for the three weapons
  - [ ] Cane
  - [ ] Candle
  - [ ] Oil Lamp
- [ ] Add their Special Effects
- [ ] Basic Enemy Interaction
  - [ ] Skeleton
  - [ ] Giant Slug
  - [ ] Arcane Casters
- [ ] Health Bar
- [ ] Inventory Bar showing current items

# Licensing
## C attempt
All art and music CC0 (c) 2026 Lucy Blight. Visit [Her Website](https://firefallowgames.co.uk/Home)!<br>
All code AGPLv3 (c) 2026 Alexis Williams. Visit [Her Website](https://abstralexis.dev/)!
# Godot attempt
