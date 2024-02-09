#include <iostream>
#include <fstream>
#include <string>
#include "raylib-cpp.hpp"
#include "Structs.cpp"
#include "SaveData.cpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <stopwatch/Stopwatch.hpp>
#include <unordered_map>
#include <GLFW/glfw3.h>
#include <map>
#include <ctime>
#include <thread>         // std::thread

using json = nlohmann::json;
namespace sw = stopwatch;

const float SizeObj = 5.0f;
const float SizeMenu = 2.0f;
struct EntityStruct MainHero;
struct EntityStruct Table;
struct RoomStruct RoomInfo;
struct TileStruct FloorTile;

bool ButtonPlayPressed = false;
bool ButtonExitPressed = false;
bool ShowMenu = false;

int save_num; 
const char* bool_cast(const bool b) {
    return b ? "true" : "false";
}

///
  /// 
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void Scene1(int saveNumber, Saving * data = nullptr)
{

    allObj.resize(10);
    int amountBuildCell = 10;
    int amountActiveBuildCell = 0;
    BuildObj buildCells [amountBuildCell];
    int pointsCell [amountBuildCell];
    
    for (int i = 0; i < amountBuildCell; ++i){ 
        
      BuildObj buildCell("buildCell" + std::to_string(i),"src/location/laboratory/buildingCell.png", 1.5f);
  
      allObj[i].SetPosObj(150 + 100 * i, 500 );
      buildCell.SetPosRect(150 + 100 * i, 500);
      buildCells[i] = buildCell;
      buildCell.id = i;
      if (data != nullptr){

      }
    }
  
    sw::Stopwatch* my_watch;
    bool ExitstTimer = false;
    //Take the time

    std::cout << "1" << std::endl;

    //------------------------------------------------------------------------------------
    // Initialization
    //------------------------------------------------------------------------------------
 
    Player *hero; 
    if (data != nullptr){
      Player her("src/image/HeroAnimation/DemonSciencer.gif",data->Knowledge, data->money);
      hero = &her;
      Tech20Century = data->Tech20Century;
      Transistor = data->Transistor;
      Computer = data->Computer;
      material = data->material;
      Mathematics = data->Mathematics;
      Being = data->Being;
      NaNtech = data->NaNtech;
      QuatumTech = data->QuatumTech;	  
      ColdNuke = data->ColdNuke;	  
      WarpEngine = data->WarpEngine;	  
      NeuralNetwork = data->NeuralNetwork;
      ArtificialIntellect = data->ArtificialIntellect;
      Robot = data->Robot;
      Singularit = data->Singularit;
      Knowledge_Point = hero->points; 
      Money_Point = hero->money;        
    }else{
      Player her("src/image/HeroAnimation/DemonSciencer.gif",0, 700);
      hero = &her;
      Knowledge_Point = 0; 
      Money_Point = 500;   
    }


    int points = 0;
    bool Show_HUD = false;

    //Floor
    FloorTile.PositionSpawn = (Vector2){0, 0};
    FloorTile.ImageTile = LoadImage("src/location/laboratory/floor.png");
    FloorTile.TextureTile = LoadTextureFromImage(FloorTile.ImageTile);
    FloorTile.CollisionRec = (Rectangle){ FloorTile.PositionSpawn.x, FloorTile.PositionSpawn.y, (float)FloorTile.TextureTile.width, (float)FloorTile.TextureTile.height};

    Object computer("computer","src/computer.png", 4.0f);
    computer.SetPosObj(200, 200);

    Object panel("panel","src/panel.png", SizeObj);
    panel.SetPosObj(600, 230);
    
    Object panelHelp("panel","GUI/panelHelp/panelHelp.png", SizeObj);
    panelHelp.SetPosObj(540, 190);

    //Camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ hero->ReturnPositionX() + 20.0f, hero->ReturnPositionY() + 20.0f };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Object dispenser("dispenser","src/dispenser.png", SizeObj);
    dispenser.SetPosObj(1000, 300);
    dispenser.setSize(2.5f);
    float increaseSizeCollisionArea = 1.5f;

    Object epress("Epress","src/epress.gif", SizeObj);
    epress.SetPosObj(950, 180);
    
    std::vector<Object> game_obj_collide;
    game_obj_collide.push_back(computer);
    game_obj_collide.push_back(epress);

    //Vector2 dataPoint = GetScreenToWorld2D((Vector2){40,200}, camera);
    Object buttonTree("buttonTree","GUI/buttonSci/ButtonSci.png", SizeMenu);
    buttonTree.SetPosObj(20,170);

    //RoomInit
    RoomInfo.PositionSpawn = (Vector2){ 0, 0 };
    RoomInfo.RoomTexImg = LoadImage("src/location/laboratory/LaboratoryHub.png");
    RoomInfo.RoomTex = LoadTextureFromImage(RoomInfo.RoomTexImg);
    RoomInfo.CollisionRec = (Rectangle){ 0.0f, 0.0f, (float)RoomInfo.RoomTex.width, (float)RoomInfo.RoomTex.height};


    Table.PositionSpawn = (Vector2){ 10, 0 };
    Table.img = LoadImage("src/location/laboratory/Table.png");
    Table.imgAnim = LoadTextureFromImage(Table.img);
    Table.frameRec = (Rectangle){ 0.0f, 0.0f, (float)Table.imgAnim.width, (float)Table.imgAnim.height};

    //VesselInit
    Vector2 PositionSpawnVessel = { 200, 225 };
    Image Vessel = LoadImage("src/image/Science/ChemicalVessel.png");
    Texture2D VesselAnim = LoadTextureFromImage(Vessel);
    Rectangle frameRecVessel = { 0.0f, 0.0f, (float)VesselAnim.width, (float)VesselAnim.height};
    
    BuildObj tableReserarchMin("tableResearch","src/tableResearch.gif", 4.5f);
    BuildObj tableReserarchMid("tableResearch2","src/tableResearch2.gif", 4.5f);
    BuildObj tableReserarchTop("tableResearch3","src/tableResearch3.gif", 4.5f);
    std::map<std::string, BuildObj> tables = {
        { "tableResearch", tableReserarchMin},
        { "tableResearch2", tableReserarchMid},
        { "tableResearch3", tableReserarchTop}
    };

    my_watch = new sw::Stopwatch;
    my_watch->start();
    my_watch->reset();           
    ExitstTimer = true;
    
    bool isHelpOpen = false;

    while (!WindowShouldClose())
    {
        
        if (IsKeyPressed(KEY_F1)){
            isHelpOpen = !isHelpOpen;
        }


        if (IsKeyPressed(KEY_F4)){
            if (ExitstTimer){
                ExitstTimer = false;
                delete my_watch;
            }
        }
        if (IsKeyPressed(KEY_F5)){
            my_watch = new sw::Stopwatch;
            my_watch->start();
            my_watch->reset();           
            ExitstTimer = true;

        }
        if (IsKeyPressed(KEY_F3)){
            LoadData("save/", "save_1"); 
        }
        if (!IsPause){
            hero->MoveHero();
        }
        hero->FramesIncrement();
        
        camera.target = (Vector2){ hero->ReturnPositionX() + 20, hero->ReturnPositionY() + 20};
     
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);
            
            DrawTextureEx(RoomInfo.RoomTex, RoomInfo.PositionSpawn, 0, 7.5, WHITE);

            panel.DrawObj();

            computer.DrawObj();
            dispenser.DrawObj();
        
            hero->collisionDetect(computer.ReturnRect(false, camera));
            //hero->collisionDetect(dispenser.ReturnRect(true, camera));

            if (ExitstTimer){
                auto duration_ms = my_watch->elapsed<sw::s>();
                std::cout << "Elapsed: " << duration_ms << " seconds." << std::endl;
                if (duration_ms >= 20){
                    DrawText(TextFormat("You can get money"), 950, 250, 20, BLUE);
                    IsCanGetMoney = true;
                }else{
                    DrawText(TextFormat("Time for get money: %02i", duration_ms), 950, 250, 20, BLUE); 
                    IsCanGetMoney = false;
                } 
            }
            if (CheckCollisionRecs(hero->ReturnframeRec(), dispenser.ReturnRect(false, camera)) && IsKeyPressed(KEY_E) && IsCanGetMoney){
                std::cout << "get money" << std::endl;
                Money_Point = hero->money + 50;
                IsCanGetMoney = false;

                epress.DrawObj();

                if (ExitstTimer){
                    ExitstTimer = false;
                    delete my_watch;
                }
                
                my_watch = new sw::Stopwatch;
                my_watch->start();
                my_watch->reset();           
                ExitstTimer = true;
            }

            if (CheckCollisionRecs(hero->ReturnframeRec(), dispenser.ReturnRect(false, camera))){
                epress.DrawObj();
            }

            for (int i = 0; i < amountBuildCell; i++)
            {
                
                allObj[i].Draw();
               
	            clickEvent(camera, hero->money, i, tables, buildCells);
                buildCells[i].clickEventListen(camera, hero->money, i, tables, buildCells);
                pointsCell[i] = buildCells[i].countPointRet(hero->points, 5, buildCells[i].IsExist());
                hero->points += pointsCell[i];
                
            }
            
            hero->DrawHero();
            hero->SpeedUp();
            
        
        EndMode2D();
        selectionBtn(camera, chooseTable, tables, buildCells);
        
        DrawText(TextFormat("InBorder: %s", bool_cast(CheckCollisionRecs(hero->ReturnframeRec(), computer.ReturnRect(false)))), 30, 140, 20, WHITE);

        buttonTree.DrawOutline(buttonTree.IsHoverObj());
        bool Show_HUD = buttonTree.clickEventListenSimple(camera);
        if (Show_HUD){ 
            hero->showHUDtech(Show_HUD);
        }else {
            hero->showHUDtech(false); 
        } 
        buttonTree.DrawObj();
        if (isHelpOpen) panelHelp.DrawObj();
        if (IsKeyPressed(KEY_ESCAPE)){
            ShowMenu = !ShowMenu;
            IsPause = !IsPause;
        }
        if (ShowMenu || ButtonPlayPressed){
            ButtonPlayPressed = GuiButton((Rectangle){ 552, 288, 120, 48 }, "Play"); 
            ButtonExitPressed = GuiButton((Rectangle){ 552, 360, 120, 48 }, "Save and exit"); 
        }
        if (ButtonPlayPressed){
            IsPause = !IsPause;
            ShowMenu = !ShowMenu;
        }
        if (ButtonExitPressed){ 
          dataGame[saveNumber].Knowledge = Knowledge_Point;
          dataGame[saveNumber].money = Money_Point;
          dataGame[saveNumber].Tech20Century = Tech20Century;
          dataGame[saveNumber].Transistor = Transistor;
          dataGame[saveNumber].Computer = Computer;
          dataGame[saveNumber].material = material;
          dataGame[saveNumber].Mathematics = Mathematics;
          dataGame[saveNumber].Being = Being;
          dataGame[saveNumber].NaNtech = NaNtech;
          dataGame[saveNumber].QuatumTech = QuatumTech;
          dataGame[saveNumber].ColdNuke = ColdNuke;
          dataGame[saveNumber].WarpEngine = WarpEngine;
	      dataGame[saveNumber].NeuralNetwork = NeuralNetwork;
          dataGame[saveNumber].ArtificialIntellect = ArtificialIntellect;
          dataGame[saveNumber].Robot = Robot;
          dataGame[saveNumber].Singularit = Singularit;
	  
          saveNumber = saveNumber + 1;
          std::string numberSaveStr = std::to_string(saveNumber);
          std::string savePath = "save/";
          std::string saveName = "save_";
          saveName = saveName + numberSaveStr;
          SaveData("save/", saveName);
          CloseWindow(); 
        }

        hero->points = Knowledge_Point;
        hero->money = Money_Point;  
        DrawText(TextFormat("Knowledge : %04d", hero->points), 30, 80, 20, WHITE);
        DrawText(TextFormat("Money : %04d", hero->money), 30, 110, 20, WHITE);
        
        if (isHelpOpen){
            Rectangle layoutHelp = { 344, 352, 224, 96 };
            Rectangle HelpText = { 344, 352, 224, 96 };
            IsPause = true;
            nlohmann::json data = json::parse(DownloadJson("text/helptext.json"));
            DrawText(TextFormat(std::string(data["help"]).c_str()), 550, 200, 20, WHITE);
        }else{
            IsPause = false;
        }

        EndDrawing();

    }
}
