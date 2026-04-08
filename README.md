# GodHunter Engine

GodHunter is a C++ game engine I'm working on for the fun of making a game engine. It's not yet ready for use but I plan to have a functionnal version of it by 2028.

## The plan
The project will be done in a few steps:
1. Create the structure for the overall project and output.
2. Create the structure for the C++ code.
3. Create the core of the engine.
4. Create a list of modules.
5. Create the documentation.

## Goals and Challenges
For this project, I gave myself a few rules, restrictions and goals:
1. I mainly want to use 'Data Oriented Design' and avoid 'Object Oriented Programming': Prefer composition over inheritence.
2. I want the engine to be modular with replaceable modules, meaning the user could choose the game to be rendered by OpenGL, Vulkan or a custom Rendering API of their choice.
3. I want the engine to provide various modules and APIs.
4. I want the engine to be fast and cross-platform and allow 2D and 3D rendering and physics.
