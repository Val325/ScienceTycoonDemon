cmake_minimum_required(VERSION 3.25)
project(Game LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(raylibPath D:/Program/raylib/raylib/src/)
set(raylibPathCPP D:/Program/raylib-cpp-master/include)
set(Libs D:/Program/raylib/Sourse/lib)


include_directories(D:/Program/raylib/Sourse/include)
include_directories(D:/Program/raylib-cpp-master/include)
include_directories(D:/Program/raylib/raylib/src)
include_directories(D:/Program/raylib/Sourse/lib/external/glfw/include/GLFW)
include_directories(D:/Program/raylib/raylib/src/external)




#SET_TARGET_PROPERTIES(raylib PROPERTIES LINKER_LANGUAGE C)
#SET_TARGET_PROPERTIES(json PROPERTIES LINKER_LANGUAGE CXX)


add_executable(Main Main.cpp)
#add_definitions(-static -lraylib -lopengl32 -lgdi32 -lwinmm)
target_link_directories(Main PUBLIC ${Libs})
target_link_libraries(Main PUBLIC libraylib.a)
target_link_libraries(Main PUBLIC libjsoncpp.a)


