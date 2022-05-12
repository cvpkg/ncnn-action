cmake_minimum_required(VERSION 3.15)
project(use_ncnn_example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "CC set to: $ENV{CC}")
message(STATUS "CXX set to:$ENV{CXX}")

if(DEFINED ENV{GITHUB_ACTIONS})
  if(WIN32)
    set(ARTIFACTS_DIR "D:/artifacts")
    #set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    #set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
  else()
    set(ARTIFACTS_DIR "~/artifacts")
  endif()
  set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/master")
  message(STATUS "ARTIFACTS_DIR is: ${ARTIFACTS_DIR}")
  message(STATUS "ncnn_DIR is: ${ncnn_DIR}")
  find_package(ncnn REQUIRED)
endif()

add_executable(testbed tested.cpp)
target_link_libraries(testbed ncnn)

