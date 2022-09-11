# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project(grafoCPP)

# flags

# files

# include
include_directories(  ./src  )

# target
add_executable( a.out ./src/main.cpp ./src/objetoIdentificado.cpp ./src/aresta.cpp ./src/vertice.cpp ./src/grafo.cpp ./src/arestaDirigida.cpp ./src/verticeDirigido.cpp ./src/grafoDirigido.cpp)


# linha para compilar para debug (comentar para otimizar compilação)
set(CMAKE_BUILD_TYPE Debug)