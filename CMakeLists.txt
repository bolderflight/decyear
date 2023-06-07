# v3.14 required for FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)
# Project information
project(DecYear
  VERSION 1.0.0
  DESCRIPTION "Decimal Year Converter"
  LANGUAGES CXX
)
include(FetchContent)
FetchContent_Declare(
  juliandate
  GIT_REPOSITORY https://github.com/bolderflight/juliandate.git
  GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(juliandate)
# Add the library target
add_library(decyear
  src/decyear.h
  src/decyear.cpp
)
# Fetch juliandate
target_link_libraries(decyear
  PRIVATE
    juliandate
)
# Setup include directories 
target_include_directories(decyear PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:include>
)
# Example and test if this project is built separately
if (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Add the  example target
  add_executable(decyear_example examples/cmake/decyear_ex.cc)
  # Add the includes
  target_include_directories(decyear_example PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  )
  # Link libraries to the example target
  target_link_libraries(decyear_example
    PRIVATE
      decyear
  )
  # Fetch google test
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
  )
  FetchContent_MakeAvailable(googletest)
  enable_testing()
  include(GoogleTest)
  # Add the test target
  add_executable(decyear_test tests/decyear_test.cc)
  # Add the includes
  target_include_directories(decyear_test PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  )
  # Link libraries to the test target
  target_link_libraries(decyear_test
    PRIVATE 
      decyear
      gtest_main 
      gtest
      gmock
  )
  # Discover unit tests
  gtest_discover_tests(decyear_test)
endif()
