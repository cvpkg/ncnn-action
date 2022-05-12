cmake_minimum_required(VERSION 3.15)
project(use_ncnn_example)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

message(STATUS "CC set to: $ENV{CC}")
message(STATUS "CXX set to:$ENV{CXX}")

if(DEFINED ENV{GITHUB_ACTIONS} AND DEFINED ENV{GITHUB_WORKSPACE})
  set(ARTIFACTS_DIR "$ENV{GITHUB_WORKSPACE}/artifacts")
  set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/master/lib/cmake/ncnn")
  message(STATUS ">>> ENV{GITHUB_ACTIONS} is: $ENV{GITHUB_ACTIONS}")
  message(STATUS ">>> ENV{GITHUB_WORKSPACE} is: $ENV{GITHUB_WORKSPACE}")
  message(STATUS ">>> ARTIFACTS_DIR is: ${ARTIFACTS_DIR}")
  message(STATUS ">>> ncnn_DIR is: ${ncnn_DIR}")
  find_package(ncnn REQUIRED)
endif()

add_executable(testbed testbed.cpp)
target_link_libraries(testbed ncnn)

