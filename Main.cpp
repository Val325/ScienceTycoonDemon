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
//#include "Savings.cpp"
#include "Utils.cpp"
const int screenWidth = 1280;
const int screenHeight = 720;
enum selectBtn {menu ,save, options, exitB };
selectBtn selectBt;
bool isHelpMenu = false;

static void ExitBtn()
{
  CloseWindow();       

}

static void OptionsBtn()
{
    
}

void HelpOptions(){
    isHelpMenu != isHelpMenu;

}

static void PlayBtn()
{
   selectBt = save;
}

static void ButtonLoad0()
{
    save_num = 0;
    Saving* dat = LoadData("save/", "save_1"); 
    Scene1(save_num, dat);
}
static void ButtonLoad1()
{
    save_num = 1;
    Saving* dat = LoadData("save/", "save_2");
    Scene1(save_num,dat);
}
static void ButtonLoad2()
{
    save_num = 2;
    Saving* dat = LoadData("save/", "save_3");
    Scene1(save_num,dat);
}

static void ButtonNew0()
{
    save_num = 0;
    SaveData("save/", "save_1");
    Scene1(save_num);
}
static void ButtonNew1()
{
    save_num = 1;
    SaveData("save/", "save_2");
    Scene1(save_num);
}
static void ButtonNew2()
{
    save_num = 2;
    SaveData("save/", "save_3");
    Scene1(save_num);
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
        (Rectangle){ 520, 540, 112, 24 },    // Label: Help
    };


    raylib::Window window(screenWidth, screenHeight, "Science tycoon");
    SetTargetFPS(60);
    Image image = LoadImage("GUI/NameGame/TitleCrop.png");
    Image atom = LoadImage("GUI/background/Atom_menu.png");

    Image exitBtn1 = LoadImage("GUI/exit button/exit.png"); 
    Image exitBtn2 = LoadImage("GUI/exit button/exit.png");
    Image exitBtn3 = LoadImage("GUI/exit button/exit.png");

    //ImageResize(&atom, 200, 200);  
    Texture2D texture = LoadTextureFromImage(image);          
    Texture2D textureAtom = LoadTextureFromImage(atom);                                                                 
    
    Texture2D textureExitBtn1 = LoadTextureFromImage(exitBtn1);
    Texture2D textureExitBtn2 = LoadTextureFromImage(exitBtn2);
    Texture2D textureExitBtn3 = LoadTextureFromImage(exitBtn3);

    Rectangle exitRecs[4] = {
        (Rectangle){ 164 + 230, 336 + 10, (float)textureExitBtn1.width * 2, (float)textureExitBtn1.height * 2 },    
        (Rectangle){ 164 + 230, 392 + 10, (float)textureExitBtn2.width * 2, (float)textureExitBtn2.height * 2 },    
        (Rectangle){ 164 + 230, 448 + 10, (float)textureExitBtn3.width * 2, (float)textureExitBtn3.height * 2 },
	(Rectangle){ 464 + offsetXmainMenu, 504 + offsetYmainMenu, 224, 48 }
    };

    UnloadImage(image);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM 
    //Scene1();
    SetExitKey(KEY_NULL);
    //nlohmann::json data = json::parse(DownloadJson("text/helptext.json"));
    //std::cout << "json data: " << data["help"] << std::endl;
    
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
                   DrawTextureEx(textureExitBtn1, {164 + 230, 336 + 10},0,2.0f, WHITE);
                   //DrawRectangleRec(exitRecs[0], RED);
                   Vector2 PositionClick = GetMousePosition();
                   if (CheckCollisionPointRec(PositionClick, exitRecs[0]) && IsMouseButtonDown(0)){
                        DeleteFile("save/save_1.dat");
                        std::cout << "save_1" << std::endl;
                   }
                }

                if (!CheckExistsFile("save/save_2.dat")){
                   if (GuiButton((Rectangle){164, 392, 224, 48}, "New game 2")) ButtonNew1(); 
                } else {
                   if (GuiButton((Rectangle){164, 392, 224, 48}, "SAVE 2")) ButtonLoad1();
                   DrawTextureEx(textureExitBtn2,{ 164 + 230, 392 + 10},0,2.0f, WHITE);
                   //DrawRectangleRec(exitRecs[1], GREEN);
                   Vector2 PositionClick = GetMousePosition();
                   if (CheckCollisionPointRec(PositionClick, exitRecs[1]) && IsMouseButtonDown(0)){
                        DeleteFile("save/save_2.dat");
                        std::cout << "save_2" << std::endl;
                   }
                } 

                if (!CheckExistsFile("save/save_3.dat")){
                   if (GuiButton((Rectangle){164, 448, 224, 48}, "New game 3")) ButtonNew2(); 
                } else {
                   if (GuiButton((Rectangle){164, 448, 224, 48}, "SAVE 3")) ButtonLoad2();
                   DrawTextureEx(textureExitBtn3, {164 + 230, 448 + 10},0,2.0f, WHITE);
                   //DrawRectangleRec(exitRecs[2], BLUE);
                   Vector2 PositionClick = GetMousePosition();
                   if (CheckCollisionPointRec(PositionClick, exitRecs[2]) && IsMouseButtonDown(0)){
                        DeleteFile("save/save_3.dat");
                        std::cout << "save_3" << std::endl;
                   }
                }
		if (GuiButton(exitRecs[3], "BACK")) selectBt = menu;
                //if (CheckExistsFile("save/save_2.dat")) if (GuiButton((Rectangle){ 164, 392, 224, 48 }, "SAVE 2")) Button1(); 
                //if (CheckExistsFile("save/save_3.dat")) if (GuiButton((Rectangle){ 164, 448, 224, 48 }, "SAVE 3")) Button2();  
            }else{
                if (GuiButton(layoutRecs[0], "EXIT")) ExitBtn(); 
                if (GuiButton(layoutRecs[1], "OPTIONS")) OptionsBtn(); 
                if (GuiButton(layoutRecs[2], "PLAY")) PlayBtn();
                if (GuiButton(layoutRecs[3], "HELP")) OptionsBtn();
            }
            Vector2 PositionClick = GetMousePosition();
            if (CheckCollisionPointRec(PositionClick, layoutRecs[3]) && IsMouseButtonPressed(0)){
               isHelpMenu =! isHelpMenu; 
            }
            if (isHelpMenu){
                nlohmann::json data = json::parse(DownloadJson("text/helptext.json"));
                DrawText(TextFormat(std::string(data["help"]).c_str()), 550, 200, 20, WHITE);
            } 
            //DrawText(TextFormat(std::string(data["help"]).c_str()), 550, 200, 20, WHITE);


            //GuiLabel(layoutRecs[3], "Science tycoon");
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }



   // 

    

    //--------------------------------------------------------------------------------------

    return 0;
}


