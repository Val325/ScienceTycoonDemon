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
#include "Savings.cpp"
const int screenWidth = 1280;
const int screenHeight = 720;
enum selectBtn {menu ,save, options, exitB };
selectBtn selectBt; 
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
   selectBt = save;
  //Scene1();
  //SaveDataBtn();
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    SetTraceLogLevel(0);

    selectBt = menu;

    // Initialization
    //--------------------------------------------------------------------------------------
    // Define controls rectangles
    int offsetXmainMenu = -300;
    int offsetYmainMenu = 0;
    
    int scienceTycoonNameOffset = -250;
    Rectangle layoutRecs[4] = {
        (Rectangle){ 464 + offsetXmainMenu, 448 + offsetYmainMenu, 224, 48 },    // Button: Exit_btn
        (Rectangle){ 464 + offsetXmainMenu, 392 + offsetYmainMenu, 224, 48 },    // Button: Options_btn
        (Rectangle){ 464 + offsetXmainMenu, 336 + offsetYmainMenu, 224, 48 },    // Button: Play_btn
        (Rectangle){ 520, 288, 112, 24 },    // Label: Science tycoon
    };
    
    raylib::Window window(screenWidth, screenHeight, "Science tycoon");
    Image image = LoadImage("GUI/NameGame/TitleCrop.png");
    Image atom = LoadImage("GUI/background/Atom_menu.png");
    //ImageResize(&atom, 200, 200);  
    Texture2D texture = LoadTextureFromImage(image);          
    Texture2D textureAtom = LoadTextureFromImage(atom);                                                                 

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
            DrawTexture(texture, 500 + offsetXmainMenu, 288, WHITE);
            DrawTexture(textureAtom, 500, 288 - 70, WHITE);
            //----------------------------------------------------------------------------------
            // Draw controls
            if (selectBt == save){
                //savings
                // 448 392 336
                if (GuiButton((Rectangle){ 164, 336, 224, 48 }, "SAVE 1")) Button0(); 
                if (GuiButton((Rectangle){ 164, 392, 224, 48 }, "SAVE 2")) Button1(); 
                if (GuiButton((Rectangle){ 164, 448, 224, 48 }, "SAVE 3")) Button2();  
            }else{
                if (GuiButton(layoutRecs[0], "EXIT")) ExitBtn(); 
                if (GuiButton(layoutRecs[1], "OPTIONS")) OptionsBtn(); 
                if (GuiButton(layoutRecs[2], "PLAY")) PlayBtn();
            }

            


            //GuiLabel(layoutRecs[3], "Science tycoon");
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }



   // 

    

    //--------------------------------------------------------------------------------------

    return 0;
}


