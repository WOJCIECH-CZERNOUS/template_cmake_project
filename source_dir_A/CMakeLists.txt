add_library(library_A source_file_a.cpp)

target_include_directories(library_A
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(library_A this_project_compiler_flags)
