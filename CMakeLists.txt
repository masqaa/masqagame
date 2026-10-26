cmake_minimum_required(VERSION 3.15)
project(KronikWygnanca CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Zbieramy pliki .cpp z folderów, w których już coś jest
file(GLOB SOURCES_ROOT "*.cpp")
file(GLOB SOURCES_POSTACIE "postacie/*.cpp")
file(GLOB SOURCES_SYSTEMY "systemy/*.cpp")

add_executable(gra
    ${SOURCES_ROOT}
    ${SOURCES_POSTACIE}
    ${SOURCES_SYSTEMY}
)

# Dzięki temu działa #include "postacie/Gracz.h" z każdego miejsca
target_include_directories(gra PRIVATE ${CMAKE_SOURCE_DIR})

target_compile_options(gra PRIVATE -Wall -Wextra)