cmake_minimum_required(VERSION 3.11)
project(interop CXX)

set(KC_PATH "kc" CACHE FILEPATH "Path to Kronos static compiler, `kc`")

set(KRONOS_SRC_FILE interop.k)
set(KRONOS_NAMESPACE Wavetable)
set(KRONOS_INTEROP_HEADER ${CMAKE_CURRENT_BINARY_DIR}/interop.h)
set(KRONOS_OBJECT_FILE ${CMAKE_CURRENT_BINARY_DIR}/interop.o)

add_custom_command(
	COMMAND ${KC_PATH} 
	${KRONOS_SRC_FILE} 
	-o ${KRONOS_OBJECT_FILE}
	-P ${KRONOS_NAMESPACE}
	-H ${KRONOS_INTEROP_HEADER}
	-O 3
	DEPENDS ${KRONOS_SRC_FILE}
	OUTPUT ${KRONOS_OBJECT_FILE} ${KRONOS_INTEROP_HEADER})

add_executable(interop main.cpp ${KRONOS_OBJECT_FILE} ${KRONOS_INTEROP_HEADER})