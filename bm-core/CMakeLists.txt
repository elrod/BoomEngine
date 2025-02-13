project(BMCore)

# SRC Directory
file(GLOB_RECURSE CORE_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Include Dir
include_directories(${RAYLIB_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/)

# Produce a static library
add_library(${PROJECT_NAME} STATIC ${CORE_SOURCES})

# link raylib
target_link_libraries(${PROJECT_NAME} ${RAYLIB_DIR}/lib/libraylib.a)

if(TARGET_PLATFORM STREQUAL "macos")
    # Custom compile defines
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_DESKTOP PLATFORM_OSX)
    # link macOS frameworks
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
    # Set target properies
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist/${TARGET_PLATFORM})
elseif(TARGET_PLATFORM STREQUAL "webassembly")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WEB)
    # Add WebAssembly-specific linking and flags here
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist/${TARGET_PLATFORM} LINK_FLAGS "-s USE_GLFW=3 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1")
endif()

