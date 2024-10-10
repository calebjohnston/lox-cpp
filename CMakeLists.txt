#================================================================================
# Build system for Lox language from Robert Nystrom
#================================================================================

cmake_minimum_required(VERSION 3.24)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(loxcc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(glm CONFIG REQUIRED)

set( SRCS
  src/main.cpp
)

add_executable(loxcc ${SRCS})

set_property(TARGET loxcc PROPERTY CXX_STANDARD 20)

#--------------------------------------------------------------------------------
# Associate linker dependencies to target(s).
#--------------------------------------------------------------------------------
target_link_libraries( loxcc
  glm::glm
)
