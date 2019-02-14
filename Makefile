# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/lumi/Programming/cpp/Discord++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lumi/Programming/cpp/Discord++

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lumi/Programming/cpp/Discord++/CMakeFiles /home/lumi/Programming/cpp/Discord++/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lumi/Programming/cpp/Discord++/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Discordpp

# Build rule for target.
Discordpp: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Discordpp
.PHONY : Discordpp

# fast build rule for target.
Discordpp/fast:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/build
.PHONY : Discordpp/fast

src/discordpp/Bot.o: src/discordpp/Bot.cpp.o

.PHONY : src/discordpp/Bot.o

# target to build an object file
src/discordpp/Bot.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Bot.cpp.o
.PHONY : src/discordpp/Bot.cpp.o

src/discordpp/Bot.i: src/discordpp/Bot.cpp.i

.PHONY : src/discordpp/Bot.i

# target to preprocess a source file
src/discordpp/Bot.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Bot.cpp.i
.PHONY : src/discordpp/Bot.cpp.i

src/discordpp/Bot.s: src/discordpp/Bot.cpp.s

.PHONY : src/discordpp/Bot.s

# target to generate assembly for a file
src/discordpp/Bot.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Bot.cpp.s
.PHONY : src/discordpp/Bot.cpp.s

src/discordpp/Gateway.o: src/discordpp/Gateway.cpp.o

.PHONY : src/discordpp/Gateway.o

# target to build an object file
src/discordpp/Gateway.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Gateway.cpp.o
.PHONY : src/discordpp/Gateway.cpp.o

src/discordpp/Gateway.i: src/discordpp/Gateway.cpp.i

.PHONY : src/discordpp/Gateway.i

# target to preprocess a source file
src/discordpp/Gateway.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Gateway.cpp.i
.PHONY : src/discordpp/Gateway.cpp.i

src/discordpp/Gateway.s: src/discordpp/Gateway.cpp.s

.PHONY : src/discordpp/Gateway.s

# target to generate assembly for a file
src/discordpp/Gateway.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Gateway.cpp.s
.PHONY : src/discordpp/Gateway.cpp.s

src/discordpp/Objects/Emoji.o: src/discordpp/Objects/Emoji.cpp.o

.PHONY : src/discordpp/Objects/Emoji.o

# target to build an object file
src/discordpp/Objects/Emoji.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Emoji.cpp.o
.PHONY : src/discordpp/Objects/Emoji.cpp.o

src/discordpp/Objects/Emoji.i: src/discordpp/Objects/Emoji.cpp.i

.PHONY : src/discordpp/Objects/Emoji.i

# target to preprocess a source file
src/discordpp/Objects/Emoji.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Emoji.cpp.i
.PHONY : src/discordpp/Objects/Emoji.cpp.i

src/discordpp/Objects/Emoji.s: src/discordpp/Objects/Emoji.cpp.s

.PHONY : src/discordpp/Objects/Emoji.s

# target to generate assembly for a file
src/discordpp/Objects/Emoji.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Emoji.cpp.s
.PHONY : src/discordpp/Objects/Emoji.cpp.s

src/discordpp/Objects/Guild.o: src/discordpp/Objects/Guild.cpp.o

.PHONY : src/discordpp/Objects/Guild.o

# target to build an object file
src/discordpp/Objects/Guild.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Guild.cpp.o
.PHONY : src/discordpp/Objects/Guild.cpp.o

src/discordpp/Objects/Guild.i: src/discordpp/Objects/Guild.cpp.i

.PHONY : src/discordpp/Objects/Guild.i

# target to preprocess a source file
src/discordpp/Objects/Guild.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Guild.cpp.i
.PHONY : src/discordpp/Objects/Guild.cpp.i

src/discordpp/Objects/Guild.s: src/discordpp/Objects/Guild.cpp.s

.PHONY : src/discordpp/Objects/Guild.s

# target to generate assembly for a file
src/discordpp/Objects/Guild.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Guild.cpp.s
.PHONY : src/discordpp/Objects/Guild.cpp.s

src/discordpp/Objects/Role.o: src/discordpp/Objects/Role.cpp.o

.PHONY : src/discordpp/Objects/Role.o

# target to build an object file
src/discordpp/Objects/Role.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Role.cpp.o
.PHONY : src/discordpp/Objects/Role.cpp.o

src/discordpp/Objects/Role.i: src/discordpp/Objects/Role.cpp.i

.PHONY : src/discordpp/Objects/Role.i

# target to preprocess a source file
src/discordpp/Objects/Role.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Role.cpp.i
.PHONY : src/discordpp/Objects/Role.cpp.i

src/discordpp/Objects/Role.s: src/discordpp/Objects/Role.cpp.s

.PHONY : src/discordpp/Objects/Role.s

# target to generate assembly for a file
src/discordpp/Objects/Role.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Role.cpp.s
.PHONY : src/discordpp/Objects/Role.cpp.s

src/discordpp/Objects/Snowflake.o: src/discordpp/Objects/Snowflake.cpp.o

.PHONY : src/discordpp/Objects/Snowflake.o

# target to build an object file
src/discordpp/Objects/Snowflake.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Snowflake.cpp.o
.PHONY : src/discordpp/Objects/Snowflake.cpp.o

src/discordpp/Objects/Snowflake.i: src/discordpp/Objects/Snowflake.cpp.i

.PHONY : src/discordpp/Objects/Snowflake.i

# target to preprocess a source file
src/discordpp/Objects/Snowflake.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Snowflake.cpp.i
.PHONY : src/discordpp/Objects/Snowflake.cpp.i

src/discordpp/Objects/Snowflake.s: src/discordpp/Objects/Snowflake.cpp.s

.PHONY : src/discordpp/Objects/Snowflake.s

# target to generate assembly for a file
src/discordpp/Objects/Snowflake.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Snowflake.cpp.s
.PHONY : src/discordpp/Objects/Snowflake.cpp.s

src/discordpp/Objects/User.o: src/discordpp/Objects/User.cpp.o

.PHONY : src/discordpp/Objects/User.o

# target to build an object file
src/discordpp/Objects/User.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/User.cpp.o
.PHONY : src/discordpp/Objects/User.cpp.o

src/discordpp/Objects/User.i: src/discordpp/Objects/User.cpp.i

.PHONY : src/discordpp/Objects/User.i

# target to preprocess a source file
src/discordpp/Objects/User.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/User.cpp.i
.PHONY : src/discordpp/Objects/User.cpp.i

src/discordpp/Objects/User.s: src/discordpp/Objects/User.cpp.s

.PHONY : src/discordpp/Objects/User.s

# target to generate assembly for a file
src/discordpp/Objects/User.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/User.cpp.s
.PHONY : src/discordpp/Objects/User.cpp.s

src/discordpp/jsoncpp.o: src/discordpp/jsoncpp.cpp.o

.PHONY : src/discordpp/jsoncpp.o

# target to build an object file
src/discordpp/jsoncpp.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/jsoncpp.cpp.o
.PHONY : src/discordpp/jsoncpp.cpp.o

src/discordpp/jsoncpp.i: src/discordpp/jsoncpp.cpp.i

.PHONY : src/discordpp/jsoncpp.i

# target to preprocess a source file
src/discordpp/jsoncpp.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/jsoncpp.cpp.i
.PHONY : src/discordpp/jsoncpp.cpp.i

src/discordpp/jsoncpp.s: src/discordpp/jsoncpp.cpp.s

.PHONY : src/discordpp/jsoncpp.s

# target to generate assembly for a file
src/discordpp/jsoncpp.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/jsoncpp.cpp.s
.PHONY : src/discordpp/jsoncpp.cpp.s

src/example/main.o: src/example/main.cpp.o

.PHONY : src/example/main.o

# target to build an object file
src/example/main.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/example/main.cpp.o
.PHONY : src/example/main.cpp.o

src/example/main.i: src/example/main.cpp.i

.PHONY : src/example/main.i

# target to preprocess a source file
src/example/main.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/example/main.cpp.i
.PHONY : src/example/main.cpp.i

src/example/main.s: src/example/main.cpp.s

.PHONY : src/example/main.s

# target to generate assembly for a file
src/example/main.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/example/main.cpp.s
.PHONY : src/example/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... Discordpp"
	@echo "... edit_cache"
	@echo "... src/discordpp/Bot.o"
	@echo "... src/discordpp/Bot.i"
	@echo "... src/discordpp/Bot.s"
	@echo "... src/discordpp/Gateway.o"
	@echo "... src/discordpp/Gateway.i"
	@echo "... src/discordpp/Gateway.s"
	@echo "... src/discordpp/Objects/Emoji.o"
	@echo "... src/discordpp/Objects/Emoji.i"
	@echo "... src/discordpp/Objects/Emoji.s"
	@echo "... src/discordpp/Objects/Guild.o"
	@echo "... src/discordpp/Objects/Guild.i"
	@echo "... src/discordpp/Objects/Guild.s"
	@echo "... src/discordpp/Objects/Role.o"
	@echo "... src/discordpp/Objects/Role.i"
	@echo "... src/discordpp/Objects/Role.s"
	@echo "... src/discordpp/Objects/Snowflake.o"
	@echo "... src/discordpp/Objects/Snowflake.i"
	@echo "... src/discordpp/Objects/Snowflake.s"
	@echo "... src/discordpp/Objects/User.o"
	@echo "... src/discordpp/Objects/User.i"
	@echo "... src/discordpp/Objects/User.s"
	@echo "... src/discordpp/jsoncpp.o"
	@echo "... src/discordpp/jsoncpp.i"
	@echo "... src/discordpp/jsoncpp.s"
	@echo "... src/example/main.o"
	@echo "... src/example/main.i"
	@echo "... src/example/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

