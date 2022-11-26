#include <iostream>
#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#pragma once
using json = nlohmann::json;
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
//
    
    class Object{
        private:
        public:
        protected:
        int Obj_id;
        Vector2 PositionSpawn;
        std::string Path; 
        Image image; 
        Texture2D TextureGame; 
        Rectangle CollisionRec;
        

        Object(int id,
                raylib::Vector2 Pos, 
                std::string path) : Obj_id(id), PositionSpawn(Pos), Path(path){
            Obj_id = id;
            PositionSpawn = Pos;
            image = LoadImage(path.c_str());
            TextureGame = LoadTextureFromImage(image);
            CollisionRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)TextureGame.width, (float)TextureGame.height};
        }

    };
    /*
    class Entity: public Object{

        private:
        public:
        protected:
        float speed;
        int points;
        int nextFrameDataOffset;
        int currentFrame;
        int framesCounter;
        int flipsCounterLeft;
        int flipsCounterRight;
        int framesSpeed;
        int animFrames;

        Entity(float speed_constr,
                int points_constr, 
                int nextFrameDataOffset_constr, 
                int currentFrame_constr, 
                int framesCounter_constr, 
                int flipsCounterLeft_constr, 
                int flipsCounterRight_constr, 
                int framesSpeed_constr, 
                int animFrames_constr):Object(Obj_id, PositionSpawn, image){

            speed = speed_constr;
            points = points_constr;
            nextFrameDataOffset = nextFrameDataOffset_constr;
            currentFrame = currentFrame_constr;
            framesCounter = framesCounter_constr;
            flipsCounterLeft = flipsCounterLeft_constr;
            flipsCounterRight = flipsCounterRight_constr;
            framesSpeed = framesSpeed_constr;
            animFrames = animFrames_constr;

        }
    };

    
    
    class Player: public Entity{
        private:
        public:
        
        Player(){
            
        }
    };
    class NPC: public Entity{
        private:
        public:
        
        NPC(){
            
        }
    };
    */
    class Tile: public Object{
        private:
        float WidthTile;
        float HeigthTile;
        bool Permeable;
        
        public:
        Tile():Object(Obj_id, PositionSpawn, Path){
            Obj_id = 0;
            PositionSpawn = (Vector2){0.0, 0.0};
            Path = "";
            WidthTile = 0;
            HeigthTile = 0;
            Permeable = false;
        }
        Tile(int Obj_id,Vector2 PositionSpawn,std::string Path, bool PremerableTile):Object(Obj_id, PositionSpawn, Path){
            WidthTile = (float)TextureGame.width;
            HeigthTile = (float)TextureGame.height;
            Permeable = PremerableTile;
            CollisionRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)TextureGame.width, (float)TextureGame.height};
             
            std::cout << "Tile not solid" << "\n"; 
            
        }
        
        void DrawTile(){
            if (this->Permeable)  std::cout << "Tile solid" << "\n";
            DrawTextureRec(TextureGame, CollisionRec, PositionSpawn, WHITE);
        }
        
        /*
        void DrawTile(Vector2 PositionSpawn, Image image, Texture2D TextureTile, Rectangle CollisionRec){
            //if (Permeable) Делается область для контача;
            DrawTextureRec(TextureTile, CollisionRec, PositionSpawn, WHITE);
        }*/

        int IdTile(){
            return Obj_id;
        }
    };

    
    class Room{
        private:
        //json для загрузки пути с id тайлов
        json JsonDataPath;
        json JsonData;
        int WidthRoom;
        int HeigthRoom;
        int AmountTiles;
        int AmountTilesUnical;
        int WidthTiles;
        int HeigthTiles;
        //std::vector<std::string> paths;
        std::vector<Tile> Floor;
        std::vector<Tile> Wall;
        std::vector<int> FloorId;
        std::vector<int> WallId;
        public:
        Room(std::string jsonPath, std::string jsonPathData) {
            //Path to image json
            JsonDataPath = json::parse(DownloadJson(jsonPathData));
            
            JsonDataPath["Length"].get_to(AmountTilesUnical);
            std::cout << "AmountTilesUnical :" << AmountTilesUnical << "\n";
            
            
            //Array width and length room
            JsonData = json::parse(DownloadJson(jsonPath));
            JsonData["Width"].get_to(WidthTiles);
            JsonData["Length"].get_to(HeigthTiles);
            //Array number with id for drawing room
            AmountTiles = WidthTiles * HeigthTiles;
            
            
            std::cout << "Floor.size :" << Floor.size() << "\n";
            
            
            std::cout << "Wall.size :" << Wall.size() << "\n";
            JsonData["Floor"].get_to(FloorId);
            JsonData["Wall"].get_to(WallId);
            
            //Download string
            std::cout << "Width :" << WidthTiles << "\n";
            std::cout << "Length :" << HeigthTiles << "\n";
            std::cout << "AmountTiles :" << AmountTiles << "\n";

            for (int i = 0; i < AmountTiles; i++){
                std::cout << FloorId[i] << "\n";
                //std::cout << WallId[i] << "\n";
            }
            
        }

        InitArraysRoom(){
            Floor.resize(AmountTiles);
            Wall.resize(AmountTiles);

        }

         /*
        void DrawTileXfloor(){
            for (int i = 0; i <= WidthTiles; i++){
                
            }
        }
       
        void tileFullingTile(){
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
    };

    
    struct TileStruct{
        Vector2 PositionSpawn;
        Texture2D TextureTile;
        Image ImageTile;
        Rectangle CollisionRec;
        bool Permeable; 
    };

    struct RoomStruct{
        Vector2 PositionSpawn;
        Texture2D RoomTex;
        Image RoomTexImg;
        Rectangle CollisionRec; 
    };
    
    struct EntityStruct{
        Vector2 PositionSpawn;
        Image img; //demonSciencer
        Texture2D imgAnim; //demonSciencerAnim
        Rectangle frameRec; 
        float speedHero;
        int points;
        int nextFrameDataOffset;
        int currentFrame;
        int framesCounter;
        int flipsCounterLeft;
        int flipsCounterRight;
        int framesSpeed;
        int animFrames;
    };

    
    
    
    
