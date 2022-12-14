#include <iostream>
#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <set>

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
        Tile(int Obj_id, std::string Path, bool PremerableTile):Object(Obj_id, PositionSpawn, Path){
            WidthTile = (float)TextureGame.width;
            HeigthTile = (float)TextureGame.height;
            Permeable = PremerableTile;
            CollisionRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)TextureGame.width, (float)TextureGame.height};

            
        }
        Tile(int Obj_id, raylib::Vector2 Pos, std::string Path, bool PremerableTile):Object(Obj_id, PositionSpawn, Path){
            PositionSpawn = (Vector2)Pos;
            WidthTile = (float)TextureGame.width;
            HeigthTile = (float)TextureGame.height;
            Permeable = PremerableTile;
            CollisionRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)TextureGame.width, (float)TextureGame.height};

            
        }
        
        void DrawTile(){
            if (this->Permeable)  std::cout << "Tile solid" << "\n";
            DrawTextureRec(TextureGame, CollisionRec, PositionSpawn, WHITE);
        }
        void DrawTile(Vector2 PositionSpawn){
            if (this->Permeable)  std::cout << "Tile solid" << "\n";
            DrawTextureRec(TextureGame, CollisionRec, PositionSpawn, WHITE);
        }

        void DrawTile(float x, float y){
            if (this->Permeable)  std::cout << "Tile solid" << "\n";
            DrawTextureRec(TextureGame, CollisionRec, (Vector2){x, y}, WHITE);
        }
        int IdTile(){
            return Obj_id;
        }
        Texture2D TextureGet(){
            return TextureGame;
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
        std::string nameId;
        std::vector<std::string> paths;
        std::vector<Tile> Floor;
        std::vector<Tile> Wall;
        std::vector<int> FloorId;
        std::set<int> FloorIdUnique;
        std::vector<int> WallId;
        std::set<int> WallIdUnique;
        public:
        Room(std::string jsonPath, std::string jsonPathData){
            const int widthBlock = 64;
            const int heightBlock = 64;


            nameId = "idTile";
            //Path to image json
            JsonDataPath = json::parse(DownloadJson(jsonPathData));
            
            AmountTilesUnical = JsonDataPath.size();
            
            std::cout << "AmountTilesUnical :" << AmountTilesUnical << "\n";
            
            
            //Array width and length room
            JsonData = json::parse(DownloadJson(jsonPath));
            JsonData["Width"].get_to(WidthTiles);
            JsonData["Length"].get_to(HeigthTiles);
            //Array number with id for drawing room
            AmountTiles = WidthTiles * HeigthTiles;
            

            JsonData["Floor"].get_to(FloorId);
            JsonData["Wall"].get_to(WallId);

            std::cout << "Floor.size :" << FloorId.size() << "\n";
            std::cout << "Wall.size :" << WallId.size() << "\n";
            
            //Download string
            std::cout << "Width :" << WidthTiles << "\n";
            std::cout << "Length :" << HeigthTiles << "\n";
            std::cout << "AmountTiles :" << AmountTiles << "\n";
            

            //FloorId and WallId array id tiles
            for (int i = 0; i < AmountTiles; i++) { 
                FloorIdUnique.insert(FloorId[i]);
            }
            for (int i = 0; i < AmountTiles; i++) { 
                WallIdUnique.insert(WallId[i]);
            }
            std::cout << "-----------------------" << "\n";
            for(auto& str: FloorIdUnique){
                std::cout << str << ' ' ;
            }
            std::cout << "\n";
            for(auto& str: WallIdUnique){
                std::cout << str << ' ' ;
            }
            std::cout << "\n";

            //Tiles download Floor
            for (auto& [key, value] : JsonDataPath.items()) {
                int i = 1;
                Floor.push_back(Tile(i, value, false));
                i++;
            }
            
            
            
            for (int i = 0; i < WidthTiles; i++) {
                switch(WallId[i]) {
                    case 7:
                        Tile(7,(Vector2){(widthBlock)* i,0.0f}, "src/location/laboratory/Tiles/Wall/wall_id_7.png", false);
                        break;
                    case 8:
                        Tile(8,(Vector2){(widthBlock)* i,0.0f}, "src/location/laboratory/Tiles/Wall/wall_id_8.png", false);
                        break;
                    case 9:
                        Tile(9,(Vector2){(widthBlock)* i,0.0f}, "src/location/laboratory/Tiles/Wall/wall_id_9.png", false);
                        break;        
                    default:
                        break;     
                }
            }

            /*
            
            for (int i = 0; i < WidthTiles; i++) { 

            DrawTextureRec(Floor.TextureTile, Floor.CollisionRec, (Vector2){(Floor.TextureTile.width)* i,0.0f}, WHITE);
                for (int j = 0; j < HeigthTiles + 1; j++) { 
                    
                DrawTextureRec(Floor.TextureTile, Floor.CollisionRec, (Vector2){(Floor.TextureTile.width)* i, (Floor.TextureTile.height)* j}, WHITE);
            }

            }
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

    
    
    
    
