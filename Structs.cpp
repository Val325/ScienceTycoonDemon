//#pragma once
#include <iostream>
#include "raylib-cpp.hpp"
#include "Utils.cpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <set>
#include<cstdio>
#include<ctime>
//#include"techprogressHUD.cpp"
#include"TechTree2.0.cpp"
#include"buildObj.hpp"
#include"selectionBtn.cpp"
using json = nlohmann::json;

// for times

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
//
//

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
            //DrawRectangle(heroRect.x, heroRect.y, (float)heroRect.width, (float)heroRect.height, RED);

            return heroRect;
        }
        void Player::collisionDetect(Rectangle recCollide){
            Rectangle leftRect = (Rectangle){ recCollide.x - 25.0f, recCollide.y, (float)imgAnim.width/7.0f, (float)imgAnim.height * 0.75f};
            //DrawRectangle(leftRect.x, leftRect.y, (float)leftRect.width, (float)leftRect.height, BLUE);

            Rectangle rightRect = (Rectangle){ recCollide.x + 193.0f, recCollide.y, (float)imgAnim.width/7.0f, (float)imgAnim.height * 0.75f};
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
                    //resetAnimation();
                    //Left();
                    //Right();
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
    

BuildObj::BuildObj(std::string name, const char *path, float size): NameObj("buildCell"), Path("src/location/laboratory/buildingCell.png"), sizeObject(1.5f){
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
BuildObj::BuildObj(): NameObj("buildCell"), Path("src/location/laboratory/buildingCell.png"), sizeObject(1.5f){
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


	     if (!allObj.empty()) {
		for (int i = 0; i <= allObj.size(); i++){
			//allObj[i].Draw();
			
			//allObj[i].SetPosObj(allObj[i].ReturnframeRec().x + 10.0f,allObj[i].ReturnframeRec().x - 60.0f);
			//allObj[i].SetPosRect(allObj[i].getPosVector().x, allObj[i].getPosVector().y);

			//allObj[i].SetPosObj(buildCells[i].getPosVector().x + 10.0f, buildCells[i].getPosVector().y - 60.0f);
			//
			//allObj[i].Draw();
			//allObj[i].countAnim(allObj[i]);
			//allObj[i].animation(allObj[i]);
	    	}
	    }

	     return PositionClickTable;
          }
	
	    
	}
        void BuildObj::clickEventListenSimple(Camera2D camera){
           Vector2 PositionClick = GetScreenToWorld2D(PositionClick, camera); 
           if (CheckCollisionPointRec(PositionClick, frameRec)){
                std::cout << "you click here!" << std::endl;
            } 
        }

        void BuildObj::clickEventListen(Camera2D camera, int &money, int id_cell,std::map<std::string, BuildObj> tableRes, BuildObj cell[]){
            

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
                    && money > 0)
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
        }

        
			
		
		
        }
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
	   
             DrawTextureEx(imgAnim, PositionSpawn, 0, sizeObject, WHITE);




        }



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
        }
        void setInterval(int num){
	        interval = num;
	    }
        void setStartTime(int num){
            startTimeTimer = num;
        }
        void reset(){
            startTimeTimer = static_cast<int>(GetTime());
        }
         //
        int countTimer(bool exist){
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
                flag = false;  
            }
           
            //std::cout << "currentTime: " << currentTime << std::endl;
            //std::cout << "elapsedTime: " << elapsedTime << std::endl;
            
            return elapsedTime;
        }
        Rectangle ReturnRect(bool draw){
            //Vector2 PositionRect = GetScreenToWorld2D({PositionSpawn.x, PositionSpawn.y}, camera);
            Rectangle checkRect = (Rectangle){PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile/2.0f};
            
            if (draw)
            {
               DrawRectangle(checkRect.x, checkRect.y, (float)checkRect.width, (float)checkRect.height, GREEN);
            }

            return checkRect;
        }
        Rectangle ReturnRect(bool draw, Camera2D camera){
            Vector2 PositionRect = GetScreenToWorld2D({PositionSpawn.x, PositionSpawn.y}, camera);
            Rectangle checkRect = (Rectangle){PositionSpawn.x, PositionSpawn.y, (float)WidthTile, (float)HeigthTile/2.0f};
            
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

