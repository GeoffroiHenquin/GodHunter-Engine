# GodHunter Engine

GodHunter is a C++ game engine I'm working on for the fun of making a game engine. It's not yet ready for use but I plan to have an functionnal early version of it by 2025.

## The plan
The project will be splited into three smaller parts:
- The Engine (A library that contains the mains features)
- A Blank Game (An executable that will use the library)
- The Editor (A program that should allow easy modification of the game)

The engine will use SDL to communicate with the operating system in order to create a window and display graphics in it as well as geting the user's input.

As a start, I will add the main features such as a Logger to debug, an event system to handle the player's inputs and an entity component system to handle the various elements of the game.

Next, I will add various systems to handle physics, rendering and user define behaviours. I plan to add one or more scripting languages for that but I am not yet sure which one(s) it will be.

Finally, I will make the editor which should have the ability to edit a game and build it into an executable.

## Goals and Challenges
For this project, I gave myself a few rules, restrictions and goals:
1. I want to limit the amount of external libraries used to the minimum. Some exeption are mades for the features that are specific to an operating system or to type of document. That is why I use SDL for the display. I will also use a library to use a scripting language.
2. I want all the assets used by a game made with my engine to be included directly into the executable. 
3. I want my engine to allow scripting in multiple languages.
4. I want my engine to be cross-platform.
5. I want my engine to allow for 2D, 3D and maybe even 4D rendering and physics.
6. I want my engine to give an easy handling of player inputs.
7. I would like for my engine to handle more specific game features like AI and maybe even multiplayer.