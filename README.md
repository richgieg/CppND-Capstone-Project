![](hipster-hop-screenshot.png?raw=true)

# Hipster Hop

Hipster Hop is a game that I created as my capstone project in Udacity's C++ Nanodegree course.

This project demonstrates various C++ control structures, object-oriented programming, modern C++
memory management techniques using smart pointers, as well as wrapping unsafe structures from a
third-party C library in a RAII (resource acquisition is initialization) handle class to ensure cleanup.

# Contents
- [Prerequisites](#prerequisites)
- [Build](#build)
- [Run](#run)
- [Play](#play)
- [Class Structure](#class-structure)
- [Rubric](#rubric)

# Prerequisites

## raylib
Description from raylib website: "raylib is a simple and easy-to-use library to enjoy videogames programming."

### Windows
- Go to https://www.raylib.com/
- Click "Download Now"
- Click "No thanks, just take me to the downloads" (donate if you'd like)
- Click "Download" next to "raylib 3.7 Windows Installer (with MinGW compiler)"
- Go through the installation process (Raylib and MinGW will installed at c:\raylib)

### Linux
*Tested with Ubuntu*
- Follow instructions at https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux
  - Install as dynamic shared library

### Mac
- Follow instructions at https://github.com/raysan5/raylib/wiki/Working-on-macOS
  - Use Homebrew option

# Clone Repository
```
git clone https://github.com/richgieg/CppND-Capstone-Project richgieg-CppND-Capstone-Project
cd richgieg-CppND-Capstone-Project
```

# Build

Now that the prerequisites are installed, you can build the game. Create a debug
build if you intend to run with a debugger. Otherwise, create a release build.

## Debug

### Windows
`C:/raylib/mingw/bin/mingw32-make.exe RAYLIB_PATH=C:/raylib/raylib PROJECT_NAME=hipster-hop OBJS=src/*.cpp BUILD_MODE=DEBUG`

### Linux
`make PROJECT_NAME=hipster-hop RAYLIB_LIBTYPE=SHARED OBJS=src/*.cpp BUILD_MODE=DEBUG`

### Mac
`make PROJECT_NAME=hipster-hop OBJS=src/*.cpp BUILD_MODE=DEBUG`

## Release

### Windows
`C:/raylib/mingw/bin/mingw32-make.exe RAYLIB_PATH=C:/raylib/raylib PROJECT_NAME=hipster-hop OBJS=src/*.cpp`

### Linux
`make PROJECT_NAME=hipster-hop RAYLIB_LIBTYPE=SHARED OBJS=src/*.cpp`

### Mac
`make PROJECT_NAME=hipster-hop OBJS=src/*.cpp`

# Run
After building either the debug or release version, run using the steps below.

## Windows
`hipster-hop` (or `.\hipster-hop.exe` if using PowerShell)

## Linux
`./hipster-hop`

## Mac
`./hipster-hop`

# Play

Hippy the Hipster is out to get a midnight snack. Unfortunately, it's very cold and
frozen tumbleweeds abound. Jump over them by pressing the space bar.

Spoiler alert: It's a sad story... Hippy will never get that midnight snack. But,
at least it's fun to try!

NOTE: When you lose you have to close the window and relaunch the game to play again.

# Class Structure

- Everything starts in `main.cpp`
- `main.cpp` creates an instance of `Game`, repeatedly calling `update` and `draw` methods
as long as the window is open
- `Game` creates a `ScrollingBackground` instance, an `EntityPool` instance containing `Enemy` instances,
an `EnemySpawner` instance, a `Player` instance, and a `GameOverScreen` instance
- `EntityPool` is a class template which can be used to conveniently create and manage `Entity` (and subclass
of `Entity`) instances. It calls `update` and `draw` on all entities in the pool. Also provides a
`getFirstInactive` method which returns the first inactive entity in the pool (useful for `EnemySpawner`, etc.)
- `EnemySpawner` is responsible for spawning enemies over time
- `Player` and `Enemy` inherit from `Entity`, since `Entity` implements the common functionality
for manipulating a sprite on screen
- `GameOverScreen` is responsible for showing "game over" text and dimming the background
- `Texture2DHandle` is an RAII wrapper class for unsafe `Texture2D` structures returned by the raylib
library (representing spritesheets and background images)
- `TextureManager` uses an `unordered_map` to maintain a cache of `shared_ptr<Texture2DHandle>`
indexed by file name. Its `loadAndGetTexture` method is used by `Entity` and `ScrollingBackground` to load
their spritesheets/images. This ensures that a particular file is only loaded once and shared pointers
are used so that the `Texture2DHandle` destructor is called automatically when necessary (and only once).

# Rubric

This project addresses the rubric items below.

## Loops, Functions, I/O

### The project demonstrates an understanding of C++ functions and control structures.
See:
- `Game.cpp` lines 13, 25
- `EntityPool.h` lines 32, 38

### The project reads data from a file and process the data, or the program writes data to a file.
See:
- `Texture2DHandle.cpp` line 5 (loading a texture file from disk using raylib)

### The project accepts user input and processes the input.
See:
- `Player.cpp` line 10 (player jumps when user presses space bar)

## Object Oriented Programming

### The project uses Object Oriented Programming techniques.
See [Class Structure](#class-structure) and corresponding header and code files for more info.

### Classes use appropriate access specifiers for class members.
See `Entity.h` for an example of private data members and public methods.

### Class constructors utilize member initialization lists.
I make heavy use of initialization lists in this project in order to ensure that
all primitive members are initialized to their default values at the very least,
and also to initialize members with arguments where arguments are given.

See:
- `Entity.cpp` line 8

### Classes abstract implementation details from their interfaces.
See: `Entity.h` for examples of appropriately named (self-documenting) methods,
including getters and setters, of which some are marked `const` in order to strongly
communicate (and ensure) that they do not modify state of the object.

### Classes follow an appropriate inheritance hierarchy.
A good example of this is how the `Enemy` and `Player` classes inherit from `Entity`, since
`Entity` implements the necessary functionality for manipulating a sprite-based game object.

See: `Entity.h`, `Player.h`, and `Enemy.h`

### Derived class functions override virtual base class functions.
`Player` overrides the virtual `update` method of `Entity` in order to react to user input.

See:
- `Player.h` line 14
- `Player.cpp` line 8
- `Entity.h` line 27
- `Entity.cpp` line 65

### Templates generalize functions in the project.
`EntityPool` is a generic class with generic methods.

See:
- `EntityPool.h` line 14

## Memory Management

### The project makes use of references in function declarations.
See:
- `ScrollingBackground.h` lines 18 and 19
- `ScrollingBackground.cpp` lines 23 and 36

### The project uses destructors appropriately.
See:
- `Texture2DHandle.cpp` line 8 (unloads unsafe `Texture2D` structure loaded by raylib library)

### The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
`TextureManager` maintains an `unordered_map` of `shared_ptr<Texture2DHandle>` instances and
hands out copies of shared pointers as requested. When the last `shared_ptr<Texture2DHandle>`
goes out of scope then the `Texture2DHandle` destructor runs, which unloads the unsafe `Texture2D`
structure loaded by raylib library (see previous rubric item).

See: `TextureManager.cpp` and `Texture2DHandle.cpp`

### The project follows the Rule of 5.
I'm not sure if this counts for full credit on this item, but `Texture2DHandle` follows the rule
of 5 by providing a destructor implementation (which is required to unload the texture) and also
deletes the copy constructor, copy assignment operator, move constructor, and move assignment operator.
The rationale for deleting these is to prevent copying and moving Texture2DHandles and thus strongly
encourage that they are managed by smart pointers.

See:
- `Texture2DHandle.h` line 19

### The project uses smart pointers instead of raw pointers.
See:
- `Entity.h` line 30
- `ScrollingBackground.h` line 20
- `TextureManager.h` lines 18 and 20
- `TextureManager.cpp` line 9
