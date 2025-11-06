add_library(superLib src/LibTest.cpp) #add library, le fait par defaut dans le current directory, creation de la variable superlib

target_include_directories(superLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # pour faire plus simple, peut aussi s'ecrire : target_include_directories(superLib PUBLIC LibTest.hpp) il vient chercher les includes de la lib dans le chemin specifié