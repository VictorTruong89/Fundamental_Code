cmake_minimum_required(VERSION 3.16)

project( DataStructures )

file( GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp )
file( GLOB HEADERS ${PROJECT_SOURCE_DIR}/src/*.hpp )

add_executable( ${PROJECT_NAME} ${SOURCES} ${HEADERS} )

set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14 )