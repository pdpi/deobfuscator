cmake_minimum_required(VERSION 3.3)
project(deobfuscate)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

find_path(LevelDB_INCLUDE_PATH NAMES leveldb/db.h)
find_library(LevelDB_LIBRARIES NAMES libleveldb.a libleveldb.lib)

if(LevelDB_INCLUDE_PATH AND LevelDB_LIBRARIES)
    include_directories(${LevelDB_INCLUDE_PATH})
    set(LevelDB_FOUND TRUE)
else()
    message(FATAL_ERROR "Could not find leveldb library.")
endif()

find_path(Snappy_INCLUDE_PATH NAMES include/snappy.h)
find_library(Snappy_LIBRARIES NAMES libsnappy.a)

if(Snappy_INCLUDE_PATH AND Snappy_LIBRARIES)
    include_directories(${Snappy_INCLUDE_PATH})
    set(Snappy_FOUND TRUE)
else()
    message(FATAL_ERROR "Could not find Snappy library.")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/utils.cpp src/utils.h src/streams.h src/serialize.h src/compat/endian.h src/compat/byteswap.h src/prevector.h src/dbwrapper.cpp src/dbwrapper.h src/clientversion.h src/version.h src/utilstrencodings.h src/utilstrencodings.cpp src/tinyformat.h)
add_executable(deobfuscate ${SOURCE_FILES})

if(Boost_FOUND)
    target_link_libraries(deobfuscate ${Boost_LIBRARIES})
endif()
if(LevelDB_FOUND)
    target_link_libraries(deobfuscate ${LevelDB_LIBRARIES})
endif()
if(Snappy_FOUND)
    target_link_libraries(deobfuscate ${Snappy_LIBRARIES})
endif()