#include <iostream>
#include "raylib-cpp.hpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <set>
#include <iostream>



#pragma once
using json = nlohmann::json;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
//
   
    class BuildObj{
        private:
            Vector2 PositionSpawn;
            Image img; 
            Texture2D imgAnim; 

            std::string NameObj;
            std::string Path;

            double startTime;


            float sizeObject;
            float speedHero;
            int points;
            int nextFrameDataOffset;
            int currentFrame;
            
            int flipsCounterLeft;
            int flipsCounterRight;
            int framesSpeed;
            int animFrames;
            bool collision;
            bool exists;
        public:
            Rectangle frameRec;
            int framesCounter;
        BuildObj(std::string name, const char *path, float size){
            NameObj = name;
            sizeObject = size;

            PositionSpawn = (Vector2){ (float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f };
            animFrames = 0;
            img = LoadImageAnim(path, &animFrames);
            imgAnim = LoadTextureFromImage(img);
            
            startTime = GetTime(); // сохраняем текущее время

            exists = true;
            frameRec; 
            speedHero = 2.0f;
            points = 0;
            nextFrameDataOffset = 0;
            currentFrame = 0;
            framesCounter = 0; 
            flipsCounterLeft = 0;
            flipsCounterRight = 1;
            
        }
        void countPoint(int &num, bool exist){

            
            double currentTime = GetTime(); 

            if (currentTime - startTime >= 5.0) { 
                num += 1.0f; 
                startTime = currentTime; 
            }
            if (!exist)
            {

            }
            
            
        }
        bool IsExist(){
            return exists;
        }
        void clickEventListen(){
            

            Vector2 PositionClick = GetMousePosition();

            if (CheckCollisionPointRec(PositionClick, frameRec) && IsMouseButtonDown(0) && exists)
            {
                UpdateTexture(imgAnim, NULL);
                DrawText("You clicked!", 200, 200, 60, RED);

                
                exists = false;
            }
            if (!exists)
            {
                
                
                static BuildObj tableReserarch("tableResearch","src/tableResearch.gif", 4.5f);

                tableReserarch.SetPosObj(frameRec.x + 10.0f, frameRec.y - 60.0f);
                tableReserarch.SetPosRect(tableReserarch.getPosVector().x,tableReserarch.getPosVector().y);
                tableReserarch.Draw();
                tableReserarch.countAnim();
                tableReserarch.animation();
            }
        }
        void DrawRect(){
            DrawRectangle(frameRec.x, frameRec.y, frameRec.width, frameRec.height, RED);
        }
        void animation() {
        if (framesCounter >= animFrames){

            currentFrame++;

            if (currentFrame >= 4) currentFrame = 0;

                nextFrameDataOffset = img.height*img.height*4*currentFrame;

                UpdateTexture(imgAnim, reinterpret_cast<uint8_t*>(img.data) + nextFrameDataOffset);



                framesCounter = 0;


            }
        }
        void SetPosObj(float x, float y){
            PositionSpawn = (Vector2){x, y};
        }
        Vector2 getPosVector(){
            return PositionSpawn;
        }
        void SetPosRect(float x, float y){
            frameRec = (Rectangle){ x, y, (float)imgAnim.width * 1.5, (float)imgAnim.height * 1.5};
        }
        void countAnim(){
            framesCounter++;
        }
        void Draw(){
            DrawTextureEx(imgAnim, PositionSpawn, 0, sizeObject, WHITE);            

            
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
        public:
            int points;
            Rectangle frameRec;
            int framesCounter;
        Player(const char *path){
            PositionSpawn = (Vector2){ (float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f };
            animFrames = 0;
            img = LoadImageAnim(path, &animFrames);
            imgAnim = LoadTextureFromImage(img);
            
            
            
            frameRec = (Rectangle){ PositionSpawn.x - 15.0f, PositionSpawn.y + 24.0f, (float)imgAnim.width, (float)imgAnim.height}; 
            speedHero = 2.0f;
            points = 0;
            nextFrameDataOffset = 0;
            currentFrame = 0;
            framesCounter = 0; 
            flipsCounterLeft = 0;
            flipsCounterRight = 1;
            
        }
        void resetAnimation(){
            currentFrame = 0;
        }
        void DrawRect(){
            DrawRectangle(PositionSpawn.x, PositionSpawn.y, (float)imgAnim.width, (float)imgAnim.height, RED);
        }

        void UpCanMove(){
            CantMoveTop = false;
        }

        void UpCantMove(){
            CantMoveTop = true;
        }

        Texture2D ReturnImg(){
            return imgAnim;
        }
        Rectangle ReturnframeRec(){
            Rectangle heroRect = (Rectangle){ PositionSpawn.x + 20.0f, PositionSpawn.y + 24.0f, (float)imgAnim.width * 0.5f, (float)imgAnim.height};
            //DrawRectangle(heroRect.x, heroRect.y, (float)heroRect.width, (float)heroRect.height, RED);

            return heroRect;
        }
        void collisionDetect(Rectangle recCollide){
            Rectangle leftRect = (Rectangle){ recCollide.x - 25.0f, recCollide.y, (float)imgAnim.width/7.0f, (float)imgAnim.height * 0.75f};
            //DrawRectangle(leftRect.x, leftRect.y, (float)leftRect.width, (float)leftRect.height, BLUE);

            Rectangle rightRect = (Rectangle){ recCollide.x + 193.0f, recCollide.y, (float)imgAnim.width/7.0f, (float)imgAnim.height * 0.75f};
            //DrawRectangle(rightRect.x, rightRect.y, (float)rightRect.width, (float)rightRect.height, YELLOW);
            collision = CheckCollisionRecs(ReturnframeRec(), recCollide);
            if (collision){                
                
                if (CheckCollisionRecs(ReturnframeRec(), leftRect)){
                    DrawText("Collision and key left is detected!", 100, 100, 60, RED);
                    resetAnimation();
                    Down();
                    Left();
                    
                    
                }else if (CheckCollisionRecs(ReturnframeRec(), rightRect)){
                    DrawText("Collision and key right is detected!", 100, 100, 60, RED);
                    resetAnimation();
                    Down();
                    Right();
                    
                }else{
                    resetAnimation();
                    CantTopMove();
                }

                
            }
        }

        Vector2 ReturnPostion(){
            return PositionSpawn;
        }
        float ReturnPositionX(){
            return PositionSpawn.x;
        }
        float ReturnPositionY(){
            return PositionSpawn.y;
        }
        void FramesIncrement(){
            framesCounter++;
        }

        void animationHero() {
        if (framesCounter >= animFrames){

            currentFrame++;

            if (currentFrame >= 5) currentFrame = 0;

                nextFrameDataOffset = img.height*img.height*4*currentFrame;

                UpdateTexture(imgAnim, reinterpret_cast<uint8_t*>(img.data) + nextFrameDataOffset);



                framesCounter = 0;


        }
        
    }
    
    //------------------------------------------------------------------------------------
    // Flip
    //------------------------------------------------------------------------------------
    void flipLeft(){

        if (flipsCounterLeft > 0) {
            flipsCounterLeft = 0;

            }else{

                img.width = -(img.width);
                frameRec.width = -(frameRec.width);


            };
        flipsCounterLeft++;

        
    }
    void flipRight(){

        if (flipsCounterRight > 0) {
            flipsCounterRight = 0;

            }else{


                img.width = -(img.width);
                frameRec.width = -(frameRec.width);


            };
        flipsCounterRight++;

        
    }

    //------------------------------------------------------------------------------------
    // Constrain Move
    //------------------------------------------------------------------------------------
    void CantTopMove(){
        if (CantMoveLeft) {
            Down();
            Right(); 
        }else if (CantMoveRight){
            Down();
            Left(); 
        }else{
            Down();
            Right();
            Left();
        }
    }
    void CantDownMove(){
    if (CantMoveLeft) {
            Up();
            Right(); 
        }else if (CantMoveRight){
            Up();
            Left(); 
        }else{
            Up();
            Right();
            Left();
        }
    }
    void CantRightMove(){
    if (CantMoveTop){
            Down();
            Left();  
        }else if (CantMoveDown){
            Up();
            Left(); 
        }else{
            Up();
            Down();
            Left();
        }
    }
    void CantleftMove(){
        if (CantMoveTop){
            Down();
            Right();  
        }else if (CantMoveDown){
            Up();
            Right(); 
        }else{
            Up();
            Down();
            Right();
        }
    }
    //------------------------------------------------------------------------------------
    // Move
    //------------------------------------------------------------------------------------
    void Up(){
        if (IsKeyDown(KEY_UP)){
            PositionSpawn.y -= speedHero;
            animationHero();
        }
       
    }
    void Down(){
        if (IsKeyDown(KEY_DOWN)){
            PositionSpawn.y += speedHero;
            animationHero();
        }
            
        }
    void Right(){
        if (IsKeyPressed(KEY_RIGHT)){
            flipRight();
            flipsCounterLeft = 0;

        }


        if (IsKeyDown(KEY_RIGHT)){
            PositionSpawn.x += speedHero;
            animationHero();
        }
        
    }
    void Left(){
        if (IsKeyPressed(KEY_LEFT)){

            flipLeft();
            flipsCounterRight = 0;
            
        }
        if (IsKeyDown(KEY_LEFT)){
            animationHero();
            PositionSpawn.x -= speedHero;
            

        }
        
    }
    //------------------------------------------------------------------------------------
    // Move
    //------------------------------------------------------------------------------------
    void MoveHero(){

        //Top-left corner x=76 y=240
        //Top-right corner x=1116 y=246
        //Down-left corner x=76 y=962
        //Down-right corner x=1116 y=960
        if (!collision)
        {
            CantMoveTopLeft = !(PositionSpawn.x > 90 && PositionSpawn.y > 246);
            CantMoveTopRight = !(PositionSpawn.x < 1110 && PositionSpawn.y > 246);
            CantMoveDownLeft = !(PositionSpawn.x < 1114 && PositionSpawn.y < 952);
            CantMoveDownRight = !(PositionSpawn.x > 90 && PositionSpawn.y < 9);

            CantMoveTop = !(PositionSpawn.y >= 246);
            CantMoveRight = !(PositionSpawn.x <= 1110);
            CantMoveLeft = !(PositionSpawn.x >= 90);
            CantMoveDown = !(PositionSpawn.y <= 946);
        

            //CheckBorders
            if (CantMoveTop){
                CantTopMove();
            }else if (CantMoveLeft){
                CantleftMove();
            }else if (CantMoveRight){
                CantRightMove();
            }else if (CantMoveDown){
                CantDownMove();
            }else {
                Up();
                Down();
                Right();
                Left();
            }
    

        }

        
        
    }

    void DrawHero(){
            DrawTextureRec(imgAnim, frameRec, PositionSpawn, WHITE);
        }
    void DrawStatistics(){
            DrawText(TextFormat("PositionX: %04f", PositionSpawn.x), 30, 20, 20, WHITE);
            DrawText(TextFormat("PositionY: %04f", PositionSpawn.y), 30, 50, 20, WHITE);
            DrawText(TextFormat("Knowledge: %04f", points), 30, 80, 20, WHITE);
        }
    };

    class Object{
        private:
        Vector2 PositionSpawn;
        std::string NameObj;
        std::string Path;
        float sizeObject;
        float WidthTile;
        float HeigthTile;
        bool Permeable;
        Image image; 
        Texture2D TextureGame; 
        public:
            Rectangle CollisionRec;
        Object(std::string name, std::string path, float size){
            NameObj = name;
            sizeObject = size;

            PositionSpawn = (Vector2){0.0, 0.0};
            image = LoadImage(path.c_str());
            
            WidthTile = (float)image.width * sizeObject;
            HeigthTile = (float)image.height * sizeObject;
            
 
            CollisionRec = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile};
            TextureGame = LoadTextureFromImage(image);
            
        }
        Rectangle ReturnRect(bool draw){

            Rectangle checkRect = (Rectangle){ PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile/2.0f};
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
            DrawRectangle(PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile, GREEN);
        }

        void DrawObj(){
            DrawTextureEx(TextureGame, PositionSpawn, 0, sizeObject, WHITE);            
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

    
    
    
    
