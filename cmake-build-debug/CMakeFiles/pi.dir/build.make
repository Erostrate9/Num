# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\75912\Desktop\pi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\75912\Desktop\pi\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pi.dir/flags.make

CMakeFiles/pi.dir/main.c.obj: CMakeFiles/pi.dir/flags.make
CMakeFiles/pi.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75912\Desktop\pi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pi.dir/main.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pi.dir\main.c.obj   -c C:\Users\75912\Desktop\pi\main.c

CMakeFiles/pi.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pi.dir/main.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75912\Desktop\pi\main.c > CMakeFiles\pi.dir\main.c.i

CMakeFiles/pi.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pi.dir/main.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75912\Desktop\pi\main.c -o CMakeFiles\pi.dir\main.c.s

CMakeFiles/pi.dir/list.c.obj: CMakeFiles/pi.dir/flags.make
CMakeFiles/pi.dir/list.c.obj: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75912\Desktop\pi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/pi.dir/list.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pi.dir\list.c.obj   -c C:\Users\75912\Desktop\pi\list.c

CMakeFiles/pi.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pi.dir/list.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75912\Desktop\pi\list.c > CMakeFiles\pi.dir\list.c.i

CMakeFiles/pi.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pi.dir/list.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75912\Desktop\pi\list.c -o CMakeFiles\pi.dir\list.c.s

CMakeFiles/pi.dir/unsigned.c.obj: CMakeFiles/pi.dir/flags.make
CMakeFiles/pi.dir/unsigned.c.obj: ../unsigned.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75912\Desktop\pi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/pi.dir/unsigned.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pi.dir\unsigned.c.obj   -c C:\Users\75912\Desktop\pi\unsigned.c

CMakeFiles/pi.dir/unsigned.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pi.dir/unsigned.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75912\Desktop\pi\unsigned.c > CMakeFiles\pi.dir\unsigned.c.i

CMakeFiles/pi.dir/unsigned.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pi.dir/unsigned.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75912\Desktop\pi\unsigned.c -o CMakeFiles\pi.dir\unsigned.c.s

CMakeFiles/pi.dir/big_int.c.obj: CMakeFiles/pi.dir/flags.make
CMakeFiles/pi.dir/big_int.c.obj: ../big_int.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75912\Desktop\pi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/pi.dir/big_int.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pi.dir\big_int.c.obj   -c C:\Users\75912\Desktop\pi\big_int.c

CMakeFiles/pi.dir/big_int.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pi.dir/big_int.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75912\Desktop\pi\big_int.c > CMakeFiles\pi.dir\big_int.c.i

CMakeFiles/pi.dir/big_int.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pi.dir/big_int.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75912\Desktop\pi\big_int.c -o CMakeFiles\pi.dir\big_int.c.s

CMakeFiles/pi.dir/rational.c.obj: CMakeFiles/pi.dir/flags.make
CMakeFiles/pi.dir/rational.c.obj: ../rational.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75912\Desktop\pi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/pi.dir/rational.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\pi.dir\rational.c.obj   -c C:\Users\75912\Desktop\pi\rational.c

CMakeFiles/pi.dir/rational.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pi.dir/rational.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75912\Desktop\pi\rational.c > CMakeFiles\pi.dir\rational.c.i

CMakeFiles/pi.dir/rational.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pi.dir/rational.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75912\Desktop\pi\rational.c -o CMakeFiles\pi.dir\rational.c.s

# Object files for target pi
pi_OBJECTS = \
"CMakeFiles/pi.dir/main.c.obj" \
"CMakeFiles/pi.dir/list.c.obj" \
"CMakeFiles/pi.dir/unsigned.c.obj" \
"CMakeFiles/pi.dir/big_int.c.obj" \
"CMakeFiles/pi.dir/rational.c.obj"

# External object files for target pi
pi_EXTERNAL_OBJECTS =

pi.exe: CMakeFiles/pi.dir/main.c.obj
pi.exe: CMakeFiles/pi.dir/list.c.obj
pi.exe: CMakeFiles/pi.dir/unsigned.c.obj
pi.exe: CMakeFiles/pi.dir/big_int.c.obj
pi.exe: CMakeFiles/pi.dir/rational.c.obj
pi.exe: CMakeFiles/pi.dir/build.make
pi.exe: CMakeFiles/pi.dir/linklibs.rsp
pi.exe: CMakeFiles/pi.dir/objects1.rsp
pi.exe: CMakeFiles/pi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\75912\Desktop\pi\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable pi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pi.dir/build: pi.exe

.PHONY : CMakeFiles/pi.dir/build

CMakeFiles/pi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pi.dir/clean

CMakeFiles/pi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\75912\Desktop\pi C:\Users\75912\Desktop\pi C:\Users\75912\Desktop\pi\cmake-build-debug C:\Users\75912\Desktop\pi\cmake-build-debug C:\Users\75912\Desktop\pi\cmake-build-debug\CMakeFiles\pi.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pi.dir/depend

