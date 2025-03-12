CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(Final_Project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# Reference: https://github.com/google/googletest/tree/main/googletest#incorporating-into-an-existing-cmake-project
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif ()

set(SOURCE_FILES 
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
add_executable(villain_revenge src/main.cpp ${SOURCE_FILES})

set(TEST_FILES 
    test/playerTests.cpp
    test/enemyTests.cpp
    test/shopTests.cpp
    test/weaponTests.cpp
    test/spellTests.cpp
    test/gameDataTests.cpp
    test/gameMasterTests.cpp
    test/upgradeSystemTests.cpp
    test/monsterTests.cpp
)
add_executable(runAllTests ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main)
