# ncnn-installer

Install ncnn on gh actions

## Use in workflows yml
action.yml:
```yml
- name: Install ncnn
  uses: zchrissirhcz/ncnn-installer@v0.1
```

## Use in CMakeLists.txt
To set the correct paths, you could add to your `CMakeLists.txt`:
```cmake
if(DEFINED ENV{GITHUB_ACTIONS} AND DEFINED ENV{GITHUB_WORKSPACE})
  set(ARTIFACTS_DIR "$ENV{GITHUB_WORKSPACE}/artifacts")
  set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/master/lib/cmake/ncnn")
  message(STATUS ">>> ENV{GITHUB_ACTIONS} is: $ENV{GITHUB_ACTIONS}")
  message(STATUS ">>> ENV{GITHUB_WORKSPACE} is: $ENV{GITHUB_WORKSPACE}")
  message(STATUS ">>> ARTIFACTS_DIR is: ${ARTIFACTS_DIR}")
  message(STATUS ">>> ncnn_DIR is: ${ncnn_DIR}")
  find_package(ncnn REQUIRED)
endif()
```

## References
- [ncnn](https://github.com/tencent/ncnn)