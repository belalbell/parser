# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mazen/CLionProjects/parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mazen/CLionProjects/parser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Parser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Parser.dir/flags.make

CMakeFiles/Parser.dir/main.cpp.o: CMakeFiles/Parser.dir/flags.make
CMakeFiles/Parser.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mazen/CLionProjects/parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Parser.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Parser.dir/main.cpp.o -c /home/mazen/CLionProjects/parser/main.cpp

CMakeFiles/Parser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parser.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mazen/CLionProjects/parser/main.cpp > CMakeFiles/Parser.dir/main.cpp.i

CMakeFiles/Parser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parser.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mazen/CLionProjects/parser/main.cpp -o CMakeFiles/Parser.dir/main.cpp.s

CMakeFiles/Parser.dir/InputHandler.cpp.o: CMakeFiles/Parser.dir/flags.make
CMakeFiles/Parser.dir/InputHandler.cpp.o: ../InputHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mazen/CLionProjects/parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Parser.dir/InputHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Parser.dir/InputHandler.cpp.o -c /home/mazen/CLionProjects/parser/InputHandler.cpp

CMakeFiles/Parser.dir/InputHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parser.dir/InputHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mazen/CLionProjects/parser/InputHandler.cpp > CMakeFiles/Parser.dir/InputHandler.cpp.i

CMakeFiles/Parser.dir/InputHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parser.dir/InputHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mazen/CLionProjects/parser/InputHandler.cpp -o CMakeFiles/Parser.dir/InputHandler.cpp.s

CMakeFiles/Parser.dir/parsing.cpp.o: CMakeFiles/Parser.dir/flags.make
CMakeFiles/Parser.dir/parsing.cpp.o: ../parsing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mazen/CLionProjects/parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Parser.dir/parsing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Parser.dir/parsing.cpp.o -c /home/mazen/CLionProjects/parser/parsing.cpp

CMakeFiles/Parser.dir/parsing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parser.dir/parsing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mazen/CLionProjects/parser/parsing.cpp > CMakeFiles/Parser.dir/parsing.cpp.i

CMakeFiles/Parser.dir/parsing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parser.dir/parsing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mazen/CLionProjects/parser/parsing.cpp -o CMakeFiles/Parser.dir/parsing.cpp.s

CMakeFiles/Parser.dir/Save_Load.cpp.o: CMakeFiles/Parser.dir/flags.make
CMakeFiles/Parser.dir/Save_Load.cpp.o: ../Save_Load.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mazen/CLionProjects/parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Parser.dir/Save_Load.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Parser.dir/Save_Load.cpp.o -c /home/mazen/CLionProjects/parser/Save_Load.cpp

CMakeFiles/Parser.dir/Save_Load.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parser.dir/Save_Load.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mazen/CLionProjects/parser/Save_Load.cpp > CMakeFiles/Parser.dir/Save_Load.cpp.i

CMakeFiles/Parser.dir/Save_Load.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parser.dir/Save_Load.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mazen/CLionProjects/parser/Save_Load.cpp -o CMakeFiles/Parser.dir/Save_Load.cpp.s

# Object files for target Parser
Parser_OBJECTS = \
"CMakeFiles/Parser.dir/main.cpp.o" \
"CMakeFiles/Parser.dir/InputHandler.cpp.o" \
"CMakeFiles/Parser.dir/parsing.cpp.o" \
"CMakeFiles/Parser.dir/Save_Load.cpp.o"

# External object files for target Parser
Parser_EXTERNAL_OBJECTS =

Parser: CMakeFiles/Parser.dir/main.cpp.o
Parser: CMakeFiles/Parser.dir/InputHandler.cpp.o
Parser: CMakeFiles/Parser.dir/parsing.cpp.o
Parser: CMakeFiles/Parser.dir/Save_Load.cpp.o
Parser: CMakeFiles/Parser.dir/build.make
Parser: CMakeFiles/Parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mazen/CLionProjects/parser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Parser.dir/build: Parser

.PHONY : CMakeFiles/Parser.dir/build

CMakeFiles/Parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Parser.dir/clean

CMakeFiles/Parser.dir/depend:
	cd /home/mazen/CLionProjects/parser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mazen/CLionProjects/parser /home/mazen/CLionProjects/parser /home/mazen/CLionProjects/parser/cmake-build-debug /home/mazen/CLionProjects/parser/cmake-build-debug /home/mazen/CLionProjects/parser/cmake-build-debug/CMakeFiles/Parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Parser.dir/depend

