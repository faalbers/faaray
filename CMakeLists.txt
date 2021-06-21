cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(faaraygui VERSION 0.1 LANGUAGES CXX)

add_compile_definitions(CLASS_DEBUG)
add_compile_definitions(SHARED_POINTER_DEBUG)

add_subdirectory(GFA)
add_subdirectory(FaaRay)
add_subdirectory(GUI)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE GUI)

#add_executable(${PROJECT_NAME} multithread.cpp)
#add_executable(${PROJECT_NAME} sharedpointer.cpp)
#add_executable(${PROJECT_NAME} pointerpass.cpp)
