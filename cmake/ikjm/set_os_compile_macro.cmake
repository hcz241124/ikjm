# 定义一个函数来判断操作系统并设置自定义编译宏
function(ikjm_set_os_compile_macro target)
    if(WIN32)
        # 如果是 Windows 系统，设置自定义编译宏 WINDOWS_BUILD
        message(STATUS "Building ${target} with windows")
        target_compile_definitions(${target} PRIVATE -DWINDOWS_BUILD)
    elseif(APPLE)
        # 如果是苹果系统，设置自定义编译宏 APPLE_BUILD
        message(STATUS "Building ${target} with MacOS")
        target_compile_definitions(${target} PRIVATE -DMACOS_BUILD)
    elseif(UNIX)
        # 如果是类 Unix 系统，设置自定义编译宏 UNIX_BUILD
        message(STATUS "Building ${target} with *UNIX")
        target_compile_definitions(${target} PRIVATE -DUNIX_BUILD)
    endif()
endfunction()