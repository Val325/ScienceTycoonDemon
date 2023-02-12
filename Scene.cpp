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

    const char* bool_cast(const bool b) {
        return b ? "true" : "false";
    }


    void BorderLimit(){
        bool move = ((MainHero.PositionSpawn.x < 1116 && MainHero.PositionSpawn.x > 76) 
            && (MainHero.PositionSpawn.y < 956 && MainHero.PositionSpawn.y > 240));

        if (move){
            MainHero.canMove = true;
        }else{
            MainHero.canMove = false;
        }



    }

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
        MainHero.canMove = ((MainHero.PositionSpawn.x < 1116 && MainHero.PositionSpawn.x > 76) 
            && (MainHero.PositionSpawn.y < 956 && MainHero.PositionSpawn.y > 240));

        

        

        if (MainHero.canMove)
        {
            Up();
            Down();
            Right();
            Left(); 
        }else{

            if (MainHero.PositionSpawn.x >= 1116)
            {
                if (MainHero.PositionSpawn.y <= 240){
                    Down();
                    Left();
                }else{
                Up();
                Down();
                Left(); 
                }
            } 
            //left top corner
            if (MainHero.PositionSpawn.x <= 76){
                if (MainHero.PositionSpawn.y <= 240 ){
                    Down();
                    Right();
                }else{
                    Up();
                    Down();
                    Right(); 
                }
                
            } 

            if (MainHero.PositionSpawn.y >= 956){
                Up();
                Right();
                Left(); 
            } 
            if (MainHero.PositionSpawn.y <= 240 ){
                if (MainHero.PositionSpawn.x <= 76){
                    Down();
                    Right();
                } else if (MainHero.PositionSpawn.y <= 240){
                    Down();
                    Left();
                }
                else{
                    Down();
                    Right();
                    Left(); 
                } 

            } 
        }
            
        

        
        
        
        
        

    }
        
    
    


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void Scene1(void)
{

//------------------------------------------------------------------------------------
// Initialization
//---   ---------------------------------------------------------------------------------
    



    //Floor
    FloorTile.PositionSpawn = (Vector2){0, 0};
    FloorTile.ImageTile = LoadImage("src/location/laboratory/floor.png");
    FloorTile.TextureTile = LoadTextureFromImage(FloorTile.ImageTile);
    FloorTile.CollisionRec = (Rectangle){ FloorTile.PositionSpawn.x, FloorTile.PositionSpawn.y, (float)FloorTile.TextureTile.width, (float)FloorTile.TextureTile.height};
    
    //HeroInit
    MainHero.PositionSpawn = (Vector2){ (float)GetScreenWidth()/2, (float)GetScreenHeight()/2 };
    MainHero.animFrames = 0;
    MainHero.img = LoadImageAnim("src/image/HeroAnimation/DemonSciencer.gif", &MainHero.animFrames);
    MainHero.imgAnim = LoadTextureFromImage(MainHero.img);

    //This offsets
    MainHero.frameRec = (Rectangle){ MainHero.PositionSpawn.x - 15.0f, MainHero.PositionSpawn.y + 24.0f, (float)MainHero.imgAnim.width, (float)MainHero.imgAnim.height};
    MainHero.points = 0;
    MainHero.speedHero = 2.0f;
    MainHero.nextFrameDataOffset = 0;
    MainHero.currentFrame = 0;
    MainHero.framesCounter = 0;
    MainHero.flipsCounterLeft = 0;
    MainHero.flipsCounterRight = 1;

    

    //Camera
    Camera2D camera = { 0 };
    camera.target = (Vector2){ MainHero.PositionSpawn.x + 20.0f, MainHero.PositionSpawn.y + 20.0f };
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

    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        MainHero.framesCounter++;

        MoveHero();
        //BorderLimit();
        camera.target = (Vector2){ MainHero.PositionSpawn.x + 20, MainHero.PositionSpawn.y + 20 };

        //Rectancle person 
        

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);    
            DrawTextureEx(RoomInfo.RoomTex, RoomInfo.PositionSpawn, 0, 7.5, WHITE);
            DrawTextureRec(MainHero.imgAnim, MainHero.frameRec, MainHero.PositionSpawn, WHITE);
        EndMode2D();

        //Log
        
        DrawText(TextFormat("PositionX: %04f", MainHero.PositionSpawn.x), 30, 20, 20, WHITE);
        DrawText(TextFormat("PositionY: %04f", MainHero.PositionSpawn.y), 30, 50, 20, WHITE);
        DrawText(TextFormat("Points: %01i", MainHero.points), 30, 80, 20, WHITE);
        DrawText(TextFormat("InBorder: %s", bool_cast(MainHero.canMove)), 30, 140, 20, WHITE);
        

        
        //DownloadJson();

        EndDrawing();

    }
    

    
}





