cmake_minimum_required(VERSION 3.28)
project(Mars)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

option(USE_SYSTEM_LLVM "Use system LLVM instead of a bundled version" False)
option(BUILD_TESTS "Whether to build the test suite" True)
option(BUILD_DOCS "Whether to build the documentation" True)

# Use LLVM's lld linker
find_program(LLD lld)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND LLD)
    message(STATUS "Using LLVM's lld linker")
    add_link_options("-fuse-ld=lld")
    set(USE_LLD TRUE)
endif ()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if (USE_SYSTEM_LLVM)
  find_package(LLVM 19 REQUIRED CONFIG)
else()
  include(FetchContent)
  FetchContent_Declare(
          llvm
          DOWNLOAD_EXTRACT_TIMESTAMP TRUE
          URL https://github.com/llvm/llvm-project/releases/download/llvmorg-19.1.3/llvm-project-19.1.3.src.tar.xz
          SOURCE_SUBDIR llvm
  )

  set(LLVM_ENABLE_PROJECTS "llvm" CACHE STRING "" FORCE)
  if (USE_LLD)
    set(LLVM_USE_LINKER "lld" CACHE STRING "" FORCE)
  endif ()

  FetchContent_MakeAvailable(llvm)
endif()

llvm_map_components_to_libnames(LLVM_LIBS support core irreader)

find_package(cxxopts REQUIRED)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(libmars)
add_subdirectory(mars)

# Tests
if(BUILD_TESTS)
  find_package(Catch2 3 REQUIRED)

  include(CTest)
  add_subdirectory(tests)
endif()

# Documentation
if (BUILD_DOCS)
    message(STATUS "Enabling documentation")
    add_subdirectory(docs)
endif ()
