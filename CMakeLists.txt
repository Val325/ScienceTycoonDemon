cmake_minimum_required(VERSION 3.25)
#for linux
#change your compiler
set(CMAKE_CXX_COMPILER "/bin/clang++")
project(Game LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(Libs ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/external/glfw/include/GLFW)
add_executable(Main Main.cpp)

if (WIN32)
    target_link_directories(Main PUBLIC ${Libs})
    target_link_libraries(Main PUBLIC libraylib.a)
    target_link_libraries(Main PUBLIC libjsoncpp.a)
    target_link_libraries(Main PUBLIC winmm.dll)
    message("Succesful compile windows")
elseif(UNIX)
    target_link_libraries(Main ${CMAKE_SOURCE_DIR}/liblinux/libraylib.a)
    option(JSONCPP_WITH_TESTS OFF)
    option(BUILD_SHARED_LIBS OFF)
    option(BUILD_OBJECT_LIBS OFF)
    target_link_libraries(Main ${JSONCPP_LIBRARIES})
    target_compile_options(Main PRIVATE -Wno-c++11-narrowing -Wunused-value -Wuninitialized -Wreturn-type -Wnull-conversion -Wcomment)
    target_compile_options(Main PRIVATE -Wl,-rpath=shared)
    message("Succesful compile unixlike system")
endif()
