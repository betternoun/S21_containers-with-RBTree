# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/project/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/project/tests/build

# Include any dependencies generated for this target.
include CMakeFiles/s21_containers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/s21_containers.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/s21_containers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/s21_containers.dir/flags.make

# Object files for target s21_containers
s21_containers_OBJECTS =

# External object files for target s21_containers
s21_containers_EXTERNAL_OBJECTS =

libs21_containers.a: CMakeFiles/s21_containers.dir/build.make
libs21_containers.a: CMakeFiles/s21_containers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libs21_containers.a"
	$(CMAKE_COMMAND) -P CMakeFiles/s21_containers.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/s21_containers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/s21_containers.dir/build: libs21_containers.a
.PHONY : CMakeFiles/s21_containers.dir/build

CMakeFiles/s21_containers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/s21_containers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/s21_containers.dir/clean

CMakeFiles/s21_containers.dir/depend:
	cd /root/project/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/project/tests /root/project/tests /root/project/tests/build /root/project/tests/build /root/project/tests/build/CMakeFiles/s21_containers.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/s21_containers.dir/depend

