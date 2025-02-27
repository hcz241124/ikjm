add_executable(ikjm4c_sample
    samplecode.c
)
target_link_libraries(ikjm4c_sample
PRIVATE
    hcz::ikjm4c
)
