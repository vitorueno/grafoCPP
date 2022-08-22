# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project(grafoCPP)

# flags

# files

# include
include_directories(  ./src  )

# target
add_executable( a.out ./src/main.cpp ./src/vertice.cpp)

# external libs - 3rd party libs
# add_subdirectory( ./libs/Logger )
# target_link_libraries( binary logger )

# add_subdirectory( ./libs/Randomize )
# target_link_libraries( binary randomize )

# add_library(randomize STATIC IMPORTED)
# set_property(TARGET randomize PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/Randomize/librandomize.a)
# target_link_libraries( binary randomize )