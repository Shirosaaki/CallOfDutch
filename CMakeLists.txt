cmake_minimum_required(VERSION 3.20)
project(CallOfDutch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclusion de SDL3 via FetchContent
include(FetchContent)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main # Ou une version spécifique
)
FetchContent_MakeAvailable(SDL3)

# Dossiers source
include_directories(src)

# Lister les fichiers sources (simplifié)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

# Liaison avec SDL3
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

# Copie des assets vers le build (optionnel au début)
