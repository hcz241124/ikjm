gen:
	cmake -Bbuild -S.
	cmake --build build --config RelWithDebInfo

gen_static:
	cmake -Bbuild_static -S. -DBUILD_SHARED_LIBS=OFF
	cmake  --build build_static --config RelWithDebInfo

gen_xcode:
	cmake -Bbuild_xcode -S. -G"Xcode"
	cmake --build build_xcode --config RelWithDebInfo

gen_vs2019:
	cmake -Bbuild_vs2019 -S -G""
	cmake --build build_vs2019 --config RelWithDebInfo

gen_mingw-w64:
	cmake -Bbuild_mingw-w64 -S. -DCMAKE_TOOLCHAIN_FILE:STRING=cmake/toolchains/mingw-toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE
	cmake --build build_mingw-w64 --config RelWithDebInfo

# CC  = /usr/local/bin/x86_64-w64-mingw32-gcc
# CXX = /usr/local/bin/x86_64-w64-mingw32-g++
# LDFLAGS  ?= 
# CFLAGS   ?= -Wall -Wextra  # C 编译器选项
# CXXFLAGS ?= -Wall -Wextra  # C++ 编译器选项

# # 源文件和目标文件
# LIB_SRCS     := $(wildcard source/*.c)       # C 源文件
# EXAMPLE_SRCS := $(wildcard example/*.c)       # C 源文件
# OBJS     := $(LIB_SRCS:.c=.o)              # 目标文件
# EXEC     := ikjm4c_example                  # 最终可执行文件名

# # 默认目标
# all: $(EXEC)

# # 链接目标
# $(EXEC): $(OBJS) $(EXAMPLE_SRCS)
# 	$(CC) -Iinclude $(LDFLAGS) -o $@ $^

# %.o: %.c
# 	$(CC) -Iinclude -DWINDOWS_BUILD -DIKJM4C_EXPORT_API $(CFLAGS) -c $< -o $@ 

.PHONY: gen gen_static gen_xcode gen_vs2019 gen_vs all 