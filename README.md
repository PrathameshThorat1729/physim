# Physim - Simple Physics Simulations

**Physim** is a collection of simple and fast *Physics Simulations* wriiten in C++ using library SFML.

Many components of this project are tried to implement from scratch for educational purpose.

# Building and Compiling

## Prerequisites
- [CMake](https://cmake.org/)
- External packages with their development headers  (for linux only)
  - freetype
  - x11
  - xrandr
  - udev
  - opengl
  - flac
  - ogg
  - vorbis
  - vorbisenc
  - vorbisfile
  - openal
  - pthread

  To install the listed packages in a Linux distribution, you can use the package manager for your specific system. Below are commands for common Linux distributions:

  ### For Debian/Ubuntu-based distributions:
  ```bash
  sudo apt update
  sudo apt install -y libfreetype6-dev libx11-dev libxrandr-dev libudev-dev libgl1-mesa-dev libflac-dev libogg-dev libvorbis-dev libvorbisenc2 libvorbisfile3 libopenal-dev libpthread-stubs0-dev
  ```

  ### For Fedora:
  ```bash
  sudo dnf install -y freetype-devel libX11-devel libXrandr-devel systemd-devel mesa-libGL-devel flac-devel libogg-devel libvorbis-devel openal-soft-devel glibc-headers
  ```

  ### For Arch Linux:
  ```bash
  sudo pacman -S --needed freetype2 libx11 libxrandr libsystemd mesa flac libogg libvorbis openal gcc-libs
  ```


## Step 1 : Cloning Reposetory
```bash
git clone --recurse-submodules https://github.com/PrathameshThorat1729/physim.git
cd physim
```
## Step 2 : Configure and Build
```bash
cmake -S . -B build
cd build
cmake --build .
```

Output will be build in *build/bin* directory. Copy that folder anywhere you want and you are ready to use it


# External Libraries Used
- [SFML](https://github.com/SFML/SFML.git)