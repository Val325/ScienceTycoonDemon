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

static void ButtonLoad0()
{
    save_num = 0;
    Saving* dat = LoadData("save/", "save_1");
    Scene1(dat);
}
static void ButtonLoad1()
{
    save_num = 1;
    Saving* dat = LoadData("save/", "save_2");
    Scene1(dat);
}
static void ButtonLoad2()
{
    save_num = 2;
    Saving* dat = LoadData("save/", "save_2");
    Scene1(dat);
}

static void ButtonNew0()
{
    //dataGame[0].Knowledge = know_point;
    //dataGame[0].money = money_point;
    save_num = 0;
    SaveData("save/", "save_1");
    Scene1();
}
static void ButtonNew1()
{
    //dataGame[0].Knowledge = know_point;
    //dataGame[0].money = money_point;
    save_num = 1;
    SaveData("save/", "save_2");
    Scene1();
}
static void ButtonNew2()
{
    //dataGame[0].Knowledge = know_point;
    //dataGame[0].money = money_point; 
    save_num = 2;
    SaveData("save/", "save_3");
    Scene1();
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
                if (!CheckExistsFile("save/save_1.dat")){
                   if (GuiButton((Rectangle){ 164, 336, 224, 48 }, "New game 1")) ButtonNew0(); 
                } else {
                   if (GuiButton((Rectangle){ 164, 336, 224, 48 }, "SAVE 1")) ButtonLoad0();
                }

                if (!CheckExistsFile("save/save_2.dat")){
                   if (GuiButton((Rectangle){164, 392, 224, 48}, "New game 2")) ButtonNew1(); 
                } else {
                   if (GuiButton((Rectangle){164, 392, 224, 48}, "SAVE 2")) ButtonLoad1();
                } 

                if (!CheckExistsFile("save/save_3.dat")){
                   if (GuiButton((Rectangle){164, 448, 224, 48}, "New game 3")) ButtonNew2(); 
                } else {
                   if (GuiButton((Rectangle){164, 448, 224, 48}, "SAVE 3")) ButtonLoad2();
                }
                //if (CheckExistsFile("save/save_2.dat")) if (GuiButton((Rectangle){ 164, 392, 224, 48 }, "SAVE 2")) Button1(); 
                //if (CheckExistsFile("save/save_3.dat")) if (GuiButton((Rectangle){ 164, 448, 224, 48 }, "SAVE 3")) Button2();  
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


