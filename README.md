# ncnn-installer

Install ncnn on Github Actions, provided as re-usable "configure-build-install-export-import" steps.

(Currently disabled Vulkan and OpenMP for fast build speed)

## Use in workflows yml
action.yml:
```yml
- name: Install ncnn
  uses: zchrissirhcz/ncnn-installer@v0.1
  with:
    ncnn_tag: '20220420' # or master
```

## Use in CMakeLists.txt
To set the correct paths, you could add to your `CMakeLists.txt`:
```cmake
if(DEFINED ENV{GITHUB_ACTIONS} AND DEFINED ENV{GITHUB_WORKSPACE})
  set(ARTIFACTS_DIR "$ENV{GITHUB_WORKSPACE}/artifacts")
  set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/$ENV{ncnn_tag}/lib/cmake/ncnn")
  message(STATUS ">>> ENV{GITHUB_ACTIONS} is: $ENV{GITHUB_ACTIONS}")
  message(STATUS ">>> ENV{GITHUB_WORKSPACE} is: $ENV{GITHUB_WORKSPACE}")
  message(STATUS ">>> ARTIFACTS_DIR is: ${ARTIFACTS_DIR}")
  message(STATUS ">>> ncnn_DIR is: ${ncnn_DIR}")
  find_package(ncnn REQUIRED)
endif()
```

The installed ncnn package root directory will be:
- Windows: `D:\a\ncnn-installer\ncnn-installer/artifacts/ncnn/master`
- Linux: `/home/runner/work/ncnn-installer/ncnn-installer/artifacts/ncnn/master`
- macOSX: `/Users/runner/work/ncnn-installer/ncnn-installer/artifacts/ncnn/master`

## References
- [ncnn](https://github.com/tencent/ncnn)