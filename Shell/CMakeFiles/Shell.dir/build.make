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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ahmed/Linux-Command-Interpreter/Shell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ahmed/Linux-Command-Interpreter/Shell

# Include any dependencies generated for this target.
include CMakeFiles/Shell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Shell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shell.dir/flags.make

CMakeFiles/Shell.dir/main.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/main.c.o: main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/main.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/main.c

CMakeFiles/Shell.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/main.c > CMakeFiles/Shell.dir/main.c.i

CMakeFiles/Shell.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/main.c -o CMakeFiles/Shell.dir/main.c.s

CMakeFiles/Shell.dir/main.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/main.c.o.requires

CMakeFiles/Shell.dir/main.c.o.provides: CMakeFiles/Shell.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/main.c.o.provides

CMakeFiles/Shell.dir/main.c.o.provides.build: CMakeFiles/Shell.dir/main.c.o

CMakeFiles/Shell.dir/ShellController.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/ShellController.c.o: ShellController.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/ShellController.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/ShellController.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/ShellController.c

CMakeFiles/Shell.dir/ShellController.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/ShellController.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/ShellController.c > CMakeFiles/Shell.dir/ShellController.c.i

CMakeFiles/Shell.dir/ShellController.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/ShellController.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/ShellController.c -o CMakeFiles/Shell.dir/ShellController.c.s

CMakeFiles/Shell.dir/ShellController.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/ShellController.c.o.requires

CMakeFiles/Shell.dir/ShellController.c.o.provides: CMakeFiles/Shell.dir/ShellController.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/ShellController.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/ShellController.c.o.provides

CMakeFiles/Shell.dir/ShellController.c.o.provides.build: CMakeFiles/Shell.dir/ShellController.c.o

CMakeFiles/Shell.dir/command_parser.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/command_parser.c.o: command_parser.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/command_parser.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/command_parser.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/command_parser.c

CMakeFiles/Shell.dir/command_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/command_parser.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/command_parser.c > CMakeFiles/Shell.dir/command_parser.c.i

CMakeFiles/Shell.dir/command_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/command_parser.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/command_parser.c -o CMakeFiles/Shell.dir/command_parser.c.s

CMakeFiles/Shell.dir/command_parser.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/command_parser.c.o.requires

CMakeFiles/Shell.dir/command_parser.c.o.provides: CMakeFiles/Shell.dir/command_parser.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/command_parser.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/command_parser.c.o.provides

CMakeFiles/Shell.dir/command_parser.c.o.provides.build: CMakeFiles/Shell.dir/command_parser.c.o

CMakeFiles/Shell.dir/command_utils.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/command_utils.c.o: command_utils.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/command_utils.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/command_utils.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/command_utils.c

CMakeFiles/Shell.dir/command_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/command_utils.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/command_utils.c > CMakeFiles/Shell.dir/command_utils.c.i

CMakeFiles/Shell.dir/command_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/command_utils.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/command_utils.c -o CMakeFiles/Shell.dir/command_utils.c.s

CMakeFiles/Shell.dir/command_utils.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/command_utils.c.o.requires

CMakeFiles/Shell.dir/command_utils.c.o.provides: CMakeFiles/Shell.dir/command_utils.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/command_utils.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/command_utils.c.o.provides

CMakeFiles/Shell.dir/command_utils.c.o.provides.build: CMakeFiles/Shell.dir/command_utils.c.o

CMakeFiles/Shell.dir/commands.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/commands.c.o: commands.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/commands.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/commands.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/commands.c

CMakeFiles/Shell.dir/commands.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/commands.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/commands.c > CMakeFiles/Shell.dir/commands.c.i

CMakeFiles/Shell.dir/commands.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/commands.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/commands.c -o CMakeFiles/Shell.dir/commands.c.s

CMakeFiles/Shell.dir/commands.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/commands.c.o.requires

CMakeFiles/Shell.dir/commands.c.o.provides: CMakeFiles/Shell.dir/commands.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/commands.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/commands.c.o.provides

CMakeFiles/Shell.dir/commands.c.o.provides.build: CMakeFiles/Shell.dir/commands.c.o

CMakeFiles/Shell.dir/environment.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/environment.c.o: environment.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/environment.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/environment.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/environment.c

CMakeFiles/Shell.dir/environment.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/environment.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/environment.c > CMakeFiles/Shell.dir/environment.c.i

CMakeFiles/Shell.dir/environment.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/environment.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/environment.c -o CMakeFiles/Shell.dir/environment.c.s

CMakeFiles/Shell.dir/environment.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/environment.c.o.requires

CMakeFiles/Shell.dir/environment.c.o.provides: CMakeFiles/Shell.dir/environment.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/environment.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/environment.c.o.provides

CMakeFiles/Shell.dir/environment.c.o.provides.build: CMakeFiles/Shell.dir/environment.c.o

CMakeFiles/Shell.dir/file_service.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/file_service.c.o: file_service.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/file_service.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/file_service.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/file_service.c

CMakeFiles/Shell.dir/file_service.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/file_service.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/file_service.c > CMakeFiles/Shell.dir/file_service.c.i

CMakeFiles/Shell.dir/file_service.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/file_service.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/file_service.c -o CMakeFiles/Shell.dir/file_service.c.s

CMakeFiles/Shell.dir/file_service.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/file_service.c.o.requires

CMakeFiles/Shell.dir/file_service.c.o.provides: CMakeFiles/Shell.dir/file_service.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/file_service.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/file_service.c.o.provides

CMakeFiles/Shell.dir/file_service.c.o.provides.build: CMakeFiles/Shell.dir/file_service.c.o

CMakeFiles/Shell.dir/logger.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/logger.c.o: logger.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/logger.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/logger.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/logger.c

CMakeFiles/Shell.dir/logger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/logger.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/logger.c > CMakeFiles/Shell.dir/logger.c.i

CMakeFiles/Shell.dir/logger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/logger.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/logger.c -o CMakeFiles/Shell.dir/logger.c.s

CMakeFiles/Shell.dir/logger.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/logger.c.o.requires

CMakeFiles/Shell.dir/logger.c.o.provides: CMakeFiles/Shell.dir/logger.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/logger.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/logger.c.o.provides

CMakeFiles/Shell.dir/logger.c.o.provides.build: CMakeFiles/Shell.dir/logger.c.o

CMakeFiles/Shell.dir/tokenizer.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/tokenizer.c.o: tokenizer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/tokenizer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/tokenizer.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/tokenizer.c

CMakeFiles/Shell.dir/tokenizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/tokenizer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/tokenizer.c > CMakeFiles/Shell.dir/tokenizer.c.i

CMakeFiles/Shell.dir/tokenizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/tokenizer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/tokenizer.c -o CMakeFiles/Shell.dir/tokenizer.c.s

CMakeFiles/Shell.dir/tokenizer.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/tokenizer.c.o.requires

CMakeFiles/Shell.dir/tokenizer.c.o.provides: CMakeFiles/Shell.dir/tokenizer.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/tokenizer.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/tokenizer.c.o.provides

CMakeFiles/Shell.dir/tokenizer.c.o.provides.build: CMakeFiles/Shell.dir/tokenizer.c.o

CMakeFiles/Shell.dir/variables.c.o: CMakeFiles/Shell.dir/flags.make
CMakeFiles/Shell.dir/variables.c.o: variables.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/Shell.dir/variables.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/Shell.dir/variables.c.o   -c /home/ahmed/Linux-Command-Interpreter/Shell/variables.c

CMakeFiles/Shell.dir/variables.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Shell.dir/variables.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ahmed/Linux-Command-Interpreter/Shell/variables.c > CMakeFiles/Shell.dir/variables.c.i

CMakeFiles/Shell.dir/variables.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Shell.dir/variables.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ahmed/Linux-Command-Interpreter/Shell/variables.c -o CMakeFiles/Shell.dir/variables.c.s

CMakeFiles/Shell.dir/variables.c.o.requires:
.PHONY : CMakeFiles/Shell.dir/variables.c.o.requires

CMakeFiles/Shell.dir/variables.c.o.provides: CMakeFiles/Shell.dir/variables.c.o.requires
	$(MAKE) -f CMakeFiles/Shell.dir/build.make CMakeFiles/Shell.dir/variables.c.o.provides.build
.PHONY : CMakeFiles/Shell.dir/variables.c.o.provides

CMakeFiles/Shell.dir/variables.c.o.provides.build: CMakeFiles/Shell.dir/variables.c.o

# Object files for target Shell
Shell_OBJECTS = \
"CMakeFiles/Shell.dir/main.c.o" \
"CMakeFiles/Shell.dir/ShellController.c.o" \
"CMakeFiles/Shell.dir/command_parser.c.o" \
"CMakeFiles/Shell.dir/command_utils.c.o" \
"CMakeFiles/Shell.dir/commands.c.o" \
"CMakeFiles/Shell.dir/environment.c.o" \
"CMakeFiles/Shell.dir/file_service.c.o" \
"CMakeFiles/Shell.dir/logger.c.o" \
"CMakeFiles/Shell.dir/tokenizer.c.o" \
"CMakeFiles/Shell.dir/variables.c.o"

# External object files for target Shell
Shell_EXTERNAL_OBJECTS =

Shell: CMakeFiles/Shell.dir/main.c.o
Shell: CMakeFiles/Shell.dir/ShellController.c.o
Shell: CMakeFiles/Shell.dir/command_parser.c.o
Shell: CMakeFiles/Shell.dir/command_utils.c.o
Shell: CMakeFiles/Shell.dir/commands.c.o
Shell: CMakeFiles/Shell.dir/environment.c.o
Shell: CMakeFiles/Shell.dir/file_service.c.o
Shell: CMakeFiles/Shell.dir/logger.c.o
Shell: CMakeFiles/Shell.dir/tokenizer.c.o
Shell: CMakeFiles/Shell.dir/variables.c.o
Shell: CMakeFiles/Shell.dir/build.make
Shell: CMakeFiles/Shell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable Shell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shell.dir/build: Shell
.PHONY : CMakeFiles/Shell.dir/build

CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/main.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/ShellController.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/command_parser.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/command_utils.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/commands.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/environment.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/file_service.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/logger.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/tokenizer.c.o.requires
CMakeFiles/Shell.dir/requires: CMakeFiles/Shell.dir/variables.c.o.requires
.PHONY : CMakeFiles/Shell.dir/requires

CMakeFiles/Shell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Shell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Shell.dir/clean

CMakeFiles/Shell.dir/depend:
	cd /home/ahmed/Linux-Command-Interpreter/Shell && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ahmed/Linux-Command-Interpreter/Shell /home/ahmed/Linux-Command-Interpreter/Shell /home/ahmed/Linux-Command-Interpreter/Shell /home/ahmed/Linux-Command-Interpreter/Shell /home/ahmed/Linux-Command-Interpreter/Shell/CMakeFiles/Shell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Shell.dir/depend

