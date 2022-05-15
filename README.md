# ncnn-action

[![test](https://github.com/cvpkg/ncnn-action/actions/workflows/test.yml/badge.svg)](https://github.com/cvpkg/ncnn-action/actions/workflows/test.yml)

Install ncnn on Github Actions, provided as re-usable "configure-build-install-export-import" steps.

(Currently disabled NCNN_VULKAN, NCNN_OPENMP, NCNN_RUNTIME_CPU for fast build speed)

## Use in workflows yml
action.yml:
```yml
- name: Install ncnn
  uses: cvpkg/ncnn-action@v0.2
  with:
    ncnn_tag: '20220420' # or master
```

## Use in CMakeLists.txt
To set the correct paths, you could add to your `CMakeLists.txt`:
```cmake
if(DEFINED ENV{GITHUB_ACTIONS} AND DEFINED ENV{GITHUB_WORKSPACE})
  set(ARTIFACTS_DIR "$ENV{GITHUB_WORKSPACE}/artifacts")
  if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/$ENV{ncnn_tag}/windows-x64/lib/cmake/ncnn")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/$ENV{ncnn_tag}/linux-x64/lib/cmake/ncnn")
  elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/$ENV{ncnn_tag}/mac-x64/lib/cmake/ncnn")
  endif()
  find_package(ncnn REQUIRED)
endif()
```

## References
- [ncnn](https://github.com/tencent/ncnn)