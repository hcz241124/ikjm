cmake_minimum_required(VERSION 3.24)

project(hcz)

MESSAGE(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

option(IKJM4C_BUILD_EXAMPLE "Build example code" ON)
option(BUILD_SHARED_LIBS "Build shared library" ON)

include(cmake/ikjm/set_os_compile_macro.cmake)

add_library(lhris
    source/ris/version.c
)
target_include_directories(lhris 
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# 使用编译器宏判断编译工具链，所以不需要配置系统特定宏定义
# ikjm_set_os_compile_macro(ikjm4c)
target_compile_definitions(lhris PRIVATE -DIKJM4C_EXPORT_API)
add_library(hcz::ris ALIAS lhris)

if (IKJM4C_BUILD_EXAMPLE)
    add_subdirectory(example)
endif ()