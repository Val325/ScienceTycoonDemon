#include <iostream>
//#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"
#include "Scene.cpp"
#pragma comment(lib, "winmm.lib")

#include <json/json.h>
#include <nlohmann/json.hpp>
#include <unordered_map>

const int screenWidth = 1280;
const int screenHeight = 720;



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    raylib::Window window(screenWidth, screenHeight, "Science tycoon");

    Scene1();
    


    

    

    //--------------------------------------------------------------------------------------

    return 0;
}
