cmake_minimum_required(VERSION 3.5)

project(MeetX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

add_subdirectory(ArgsHandler)
add_subdirectory(Definitions)
add_subdirectory(PSQLW)

include_directories(ArgsHandler/include)
include_directories(Definitions/include)
include_directories(PSQLW/include)
include_directories(Types)
include_directories(include)


include(GNUInstallDirs)

add_executable(MeetX main.cpp
    include/Init.hpp)

install(TARGETS MeetX
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(MeetX PRIVATE ArgsHandler Definitions PSQLWrapper spdlog::spdlog)
