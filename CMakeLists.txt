cmake_minimum_required(VERSION 3.16)
project(godot_opencv_plugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GODOT_CPP_PATH "C:/Users/jaisu/Desktop/Godot-OpenCV-plugin/godot-cpp")
add_subdirectory(${GODOT_CPP_PATH} godot-cpp-build)

include_directories(
    ${GODOT_CPP_PATH}/include
    ${GODOT_CPP_PATH}/gen/include
    ${CMAKE_SOURCE_DIR}/src
)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


file(GLOB SOURCE_FILES
    src/*.cpp
)


add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})


target_link_libraries(${PROJECT_NAME}
    godot-cpp
    ${OpenCV_LIBS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/godot/gdextension/bin"
)
