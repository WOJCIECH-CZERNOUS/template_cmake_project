# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(this_project VERSION 0.1.0)

add_library(this_project_compiler_flags INTERFACE)
target_compile_features(this_project_compiler_flags INTERFACE cxx_std_17)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(this_project_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

if(APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
elseif(UNIX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

# add libraries

add_subdirectory(source_dir_B)
add_subdirectory(source_dir_A)
list(APPEND EXTRA_LIBS library_B)
list(APPEND EXTRA_LIBS library_A)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/source_dir_B")
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/source_dir_A")

# add the executable
add_executable(ThisProject source_file_main.cpp)

target_link_libraries(ThisProject PUBLIC ${EXTRA_LIBS})
target_link_libraries(ThisProject PUBLIC this_project_compiler_flags)

# add to the search path, so that we will find .hpp
target_include_directories(ThisProject PUBLIC
  "${PROJECT_BINARY_DIR}"
  ${EXTRA_INCLUDES}
  )   

# add the install targets
install(TARGETS ThisProject DESTINATION bin)

# enable testing
enable_testing() 

# use a loop to simplify adding tests
foreach(arg RANGE 1 1)
 add_test(NAME test${arg} COMMAND ThisProject test${arg})
endforeach()

#set_tests_properties(test14 PROPERTIES PASS_REGULAR_EXPRESSION "Bets 10, 90 left. Lost. Bets 20, 70 left. Lost.")
