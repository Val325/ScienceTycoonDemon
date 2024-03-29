//#pragma once
#include <iostream>
#include "raylib-cpp.hpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <set>
#include<cstdio>
#include<ctime>
#include <stopwatch/Stopwatch.hpp>
//#include"techprogressHUD.cpp"
#include"TechTree2.0.cpp"
#include"buildObj.hpp"
#include"selectionBtn.cpp"
#include "raygui.h"

#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <sstream>

using json = nlohmann::json;
namespace sw = stopwatch;

float sizeBuild = 4.5f;
// for times

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
//
//
    //building, which something generate
    class Generator{
        private:
            //Main data
            int id;
            int moneyWithdraw;
            int moneyGetPerTimer;
            int pointsGetPerTimer; 
            std::string NameObj;
            std::string Path;
            std::string Type; 
            Vector2 Position;
            bool isDraw;
            
            //Timer
            sw::Stopwatch* watch_time;
            int timeElapse;
            bool isExistTimer;

            //Animation
            Image img;
            Texture2D imgAnim;
            int animFrames;
            int framesCounter;
            int currentFrame;
            int nextFrameDataOffset;
        public:
            Generator(){
                nextFrameDataOffset = 0;
                currentFrame = 0;
                framesCounter = 0;
                animFrames = 0;
                isDraw = true;

                //timer
                timeElapse = 5;
                watch_time = new sw::Stopwatch;
                watch_time->start();
                watch_time->reset();           
                isExistTimer = true;
            }
            void setId(int num){
                id = num;
            }
            void setName(std::string name){
                NameObj = name;
            }
            void setPath(std::string path){
                Path = path;
            }
            
            // Prive build
            void setMoneyWithdraw(int num){
                moneyWithdraw = num;
            }
            // Money per time
            void setMoneyPerTimer(int num){
                moneyGetPerTimer = num;
            }
            // Knowledge point per time
            void setPointsPerTimer(int num){
                moneyGetPerTimer = num;
            }
            void setPosition(Vector2 pos){
                Position = pos;
            }
            void setPosition(int x, int y){
                Position.x = x;
                Position.y = y;
            }
            void setDraw(bool isDrawing){
                isDraw = isDrawing;
            }
            void SetElapseTime(int time){
                timeElapse = time;
            }
            // need call it for animation
            void setAnimation(){
                img = LoadImageAnim(Path.c_str(), &animFrames);
                imgAnim = LoadTextureFromImage(img);
            }
            void Animation(){
                //std::cout << "framesCounter: " << framesCounter << std::endl;
                framesCounter++;
                if (framesCounter >= animFrames){
                    currentFrame++;
                    //std::cout << "currentFrame: " << currentFrame << std::endl;
                    if (currentFrame >= 4) currentFrame = 0;
                        nextFrameDataOffset = img.height*img.height*4*currentFrame;
                        UpdateTexture(imgAnim, reinterpret_cast<uint8_t*>(img.data) + nextFrameDataOffset);
                        framesCounter = 0;
                    }
            }
            int getFramesCounter(){
                return framesCounter;
            }
            void Draw(){
	            if (isDraw){ 
                    DrawTextureEx(imgAnim, Position, 0, sizeBuild, WHITE);
                }
            }
            void StartTimer(){
                if (isExistTimer){
                    auto timer = watch_time->elapsed<sw::s>();
                    if (timer >= timeElapse){
                        isExistTimer = false;
                    }else{
                        std::cout << "Time: " << timer << std::endl;
                    } 
                }
                if (!isExistTimer){
                    delete watch_time;
                    watch_time = new sw::Stopwatch;
                    watch_time->start();
                    watch_time->reset();           
                    isExistTimer = true;
                }
            }

            ~Generator(){
                isExistTimer = false;
                delete watch_time;
            }
    };



    class GuiElem{
        private:
        public:
            int id;
            bool isDraw;
            Vector2 Position;
            GuiElem(){} 
    };

    class ItemMenuSelection : public GuiElem{
        private:
            Rectangle itemRec;
            Rectangle labelRec;

            bool IsExist;
            bool IsClick;
            
            std::string typeSpawn;
            std::string label;
            std::string buttonText;


        public:
            ItemMenuSelection(){
                IsExist = false;
                IsClick = false;
                itemRec = (Rectangle){ 352, 384, 120, 24 };
                labelRec = (Rectangle){ 480, 384, 120, 24 };
            }
            void SetId(int num){
                id = num;
            }
            void SetType(std::string text){
                typeSpawn = text;
            }
            void SetLabel(std::string text){
                label = text;
            }
            void SetButtonText(std::string text){
                buttonText = text;
            }

            void Draw(){
                if (IsExist){
                    if (GuiButton(itemRec, buttonText.c_str())){
                        IsClick = true;
                        toggleDraw();
                    }
                    IsClick = false;
                    GuiLabel(labelRec, label.c_str());
                }
            }
            Rectangle GetItemRec(){
                return itemRec; 
            }
            std::string GetButtonText(){
                return buttonText; 
            }
            bool GetClick(){
                return IsClick;
            }
            void toggleDraw(){
                IsExist = !IsExist;
            }
            void setDrawFalse(){
                IsExist = false;
            }
            void setDrawTrue(){
                IsExist = true;
            }
            void SetItemPos(int xpos, int ypos){
                itemRec.x = xpos;
                itemRec.y = ypos;
            }
            void SetLabelPos(int xpos, int ypos){
                labelRec.x = xpos;
                labelRec.y = ypos;
            }
    }; 

    class MenuSelection : public GuiElem{
        private:
            int IdClickBuild;
            Rectangle buttonRec;
            bool isOpenMenu;
            std::vector<ItemMenuSelection> itemsMenu;
            std::vector<bool> isClicked;
             
            std::vector<Generator> GeneratorBuild;
            TableDat tableGameSave[50];

            bool IsOneClicked;
        public:
            MenuSelection(){
                IsOneClicked = false;
                isOpenMenu = false;
                buttonRec = (Rectangle){ 344, 352, 256, 128 };

                ItemMenuSelection tableMin;
                tableMin.SetLabel("table min");
                tableMin.SetButtonText("buy table min");
                itemsMenu.push_back(tableMin);
                //isClicked.push_back();


                ItemMenuSelection tableMid;
                tableMid.SetLabel("table min");
                // + 30 
                tableMid.SetItemPos(352, 416);
                tableMid.SetLabelPos(480, 416);
                tableMid.SetButtonText("buy table min");
                itemsMenu.push_back(tableMid);


                ItemMenuSelection tableTop;
                tableTop.SetLabel("table min");
                tableTop.SetItemPos(352, 448);
                tableTop.SetLabelPos(480, 448);
                tableTop.SetButtonText("buy table min");
                itemsMenu.push_back(tableTop);

            }
            void Draw(){
                if (isOpenMenu){
                    itemsMenu[0].setDrawTrue();
                    itemsMenu[1].setDrawTrue();
                    itemsMenu[2].setDrawTrue();
                    isOpenMenu = !GuiWindowBox(buttonRec, "Select table");
                    itemsMenu[0].Draw();
                    itemsMenu[1].Draw();
                    itemsMenu[2].Draw();
                    
                    if (GuiButton(itemsMenu[0].GetItemRec(), itemsMenu[0].GetButtonText().c_str()) && !IsOneClicked){
                       std::cout << "min clicked" << std::endl;
                       std::cout << "Click num: " << IdClickBuild << std::endl;
                       IsOneClicked = true;
                    }
                    if (GuiButton(itemsMenu[1].GetItemRec(), itemsMenu[1].GetButtonText().c_str()) && !IsOneClicked){
                       std::cout << "mid clicked" << std::endl;
                       std::cout << "Click num: " << IdClickBuild << std::endl;
                       IsOneClicked = true;
                    }                    
                    if (GuiButton(itemsMenu[2].GetItemRec(), itemsMenu[2].GetButtonText().c_str()) && !IsOneClicked){
                       std::cout << "top clicked" << std::endl;
                       std::cout << "Click num: " << IdClickBuild << std::endl;
                       IsOneClicked = true;
                    }
                    
                    if (!isOpenMenu){
                        IsOneClicked = false;
                    }
                }
                //setDrawTrue(); 
            }
            void SetGeneratorBuild(std::vector<Generator> &GenBuild){
                GeneratorBuild = GenBuild;
            }
            void SetTableBuild(struct TableDat * data){
                for (int i = 0; i < GeneratorBuild.size(); i++){
                    tableGameSave[i].type = data[i].type;
                    tableGameSave[i].isExists = data[i].isExists;
                    tableGameSave[i].idTables = data[i].idTables;
                    tableGameSave[i].xpos = data[i].xpos;
                    tableGameSave[i].ypos = data[i].ypos;
                }

            }
            void IdClick(int id){
                IdClickBuild = id;
            }
            void toggleDraw(){
                isOpenMenu = !isOpenMenu;
            }
            void setDrawFalse(){
                isOpenMenu = false;
            }
            void setDrawTrue(){
                isOpenMenu = true;
            }
            void SetPos(int xpos, int ypos){
                buttonRec.x = xpos;
                buttonRec.y = ypos;
            }
    };

class BuildObj{
        private:
            Vector2 PositionSpawn;
            Image img;
            Texture2D imgAnim;
            
            Object shadow;

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
	    bool isClickedTable;
            std::vector<BuildObj> ojects;
	    Vector2 PositionClickTable;
        public:
            bool isDraw;
	        int id;
            Rectangle frameRec;
            int framesCounter;
            int price;
            int numCells;
        BuildObj(std::string name, const char *path, float size);   
	BuildObj();

    void countPoint(int num, bool exist);         //
	void setInterval(int num);
    int countPointRet(int num, int addPoint, bool exist);        
	int getPoints();
	int ReturnID();
	bool IsExist();
    void setPath(std::string path_img);
	void SetIsExist(bool ex);
    void clickEventListenSimple(Camera2D camera, BuildObj &obj, MenuSelection &menu, std::vector<Generator> &GenBuild, struct TableDat * data);
    void clickEventListen(Camera2D camera, int &money, int id_cell, std::map<std::string, BuildObj> tableRes, BuildObj cell[]);
    void clickEventListenV2(Camera2D camera, int &money, int id_cell, std::map<std::string, BuildObj> tableRes, BuildObj cell[]);  
	void SelectionPopUp(Camera2D camera, Player &play, int &money, BuildObj cell[], int id_cell,std::map<std::string, BuildObj> tableRes);
	void DrawRect();
	Rectangle ReturnframeRec();
	float ReturnframeRecX();
	float ReturnframeRecY();
	Vector2 ReturnPostionClick(Camera2D);
    void animation(BuildObj &obj); 
	void SetPosObj(float x, float y);
    Vector2 getPosVector();
    void SetPosRect(float x, float y);
	void countAnim(BuildObj &obj);         
    void Draw();
    //bool isNull() const;
 };

	Player::Player(const char *path, int knowledgeData, int moneyData){
            PositionSpawn = (Vector2){ (float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f };
            animFrames = 0;
            img = LoadImageAnim(path, &animFrames);
            imgAnim = LoadTextureFromImage(img);
            money = moneyData;
            canMove = true;

            frameRec = (Rectangle){ PositionSpawn.x - 15.0f, PositionSpawn.y + 24.0f, (float)imgAnim.width, (float)imgAnim.height};
            speedHero = 3.5f;
            points = knowledgeData;
            nextFrameDataOffset = 0;
            currentFrame = 0;
            framesCounter = 0;
            flipsCounterLeft = 0;
            flipsCounterRight = 1;
            HUDtechShow = false;

        }
        void Player::setMovable(bool setData){

          canMove = setData;
        }
        void Player::showHUDtech(bool isShow){
           
          
          if (HUDtechShow) {
            HUDtechShow = ShowHUDTechTree(HUDtechShow);  
            
          }
	
          
          if (IsKeyPressed(KEY_TAB) || isShow) {
            WindowBox000Active = true;
            HUDtechShow = true;
          }


        }
        void Player::addPoints(int num){
            points += num;
        }
        void Player::addMoney(int num){
            money += num;
        }
        void Player::resetAnimation(){
            currentFrame = 0;
        }
        void Player::DrawRect(){
            DrawRectangle(PositionSpawn.x, PositionSpawn.y, (float)imgAnim.width, (float)imgAnim.height, RED);
        }

        void Player::UpCanMove(){
            CantMoveTop = false;
        }

        void Player::UpCantMove(){
            CantMoveTop = true;
        }
        void Player::SpeedUp(){
            const float maxSpeed = 3.0f;
            if (IsKeyDown(KEY_LEFT_SHIFT)){
                if (speedHero <= maxSpeed) {
                    speedHero += 1;
                }else {
                    speedHero = maxSpeed;
                }
            }else{
                speedHero = 2.0f;
            }

        }
        Texture2D Player::ReturnImg(){
            return imgAnim;
        }
        Rectangle Player::ReturnframeRec(){
            Rectangle heroRect = (Rectangle){ PositionSpawn.x + 20.0f, PositionSpawn.y + 24.0f, (float)imgAnim.width * 0.5f, (float)imgAnim.height};
            //DrawRectangle(Просто злая сказка же для наших глубинариев. Наших мальчиков в трусиках трахают на фронте гейсолдаты НАТО. Это будет эпично heroRect.x, heroRect.y, (float)heroRect.width, (float)heroRect.height, RED);

            return heroRect;
        }
        void Player::collisionDetect(Rectangle recCollide){
            Rectangle leftRect = (Rectangle){ recCollide.x - 30.0f, recCollide.y, (float)imgAnim.width/7.0f, (float)imgAnim.height * 0.75f};
            //DrawRectangle(leftRect.x, leftRect.y, (float)leftRect.width, (float)leftRect.height, BLUE);

            Rectangle rightRect = (Rectangle){ recCollide.x + 160.0f, recCollide.y, (float)imgAnim.width/7.0f, (float)imgAnim.height * 0.75f};
            //DrawRectangle(rightRect.x, rightRect.y, (float)rightRect.width, (float)rightRect.height, YELLOW);
            collision = CheckCollisionRecs(ReturnframeRec(), recCollide);
            if (collision){

                if (CheckCollisionRecs(ReturnframeRec(), leftRect)){
                    //DrawText("Collision and key left is detected!", 100, 100, 60, RED);
                    resetAnimation();
                    Down();
                    Left();


                }else if (CheckCollisionRecs(ReturnframeRec(), rightRect)){
                    //DrawText("Collision and key right is detected!", 100, 100, 60, RED);
                    resetAnimation();
                    Down();
                    Right();

                }else{
                    //DrawText("Cant top move!", 100, 100, 60, RED);
                    //resetAnimation();
                    //Left();
                    //Right();
                    //UpCantMove();
                    //CantTopMove();
                    CantTopMoveTable();

                }

            }
        }

        Vector2 Player::ReturnPostion(){
            return PositionSpawn;
        }
        float Player::ReturnPositionX(){
            return PositionSpawn.x;
        }
        float Player::ReturnPositionY(){
            return PositionSpawn.y;
        }
        void Player::FramesIncrement(){
            framesCounter++;
        }

        void Player::animationHero() {
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
    void Player::flipLeft(){

        if (flipsCounterLeft > 0) {
            flipsCounterLeft = 0;

            }else{

                img.width = -(img.width);
                frameRec.width = -(frameRec.width);


            };
        flipsCounterLeft++;


    }
    void Player::flipRight(){

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
    void Player::CantTopMove(){
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
    void Player::CantTopMoveTable(){
        Down();
        Left();
        Right();

    }
    void Player::CantDownMove(){
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
    void Player::CantDownMoveTable(){
        Up();
        Right();
        Left();
    }
    void Player::CantRightMove(){
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
    void Player::CantRightMoveTable(){
        Up();
        Down();
        Left();
    }
    void Player::CantleftMove(){
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
    void Player::CantleftMoveTable(){
        Up();
        Down();
        Right();
    }
    //------------------------------------------------------------------------------------
    // Move
    //------------------------------------------------------------------------------------
    void Player::Up(){
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
            PositionSpawn.y -= speedHero;
            animationHero();
        }

    }
    void Player::Down(){
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
            PositionSpawn.y += speedHero;
            animationHero();
        }

        }
    void Player::Right(){
        if (IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_D)){
            flipRight();
            flipsCounterLeft = 0;

        }


        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
            PositionSpawn.x += speedHero;
            animationHero();
        }

    }
    void Player::Left(){
        if (IsKeyPressed(KEY_LEFT)  || IsKeyDown(KEY_A)){

            flipLeft();
            flipsCounterRight = 0;

        }
        if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)){
            animationHero();
            PositionSpawn.x -= speedHero;


        }

    }
    //------------------------------------------------------------------------------------
    // Move
    //------------------------------------------------------------------------------------
    void Player::MoveHero(){

        //Top-left corner x=76 y=240
        //Top-right corner x=1116 y=246
        //Down-left corner x=76 y=962
        //Down-right corner x=1116 y=960
        if (!collision && canMove)
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

    void Player::DrawHero(){
            DrawTextureRec(imgAnim, frameRec, PositionSpawn, WHITE);
        }
    void Player::DrawStatistics(){
            DrawText(TextFormat("PositionX: %04f", PositionSpawn.x), 30, 20, 20, WHITE);
            DrawText(TextFormat("PositionY: %04f", PositionSpawn.y), 30, 50, 20, WHITE);
            DrawText(TextFormat("Knowledge: %04f", points), 30, 80, 20, WHITE);
        }
    


/*
        bool BuildObj::isNull() const {
            return this == nullptr;  
        }
*/
    
    class Board{
        private:
            int sizeCells;
            std::vector<BuildObj> cells;
            std::vector<Generator> GeneratorBuild;
            Camera2D camera;
 
            TableDat tableGameSave[50];
            MenuSelection menu;
        public:
            Board(){
                
                sizeCells = 50;
                cells.resize(sizeCells);
                GeneratorBuild.resize(sizeCells);
                for (int i = 0; i < cells.size(); i++){
                    cells[i].numCells = i; // from 0 + 1 ... 
                    GeneratorBuild[i].setId(i);
                    
                    tableGameSave[i].type = "";
                    tableGameSave[i].idTables = i;

                }
            }
            void setCamera(Camera2D &cam){
                camera = cam;
            }
            void SetMenu(MenuSelection &men){
                menu = men;
            }
            void Draw(MenuSelection &menuSelect){
                int j = 0;
                int q = 0;

                menuSelect.SetGeneratorBuild(GeneratorBuild);
                menuSelect.SetTableBuild(tableGameSave);

                    for (int i = 0; i < cells.size(); i++){
                        cells[i].setPath("src/location/laboratory/buildingCell.png");
                        Vector2 positionPlace = {170 + 100 * q, 500 + 100 * j};
                        
                        //save in struct of arrays build
                        tableGameSave[i].xpos = 170 + 100 * q;
                        tableGameSave[i].ypos = 500 + 100 * j;
 
                        //for debug
                        //cells[i].DrawRect();
                        


                        cells[i].clickEventListenSimple(camera, cells[i], menuSelect, GeneratorBuild, tableGameSave);
                    
                        cells[i].SetPosObj(positionPlace.x, positionPlace.y);
                        cells[i].SetPosRect(positionPlace.x, positionPlace.y);
                        cells[i].Draw();

                        q++;
                        // if i is 10, 20, 30 ...
                        if ((i + 1) % 10 == 0){
                            j++;
                            q = 0;
                        }                       
                } 
            }
            void SaveToFile(std::string path, std::string name){
                std::string extension = ".dat";
                std::string fullNameFile = path + name + extension; 
                std::ofstream file(fullNameFile, std::ios::out | std::ios::binary);
                
                if(!file) {
                    std::cout << "Cannot open file!" << std::endl;
                }

                for (int i = 0; i < cells.size(); i++){
                    tableGameSave[i].isExists = cells[i].isDraw;
                }

                //rewrite it
                file.write((char *)&tableGameSave, sizeof(tableGameSave));
                file.close();

                if(!file.good()) {
                    std::cout << "Error occurred at writing time!" << std::endl;
                }
            }
            bool isHasSave(const std::string& name){
                std::ifstream f(name.c_str());
                return f.good();
            }
            void LoadFromFile(std::string path, std::string name){
                std::string extension = ".dat";
                std::string fullNameFile = path + name + extension;
                std::ifstream file(fullNameFile, std::ios::out | std::ios::binary);
                if(!file) {
                    std::cout << "Cannot open file!" << std::endl;
                }

                file.read((char *) &tableGameSave, sizeof(tableGameSave));
                file.close();
                
                for (int i = 0; i < cells.size(); i++){
                    std::cout << "id: " << tableGameSave[i].idTables << " pos x: " << tableGameSave[i].xpos << " pos y: " << tableGameSave[i].ypos << std::endl;
                    cells[i].isDraw = tableGameSave[i].isExists;
                    //cells[i].SetPosObj(tableGameSave[i].xpos, tableGameSave[i].ypos);
                    //cells[i].SetPosRect(tableGameSave[i].xpos, tableGameSave[i].ypos);
                }

                if(!file.good()) {
                    std::cout << "Error occurred at reading time!" << std::endl;
                }
            }

        };




BuildObj::BuildObj(std::string name, const char *path, float size): NameObj("buildCell"), Path("src/location/laboratory/buildingCell.png"), sizeObject(1.5f),shadow("shadow","src/shadowpanel.png", 5.0f){
            NameObj = name;
            sizeObject = size;
            Path = path;
            PositionSpawn = (Vector2){ (float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f };
            animFrames = 0;
            img = LoadImageAnim(path, &animFrames);
            imgAnim = LoadTextureFromImage(img);
            price = 50;
            numCells = 0;

            startTime = GetTime(); // сохраняем текущее время
            startTimeTimer = static_cast<int>(GetTime()) - 5;
            interval = 5;
            flag = false;

            exists = false;
            isSect = false;
	    isClickedTable = false;
            frameRec; 
            speedHero = 2.0f;
            points = 0;
            nextFrameDataOffset = 0;
            currentFrame = 0;
            framesCounter = 0;
            flipsCounterLeft = 0;
            flipsCounterRight = 1;
            }
BuildObj::BuildObj(): NameObj("buildCell"), Path("src/location/laboratory/buildingCell.png"), sizeObject(1.5f), shadow("shadow","src/shadowpanel.png", 5.0f){
            NameObj = "buildCell";
            sizeObject = 1.5f;
            Path = "src/location/laboratory/buildingCell.png";
            PositionSpawn = (Vector2){ (float)GetScreenWidth()/2.0f, (float)GetScreenHeight()/2.0f };
            animFrames = 0;
            img = LoadImageAnim(Path.c_str(), &animFrames);
            imgAnim = LoadTextureFromImage(img);
            price = 50;
            numCells = 0;

            startTime = GetTime(); // сохраняем текущее время
            startTimeTimer = static_cast<int>(GetTime()) - 5;
            interval = 5;
            flag = false;
            /*
            Image img;
            Texture2D imgAnim;
            int animFrames;
            int framesCounter;
            int currentFrame;
            int nextFrameDataOffset;
            */
	    isClickedTable = false;
            exists = false;
            frameRec; 
            speedHero = 2.0f;
            points = 0;
            nextFrameDataOffset = 0;
            currentFrame = 0;
            framesCounter = 0;
            flipsCounterLeft = 0;
            flipsCounterRight = 1;
            isDraw = true;
        }

        void BuildObj::setPath(std::string path_img){
           Path = path_img; 
        }
        void BuildObj::countPoint(int num, bool exist){
            
        }
	void BuildObj::setInterval(int num){
	    interval = num;
	}
         //
        int BuildObj::countPointRet(int num, int addPoint, bool exist){
            int currentTime = static_cast<int>(GetTime());
            int elapsedTime = currentTime - startTimeTimer;
            
            
            int totalPoint = 0;
           

            if (elapsedTime >= interval) 
            {
                flag = true;  
                startTimeTimer = currentTime;  
            }
    
            if (flag && exist)  
            {

                Knowledge_Point += (AmountMinTable * 10) + (AmountMidTable * 20) + (AmountTopTable * 30);
		std::cout << "Knowledge_Point: "<< Knowledge_Point  << std::endl;
                flag = false;  
            }
           
            //std::cout << "currentTime: " << currentTime << std::endl;
            //std::cout << "elapsedTime: " << elapsedTime << std::endl;
            
            return totalPoint;
        }
        int BuildObj::getPoints(){
            return points;
        }
        bool BuildObj::IsExist(){
            return exists;
        }
	Rectangle BuildObj::ReturnframeRec(){
	    return frameRec;	
	}	
	float BuildObj::ReturnframeRecX(){
	    return frameRec.x;	
	}	
	float BuildObj::ReturnframeRecY(){
	    return frameRec.y;	
	}
	int BuildObj::ReturnID(){
	    return id;	
	}
	Vector2 BuildObj::ReturnPostionClick(Camera2D camera){

	  Vector2 PositionClick = GetScreenToWorld2D(PositionClick, camera); 
          if (CheckCollisionPointRec(PositionClick, frameRec) && IsMouseButtonDown(0) && !isClickedTable){
             isClickedTable = true;
	     PositionClickTable = PositionClick;
	     return PositionClickTable; 
          }
          if (isClickedTable) {


	    // if (!allObj.empty()) {
		//for (int i = 0; i <= allObj.size(); i++){
			//allObj[i].Draw();
			
			//allObj[i].SetPosObj(allObj[i].ReturnframeRec().x + 10.0f,allObj[i].ReturnframeRec().x - 60.0f);
			//allObj[i].SetPosRect(allObj[i].getPosVector().x, allObj[i].getPosVector().y);

			//allObj[i].SetPosObj(buildCells[i].getPosVector().x + 10.0f, buildCells[i].getPosVector().y - 60.0f);
			//
			//allObj[i].Draw();
			//allObj[i].countAnim(allObj[i]);
			//allObj[i].animation(allObj[i]);
	    //	}
	    //}

	     return PositionClickTable;
          }
	
	    
	}
    void BuildObj::clickEventListenSimple(Camera2D camera, BuildObj &obj, MenuSelection &menu, std::vector<Generator> &GenBuild, struct TableDat * data){
           Vector2 PositionClick = GetMousePosition();
           PositionClick = GetScreenToWorld2D(PositionClick, camera);
            

           if (CheckCollisionPointRec(PositionClick, frameRec) && IsMouseButtonDown(0) && !IsPause){
                if (obj.isDraw){
                    std::cout << "x: " << PositionClick.x << " y:" << PositionClick.y << std::endl;
                    std::cout << "numCells: " << numCells << std::endl;
                    menu.toggleDraw(); 
                    obj.isDraw = false;
                    //GenBuild
                    //get click
                    int numClick = obj.numCells;
                    menu.IdClick(numClick);
                }
                //isClicked = false;
                
            }
           if (CheckCollisionPointRec(PositionClick, frameRec) && !IsPause){
                
                
                if (obj.isDraw){
                    shadow.SetPosObj(frameRec.x + 7, frameRec.y + 7);
                    shadow.DrawObj();
                    std::cout << "framerec x: " << frameRec.x << " y:" << frameRec.y << std::endl;
                }
                
           }
        }

        void BuildObj::clickEventListen(Camera2D camera, int &money, int id_cell,std::map<std::string, BuildObj> tableRes, BuildObj cell[]){
            
            /*
            bool isLoadTexture = false;
            money = PlayerMoney;
            Vector2 PositionClick = GetMousePosition();
            Vector2 PositionBeforeClick = PositionSpawn;
            PositionClick = GetScreenToWorld2D(PositionClick, camera);
            BuildObj *table;
            bool isClosed;
            int click_id = 0;
            //!exists
            if (CheckCollisionPointRec(PositionClick, frameRec) 
                    && IsMouseButtonDown(0) 
                    && !allObjIsExists[id_cell] 
                    && !allObjIsSelected[id_cell]
                    && money >= 0)
            {
                click_id = id_cell;
                numCells += 1;
                //money -= price * numCells;
                //money -= price;
		        chooseTable = id_cell;	
               	WindowBoxPopUpSelectTableActive = true;
                exists = true;
                allObjIsExists[id_cell] = true;
            }

//if (exists){
         if (exists){   
	        std::cout << "PositionBeforeClick: x: " << PositionBeforeClick.x << " y: " << PositionBeforeClick.y << std::endl;
            std::cout << "PositionSpawn: x: " << PositionSpawn.x << " y: " << PositionSpawn.y << std::endl;
            std::cout << "allObj[id_cell].getPosVector(): x: " << allObj[id_cell].getPosVector().x << " y: " << allObj[id_cell].getPosVector().y << std::endl;

        if (!WindowBoxPopUpSelectTableActive && !allObjIsExists[id_cell] && allObjIsSelected[id_cell]){
            
            allObj[id_cell].countAnim(allObj[id_cell]);
		    allObj[id_cell].animation(allObj[id_cell]);
            */
        //}

        
			
		
		
        //}
}
          void BuildObj::clickEventListenV2(Camera2D camera, int &money, int id_cell,std::map<std::string, BuildObj> tableRes, BuildObj cell[]){
            
          }
	
        void BuildObj::SelectionPopUp(Camera2D camera, Player &play, int &money, BuildObj cell[], int id_cell,std::map<std::string, BuildObj> tableRes){
          Vector2 PositionClick = GetMousePosition();
          Vector2 PositionPlayer = play.ReturnPostion();
          int isClosed;
	  BuildObj table;
          
          if (CheckCollisionPointRec(PositionClick, frameRec) && IsMouseButtonDown(0) && !isSect){
            //numCells += 1;
                
            //money -= price * numCells; 
            isSect = true; 
          }
          if (isSect) {
            play.setMovable(false);
	    
            //isClosed = selectionBtn(camera ,id_cell, tableRes);
	    //chooseTable = id_cell; 
	    
	    
            if (isClosed == 0) {
              isSect = false;
              play.setMovable(true);

	      
            }/*
	    if (!allObj.empty()) {
		for (int i = 0; i <= allObj.size(); i++){
			//allObj[i].Draw();
			//allObj[i].SetPosObj(allObj[i].ReturnframeRec().x + 10.0f,allObj[i].ReturnframeRec().x - 60.0f);
			
			
		
			allObj[i].SetPosRect(frameRec.x + 10.0f, frameRec.y - 60.0f);
			allObj[i].SetPosObj(cell[i].frameRec.x,cell[i].frameRec.y);

			
			//allObj[i].Draw();
			//allObj[i].countAnim(allObj[i]);
			//allObj[i].animation(allObj[i]);
			
	    	}
	    }*/

          }
	 
        }
        void BuildObj::DrawRect(){
            DrawRectangle(frameRec.x, frameRec.y, frameRec.width, frameRec.height, RED);
        }
        void BuildObj::animation(BuildObj &obj) {
        if (obj.framesCounter >= animFrames){

            currentFrame++;

            if (currentFrame >= 4) currentFrame = 0;

                nextFrameDataOffset = img.height*img.height*4*currentFrame;

                UpdateTexture(imgAnim, reinterpret_cast<uint8_t*>(img.data) + nextFrameDataOffset);



                framesCounter = 0;


            }
        }
        void BuildObj::SetPosObj(float x, float y){
            PositionSpawn = (Vector2){x, y};
        }
        Vector2 BuildObj::getPosVector(){
            return PositionSpawn;
        }
        void BuildObj::SetPosRect(float x, float y){
            frameRec = (Rectangle){ x, y, (float)imgAnim.width * 1.5f, (float)imgAnim.height * 1.5f};
        }
        void BuildObj::countAnim(BuildObj &obj){
            obj.framesCounter++;
        }
        void BuildObj::SetIsExist(bool ex){
            exists = ex;
	} 
        void BuildObj::Draw(){
	        if (isDraw){ 
             DrawTextureEx(imgAnim, PositionSpawn, 0, sizeObject, WHITE);
            }
        }


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

