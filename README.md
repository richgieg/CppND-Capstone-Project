# Intro

This is my game Hipster Hop that I created as my capstone project in Udacity's C++ Nanodegree course.

This project demonstrates various C++ control structures, object-oriented programming, modern C++
memory management techniques using smart pointers, as well as wrapping unsafe structures from a
third-party C library in a RAII (resource acquisition is initialization) handle class to ensure cleanup.

# Contents
- [Prerequisites](#prerequisites)
- [Build](#build)
- [Run](#run)
- [Play](#play)

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
