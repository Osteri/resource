cmake_minimum_required(VERSION 2.8)

project(Resource)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ignore IDE macro
set(void ${QT_QMAKE_EXECUTABLE})

# add source files
aux_source_directory(. SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})
