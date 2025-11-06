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

find_package(SFML 3.0.2 REQUIRED COMPONENTS Graphics Audio Network System Main)

add_executable(CMakeProject1 CMakeProject1.cpp)

enable_testing()

# Création de l'exécutable
add_executable(Test Truc.cpp)

# Liaison des bibliothèques
target_link_libraries(Test PRIVATE Catch2::Catch2WithMain)
#target_link_libraries(CMakeProject1 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(CMakeProject1 SFML::Graphics SFML::Window SFML::Audio SFML::Network SFML::System SFML::Main)

include(cmake/extras/Catch.cmake)
catch_discover_tests(Test)
