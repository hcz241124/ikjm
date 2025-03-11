## macos

查看导出函数符号

```zsh
nm -gU /path/to/lib
# macOS 使用otool替代ldd
otool -L /path/to/lib
```