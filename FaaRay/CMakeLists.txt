file(GLOB MORE_TARGETS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */*.cpp )
get_target_property(GFA_SOURCE_DIR GFA SOURCE_DIR)

add_library(FaaRay ${MORE_TARGETS})
target_link_libraries(FaaRay PRIVATE GFA)
target_include_directories(FaaRay PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GFA_SOURCE_DIR})


#file(GLOB TARGET_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */*.cpp )


#add_library(faaray ${TARGET_FILES})

# add gfa library to faaray
#get_target_property(GFA_SOURCE_DIR gfa SOURCE_DIR)
#target_link_libraries(faaray PRIVATE gfa)
#target_include_directories(faaray PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${GFA_SOURCE_DIR})
#get_target_property(BLAH faaray INCLUDE_DIRECTORIES)
#message("blah:" ${BLAH})
