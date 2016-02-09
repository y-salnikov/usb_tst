cmake_minimum_required (VERSION 2.8)
project (usbtst)
# The version number.
set (TARGET usbtst)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -pipe -Wall")
#set_directory_properties(PROPERTY ADDITIONAL_MAKE_CLEAN_FILES firmware_hex.c)

IF(MINGW)
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DWIN32=1")
ELSE(MINGW)
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -DUNIX=1")
ENDIF(MINGW)


set(SOURCE_FILES main.c usb.c firmware_hex.c compat.c)

# configure a header file to pass some of the CMake settings
# to the source code
# add the binary tree to the search path for include files
# so that we will find
include_directories("${PROJECT_BINARY_DIR}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

find_package(libusb-1.0 REQUIRED)
if(NOT LIBUSB_1_FOUND)
	message(SEND_ERROR "Failed to find libusb-1.0")
	return()
else()
    include_directories(${LIBUSB_1_INCLUDE_DIR})
endif()

find_package (Threads)

# add the executable
add_executable(${TARGET} ${SOURCE_FILES} )

target_link_libraries(${TARGET}  ${LIBUSB_1_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})



