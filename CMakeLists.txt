cmake_minimum_required(VERSION 3.11.0)
project(curltest)

# include conan generated build file
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# set up our executable
add_executable(curly src/main.c)
target_link_libraries(curly ${CONAN_LIBS})

# support gsasl if installed
find_library(GSASL_LIB gsasl)
if(GSASL_LIB)
	target_link_libraries(curly gsasl)
endif()

