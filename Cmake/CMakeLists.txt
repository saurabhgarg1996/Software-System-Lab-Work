cmake_minimum_required(VERSION 2.6) 
project(square_and_add) 
set(tutorial_SRCS ./src/main.cc ./libsrc/include/square.h ./libsrc/src/square.cc)
include_directories(${square_and_add_SOURCE_DIR}/libsrc/include)

add_executable(sqnadd_no_lib ${tutorial_SRCS})
SET_TARGET_PROPERTIES(sqnadd_no_lib PROPERTIES OUTPUT_NAME no_lib_exec)

#SET_TARGET_PROPERTIES(sqnadd_no_lib PROPERTIES OUTPUT_NAME no_lib_exec)
add_library(build_static_lib STATIC ./libsrc/include/square.h ./libsrc/src/square.cc)
SET_TARGET_PROPERTIES(build_static_lib PROPERTIES OUTPUT_NAME static_library PREFIX "")

add_executable(static_lib_exec ${tutorial_SRCS})
target_link_libraries(static_lib_exec build_static_lib)
SET_TARGET_PROPERTIES(static_lib_exec PROPERTIES OUTPUT_NAME sqnadd_stat_lib)

add_library(build_dynamic_lib SHARED ./libsrc/include/square.h ./libsrc/src/square.cc)
SET_TARGET_PROPERTIES(build_dynamic_lib PROPERTIES OUTPUT_NAME dynamic_library PREFIX "")

add_executable(dynamic_lib_exec ${tutorial_SRCS})
target_link_libraries(dynamic_lib_exec build_dynamic_lib)
SET_TARGET_PROPERTIES(dynamic_lib_exec PROPERTIES OUTPUT_NAME sqnadd_dyn_lib)
install( TARGETS static_lib_exec dynamic_lib_exec
	RUNTIME DESTINATION ./libs
	LIBRARY DESTINATION ./libs)
# CONFIGURATIONS Debug
#	LIBRARY DESTINATION ./libs CONFIGURATIONS Debug)

