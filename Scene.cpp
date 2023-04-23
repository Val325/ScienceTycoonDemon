#include <iostream>
#include <fstream>
#include <string>
#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"
#include "Structs.cpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>

using json = nlohmann::json;

    const float SizeObj = 5.0f;

    struct EntityStruct MainHero;
    struct EntityStruct Table;
    struct RoomStruct RoomInfo;
    struct TileStruct FloorTile;

    

    const char* bool_cast(const bool b) {
        return b ? "true" : "false";
    }

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void Scene1(void)
{

//------------------------------------------------------------------------------------
// Initialization
//---   ---------------------------------------------------------------------------------
    
    int points;

    //Floor
    FloorTile.PositionSpawn = (Vector2){0, 0};
    FloorTile.ImageTile = LoadImage("src/location/laboratory/floor.png");
    FloorTile.TextureTile = LoadTextureFromImage(FloorTile.ImageTile);
    FloorTile.CollisionRec = (Rectangle){ FloorTile.PositionSpawn.x, FloorTile.PositionSpawn.y, (float)FloorTile.TextureTile.width, (float)FloorTile.TextureTile.height};


    Player hero("src/image/HeroAnimation/DemonSciencer.gif");

    Object computer("computer","src/computer.png", 4.0f);
    computer.SetPosObj(200, 200);

    Object panel("panel","src/panel.png", SizeObj);
    panel.SetPosObj(600, 230);
    /*
    BuildObj buildCell("buildCell","src/location/laboratory/buildingCell.png", 1.5f);
    buildCell.SetPosObj(200, 500);
    buildCell.SetPosRect(buildCell.getPosVector().x,buildCell.getPosVector().y);
    */
    int maxOjb = 5;
    BuildObj BuildObjArray[maxOjb];


    for (int i = 0; i < maxOjb; ++i)
    {
        int distanceX = 200 + i * 200;
        BuildObj buildCell("buildCell" + std::to_string(i),"src/location/laboratory/buildingCell.png", 1.5f);
        BuildObjArray[i] = buildCell;
        BuildObjArray[i].SetPosObj(distanceX, 500);
        BuildObjArray[i].SetPosRect(BuildObjArray[i].getPosVector().x,BuildObjArray[i].getPosVector().y);
    }

    //Camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ hero.ReturnPositionX() + 20.0f, hero.ReturnPositionY() + 20.0f };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


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


    SetTargetFPS(60);
    
    
    while (!WindowShouldClose())    
    {
        
        
        hero.MoveHero();

        hero.FramesIncrement();
        
         
            


        /*
        points = buildCell.countPointRet(hero.points, buildCell.IsExist());
        hero.points = points;*/
        camera.target = (Vector2){ hero.ReturnPositionX() + 20, hero.ReturnPositionY() + 20};

        


        BeginDrawing();
        
       
        ClearBackground(BLACK);
        
        BeginMode2D(camera);    
            DrawTextureEx(RoomInfo.RoomTex, RoomInfo.PositionSpawn, 0, 7.5, WHITE);

            panel.DrawObj();

            computer.DrawObj();
            
            hero.collisionDetect(computer.ReturnRect(false));
            hero.DrawHero();
            for (BuildObj obj : BuildObjArray){
                points = obj.countPointRet(hero.points, obj.IsExist());
                hero.points += points;
                obj.clickEventListen(camera);
                obj.countPoint(0, obj.IsExist());
                obj.Draw();
            }
            
            //buildCell.DrawRect();
            
        EndMode2D();
        
        //Log

        
        //hero.DrawStatistics();
        
        DrawText(TextFormat("InBorder: %s", bool_cast(CheckCollisionRecs(hero.ReturnframeRec(), computer.ReturnRect(false)))), 30, 140, 20, WHITE);
        DrawText(TextFormat("Knowledge (Points): %04d", points), 30, 80, 20, WHITE);
        


        EndDrawing();

    }
    

    
}





