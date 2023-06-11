#include <iostream>
#include <fstream>
#include <string>
#include "raylib-cpp.hpp"
#include "Structs.cpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <map>

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
    allObj.resize(10);
    int amountBuildCell = 10;
    int amountActiveBuildCell = 0;
    BuildObj buildCells [amountBuildCell];
    int pointsCell [amountBuildCell];
    for (int i = 0; i < amountBuildCell; ++i)
    {
        BuildObj buildCell("buildCell" + std::to_string(i),"src/location/laboratory/buildingCell.png", 1.5f);
        buildCell.SetPosObj(200 + 100 * i, 500);
        buildCell.SetPosRect(buildCell.getPosVector().x,buildCell.getPosVector().y);
        buildCells[i] = buildCell;
	buildCell.id = i;
    }
    std::cout << "1" << std::endl; 
//------------------------------------------------------------------------------------
// Initialization
//---   ---------------------------------------------------------------------------------

    
    int points = 0;


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

    
    
    std::cout << "2" << std::endl; 
    
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
    
    BuildObj tableReserarchMin("tableResearch","src/tableResearch.gif", 4.5f);
    BuildObj tableReserarchMid("tableResearch2","src/tableResearch2.gif", 4.5f);
    BuildObj tableReserarchTop("tableResearch3","src/tableResearch3.gif", 4.5f);
    std::cout << "3" << std::endl; 
    std::map<std::string, BuildObj> tables = {
        { "tableResearch", tableReserarchMin},
        { "tableResearch2", tableReserarchMid},
        { "tableResearch3", tableReserarchTop}
    };
    std::cout << "4" << std::endl; 

    SetTargetFPS(60);


    while (!WindowShouldClose())
    {


        hero.MoveHero();

        hero.FramesIncrement();

        
        


        camera.target = (Vector2){ hero.ReturnPositionX() + 20, hero.ReturnPositionY() + 20};




        BeginDrawing();


        ClearBackground(BLACK);

        BeginMode2D(camera);
            DrawTextureEx(RoomInfo.RoomTex, RoomInfo.PositionSpawn, 0, 7.5, WHITE);

            panel.DrawObj();

            computer.DrawObj();

            hero.collisionDetect(computer.ReturnRect(false));
            hero.DrawHero();
            //hero.showHUDtech();
            //buildCells.SelectionPopUp(camera);
	    //buildCells[chooseTable].clickEventListen(camera, hero.money, chooseTable, tables);
            for (int i = 0; i < amountBuildCell; i++)
            {
		
                buildCells[i].clickEventListen(camera, hero.money, i, tables);

	    	buildCells[i].Draw();
		pointsCell[i] = buildCells[i].countPointRet(hero.points, buildCells[i].IsExist());



                //buildCells[i].SelectionPopUp(camera, hero);
              	//buildCells[i].countPoint(0, buildCells[i].IsExist());
                //buildCells[i].Draw();
		//buildCells[i].ReturnPostionClick(camera);
            }
	    
	     

            //buildCell.DrawRect();
            
        EndMode2D();

        //Log


        selectionBtn(camera, chooseTable, tables);
        //hero.DrawStatistics();
        
        DrawText(TextFormat("InBorder: %s", bool_cast(CheckCollisionRecs(hero.ReturnframeRec(), computer.ReturnRect(false)))), 30, 140, 20, WHITE);
        
        for (int i = 0; i < amountBuildCell; ++i)
        {
            pointsCell[i] = buildCells[i].countPointRet(hero.points, buildCells[i].IsExist()); 
            hero.points += pointsCell[i];
	    //selectionBtn(camera, i, tables);
            //buildCells[i].SelectionPopUp(camera, hero, hero.money, buildCells, i, tables);
	    //buildCells[i].Draw();
            
        }
        
        hero.showHUDtech();
       
        DrawText(TextFormat("Knowledge (Points): %04d", hero.points), 30, 80, 20, WHITE);
        DrawText(TextFormat("Money (hryvnia): %04d", hero.money), 30, 110, 20, WHITE);


        EndDrawing();

    }



}
