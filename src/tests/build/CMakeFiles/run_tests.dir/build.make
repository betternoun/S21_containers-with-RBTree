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
include CMakeFiles/run_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_tests.dir/flags.make

CMakeFiles/run_tests.dir/containers/test_list.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containers/test_list.cpp.o: /root/project/tests/containers/test_list.cpp
CMakeFiles/run_tests.dir/containers/test_list.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_tests.dir/containers/test_list.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containers/test_list.cpp.o -MF CMakeFiles/run_tests.dir/containers/test_list.cpp.o.d -o CMakeFiles/run_tests.dir/containers/test_list.cpp.o -c /root/project/tests/containers/test_list.cpp

CMakeFiles/run_tests.dir/containers/test_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containers/test_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containers/test_list.cpp > CMakeFiles/run_tests.dir/containers/test_list.cpp.i

CMakeFiles/run_tests.dir/containers/test_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containers/test_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containers/test_list.cpp -o CMakeFiles/run_tests.dir/containers/test_list.cpp.s

CMakeFiles/run_tests.dir/containers/test_map.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containers/test_map.cpp.o: /root/project/tests/containers/test_map.cpp
CMakeFiles/run_tests.dir/containers/test_map.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_tests.dir/containers/test_map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containers/test_map.cpp.o -MF CMakeFiles/run_tests.dir/containers/test_map.cpp.o.d -o CMakeFiles/run_tests.dir/containers/test_map.cpp.o -c /root/project/tests/containers/test_map.cpp

CMakeFiles/run_tests.dir/containers/test_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containers/test_map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containers/test_map.cpp > CMakeFiles/run_tests.dir/containers/test_map.cpp.i

CMakeFiles/run_tests.dir/containers/test_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containers/test_map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containers/test_map.cpp -o CMakeFiles/run_tests.dir/containers/test_map.cpp.s

CMakeFiles/run_tests.dir/containers/test_queue.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containers/test_queue.cpp.o: /root/project/tests/containers/test_queue.cpp
CMakeFiles/run_tests.dir/containers/test_queue.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run_tests.dir/containers/test_queue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containers/test_queue.cpp.o -MF CMakeFiles/run_tests.dir/containers/test_queue.cpp.o.d -o CMakeFiles/run_tests.dir/containers/test_queue.cpp.o -c /root/project/tests/containers/test_queue.cpp

CMakeFiles/run_tests.dir/containers/test_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containers/test_queue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containers/test_queue.cpp > CMakeFiles/run_tests.dir/containers/test_queue.cpp.i

CMakeFiles/run_tests.dir/containers/test_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containers/test_queue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containers/test_queue.cpp -o CMakeFiles/run_tests.dir/containers/test_queue.cpp.s

CMakeFiles/run_tests.dir/containers/test_set.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containers/test_set.cpp.o: /root/project/tests/containers/test_set.cpp
CMakeFiles/run_tests.dir/containers/test_set.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/run_tests.dir/containers/test_set.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containers/test_set.cpp.o -MF CMakeFiles/run_tests.dir/containers/test_set.cpp.o.d -o CMakeFiles/run_tests.dir/containers/test_set.cpp.o -c /root/project/tests/containers/test_set.cpp

CMakeFiles/run_tests.dir/containers/test_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containers/test_set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containers/test_set.cpp > CMakeFiles/run_tests.dir/containers/test_set.cpp.i

CMakeFiles/run_tests.dir/containers/test_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containers/test_set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containers/test_set.cpp -o CMakeFiles/run_tests.dir/containers/test_set.cpp.s

CMakeFiles/run_tests.dir/containers/test_stack.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containers/test_stack.cpp.o: /root/project/tests/containers/test_stack.cpp
CMakeFiles/run_tests.dir/containers/test_stack.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/run_tests.dir/containers/test_stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containers/test_stack.cpp.o -MF CMakeFiles/run_tests.dir/containers/test_stack.cpp.o.d -o CMakeFiles/run_tests.dir/containers/test_stack.cpp.o -c /root/project/tests/containers/test_stack.cpp

CMakeFiles/run_tests.dir/containers/test_stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containers/test_stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containers/test_stack.cpp > CMakeFiles/run_tests.dir/containers/test_stack.cpp.i

CMakeFiles/run_tests.dir/containers/test_stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containers/test_stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containers/test_stack.cpp -o CMakeFiles/run_tests.dir/containers/test_stack.cpp.s

CMakeFiles/run_tests.dir/containers/test_tree.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containers/test_tree.cpp.o: /root/project/tests/containers/test_tree.cpp
CMakeFiles/run_tests.dir/containers/test_tree.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/run_tests.dir/containers/test_tree.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containers/test_tree.cpp.o -MF CMakeFiles/run_tests.dir/containers/test_tree.cpp.o.d -o CMakeFiles/run_tests.dir/containers/test_tree.cpp.o -c /root/project/tests/containers/test_tree.cpp

CMakeFiles/run_tests.dir/containers/test_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containers/test_tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containers/test_tree.cpp > CMakeFiles/run_tests.dir/containers/test_tree.cpp.i

CMakeFiles/run_tests.dir/containers/test_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containers/test_tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containers/test_tree.cpp -o CMakeFiles/run_tests.dir/containers/test_tree.cpp.s

CMakeFiles/run_tests.dir/containers/test_vector.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containers/test_vector.cpp.o: /root/project/tests/containers/test_vector.cpp
CMakeFiles/run_tests.dir/containers/test_vector.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/run_tests.dir/containers/test_vector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containers/test_vector.cpp.o -MF CMakeFiles/run_tests.dir/containers/test_vector.cpp.o.d -o CMakeFiles/run_tests.dir/containers/test_vector.cpp.o -c /root/project/tests/containers/test_vector.cpp

CMakeFiles/run_tests.dir/containers/test_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containers/test_vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containers/test_vector.cpp > CMakeFiles/run_tests.dir/containers/test_vector.cpp.i

CMakeFiles/run_tests.dir/containers/test_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containers/test_vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containers/test_vector.cpp -o CMakeFiles/run_tests.dir/containers/test_vector.cpp.s

CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o: /root/project/tests/containersplus/test_array.cpp
CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o -MF CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o.d -o CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o -c /root/project/tests/containersplus/test_array.cpp

CMakeFiles/run_tests.dir/containersplus/test_array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containersplus/test_array.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containersplus/test_array.cpp > CMakeFiles/run_tests.dir/containersplus/test_array.cpp.i

CMakeFiles/run_tests.dir/containersplus/test_array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containersplus/test_array.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containersplus/test_array.cpp -o CMakeFiles/run_tests.dir/containersplus/test_array.cpp.s

CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o: /root/project/tests/containersplus/test_multiset.cpp
CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o -MF CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o.d -o CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o -c /root/project/tests/containersplus/test_multiset.cpp

CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/project/tests/containersplus/test_multiset.cpp > CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.i

CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/project/tests/containersplus/test_multiset.cpp -o CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.s

# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/containers/test_list.cpp.o" \
"CMakeFiles/run_tests.dir/containers/test_map.cpp.o" \
"CMakeFiles/run_tests.dir/containers/test_queue.cpp.o" \
"CMakeFiles/run_tests.dir/containers/test_set.cpp.o" \
"CMakeFiles/run_tests.dir/containers/test_stack.cpp.o" \
"CMakeFiles/run_tests.dir/containers/test_tree.cpp.o" \
"CMakeFiles/run_tests.dir/containers/test_vector.cpp.o" \
"CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o" \
"CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

run_tests: CMakeFiles/run_tests.dir/containers/test_list.cpp.o
run_tests: CMakeFiles/run_tests.dir/containers/test_map.cpp.o
run_tests: CMakeFiles/run_tests.dir/containers/test_queue.cpp.o
run_tests: CMakeFiles/run_tests.dir/containers/test_set.cpp.o
run_tests: CMakeFiles/run_tests.dir/containers/test_stack.cpp.o
run_tests: CMakeFiles/run_tests.dir/containers/test_tree.cpp.o
run_tests: CMakeFiles/run_tests.dir/containers/test_vector.cpp.o
run_tests: CMakeFiles/run_tests.dir/containersplus/test_array.cpp.o
run_tests: CMakeFiles/run_tests.dir/containersplus/test_multiset.cpp.o
run_tests: CMakeFiles/run_tests.dir/build.make
run_tests: libs21_containers.a
run_tests: /usr/lib/x86_64-linux-gnu/libgtest_main.a
run_tests: /usr/lib/x86_64-linux-gnu/libgtest.a
run_tests: CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/root/project/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable run_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_tests.dir/build: run_tests
.PHONY : CMakeFiles/run_tests.dir/build

CMakeFiles/run_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_tests.dir/clean

CMakeFiles/run_tests.dir/depend:
	cd /root/project/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/project/tests /root/project/tests /root/project/tests/build /root/project/tests/build /root/project/tests/build/CMakeFiles/run_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/run_tests.dir/depend

