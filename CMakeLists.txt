cmake_minimum_required(VERSION 3.10)
project(CursedEngin LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /NODEFAULTLIB:LIBCMT")
endif()

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_definitions(-DPDC_WIDE)
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the directory containing pdcurses.lib
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib)

# Add the directory containing curses.h
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/PDCursesMod)

# Link against pdcurses
if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE pdcurses winmm)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE pdcurses)
endif()