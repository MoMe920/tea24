cmake_minimum_required(VERSION 3.15)
project(version VERSION 0.0.1 LANGUAGES CXX)

# 1. configure_file(...): Generiert aus der .in-Datei eine echte .h-Datei im Build-Ordner
configure_file(
    version_config.h.in
    "${CMAKE_CURRENT_BINARY_DIR}/version_config.h"
    @ONLY
)


# 3. Die statische Bibliothek 'version' erzeugen
add_library(version STATIC
    src/version.cpp
)

# 2. Die generierte Header-Location in die Include-Pfade aufnehmen,
# damit der Compiler den generierten Header im Build-Ordner finden kann.
target_include_directories(version PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

