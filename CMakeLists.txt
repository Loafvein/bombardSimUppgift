# Ange minsta version av CMake som krävs
cmake_minimum_required(VERSION 3.11)

# Definiera projektets namn
project(Simulation)

# Ange vilken standard C++ vi använder (C++11 i det här fallet)
set(CMAKE_CXX_STANDARD 11)

# Använd FetchContent för att hämta och bygga Raylib om det inte redan finns
include(FetchContent)

# Hämta Raylib från GitHub
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master  # Eller specificera en version, t.ex. v4.0
)
# Anpassningar för Raspberry Pi
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Bygger för Raspberry Pi")
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)  # Inga exempel
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)     # Inga spel
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPLATFORM_RPI")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPLATFORM_RPI")
endif()

# Bygg Raylib som ett statiskt bibliotek (istället för ett delat bibliotek)
set(RAYLIB_BUILD_SHARED OFF CACHE BOOL "Build Raylib as a static library")

# Gör Raylib tillgängligt för bygget
FetchContent_MakeAvailable(raylib)

# Kopiera assets-mappen från projektets rot till byggmappen
file(COPY ${CMAKE_SOURCE_DIR}/assets/ DESTINATION ${CMAKE_BINARY_DIR}/assets)

# Lägg till dina källkodsfil
add_executable(Simulation main.cpp Payload.cpp Aircraft.cpp Dropdownmenu.cpp FatMan.cpp SupplyDrop.cpp)#här ska du lägga in din klass'.cpp' som du vill implementera  

# Länka Raylib till vårt projekt
target_link_libraries(Simulation raylib)

# Inkludera Raylibs header-filer
target_include_directories(Simulation PRIVATE ${raylib_SOURCE_DIR}/src)
