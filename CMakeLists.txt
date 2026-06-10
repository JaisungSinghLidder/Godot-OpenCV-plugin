cmake_minimum_required(VERSION 3.16)
project(godot_opencv_plugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(GODOT_CPP_PATH "${CMAKE_SOURCE_DIR}/godot-cpp")

add_subdirectory(${GODOT_CPP_PATH} godot-cpp-build)

set(OpenCV_STATIC ON)
find_package(OpenCV REQUIRED)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(${PROJECT_NAME} SHARED ${MY_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${GODOT_CPP_PATH}/include
    ${GODOT_CPP_PATH}/gen/include
    ${CMAKE_SOURCE_DIR}/src
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    godot-cpp
    ${OpenCV_LIBS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/godot/gdextension/bin"
)

