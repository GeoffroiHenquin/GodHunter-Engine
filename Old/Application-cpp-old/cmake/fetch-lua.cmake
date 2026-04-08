### Fetch Lua
### This file is made to fetch and include Lua into the project.
### Lua is a scripting programming language.

# Include FetchContent
include(FetchContent)

# Fetch Lua from GitHub
FetchContent_Declare(
	lua
	GIT_REPOSITORY https://github.com/lua/lua
	GIT_TAG        v5.4
)
FetchContent_MakeAvailable(lua)

# Build Lua into a static library
add_library(lua STATIC
	${lua_SOURCE_DIR}/lapi.c
	${lua_SOURCE_DIR}/lcode.c
	${lua_SOURCE_DIR}/lctype.c
	${lua_SOURCE_DIR}/ldebug.c
	${lua_SOURCE_DIR}/ldo.c
	${lua_SOURCE_DIR}/ldump.c
	${lua_SOURCE_DIR}/lfunc.c
	${lua_SOURCE_DIR}/lgc.c
	${lua_SOURCE_DIR}/llex.c
	${lua_SOURCE_DIR}/lmem.c
	${lua_SOURCE_DIR}/lobject.c
	${lua_SOURCE_DIR}/lopcodes.c
	${lua_SOURCE_DIR}/lparser.c
	${lua_SOURCE_DIR}/lstate.c
	${lua_SOURCE_DIR}/lstring.c
	${lua_SOURCE_DIR}/ltable.c
	${lua_SOURCE_DIR}/ltm.c
	${lua_SOURCE_DIR}/lundump.c
	${lua_SOURCE_DIR}/lvm.c
	${lua_SOURCE_DIR}/lzio.c
	${lua_SOURCE_DIR}/lauxlib.c
	${lua_SOURCE_DIR}/lbaselib.c
	${lua_SOURCE_DIR}/lcorolib.c
	${lua_SOURCE_DIR}/ldblib.c
	${lua_SOURCE_DIR}/liolib.c
	${lua_SOURCE_DIR}/lmathlib.c
	${lua_SOURCE_DIR}/loslib.c
	${lua_SOURCE_DIR}/lstrlib.c
	${lua_SOURCE_DIR}/ltablib.c
	${lua_SOURCE_DIR}/lutf8lib.c
	${lua_SOURCE_DIR}/loadlib.c
	${lua_SOURCE_DIR}/linit.c)
target_include_directories(lua PUBLIC ${lua_SOURCE_DIR})
target_link_libraries(${ProjectId} lua)