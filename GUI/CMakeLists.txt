set(CMAKE_PREFIX_PATH C:/Qt/6.1.1/mingw81_64)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets OpenGLWidgets REQUIRED)

file(GLOB GUI_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

get_target_property(GFA_SOURCE_DIR GFA SOURCE_DIR)
get_target_property(FAARAY_SOURCE_DIR FaaRay SOURCE_DIR)
add_library(GUI ${GUI_SOURCES})
target_link_libraries(GUI PRIVATE Qt6::Widgets FaaRay)
target_include_directories(GUI PUBLIC ${GFA_SOURCE_DIR} ${FAARAY_SOURCE_DIR})
