# mingw-toolchain.cmake
set(CMAKE_SYSTEM_NAME Windows)

# 设置交叉编译工具链
set(CMAKE_C_COMPILER /usr/local/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /usr/local/bin/x86_64-w64-mingw32-g++)
set(CMAKE_RC_COMPILER /usr/local/bin/x86_64-w64-mingw32-windres)

# 禁用默认的系统根路径
set(CMAKE_FIND_ROOT_PATH "")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE NEVER)
