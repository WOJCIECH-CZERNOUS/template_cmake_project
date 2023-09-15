add_library(library_B source_file_b.cpp)

target_include_directories(library_B 
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )

target_link_libraries(library_B this_project_compiler_flags library_A)

#add_library(archive archive.cpp zip.cpp lzma.cpp)
#add_executable(zipapp zipapp.cpp)
#target_link_libraries(zipapp archive)
