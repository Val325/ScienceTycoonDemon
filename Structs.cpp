#include <iostream>
#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
//
    
    class Object{
        private:
        public:
        int id;
        raylib::Vector2 PositionSpawn;
        raylib::Image img; 
        raylib::Texture2D imgAnim; 
        raylib::Rectangle CollisionRec;
        ObjectGame(){
            
        }
    };
    
    class Entity: public Object{
        private:
        public:
        int id;
        float speed;
        int points;
        int nextFrameDataOffset;
        int currentFrame;
        int framesCounter;
        int flipsCounterLeft;
        int flipsCounterRight;
        int framesSpeed;
        int animFrames;
        Entity(){
            
        }
    };
    class Player: public Entity{
        private:
        public:
        int id;
        Player(){
            
        }
    };
    class NPC: public Entity{
        private:
        public:
        int id;
        NPC(){
            
        }
    };
    class Tile: public Object{
        private:
        int id;
        bool Permeable; 
        public:
        Tile(){
            
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
    };

    
    
    
    
