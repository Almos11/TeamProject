cmake_minimum_required(VERSION 3.16)
project(Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIS_DIR})

find_package(Boost 1.71.0 REQUIRED)
find_package(Threads REQUIRED)

if (WIN32 AND NOT MSVC AND NOT BORLAND)
    # For sockets to work correctly
    link_libraries(wsock32 ws2_32)
else ()
    link_libraries(Threads::Threads)
endif ()

include_directories(Library)
include_directories(Game)
include_directories(Server)
include_directories(Client)
add_subdirectory(Server Server/)
add_subdirectory(Client Client/)
add_subdirectory(Library Library/)
#add_subdirectory(libs)
#add_subdirectory(test)
#add_subdirectory(Game Game/)
