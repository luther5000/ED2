cmake_minimum_required(VERSION 3.20)
project(01-buscaLinearMemoria LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

add_executable(buscaLinear.exe
        src/mainBuscaLinear.c
        src/tabelaEncadeada.c
        src/tabelaIndexada.c
        src/tipoFilme.c)