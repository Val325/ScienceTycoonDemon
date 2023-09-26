#include <iostream>
#include <fstream>
#include <string>
#include "raylib-cpp.hpp"
#include "Structs.cpp"
#include "SaveData.cpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <map>

using json = nlohmann::json;
const float SizeObj = 5.0f;
const float SizeMenu = 2.0f;
//int Knowledge_Point = 0;
struct EntityStruct MainHero;
struct EntityStruct Table;
struct RoomStruct RoomInfo;
struct TileStruct FloorTile;

int save_num; 
const char* bool_cast(const bool b) {
    return b ? "true" : "false";
}
///
  /// 
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void Scene1(Saving * data = nullptr)
{

    allObj.resize(10);
    int amountBuildCell = 10;
    int amountActiveBuildCell = 0;
    BuildObj buildCells [amountBuildCell];
    int pointsCell [amountBuildCell];
    for (int i = 0; i < amountBuildCell; ++i){
        BuildObj buildCell("buildCell" + std::to_string(i),"src/location/laboratory/buildingCell.png", 1.5f);
        //allObj[i].SetPosObj(150 + 100 * i, 500);
        allObj[i].SetPosObj(150 + 100 * i, 500);
        //buildCell.SetPosObj(150 + 100 * i, 500);
        buildCell.SetPosRect(150 + 100 * i, 500);
        buildCells[i] = buildCell;
	    buildCell.id = i;
    } 
    std::cout << "1" << std::endl;

    //------------------------------------------------------------------------------------
    // Initialization
    //------------------------------------------------------------------------------------

    Player *hero; 
    if (data != nullptr){
      Player her("src/image/HeroAnimation/DemonSciencer.gif",data->Knowledge, data->money);
      hero = &her;
    }else{
      Player her("src/image/HeroAnimation/DemonSciencer.gif",0, 700);
      hero = &her;
    }
    Knowledge_Point += hero->points; 
    
    int points = 0;
    bool Show_HUD = false;

    //Floor
    FloorTile.PositionSpawn = (Vector2){0, 0};
    FloorTile.ImageTile = LoadImage("src/location/laboratory/floor.png");
    FloorTile.TextureTile = LoadTextureFromImage(FloorTile.ImageTile);
    FloorTile.CollisionRec = (Rectangle){ FloorTile.PositionSpawn.x, FloorTile.PositionSpawn.y, (float)FloorTile.TextureTile.width, (float)FloorTile.TextureTile.height};


    //Player hero("src/image/HeroAnimation/DemonSciencer.gif");


    Object computer("computer","src/computer.png", 4.0f);
    computer.SetPosObj(200, 200);

    Object panel("panel","src/panel.png", SizeObj);
    panel.SetPosObj(600, 230);

    
    std::cout << "2" << std::endl; 
    
    //Camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ hero->ReturnPositionX() + 20.0f, hero->ReturnPositionY() + 20.0f };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

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

    SetTargetFPS(60);

    //hero.points = know_point;
    //hero.money = money_point;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F2)){
            dataGame[0].Knowledge = hero->points;
            dataGame[0].money = hero->money; 
            SaveData("save/", "save_1");
        }
        if (IsKeyPressed(KEY_F3)){
            LoadData("save/", "save_1"); 
        }
        hero->MoveHero();

        hero->FramesIncrement();
        
        camera.target = (Vector2){ hero->ReturnPositionX() + 20, hero->ReturnPositionY() + 20};
     
        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);
            DrawTextureEx(RoomInfo.RoomTex, RoomInfo.PositionSpawn, 0, 7.5, WHITE);

            panel.DrawObj();

            computer.DrawObj();
            
            hero->collisionDetect(computer.ReturnRect(false));
       
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

        //Log


        selectionBtn(camera, chooseTable, tables, buildCells);
        //hero.DrawStatistics();
        
        DrawText(TextFormat("InBorder: %s", bool_cast(CheckCollisionRecs(hero->ReturnframeRec(), computer.ReturnRect(false)))), 30, 140, 20, WHITE);
        
        for (int i = 0; i < amountBuildCell; ++i)
        {

            /*
            pointsCell[i] = buildCells[i].countPointRet(hero.points, 5, buildCells[i].IsExist()); 
            hero.points += pointsCell[i];
            */




            //allObj[i].SetPosObj(150 + 100 * i, 500);

            //allObj[i].SetPosRect(150 + 100 * i, 500);  
	    //selectionBtn(camera, i, tables);
            //buildCells[i].SelectionPopUp(camera, hero, hero.money, buildCells, i, tables);
	    //buildCells[i].Draw();
	    
            
        }
        //hero->points = Knowledge_Point;
        //hero.showHUDtech();
        //hero->points = Knowledge_Point;
       // hero->points = Knowledge_Point; 
        buttonTree.DrawOutline(buttonTree.IsHoverObj());
        bool Show_HUD = buttonTree.clickEventListenSimple(camera);
        if (Show_HUD){ 
            hero->showHUDtech(Show_HUD);
        }else {
            hero->showHUDtech(false); 
        } 
        buttonTree.DrawObj();
        
        //know_point = hero.points;
        //money_point = hero.money;
        //hero.points = know_point;
        //hero.money = money_point;
        //
        //Knowledge_Point += hero->points;
        hero->points = Knowledge_Point; 
        DrawText(TextFormat("Knowledge (Points): %04d", hero->points), 30, 80, 20, WHITE);
        DrawText(TextFormat("Money (hryvnia): %04d", hero->money), 30, 110, 20, WHITE);


        EndDrawing();

    }



}
