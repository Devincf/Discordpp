# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/lumi/code/cpp/Discord++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lumi/code/cpp/Discord++

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
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lumi/code/cpp/Discord++/CMakeFiles /home/lumi/code/cpp/Discord++/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/lumi/code/cpp/Discord++/CMakeFiles 0
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

src/discordpp/Core/Discordpp.o: src/discordpp/Core/Discordpp.cpp.o

.PHONY : src/discordpp/Core/Discordpp.o

# target to build an object file
src/discordpp/Core/Discordpp.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Discordpp.cpp.o
.PHONY : src/discordpp/Core/Discordpp.cpp.o

src/discordpp/Core/Discordpp.i: src/discordpp/Core/Discordpp.cpp.i

.PHONY : src/discordpp/Core/Discordpp.i

# target to preprocess a source file
src/discordpp/Core/Discordpp.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Discordpp.cpp.i
.PHONY : src/discordpp/Core/Discordpp.cpp.i

src/discordpp/Core/Discordpp.s: src/discordpp/Core/Discordpp.cpp.s

.PHONY : src/discordpp/Core/Discordpp.s

# target to generate assembly for a file
src/discordpp/Core/Discordpp.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Discordpp.cpp.s
.PHONY : src/discordpp/Core/Discordpp.cpp.s

src/discordpp/Core/Rest/DiscordAPI.o: src/discordpp/Core/Rest/DiscordAPI.cpp.o

.PHONY : src/discordpp/Core/Rest/DiscordAPI.o

# target to build an object file
src/discordpp/Core/Rest/DiscordAPI.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Rest/DiscordAPI.cpp.o
.PHONY : src/discordpp/Core/Rest/DiscordAPI.cpp.o

src/discordpp/Core/Rest/DiscordAPI.i: src/discordpp/Core/Rest/DiscordAPI.cpp.i

.PHONY : src/discordpp/Core/Rest/DiscordAPI.i

# target to preprocess a source file
src/discordpp/Core/Rest/DiscordAPI.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Rest/DiscordAPI.cpp.i
.PHONY : src/discordpp/Core/Rest/DiscordAPI.cpp.i

src/discordpp/Core/Rest/DiscordAPI.s: src/discordpp/Core/Rest/DiscordAPI.cpp.s

.PHONY : src/discordpp/Core/Rest/DiscordAPI.s

# target to generate assembly for a file
src/discordpp/Core/Rest/DiscordAPI.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Rest/DiscordAPI.cpp.s
.PHONY : src/discordpp/Core/Rest/DiscordAPI.cpp.s

src/discordpp/Core/Rest/RestAPI.o: src/discordpp/Core/Rest/RestAPI.cpp.o

.PHONY : src/discordpp/Core/Rest/RestAPI.o

# target to build an object file
src/discordpp/Core/Rest/RestAPI.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Rest/RestAPI.cpp.o
.PHONY : src/discordpp/Core/Rest/RestAPI.cpp.o

src/discordpp/Core/Rest/RestAPI.i: src/discordpp/Core/Rest/RestAPI.cpp.i

.PHONY : src/discordpp/Core/Rest/RestAPI.i

# target to preprocess a source file
src/discordpp/Core/Rest/RestAPI.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Rest/RestAPI.cpp.i
.PHONY : src/discordpp/Core/Rest/RestAPI.cpp.i

src/discordpp/Core/Rest/RestAPI.s: src/discordpp/Core/Rest/RestAPI.cpp.s

.PHONY : src/discordpp/Core/Rest/RestAPI.s

# target to generate assembly for a file
src/discordpp/Core/Rest/RestAPI.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/Rest/RestAPI.cpp.s
.PHONY : src/discordpp/Core/Rest/RestAPI.cpp.s

src/discordpp/Core/WebSocket/Gateway.o: src/discordpp/Core/WebSocket/Gateway.cpp.o

.PHONY : src/discordpp/Core/WebSocket/Gateway.o

# target to build an object file
src/discordpp/Core/WebSocket/Gateway.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/WebSocket/Gateway.cpp.o
.PHONY : src/discordpp/Core/WebSocket/Gateway.cpp.o

src/discordpp/Core/WebSocket/Gateway.i: src/discordpp/Core/WebSocket/Gateway.cpp.i

.PHONY : src/discordpp/Core/WebSocket/Gateway.i

# target to preprocess a source file
src/discordpp/Core/WebSocket/Gateway.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/WebSocket/Gateway.cpp.i
.PHONY : src/discordpp/Core/WebSocket/Gateway.cpp.i

src/discordpp/Core/WebSocket/Gateway.s: src/discordpp/Core/WebSocket/Gateway.cpp.s

.PHONY : src/discordpp/Core/WebSocket/Gateway.s

# target to generate assembly for a file
src/discordpp/Core/WebSocket/Gateway.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Core/WebSocket/Gateway.cpp.s
.PHONY : src/discordpp/Core/WebSocket/Gateway.cpp.s

src/discordpp/Events/ChannelCreateEvent.o: src/discordpp/Events/ChannelCreateEvent.cpp.o

.PHONY : src/discordpp/Events/ChannelCreateEvent.o

# target to build an object file
src/discordpp/Events/ChannelCreateEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/ChannelCreateEvent.cpp.o
.PHONY : src/discordpp/Events/ChannelCreateEvent.cpp.o

src/discordpp/Events/ChannelCreateEvent.i: src/discordpp/Events/ChannelCreateEvent.cpp.i

.PHONY : src/discordpp/Events/ChannelCreateEvent.i

# target to preprocess a source file
src/discordpp/Events/ChannelCreateEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/ChannelCreateEvent.cpp.i
.PHONY : src/discordpp/Events/ChannelCreateEvent.cpp.i

src/discordpp/Events/ChannelCreateEvent.s: src/discordpp/Events/ChannelCreateEvent.cpp.s

.PHONY : src/discordpp/Events/ChannelCreateEvent.s

# target to generate assembly for a file
src/discordpp/Events/ChannelCreateEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/ChannelCreateEvent.cpp.s
.PHONY : src/discordpp/Events/ChannelCreateEvent.cpp.s

src/discordpp/Events/DispatchEvent.o: src/discordpp/Events/DispatchEvent.cpp.o

.PHONY : src/discordpp/Events/DispatchEvent.o

# target to build an object file
src/discordpp/Events/DispatchEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/DispatchEvent.cpp.o
.PHONY : src/discordpp/Events/DispatchEvent.cpp.o

src/discordpp/Events/DispatchEvent.i: src/discordpp/Events/DispatchEvent.cpp.i

.PHONY : src/discordpp/Events/DispatchEvent.i

# target to preprocess a source file
src/discordpp/Events/DispatchEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/DispatchEvent.cpp.i
.PHONY : src/discordpp/Events/DispatchEvent.cpp.i

src/discordpp/Events/DispatchEvent.s: src/discordpp/Events/DispatchEvent.cpp.s

.PHONY : src/discordpp/Events/DispatchEvent.s

# target to generate assembly for a file
src/discordpp/Events/DispatchEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/DispatchEvent.cpp.s
.PHONY : src/discordpp/Events/DispatchEvent.cpp.s

src/discordpp/Events/Event.o: src/discordpp/Events/Event.cpp.o

.PHONY : src/discordpp/Events/Event.o

# target to build an object file
src/discordpp/Events/Event.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/Event.cpp.o
.PHONY : src/discordpp/Events/Event.cpp.o

src/discordpp/Events/Event.i: src/discordpp/Events/Event.cpp.i

.PHONY : src/discordpp/Events/Event.i

# target to preprocess a source file
src/discordpp/Events/Event.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/Event.cpp.i
.PHONY : src/discordpp/Events/Event.cpp.i

src/discordpp/Events/Event.s: src/discordpp/Events/Event.cpp.s

.PHONY : src/discordpp/Events/Event.s

# target to generate assembly for a file
src/discordpp/Events/Event.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/Event.cpp.s
.PHONY : src/discordpp/Events/Event.cpp.s

src/discordpp/Events/GuildCreateEvent.o: src/discordpp/Events/GuildCreateEvent.cpp.o

.PHONY : src/discordpp/Events/GuildCreateEvent.o

# target to build an object file
src/discordpp/Events/GuildCreateEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/GuildCreateEvent.cpp.o
.PHONY : src/discordpp/Events/GuildCreateEvent.cpp.o

src/discordpp/Events/GuildCreateEvent.i: src/discordpp/Events/GuildCreateEvent.cpp.i

.PHONY : src/discordpp/Events/GuildCreateEvent.i

# target to preprocess a source file
src/discordpp/Events/GuildCreateEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/GuildCreateEvent.cpp.i
.PHONY : src/discordpp/Events/GuildCreateEvent.cpp.i

src/discordpp/Events/GuildCreateEvent.s: src/discordpp/Events/GuildCreateEvent.cpp.s

.PHONY : src/discordpp/Events/GuildCreateEvent.s

# target to generate assembly for a file
src/discordpp/Events/GuildCreateEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/GuildCreateEvent.cpp.s
.PHONY : src/discordpp/Events/GuildCreateEvent.cpp.s

src/discordpp/Events/HeartbeatACKEvent.o: src/discordpp/Events/HeartbeatACKEvent.cpp.o

.PHONY : src/discordpp/Events/HeartbeatACKEvent.o

# target to build an object file
src/discordpp/Events/HeartbeatACKEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/HeartbeatACKEvent.cpp.o
.PHONY : src/discordpp/Events/HeartbeatACKEvent.cpp.o

src/discordpp/Events/HeartbeatACKEvent.i: src/discordpp/Events/HeartbeatACKEvent.cpp.i

.PHONY : src/discordpp/Events/HeartbeatACKEvent.i

# target to preprocess a source file
src/discordpp/Events/HeartbeatACKEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/HeartbeatACKEvent.cpp.i
.PHONY : src/discordpp/Events/HeartbeatACKEvent.cpp.i

src/discordpp/Events/HeartbeatACKEvent.s: src/discordpp/Events/HeartbeatACKEvent.cpp.s

.PHONY : src/discordpp/Events/HeartbeatACKEvent.s

# target to generate assembly for a file
src/discordpp/Events/HeartbeatACKEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/HeartbeatACKEvent.cpp.s
.PHONY : src/discordpp/Events/HeartbeatACKEvent.cpp.s

src/discordpp/Events/HelloEvent.o: src/discordpp/Events/HelloEvent.cpp.o

.PHONY : src/discordpp/Events/HelloEvent.o

# target to build an object file
src/discordpp/Events/HelloEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/HelloEvent.cpp.o
.PHONY : src/discordpp/Events/HelloEvent.cpp.o

src/discordpp/Events/HelloEvent.i: src/discordpp/Events/HelloEvent.cpp.i

.PHONY : src/discordpp/Events/HelloEvent.i

# target to preprocess a source file
src/discordpp/Events/HelloEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/HelloEvent.cpp.i
.PHONY : src/discordpp/Events/HelloEvent.cpp.i

src/discordpp/Events/HelloEvent.s: src/discordpp/Events/HelloEvent.cpp.s

.PHONY : src/discordpp/Events/HelloEvent.s

# target to generate assembly for a file
src/discordpp/Events/HelloEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/HelloEvent.cpp.s
.PHONY : src/discordpp/Events/HelloEvent.cpp.s

src/discordpp/Events/MessageCreateEvent.o: src/discordpp/Events/MessageCreateEvent.cpp.o

.PHONY : src/discordpp/Events/MessageCreateEvent.o

# target to build an object file
src/discordpp/Events/MessageCreateEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/MessageCreateEvent.cpp.o
.PHONY : src/discordpp/Events/MessageCreateEvent.cpp.o

src/discordpp/Events/MessageCreateEvent.i: src/discordpp/Events/MessageCreateEvent.cpp.i

.PHONY : src/discordpp/Events/MessageCreateEvent.i

# target to preprocess a source file
src/discordpp/Events/MessageCreateEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/MessageCreateEvent.cpp.i
.PHONY : src/discordpp/Events/MessageCreateEvent.cpp.i

src/discordpp/Events/MessageCreateEvent.s: src/discordpp/Events/MessageCreateEvent.cpp.s

.PHONY : src/discordpp/Events/MessageCreateEvent.s

# target to generate assembly for a file
src/discordpp/Events/MessageCreateEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/MessageCreateEvent.cpp.s
.PHONY : src/discordpp/Events/MessageCreateEvent.cpp.s

src/discordpp/Events/ReadyEvent.o: src/discordpp/Events/ReadyEvent.cpp.o

.PHONY : src/discordpp/Events/ReadyEvent.o

# target to build an object file
src/discordpp/Events/ReadyEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/ReadyEvent.cpp.o
.PHONY : src/discordpp/Events/ReadyEvent.cpp.o

src/discordpp/Events/ReadyEvent.i: src/discordpp/Events/ReadyEvent.cpp.i

.PHONY : src/discordpp/Events/ReadyEvent.i

# target to preprocess a source file
src/discordpp/Events/ReadyEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/ReadyEvent.cpp.i
.PHONY : src/discordpp/Events/ReadyEvent.cpp.i

src/discordpp/Events/ReadyEvent.s: src/discordpp/Events/ReadyEvent.cpp.s

.PHONY : src/discordpp/Events/ReadyEvent.s

# target to generate assembly for a file
src/discordpp/Events/ReadyEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/ReadyEvent.cpp.s
.PHONY : src/discordpp/Events/ReadyEvent.cpp.s

src/discordpp/Events/TypingStartEvent.o: src/discordpp/Events/TypingStartEvent.cpp.o

.PHONY : src/discordpp/Events/TypingStartEvent.o

# target to build an object file
src/discordpp/Events/TypingStartEvent.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/TypingStartEvent.cpp.o
.PHONY : src/discordpp/Events/TypingStartEvent.cpp.o

src/discordpp/Events/TypingStartEvent.i: src/discordpp/Events/TypingStartEvent.cpp.i

.PHONY : src/discordpp/Events/TypingStartEvent.i

# target to preprocess a source file
src/discordpp/Events/TypingStartEvent.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/TypingStartEvent.cpp.i
.PHONY : src/discordpp/Events/TypingStartEvent.cpp.i

src/discordpp/Events/TypingStartEvent.s: src/discordpp/Events/TypingStartEvent.cpp.s

.PHONY : src/discordpp/Events/TypingStartEvent.s

# target to generate assembly for a file
src/discordpp/Events/TypingStartEvent.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Events/TypingStartEvent.cpp.s
.PHONY : src/discordpp/Events/TypingStartEvent.cpp.s

src/discordpp/Managers/GuildManager.o: src/discordpp/Managers/GuildManager.cpp.o

.PHONY : src/discordpp/Managers/GuildManager.o

# target to build an object file
src/discordpp/Managers/GuildManager.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Managers/GuildManager.cpp.o
.PHONY : src/discordpp/Managers/GuildManager.cpp.o

src/discordpp/Managers/GuildManager.i: src/discordpp/Managers/GuildManager.cpp.i

.PHONY : src/discordpp/Managers/GuildManager.i

# target to preprocess a source file
src/discordpp/Managers/GuildManager.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Managers/GuildManager.cpp.i
.PHONY : src/discordpp/Managers/GuildManager.cpp.i

src/discordpp/Managers/GuildManager.s: src/discordpp/Managers/GuildManager.cpp.s

.PHONY : src/discordpp/Managers/GuildManager.s

# target to generate assembly for a file
src/discordpp/Managers/GuildManager.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Managers/GuildManager.cpp.s
.PHONY : src/discordpp/Managers/GuildManager.cpp.s

src/discordpp/Managers/UserManager.o: src/discordpp/Managers/UserManager.cpp.o

.PHONY : src/discordpp/Managers/UserManager.o

# target to build an object file
src/discordpp/Managers/UserManager.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Managers/UserManager.cpp.o
.PHONY : src/discordpp/Managers/UserManager.cpp.o

src/discordpp/Managers/UserManager.i: src/discordpp/Managers/UserManager.cpp.i

.PHONY : src/discordpp/Managers/UserManager.i

# target to preprocess a source file
src/discordpp/Managers/UserManager.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Managers/UserManager.cpp.i
.PHONY : src/discordpp/Managers/UserManager.cpp.i

src/discordpp/Managers/UserManager.s: src/discordpp/Managers/UserManager.cpp.s

.PHONY : src/discordpp/Managers/UserManager.s

# target to generate assembly for a file
src/discordpp/Managers/UserManager.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Managers/UserManager.cpp.s
.PHONY : src/discordpp/Managers/UserManager.cpp.s

src/discordpp/Objects/Channel.o: src/discordpp/Objects/Channel.cpp.o

.PHONY : src/discordpp/Objects/Channel.o

# target to build an object file
src/discordpp/Objects/Channel.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Channel.cpp.o
.PHONY : src/discordpp/Objects/Channel.cpp.o

src/discordpp/Objects/Channel.i: src/discordpp/Objects/Channel.cpp.i

.PHONY : src/discordpp/Objects/Channel.i

# target to preprocess a source file
src/discordpp/Objects/Channel.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Channel.cpp.i
.PHONY : src/discordpp/Objects/Channel.cpp.i

src/discordpp/Objects/Channel.s: src/discordpp/Objects/Channel.cpp.s

.PHONY : src/discordpp/Objects/Channel.s

# target to generate assembly for a file
src/discordpp/Objects/Channel.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Channel.cpp.s
.PHONY : src/discordpp/Objects/Channel.cpp.s

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

src/discordpp/Objects/Message.o: src/discordpp/Objects/Message.cpp.o

.PHONY : src/discordpp/Objects/Message.o

# target to build an object file
src/discordpp/Objects/Message.cpp.o:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Message.cpp.o
.PHONY : src/discordpp/Objects/Message.cpp.o

src/discordpp/Objects/Message.i: src/discordpp/Objects/Message.cpp.i

.PHONY : src/discordpp/Objects/Message.i

# target to preprocess a source file
src/discordpp/Objects/Message.cpp.i:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Message.cpp.i
.PHONY : src/discordpp/Objects/Message.cpp.i

src/discordpp/Objects/Message.s: src/discordpp/Objects/Message.cpp.s

.PHONY : src/discordpp/Objects/Message.s

# target to generate assembly for a file
src/discordpp/Objects/Message.cpp.s:
	$(MAKE) -f CMakeFiles/Discordpp.dir/build.make CMakeFiles/Discordpp.dir/src/discordpp/Objects/Message.cpp.s
.PHONY : src/discordpp/Objects/Message.cpp.s

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
	@echo "... src/discordpp/Core/Discordpp.o"
	@echo "... src/discordpp/Core/Discordpp.i"
	@echo "... src/discordpp/Core/Discordpp.s"
	@echo "... src/discordpp/Core/Rest/DiscordAPI.o"
	@echo "... src/discordpp/Core/Rest/DiscordAPI.i"
	@echo "... src/discordpp/Core/Rest/DiscordAPI.s"
	@echo "... src/discordpp/Core/Rest/RestAPI.o"
	@echo "... src/discordpp/Core/Rest/RestAPI.i"
	@echo "... src/discordpp/Core/Rest/RestAPI.s"
	@echo "... src/discordpp/Core/WebSocket/Gateway.o"
	@echo "... src/discordpp/Core/WebSocket/Gateway.i"
	@echo "... src/discordpp/Core/WebSocket/Gateway.s"
	@echo "... src/discordpp/Events/ChannelCreateEvent.o"
	@echo "... src/discordpp/Events/ChannelCreateEvent.i"
	@echo "... src/discordpp/Events/ChannelCreateEvent.s"
	@echo "... src/discordpp/Events/DispatchEvent.o"
	@echo "... src/discordpp/Events/DispatchEvent.i"
	@echo "... src/discordpp/Events/DispatchEvent.s"
	@echo "... src/discordpp/Events/Event.o"
	@echo "... src/discordpp/Events/Event.i"
	@echo "... src/discordpp/Events/Event.s"
	@echo "... src/discordpp/Events/GuildCreateEvent.o"
	@echo "... src/discordpp/Events/GuildCreateEvent.i"
	@echo "... src/discordpp/Events/GuildCreateEvent.s"
	@echo "... src/discordpp/Events/HeartbeatACKEvent.o"
	@echo "... src/discordpp/Events/HeartbeatACKEvent.i"
	@echo "... src/discordpp/Events/HeartbeatACKEvent.s"
	@echo "... src/discordpp/Events/HelloEvent.o"
	@echo "... src/discordpp/Events/HelloEvent.i"
	@echo "... src/discordpp/Events/HelloEvent.s"
	@echo "... src/discordpp/Events/MessageCreateEvent.o"
	@echo "... src/discordpp/Events/MessageCreateEvent.i"
	@echo "... src/discordpp/Events/MessageCreateEvent.s"
	@echo "... src/discordpp/Events/ReadyEvent.o"
	@echo "... src/discordpp/Events/ReadyEvent.i"
	@echo "... src/discordpp/Events/ReadyEvent.s"
	@echo "... src/discordpp/Events/TypingStartEvent.o"
	@echo "... src/discordpp/Events/TypingStartEvent.i"
	@echo "... src/discordpp/Events/TypingStartEvent.s"
	@echo "... src/discordpp/Managers/GuildManager.o"
	@echo "... src/discordpp/Managers/GuildManager.i"
	@echo "... src/discordpp/Managers/GuildManager.s"
	@echo "... src/discordpp/Managers/UserManager.o"
	@echo "... src/discordpp/Managers/UserManager.i"
	@echo "... src/discordpp/Managers/UserManager.s"
	@echo "... src/discordpp/Objects/Channel.o"
	@echo "... src/discordpp/Objects/Channel.i"
	@echo "... src/discordpp/Objects/Channel.s"
	@echo "... src/discordpp/Objects/Emoji.o"
	@echo "... src/discordpp/Objects/Emoji.i"
	@echo "... src/discordpp/Objects/Emoji.s"
	@echo "... src/discordpp/Objects/Guild.o"
	@echo "... src/discordpp/Objects/Guild.i"
	@echo "... src/discordpp/Objects/Guild.s"
	@echo "... src/discordpp/Objects/Message.o"
	@echo "... src/discordpp/Objects/Message.i"
	@echo "... src/discordpp/Objects/Message.s"
	@echo "... src/discordpp/Objects/Role.o"
	@echo "... src/discordpp/Objects/Role.i"
	@echo "... src/discordpp/Objects/Role.s"
	@echo "... src/discordpp/Objects/Snowflake.o"
	@echo "... src/discordpp/Objects/Snowflake.i"
	@echo "... src/discordpp/Objects/Snowflake.s"
	@echo "... src/discordpp/Objects/User.o"
	@echo "... src/discordpp/Objects/User.i"
	@echo "... src/discordpp/Objects/User.s"
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

