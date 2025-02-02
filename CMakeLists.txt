cmake_minimum_required(VERSION 3.27)

# Nome del progetto root
project(BoomEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Define the target platform with a default value if not specified
if(NOT TARGET_PLATFORM)
    set(TARGET_PLATFORM "macos" CACHE STRING "Target platform (e.g., 'macos', 'webassembly')")
endif()

# Imposta il percorso per la directory di output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist/${TARGET_PLATFORM})

if(TARGET_PLATFORM STREQUAL "macos")
    set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/libs/macos/raylib-5.5_macos)
elseif(TARGET_PLATFORM STREQUAL "webassembly")
    set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/libs/wasm/raylib-5.5_webassembly)
else()
    message(FATAL_ERROR "Unsupported target platform")
endif()

# # Imposta il percorso a Raylib per i sottoprogetti
# set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/libs/macos/raylib-5.5_macos)

# Aggiungi i sottoprogetti (app e core)
add_subdirectory(bm-core)
add_subdirectory(bm-sample)
