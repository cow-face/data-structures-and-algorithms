# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/135/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/135/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caden/compsci/data_structures/HW7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caden/compsci/data_structures/HW7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Homework_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Homework_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Homework_4.dir/flags.make

CMakeFiles/Homework_4.dir/hw4.cpp.o: CMakeFiles/Homework_4.dir/flags.make
CMakeFiles/Homework_4.dir/hw4.cpp.o: ../hw4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caden/compsci/data_structures/HW7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Homework_4.dir/hw4.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework_4.dir/hw4.cpp.o -c /home/caden/compsci/data_structures/HW7/hw4.cpp

CMakeFiles/Homework_4.dir/hw4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework_4.dir/hw4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caden/compsci/data_structures/HW7/hw4.cpp > CMakeFiles/Homework_4.dir/hw4.cpp.i

CMakeFiles/Homework_4.dir/hw4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework_4.dir/hw4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caden/compsci/data_structures/HW7/hw4.cpp -o CMakeFiles/Homework_4.dir/hw4.cpp.s

CMakeFiles/Homework_4.dir/main.cpp.o: CMakeFiles/Homework_4.dir/flags.make
CMakeFiles/Homework_4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caden/compsci/data_structures/HW7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Homework_4.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework_4.dir/main.cpp.o -c /home/caden/compsci/data_structures/HW7/main.cpp

CMakeFiles/Homework_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework_4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caden/compsci/data_structures/HW7/main.cpp > CMakeFiles/Homework_4.dir/main.cpp.i

CMakeFiles/Homework_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework_4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caden/compsci/data_structures/HW7/main.cpp -o CMakeFiles/Homework_4.dir/main.cpp.s

CMakeFiles/Homework_4.dir/recursive.cpp.o: CMakeFiles/Homework_4.dir/flags.make
CMakeFiles/Homework_4.dir/recursive.cpp.o: ../recursive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caden/compsci/data_structures/HW7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Homework_4.dir/recursive.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework_4.dir/recursive.cpp.o -c /home/caden/compsci/data_structures/HW7/recursive.cpp

CMakeFiles/Homework_4.dir/recursive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework_4.dir/recursive.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caden/compsci/data_structures/HW7/recursive.cpp > CMakeFiles/Homework_4.dir/recursive.cpp.i

CMakeFiles/Homework_4.dir/recursive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework_4.dir/recursive.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caden/compsci/data_structures/HW7/recursive.cpp -o CMakeFiles/Homework_4.dir/recursive.cpp.s

CMakeFiles/Homework_4.dir/hw7.cpp.o: CMakeFiles/Homework_4.dir/flags.make
CMakeFiles/Homework_4.dir/hw7.cpp.o: ../hw7.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caden/compsci/data_structures/HW7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Homework_4.dir/hw7.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework_4.dir/hw7.cpp.o -c /home/caden/compsci/data_structures/HW7/hw7.cpp

CMakeFiles/Homework_4.dir/hw7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework_4.dir/hw7.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caden/compsci/data_structures/HW7/hw7.cpp > CMakeFiles/Homework_4.dir/hw7.cpp.i

CMakeFiles/Homework_4.dir/hw7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework_4.dir/hw7.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caden/compsci/data_structures/HW7/hw7.cpp -o CMakeFiles/Homework_4.dir/hw7.cpp.s

# Object files for target Homework_4
Homework_4_OBJECTS = \
"CMakeFiles/Homework_4.dir/hw4.cpp.o" \
"CMakeFiles/Homework_4.dir/main.cpp.o" \
"CMakeFiles/Homework_4.dir/recursive.cpp.o" \
"CMakeFiles/Homework_4.dir/hw7.cpp.o"

# External object files for target Homework_4
Homework_4_EXTERNAL_OBJECTS =

Homework_4: CMakeFiles/Homework_4.dir/hw4.cpp.o
Homework_4: CMakeFiles/Homework_4.dir/main.cpp.o
Homework_4: CMakeFiles/Homework_4.dir/recursive.cpp.o
Homework_4: CMakeFiles/Homework_4.dir/hw7.cpp.o
Homework_4: CMakeFiles/Homework_4.dir/build.make
Homework_4: CMakeFiles/Homework_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caden/compsci/data_structures/HW7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Homework_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Homework_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Homework_4.dir/build: Homework_4

.PHONY : CMakeFiles/Homework_4.dir/build

CMakeFiles/Homework_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Homework_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Homework_4.dir/clean

CMakeFiles/Homework_4.dir/depend:
	cd /home/caden/compsci/data_structures/HW7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caden/compsci/data_structures/HW7 /home/caden/compsci/data_structures/HW7 /home/caden/compsci/data_structures/HW7/cmake-build-debug /home/caden/compsci/data_structures/HW7/cmake-build-debug /home/caden/compsci/data_structures/HW7/cmake-build-debug/CMakeFiles/Homework_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Homework_4.dir/depend

