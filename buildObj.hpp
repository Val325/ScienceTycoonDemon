#pragma once
#include <iostream>
#include "raylib-cpp.hpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <set>
#include<cstdio>
#include<ctime>

int Knowledge_Point;
int Money_Point;
bool IsCanGetMoney = false;
bool IsPause = false;


class Object{
        private:
        Vector2 PositionSpawn;
        std::string NameObj;
        std::string Path;

        float sizeObject;
        float WidthTile;
        float HeigthTile;
        bool Permeable;
        bool drawOutline;
        
        Image image;
        Texture2D TextureGame;
        Rectangle frameRec;

        double startTime;
        int startTimeTimer;
        int interval;
        bool flag;
        int currentTime;
        int elapsedTime;

        bool pause_obj;
        bool isStopTimer;
        public:
            Rectangle CollisionRec;
        Object(std::string name, std::string path, float size){
            NameObj = name;
            sizeObject = size;

            PositionSpawn = (Vector2){0.0, 0.0};
            image = LoadImage(path.c_str());

            WidthTile = (float)image.width * sizeObject;
            HeigthTile = (float)image.height * sizeObject;
            drawOutline = false;

            CollisionRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile};
            frameRec; 
            TextureGame = LoadTextureFromImage(image);
            

            startTime = GetTime(); // сохраняем текущее время
            startTimeTimer = static_cast<int>(GetTime());
            interval = 20; 
            flag = false;
            pause_obj = false;
        }
        void setSize(float size){
            sizeObject = size; 
        }
        void setInterval(int num){
	        interval = num;
	    }
        void setStartTime(int num){
            startTimeTimer = num;
        }
        void pause(){
            pause_obj = true;
            currentTime = 0;
            elapsedTime = 0;
        }
        void play(){
            pause_obj = false;
        }
        bool returnIsPause(){
            return pause_obj;
        }
        int returnElapsedTime(){
            return elapsedTime;
        }
        void setElapsedTime(int num){
            elapsedTime = num;
        }
        int returnCurrentTime(){
            return currentTime;
        }
        void setCurrentTime(int num){
            currentTime = num;
        }
        int countTimer(bool exist){

            
        }
        void countTimer(int time){

        }

        Rectangle ReturnRect(bool draw){
            //Vector2 PositionRect = GetScreenToWorld2D({PositionSpawn.x, PositionSpawn.y});
            Rectangle checkRect = (Rectangle){PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile/2.0f};
            
            if (draw)
            {
               DrawRectangle(checkRect.x, checkRect.y, (float)checkRect.width, (float)checkRect.height, GREEN);
            }

            return checkRect;
        }
        Rectangle ReturnRect(bool draw, Camera2D camera){
            Vector2 PositionRect = GetWorldToScreen2D(PositionSpawn, camera);
            Rectangle checkRect = (Rectangle){PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile/2.0f};
            //Rectangle checkRect = (Rectangle){PositionRect.x, PositionRect.y, (float)WidthTile, (float)HeigthTile/2.0f}; 
            
            if (draw)
            {
               DrawRectangle(checkRect.x, checkRect.y, (float)checkRect.width, (float)checkRect.height, GREEN);
            }

            return checkRect;
        }
        Vector2 ReturnPosition(){
            return PositionSpawn;
        }
        void SetPosObj(Vector2 PositionSpawn){
  
            PositionSpawn = (Vector2){0.0, 0.0};
        }

        void SetPosObj(float x, float y){
            PositionSpawn = (Vector2){x, y};
        }

        void DrawRect(){
            if (drawOutline){
                DrawRectangle(frameRec.x, frameRec.y, (float)WidthTile, (float)HeigthTile, GREEN);
            }
        }

        void DrawObj(){
            DrawTextureEx(TextureGame, PositionSpawn, 0, sizeObject, WHITE);
        }
        void DrawOutline(bool isDraw){
            if (isDraw){
                DrawRectangle(frameRec.x, frameRec.y, (float)WidthTile, (float)HeigthTile, BLACK);
            }
        }

        bool clickEventListenSimple(Camera2D camera){
           Vector2 PositionClick = GetMousePosition();
           //PositionClick = GetScreenToWorld2D(PositionClick, camera);
           frameRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile}; 
           if (CheckCollisionPointRec(PositionClick, frameRec) && IsMouseButtonDown(0)){
                //std::cout << "you click here!" << std::endl;
   
                //temporaly
                //hardcoding
                
              return true; 
	
          
            
           }
            return false;
        }
        bool IsHoverObj(){
           Vector2 PositionClick = GetMousePosition();
           //PositionClick = GetScreenToWorld2D(PositionClick, camera);
           frameRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile}; 
           if (CheckCollisionPointRec(PositionClick, frameRec)){
                //std::cout << "you hover here!" << std::endl;
                return true; 
           }
           return false;
        }
    };


class Player{
        private:
            Vector2 PositionSpawn;
            Image img;
            Texture2D imgAnim;

            float speedHero;

            int nextFrameDataOffset;
            int currentFrame;

            int flipsCounterLeft;
            int flipsCounterRight;
            int framesSpeed;
            int animFrames;
            bool canMove;
            bool collision;

            bool CantMoveTopLeft;
            bool CantMoveTopRight;
            bool CantMoveDownLeft;
            bool CantMoveDownRight;

            bool CantMoveTop;
            bool CantMoveRight;
            bool CantMoveLeft;
            bool CantMoveDown;

            bool HUDtechShow;
        public:
            int points;
            int money;
            Rectangle frameRec;
            int framesCounter;
        Player(const char *path, int knowledgeData, int moneyData);
	void setMovable(bool setData);
	void showHUDtech(bool isShow);
        void addPoints(int num);
	void resetAnimation();
	void DrawRect();
        void UpCanMove();
        void UpCantMove();
        Texture2D ReturnImg();
    void addMoney(int num);
	Rectangle ReturnframeRec();
	void collisionDetect(Rectangle recCollide);
        Vector2 ReturnPostion();
	float ReturnPositionX();
	float ReturnPositionY();
	void FramesIncrement();
        void animationHero();
	void flipLeft();
	void flipRight();
    void SpeedUp();
    //------------------------------------------------------------------------------------
    // Constrain Move table
    //------------------------------------------------------------------------------------
    void CantTopMoveTable();
    void CantDownMoveTable();
    void CantRightMoveTable();
    void CantleftMoveTable();
    //------------------------------------------------------------------------------------
    // Constrain Move
    //------------------------------------------------------------------------------------
    void CantTopMove();
    void CantDownMove();
    void CantRightMove();
    void CantleftMove();
    //------------------------------------------------------------------------------------
    // Move
    //------------------------------------------------------------------------------------
    void Up();
    void Down();
    void Right();
    void Left();
    //------------------------------------------------------------------------------------
    // Move
    //------------------------------------------------------------------------------------
    void MoveHero();
    void DrawHero();
    void DrawStatistics();
};








