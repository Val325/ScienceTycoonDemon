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
        bool canMove;
    };

    
    
    
    
