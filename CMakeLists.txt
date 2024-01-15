cmake_minimum_required(VERSION 3.25)
#for linux
#set(CMAKE_CXX_COMPILER "/bin/clang++")
set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")
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
elseif(UNIX)



    message("windows compile")
        #target_link_libraries(Main ${CMAKE_SOURCE_DIR}/shared/windows/raylib.dll)
        #target_compile_options(Main PRIVATE -Wno-c++11-narrowing -Wunused-value -Wuninitialized -Wreturn-type -Wcomment)
        #target_link_directories(Main PUBLIC ${CMAKE_SOURCE_DIR}/shared/windows)
    add_library(raylib SHARED IMPORTED)
    set_property(TARGET raylib PROPERTY IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/shared/windows/raylib.dll")
    target_link_libraries(Main raylib)
    #set_target_properties(Main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/shared/windows/")
    #set(DLL_LIBRARIES_PATH "shared/windows")
    #target_compile_options(Main PRIVATE -Wl,-rpath=shared)
    message("Succesful crosscompile")

        #target_link_libraries(Main ${CMAKE_SOURCE_DIR}/liblinux/libraylib.a)
        #option(JSONCPP_WITH_TESTS OFF)
        #option(BUILD_SHARED_LIBS OFF)
        #option(BUILD_OBJECT_LIBS OFF)
        #target_link_libraries(Main ${JSONCPP_LIBRARIES})
        #target_compile_options(Main PRIVATE -Wno-c++11-narrowing -Wunused-value -Wuninitialized -Wreturn-type -Wnull-conversion -Wcomment)
    
        #message("Succesful compile")


endif()
