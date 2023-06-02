#pragma once
#include <iostream>
#include "raylib-cpp.hpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <set>
#include<cstdio>
#include<ctime>

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
        Player(const char *path);
	void setMovable(bool setData);
	void showHUDtech();
        void addPoints(int num);
	void resetAnimation();
	void DrawRect();
        void UpCanMove();
        void UpCantMove();
        Texture2D ReturnImg();
	Rectangle ReturnframeRec();
	void collisionDetect(Rectangle recCollide);
        Vector2 ReturnPostion();
	float ReturnPositionX();
	float ReturnPositionY();
	void FramesIncrement();
        void animationHero();
	void flipLeft();
	void flipRight();
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


class BuildObj{
        private:
            Vector2 PositionSpawn;
            Image img;
            Texture2D imgAnim;

            std::string NameObj;
            std::string Path;

            double startTime;
            int startTimeTimer;
            int interval;
            bool flag;

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
            bool isSect;
            std::vector<BuildObj> ojects;
        public:
            Rectangle frameRec;
            int framesCounter;
            int price;
            int numCells;
        BuildObj(std::string name, const char *path, float size);   
	BuildObj();

        void countPoint(int num, bool exist);         //
        int countPointRet(int num, bool exist);        
	int getPoints();
	bool IsExist();
        void clickEventListen(Camera2D camera, int &money);        
	void SelectionPopUp(Camera2D camera, Player &play, int &money);
	void DrawRect();
        void animation(BuildObj &obj); 
	void SetPosObj(float x, float y);
        Vector2 getPosVector();
        void SetPosRect(float x, float y);
	void countAnim(BuildObj &obj);         
        void Draw();    
 };

