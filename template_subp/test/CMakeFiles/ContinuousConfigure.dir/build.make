# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/santiago/git-repositories/collections

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/santiago/git-repositories/collections

# Utility rule file for ContinuousConfigure.

# Include the progress variables for this target.
include array/test/CMakeFiles/ContinuousConfigure.dir/progress.make

array/test/CMakeFiles/ContinuousConfigure:
	cd /home/santiago/git-repositories/collections/array/test && /usr/bin/ctest -D ContinuousConfigure

ContinuousConfigure: array/test/CMakeFiles/ContinuousConfigure
ContinuousConfigure: array/test/CMakeFiles/ContinuousConfigure.dir/build.make
.PHONY : ContinuousConfigure

# Rule to build all files generated by this target.
array/test/CMakeFiles/ContinuousConfigure.dir/build: ContinuousConfigure
.PHONY : array/test/CMakeFiles/ContinuousConfigure.dir/build

array/test/CMakeFiles/ContinuousConfigure.dir/clean:
	cd /home/santiago/git-repositories/collections/array/test && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousConfigure.dir/cmake_clean.cmake
.PHONY : array/test/CMakeFiles/ContinuousConfigure.dir/clean

array/test/CMakeFiles/ContinuousConfigure.dir/depend:
	cd /home/santiago/git-repositories/collections && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/santiago/git-repositories/collections /home/santiago/git-repositories/collections/array/test /home/santiago/git-repositories/collections /home/santiago/git-repositories/collections/array/test /home/santiago/git-repositories/collections/array/test/CMakeFiles/ContinuousConfigure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : array/test/CMakeFiles/ContinuousConfigure.dir/depend
