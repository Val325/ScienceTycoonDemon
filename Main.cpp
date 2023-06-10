#include <iostream>
//#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"
#include "Scene.cpp"
#pragma comment(lib, "winmm.lib")

#include <json/json.h>
#include <nlohmann/json.hpp>
#include <unordered_map>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

const int screenWidth = 1280;
const int screenHeight = 720;

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
// Button: Exit_btn logic
static void ExitBtn()
{
  CloseWindow();        // Close window and OpenGL context

}
// Button: Options_btn logic
static void OptionsBtn()
{
    // TODO: Implement control logic
}
// Button: Play_btn logic
static void PlayBtn()
{
  Scene1();

}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    std::cout << "start" << std::endl; 
    SetTraceLogLevel(0);
    // Initialization
    //--------------------------------------------------------------------------------------
    // Define controls rectangles
    Rectangle layoutRecs[4] = {
        (Rectangle){ 464, 448, 224, 48 },    // Button: Exit_btn
        (Rectangle){ 464, 392, 224, 48 },    // Button: Options_btn
        (Rectangle){ 464, 336, 224, 48 },    // Button: Play_btn
        (Rectangle){ 520, 288, 112, 24 },    // Label: Science tycooN
    };
    
    raylib::Window window(screenWidth, screenHeight, "Science tycoon");

    //Scene1();
    SetExitKey(KEY_NULL); 

     // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            // Draw controls
            if (GuiButton(layoutRecs[0], "EXIT")) ExitBtn(); 
            if (GuiButton(layoutRecs[1], "OPTIONS")) OptionsBtn(); 
            if (GuiButton(layoutRecs[2], "PLAY")) PlayBtn(); 
            GuiLabel(layoutRecs[3], "Science tycoon");
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

   // 

    

    //--------------------------------------------------------------------------------------

    return 0;
}


