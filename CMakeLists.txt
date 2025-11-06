cmake_minimum_required(VERSION 3.15)
project(CMakeProject1)

# CPM setup
set(CPM_DOWNLOAD_VERSION 0.42.0)
#cmake setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/CPM.cmake)

## Dépendances externes
CPMAddPackage(
    NAME Catch2
    GITHUB_REPOSITORY catchorg/Catch2
    VERSION 3.6.0
    OPTIONS "CATCH_BUILD_TESTING OFF"
)
CPMAddPackage(
    NAME SFML
    GITHUB_REPOSITORY SFML/SFML
    GIT_TAG 3.0.0
    OPTIONS
        "SFML_BUILD_EXAMPLES OFF"
        "SFML_BUILD_TEST_SUITE OFF"
        "SFML_BUILD_DOC OFF"
        "SFML_SHARED_LIBS ON"
        "CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
        $<$<PLATFORM_ID:Windows>:"SFML_GENERATE_PDB ON">
        $<$<AND:$<PLATFORM_ID:Darwin>,$<CONFIG:Release>>:
            "CMAKE_INSTALL_PREFIX=/Library/Frameworks"
            "SFML_BUILD_FRAMEWORKS ON"
        >
        $<$<AND:$<PLATFORM_ID:Darwin>,$<CONFIG:Debug>>:
            "SFML_BUILD_FRAMEWORKS OFF"
        >
)

add_executable(CMakeProject1 CMakeProject1.cpp)

enable_testing()

# Création de l'exécutable
add_executable(Test Truc.cpp)

# Liaison des bibliothèques
target_link_libraries(Test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(CMakeProject1 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

include(cmake/extras/Catch.cmake)
catch_discover_tests(Test)