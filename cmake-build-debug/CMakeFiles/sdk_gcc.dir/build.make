# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fuhongshuai/Downloads/sdk-gcc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sdk_gcc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sdk_gcc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sdk_gcc.dir/flags.make

CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o: CMakeFiles/sdk_gcc.dir/flags.make
CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o: ../ecs/ecs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o -c /Users/fuhongshuai/Downloads/sdk-gcc/ecs/ecs.cpp

CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fuhongshuai/Downloads/sdk-gcc/ecs/ecs.cpp > CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.i

CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fuhongshuai/Downloads/sdk-gcc/ecs/ecs.cpp -o CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.s

CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.requires:

.PHONY : CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.requires

CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.provides: CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdk_gcc.dir/build.make CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.provides.build
.PHONY : CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.provides

CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.provides.build: CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o


CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o: CMakeFiles/sdk_gcc.dir/flags.make
CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o: ../ecs/io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o -c /Users/fuhongshuai/Downloads/sdk-gcc/ecs/io.cpp

CMakeFiles/sdk_gcc.dir/ecs/io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdk_gcc.dir/ecs/io.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fuhongshuai/Downloads/sdk-gcc/ecs/io.cpp > CMakeFiles/sdk_gcc.dir/ecs/io.cpp.i

CMakeFiles/sdk_gcc.dir/ecs/io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdk_gcc.dir/ecs/io.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fuhongshuai/Downloads/sdk-gcc/ecs/io.cpp -o CMakeFiles/sdk_gcc.dir/ecs/io.cpp.s

CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.requires:

.PHONY : CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.requires

CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.provides: CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdk_gcc.dir/build.make CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.provides.build
.PHONY : CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.provides

CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.provides.build: CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o


CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o: CMakeFiles/sdk_gcc.dir/flags.make
CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o: ../ecs/LinearRegression.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o -c /Users/fuhongshuai/Downloads/sdk-gcc/ecs/LinearRegression.cpp

CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fuhongshuai/Downloads/sdk-gcc/ecs/LinearRegression.cpp > CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.i

CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fuhongshuai/Downloads/sdk-gcc/ecs/LinearRegression.cpp -o CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.s

CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.requires:

.PHONY : CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.requires

CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.provides: CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdk_gcc.dir/build.make CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.provides.build
.PHONY : CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.provides

CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.provides.build: CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o


CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o: CMakeFiles/sdk_gcc.dir/flags.make
CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o: ../ecs/predict.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o -c /Users/fuhongshuai/Downloads/sdk-gcc/ecs/predict.cpp

CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fuhongshuai/Downloads/sdk-gcc/ecs/predict.cpp > CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.i

CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fuhongshuai/Downloads/sdk-gcc/ecs/predict.cpp -o CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.s

CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.requires:

.PHONY : CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.requires

CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.provides: CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdk_gcc.dir/build.make CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.provides.build
.PHONY : CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.provides

CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.provides.build: CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o


CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o: CMakeFiles/sdk_gcc.dir/flags.make
CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o: ../ecs/Utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o -c /Users/fuhongshuai/Downloads/sdk-gcc/ecs/Utils.cpp

CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fuhongshuai/Downloads/sdk-gcc/ecs/Utils.cpp > CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.i

CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fuhongshuai/Downloads/sdk-gcc/ecs/Utils.cpp -o CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.s

CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.requires:

.PHONY : CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.requires

CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.provides: CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/sdk_gcc.dir/build.make CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.provides.build
.PHONY : CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.provides

CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.provides.build: CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o


# Object files for target sdk_gcc
sdk_gcc_OBJECTS = \
"CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o" \
"CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o" \
"CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o" \
"CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o" \
"CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o"

# External object files for target sdk_gcc
sdk_gcc_EXTERNAL_OBJECTS =

sdk_gcc: CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o
sdk_gcc: CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o
sdk_gcc: CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o
sdk_gcc: CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o
sdk_gcc: CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o
sdk_gcc: CMakeFiles/sdk_gcc.dir/build.make
sdk_gcc: CMakeFiles/sdk_gcc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable sdk_gcc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sdk_gcc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sdk_gcc.dir/build: sdk_gcc

.PHONY : CMakeFiles/sdk_gcc.dir/build

CMakeFiles/sdk_gcc.dir/requires: CMakeFiles/sdk_gcc.dir/ecs/ecs.cpp.o.requires
CMakeFiles/sdk_gcc.dir/requires: CMakeFiles/sdk_gcc.dir/ecs/io.cpp.o.requires
CMakeFiles/sdk_gcc.dir/requires: CMakeFiles/sdk_gcc.dir/ecs/LinearRegression.cpp.o.requires
CMakeFiles/sdk_gcc.dir/requires: CMakeFiles/sdk_gcc.dir/ecs/predict.cpp.o.requires
CMakeFiles/sdk_gcc.dir/requires: CMakeFiles/sdk_gcc.dir/ecs/Utils.cpp.o.requires

.PHONY : CMakeFiles/sdk_gcc.dir/requires

CMakeFiles/sdk_gcc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sdk_gcc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sdk_gcc.dir/clean

CMakeFiles/sdk_gcc.dir/depend:
	cd /Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fuhongshuai/Downloads/sdk-gcc /Users/fuhongshuai/Downloads/sdk-gcc /Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug /Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug /Users/fuhongshuai/Downloads/sdk-gcc/cmake-build-debug/CMakeFiles/sdk_gcc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sdk_gcc.dir/depend
