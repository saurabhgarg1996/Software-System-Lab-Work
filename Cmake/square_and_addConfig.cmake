get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH) 
include(${SELF_DIR}/square_and_add-targets.cmake) 
get_filename_component(square_and_add_INCLUDE_DIRS "${SELF_DIR}/../../include" ABSOLUTE)
