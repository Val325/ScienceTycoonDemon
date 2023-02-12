cmake_minimum_required(VERSION 3.25)
project(Game LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(Libs ${CMAKE_SOURCE_DIR}/lib)

message (${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)


include_directories(${CMAKE_SOURCE_DIR}/lib/external/glfw/include/GLFW)


add_executable(Main Main.cpp)
target_link_directories(Main PUBLIC ${Libs})
target_link_libraries(Main PUBLIC libraylib.a)
target_link_libraries(Main PUBLIC libjsoncpp.a)


