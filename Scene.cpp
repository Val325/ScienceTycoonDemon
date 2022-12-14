#include <iostream>
#include <fstream>
#include <string>
#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"
#include "Structs.cpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>

using json = nlohmann::json;

    struct EntityStruct MainHero;
    struct EntityStruct Table;
    struct RoomStruct RoomInfo;
    struct TileStruct FloorTile;


    void animationHero() {
        if (MainHero.framesCounter >= MainHero.animFrames){

            MainHero.currentFrame++;

            if (MainHero.currentFrame >= 5) MainHero.currentFrame = 0;

                MainHero.nextFrameDataOffset = MainHero.img.height*MainHero.img.height*4*MainHero.currentFrame;

                UpdateTexture(MainHero.imgAnim, MainHero.img.data + MainHero.nextFrameDataOffset);



                MainHero.framesCounter = 0;


        }
        
    }
    
    //------------------------------------------------------------------------------------
    // Flip
    //------------------------------------------------------------------------------------
    void flipLeft(){

        if (MainHero.flipsCounterLeft > 0) {
            MainHero.flipsCounterLeft = 0;

            }else{

                MainHero.img.width = -(MainHero.img.width);
                MainHero.frameRec.width = -(MainHero.frameRec.width);


            };
        MainHero.flipsCounterLeft++;

        
    }

    void flipRight(){

        if (MainHero.flipsCounterRight > 0) {
            MainHero.flipsCounterRight = 0;

            }else{


                MainHero.img.width = -(MainHero.img.width);
                MainHero.frameRec.width = -(MainHero.frameRec.width);


            };
        MainHero.flipsCounterRight++;

        
    }
    //------------------------------------------------------------------------------------
    // Move
    //------------------------------------------------------------------------------------
    void Up(){
        if (IsKeyDown(KEY_UP)){
            MainHero.PositionSpawn.y -= MainHero.speedHero;
            animationHero();
        }
       
    }
    void Down(){
        if (IsKeyDown(KEY_DOWN)){
            MainHero.PositionSpawn.y += MainHero.speedHero;
            animationHero();
        }
            
        }
    void Right(){
        if (IsKeyPressed(KEY_RIGHT)){
            flipRight();
            MainHero.flipsCounterLeft = 0;

        }


        if (IsKeyDown(KEY_RIGHT)){
            MainHero.PositionSpawn.x += MainHero.speedHero;
            animationHero();
        }
        
    }
    void Left(){
        if (IsKeyPressed(KEY_LEFT)){

            flipLeft();
            MainHero.flipsCounterRight = 0;
            
        }
        if (IsKeyDown(KEY_LEFT)){
            animationHero();
            MainHero.PositionSpawn.x -= MainHero.speedHero;
            

        }
        
    }
    void MoveHero(){
        Up();
        Down();
        Right();
        Left();

    }
    
    //------------------------------------------------------------------------------------
    // HeroEndFunctions
    //------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------
    // TileSetFunction
    //------------------------------------------------------------------------------------
    /*
    void tileFullingOneTile(){
        int monitorHeight = GetScreenHeight();
        int monitorWidth = GetScreenWidth();

        int AmountTotalTileWidth = monitorWidth / Floor.TextureTile.width;
        int AmountTotalTileHeight = monitorHeight / Floor.TextureTile.height;

        //FullingTileX
        for (int i = 0; i < AmountTotalTileWidth; i++) { 
            DrawTextureRec(Floor.TextureTile, Floor.CollisionRec, (Vector2){(Floor.TextureTile.width)* i,0.0f}, WHITE);
                for (int j = 0; j < AmountTotalTileHeight + 1; j++) { 
                DrawTextureRec(Floor.TextureTile, Floor.CollisionRec, (Vector2){(Floor.TextureTile.width)* i, (Floor.TextureTile.height)* j}, WHITE);
            }
        }
    }

    void tileFullFloor(){}
    void tileFullWall(){}
    */
    //------------------------------------------------------------------------------------
    // TileSetFunctionEnd
    //------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void Scene1(void)
{

//------------------------------------------------------------------------------------
// Initialization
//---   ---------------------------------------------------------------------------------
    
    //Floor
    /*
    FloorTile.PositionSpawn = (Vector2){0.0f, 0.0f};
    FloorTile.ImageTile = LoadImage("src/location/laboratory/floor.png");
    FloorTile.TextureTile = LoadTextureFromImage(FloorTile.ImageTile);
    FloorTile.CollisionRec = (Rectangle){ FloorTile.PositionSpawn.x, FloorTile.PositionSpawn.y, (float)FloorTile.TextureTile.width, (float)FloorTile.TextureTile.height};
    */
    //HeroInit
    MainHero.PositionSpawn = (Vector2){ (float)GetScreenWidth()/2, (float)GetScreenHeight()/2 };
    MainHero.animFrames = 0;
    MainHero.img = LoadImageAnim("src/image/HeroAnimation/DemonSciencer.gif", &MainHero.animFrames);
    MainHero.imgAnim = LoadTextureFromImage(MainHero.img);
    MainHero.frameRec = (Rectangle){ 0.0f, 0.0f, (float)MainHero.imgAnim.width, (float)MainHero.imgAnim.height};
    MainHero.points = 0;
    MainHero.speedHero = 2.0f;
    MainHero.nextFrameDataOffset = 0;
    MainHero.currentFrame = 0;
    MainHero.framesCounter = 0;
    MainHero.flipsCounterLeft = 0;
    MainHero.flipsCounterRight = 1;

    //RoomInit
    RoomInfo.PositionSpawn = (Vector2){ 150, 0 };
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





    

    Room Lab("src/location/laboratory/Tiles/TiledMapLAboratory.json","src/location/laboratory/Tiles/JsonDataPath.json");
    
    
    
    SetTargetFPS(60);
    
    //DownloadJson();

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        MainHero.framesCounter++;
        MoveHero();


        BeginDrawing();

        

        ClearBackground(RAYWHITE);



        

        //tileFullingOneTile();


        //DrawTextureEx(RoomInfo.RoomTex, RoomInfo.PositionSpawn, 0, 6, WHITE);
        DrawTextureRec(MainHero.imgAnim, MainHero.frameRec, MainHero.PositionSpawn, WHITE);
        
        //DrawTextureRec(Table.imgAnim, Table.frameRec, Table.PositionSpawn, WHITE);
        //DrawTextureRec(VesselAnim, frameRecVessel, PositionSpawnVessel, WHITE);

        //Log
        
        DrawText(TextFormat("PositionX: %04f", MainHero.PositionSpawn.x), 30, 20, 20, WHITE);
        DrawText(TextFormat("PositionY: %04f", MainHero.PositionSpawn.y), 30, 50, 20, WHITE);
        DrawText(TextFormat("Points: %01i", MainHero.points), 30, 80, 20, WHITE);
        //DrawText(TextFormat("NumberArrayFromJSON: %04i", JsonToArrayNumber("src/location/laboratory/Tiles/TiledMapLAboratory.json", 250)), 30, 110, 20, GRAY);
        DrawText(TextFormat("MainHero.animFrames: %04f", MainHero.animFrames), 30, 140, 20, WHITE);
        
        //DownloadJson();

        EndDrawing();

    }
    

    
}





