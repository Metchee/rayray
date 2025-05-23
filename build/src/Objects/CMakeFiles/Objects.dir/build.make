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
CMAKE_SOURCE_DIR = /home/gabinrudigoz/raytracer/rayray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabinrudigoz/raytracer/rayray/build

# Include any dependencies generated for this target.
include src/Objects/CMakeFiles/Objects.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Objects/CMakeFiles/Objects.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Objects/CMakeFiles/Objects.dir/progress.make

# Include the compile flags for this target's objects.
include src/Objects/CMakeFiles/Objects.dir/flags.make

src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.o: src/Objects/CMakeFiles/Objects.dir/flags.make
src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.o: /home/gabinrudigoz/raytracer/rayray/src/Objects/sphereObj.cpp
src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.o: src/Objects/CMakeFiles/Objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gabinrudigoz/raytracer/rayray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.o"
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.o -MF CMakeFiles/Objects.dir/sphereObj.cpp.o.d -o CMakeFiles/Objects.dir/sphereObj.cpp.o -c /home/gabinrudigoz/raytracer/rayray/src/Objects/sphereObj.cpp

src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Objects.dir/sphereObj.cpp.i"
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabinrudigoz/raytracer/rayray/src/Objects/sphereObj.cpp > CMakeFiles/Objects.dir/sphereObj.cpp.i

src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Objects.dir/sphereObj.cpp.s"
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabinrudigoz/raytracer/rayray/src/Objects/sphereObj.cpp -o CMakeFiles/Objects.dir/sphereObj.cpp.s

src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.o: src/Objects/CMakeFiles/Objects.dir/flags.make
src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.o: /home/gabinrudigoz/raytracer/rayray/src/Objects/planeObj.cpp
src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.o: src/Objects/CMakeFiles/Objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gabinrudigoz/raytracer/rayray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.o"
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.o -MF CMakeFiles/Objects.dir/planeObj.cpp.o.d -o CMakeFiles/Objects.dir/planeObj.cpp.o -c /home/gabinrudigoz/raytracer/rayray/src/Objects/planeObj.cpp

src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Objects.dir/planeObj.cpp.i"
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gabinrudigoz/raytracer/rayray/src/Objects/planeObj.cpp > CMakeFiles/Objects.dir/planeObj.cpp.i

src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Objects.dir/planeObj.cpp.s"
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gabinrudigoz/raytracer/rayray/src/Objects/planeObj.cpp -o CMakeFiles/Objects.dir/planeObj.cpp.s

# Object files for target Objects
Objects_OBJECTS = \
"CMakeFiles/Objects.dir/sphereObj.cpp.o" \
"CMakeFiles/Objects.dir/planeObj.cpp.o"

# External object files for target Objects
Objects_EXTERNAL_OBJECTS =

src/Objects/libObjects.a: src/Objects/CMakeFiles/Objects.dir/sphereObj.cpp.o
src/Objects/libObjects.a: src/Objects/CMakeFiles/Objects.dir/planeObj.cpp.o
src/Objects/libObjects.a: src/Objects/CMakeFiles/Objects.dir/build.make
src/Objects/libObjects.a: src/Objects/CMakeFiles/Objects.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/gabinrudigoz/raytracer/rayray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libObjects.a"
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && $(CMAKE_COMMAND) -P CMakeFiles/Objects.dir/cmake_clean_target.cmake
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Objects.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Objects/CMakeFiles/Objects.dir/build: src/Objects/libObjects.a
.PHONY : src/Objects/CMakeFiles/Objects.dir/build

src/Objects/CMakeFiles/Objects.dir/clean:
	cd /home/gabinrudigoz/raytracer/rayray/build/src/Objects && $(CMAKE_COMMAND) -P CMakeFiles/Objects.dir/cmake_clean.cmake
.PHONY : src/Objects/CMakeFiles/Objects.dir/clean

src/Objects/CMakeFiles/Objects.dir/depend:
	cd /home/gabinrudigoz/raytracer/rayray/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gabinrudigoz/raytracer/rayray /home/gabinrudigoz/raytracer/rayray/src/Objects /home/gabinrudigoz/raytracer/rayray/build /home/gabinrudigoz/raytracer/rayray/build/src/Objects /home/gabinrudigoz/raytracer/rayray/build/src/Objects/CMakeFiles/Objects.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/Objects/CMakeFiles/Objects.dir/depend

