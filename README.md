# ncnn-installer

Install ncnn on gh actions

## Usage
action.yml:
```yml
- name: Install ncnn
  uses: zchrissirhcz/ncnn-installer@v0.1
```

### On Linux/macOSX
* The whole package will installed in `~/artifacts/ncnn/master`

### On Windows
* The whole package will installed in `D:/artifacts/ncnn/master`

### Use with cmake
To set the correct paths, you could add to your `CMakeLists.txt`:
```cmake
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
```

## References
- [ncnn](https://github.com/tencent/ncnn)