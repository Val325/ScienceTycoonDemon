cmake_minimum_required(VERSION 3.25)
project(Game LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(Libs ${CMAKE_SOURCE_DIR}/lib)

message (${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories(${CMAKE_SOURCE_DIR}/lib/external/glfw/include/GLFW)

add_executable(Main Main.cpp)

if (WIN32)
    target_link_directories(Main PUBLIC ${Libs})
    target_link_libraries(Main PUBLIC libraylib.a)
    target_link_libraries(Main PUBLIC libjsoncpp.a)
    target_link_libraries(Main PUBLIC winmm.dll)
elseif(UNIX)
  #  add_subdirectory("${PROJECT_SOURCE_DIR}/deps/raylib")
    target_include_directories(Main PRIVATE ${raylib_INCLUDE_DIRS})
    target_link_libraries(Main raylib)

    option(JSONCPP_WITH_TESTS OFF)
    option(BUILD_SHARED_LIBS OFF)
    option(BUILD_OBJECT_LIBS OFF)
    #  add_subdirectory("${PROJECT_SOURCE_DIR}/deps/jsoncpp")
    target_link_libraries(Main ${JSONCPP_LIBRARIES})
endif()
