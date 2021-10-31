# Contents
[asdf](#prerequisites)

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
`git clone https://github.com/richgieg/CppND-Capstone-Project richgieg-CppND-Capstone-Project`

# Debug Build

## Windows
```
cd richgieg-CppND-Capstone-Project
C:/raylib/mingw/bin/mingw32-make.exe RAYLIB_PATH=C:/raylib/raylib PROJECT_NAME=hipster-hop OBJS=src/*.cpp BUILD_MODE=DEBUG
```

## Linux
```
make PROJECT_NAME=hipster-hop RAYLIB_LIBTYPE=SHARED OBJS=src/*.cpp BUILD_MODE=DEBUG
```

## Mac
```
make PROJECT_NAME=hipster-hop OBJS=src/*.cpp BUILD_MODE=DEBUG
```

# Release Build

## Windows
```
cd richgieg-CppND-Capstone-Project
C:/raylib/mingw/bin/mingw32-make.exe RAYLIB_PATH=C:/raylib/raylib PROJECT_NAME=hipster-hop OBJS=src/*.cpp
```

## Linux
```
make PROJECT_NAME=hipster-hop RAYLIB_LIBTYPE=SHARED OBJS=src/*.cpp
```

## Mac
```
make PROJECT_NAME=hipster-hop OBJS=src/*.cpp
```

# Run
After building either the debug or release version, run using the steps below.

## Windows
`hipster-hop` (or `.\hipster-hop.exe` if using PowerShell)

## Linux
./hipster-hop

## Mac
./hipster-hop
