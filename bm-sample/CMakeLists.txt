# Definisci il progetto app
project(BMSample)

# Imposta il percorso ai file sorgente di app
file(GLOB_RECURSE APP_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

include_directories(${RAYLIB_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/bm-core/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(RESOURCES_DIR ${PROJECT_SOURCE_DIR}/resources)

# Crea l'eseguibile per app
add_executable(${PROJECT_NAME} ${APP_SOURCES})
# Linka Raylib e il core a app
target_link_libraries(${PROJECT_NAME} BMCore ${RAYLIB_DIR}/lib/libraylib.a)

if(TARGET_PLATFORM STREQUAL "macos")

    # Custom compile defines
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_DESKTOP PLATFORM_OSX)
    # Link delle librerie richieste su macOS
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL" "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
    # Imposta il target di compilazione
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist/${TARGET_PLATFORM})
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RESOURCES_DIR}
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
    )
elseif(TARGET_PLATFORM STREQUAL "webassembly")
    target_compile_definitions(${PROJECT_NAME} PRIVATE PLATFORM_WEB)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file ${RESOURCES_DIR}@/resources -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1 --shell-file ${PROJECT_SOURCE_DIR}/platforms/wasm/shell.html")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()