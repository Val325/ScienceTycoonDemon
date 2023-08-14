#include <iostream>
//#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"
#include "Scene.cpp"
#pragma comment(lib, "winmm.lib")
#include "raylib.h"
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
    Image image = LoadImage("GUI/NameGame/TitleCrop.png");     
    Texture2D texture = LoadTextureFromImage(image);          
                                                              

    UnloadImage(image);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM 
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

            ClearBackground(BLACK);
            DrawTexture(texture, 500, 288, WHITE);
            //----------------------------------------------------------------------------------
            // Draw controls
            if (GuiButton(layoutRecs[0], "EXIT")) ExitBtn(); 
            if (GuiButton(layoutRecs[1], "OPTIONS")) OptionsBtn(); 
            if (GuiButton(layoutRecs[2], "PLAY")) PlayBtn();
            
            //GuiLabel(layoutRecs[3], "Science tycoon");
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }



   // 

    

    //--------------------------------------------------------------------------------------

    return 0;
}


