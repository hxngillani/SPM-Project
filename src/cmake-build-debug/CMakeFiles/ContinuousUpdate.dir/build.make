# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /cygdrive/c/Users/chris/AppData/Local/JetBrains/CLion2021.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/chris/AppData/Local/JetBrains/CLion2021.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ/cmake-build-debug

# Utility rule file for ContinuousUpdate.

# Include any custom commands dependencies for this target.
include CMakeFiles/ContinuousUpdate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ContinuousUpdate.dir/progress.make

CMakeFiles/ContinuousUpdate:
	/cygdrive/c/Users/chris/AppData/Local/JetBrains/CLion2021.3/cygwin_cmake/bin/ctest.exe -D ContinuousUpdate

ContinuousUpdate: CMakeFiles/ContinuousUpdate
ContinuousUpdate: CMakeFiles/ContinuousUpdate.dir/build.make
.PHONY : ContinuousUpdate

# Rule to build all files generated by this target.
CMakeFiles/ContinuousUpdate.dir/build: ContinuousUpdate
.PHONY : CMakeFiles/ContinuousUpdate.dir/build

CMakeFiles/ContinuousUpdate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuousUpdate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousUpdate.dir/clean

CMakeFiles/ContinuousUpdate.dir/depend:
	cd /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ/cmake-build-debug /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ/cmake-build-debug /cygdrive/c/Users/chris/Documents/SPM/Jacobi_PRJ/cmake-build-debug/CMakeFiles/ContinuousUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousUpdate.dir/depend

