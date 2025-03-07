CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(Final_Project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${LIBRARY_OUTPUT_PATH})
include_directories(${CMAKE_SOURCE_DIR}/test/lib/googletest/include/)

ADD_EXECUTABLE(villain_revenge
    src/main.cpp
    src/enemy.cpp
    src/character.cpp
    src/item.cpp
    src/spell.cpp
    src/spell_viewer.cpp
    src/weapon_viewer.cpp
    src/weapon.cpp
    src/gamedata.cpp
    src/gamemaster.cpp
    src/player.cpp
    src/monster.cpp
    src/shop.cpp
    src/shop_viewer.cpp
    src/upgradesystem.cpp
)

add_subdirectory(src)
add_subdirectory(test)