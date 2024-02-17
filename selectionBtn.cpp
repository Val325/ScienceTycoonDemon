#include "raygui.h"
//#include "Structs.cpp"
#include "buildObj.hpp"
//#include "Scene.cpp"
#include "SaveData.cpp"
#pragma once
//class BuildObj;
//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
//
std::vector<BuildObj> allObj;
//int Knowledge_Point = 0;
//BuildObj allObj[10];
bool allObjIsExists[10] = {false};
bool allObjIsSelected[10] = {false};
std::string typesTablesArray[10] = {""};
bool WindowBoxPopUpSelectTableActive = false;
bool isSelectedTable = false;
int chooseTable = NULL;
int PlayerMoney = Money_Point;
int save_num; 

int AmountMinTable = 0;
int AmountMidTable = 0;
int AmountTopTable = 0;

void TableMin(int id_cell, BuildObj obj)
{

   int tempMoney;
   tempMoney = Money_Point - 50;
   if (tempMoney >= 0){

      Money_Point = Money_Point - 50;
      allObjIsExists[id_cell] = true;
      AmountMinTable++; 
      allObj[id_cell] = obj;
      allObj[id_cell].SetPosObj(150 + 100 * id_cell, 440);
      allObj[id_cell].SetPosRect(150 + 100 * id_cell, 440);
      isSelectedTable = true;
      allObjIsSelected[id_cell] = true;

   }
   
   
}

   
   

void TableMid(int id_cell, BuildObj obj)
{

    int tempMoney;
    tempMoney = Money_Point - 150;
    if (tempMoney >= 0){

      allObjIsExists[id_cell] = true;

      Money_Point = Money_Point - 150;
      AmountMidTable++; 
      allObj[id_cell] = obj;
      allObj[id_cell].SetPosObj(150 + 100 * id_cell, 440);
      allObj[id_cell].SetPosRect(150 + 100 * id_cell, 440);
      isSelectedTable = true;
      allObjIsSelected[id_cell] = true;

    }
    
    
}
void TableEnd(int id_cell, BuildObj obj)
{

    int tempMoney;
    tempMoney = Money_Point - 450;
    if (tempMoney >= 0){

        AmountTopTable++; 
        allObjIsExists[id_cell] = true;

        Money_Point = Money_Point - 450;
        allObj[id_cell] = obj;
        allObj[id_cell].SetPosObj(150 + 100 * id_cell, 440);
        allObj[id_cell].SetPosRect(150 + 100 * id_cell, 440);  
        isSelectedTable = true;
        allObjIsSelected[id_cell] = true;


    }
    
}


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void clickEvent(Camera2D camera, int &money, int id_cell,std::map<std::string, BuildObj> tableRes, BuildObj cell[]){
   
        

        //allObj[id_cell].SetPosRect(150 + 100 * id_cell, 500);  
        /*
        if (WindowBoxPopUpSelectTableActive){
              
            allObj[id_cell].countAnim(allObj[id_cell]);
		    allObj[id_cell].animation(allObj[id_cell]);
        }*/


}

bool selectionBtn(Camera2D camera,int id_cell, std::map<std::string, BuildObj> tableRes, BuildObj cell[]){
    Rectangle layoutRecs[7] = {
        (Rectangle){ 344, 352, 256, 128 },
        (Rectangle){ 352, 384, 120, 24 },
        (Rectangle){ 352, 416, 120, 24 },
        (Rectangle){ 352, 448, 120, 24 },
        (Rectangle){ 480, 384, 120, 24 },
        (Rectangle){ 480, 416, 120, 24 },
        (Rectangle){ 480, 448, 120, 24 },
    };
    
    if (WindowBoxPopUpSelectTableActive){
                WindowBoxPopUpSelectTableActive = !GuiWindowBox(layoutRecs[0], "Select table");
                if (GuiButton(layoutRecs[1], "Table light")) {
                    TableMin(id_cell, tableRes["tableResearch"]);
		        }
                if (GuiButton(layoutRecs[2], "Table medium")){ 
			        TableMid(id_cell, tableRes["tableResearch2"]);
                } 
                if (GuiButton(layoutRecs[3], "Table top")){ 
			        TableEnd(id_cell, tableRes["tableResearch3"]);
                } 
                GuiLabel(layoutRecs[4], "Know points 20");
                GuiLabel(layoutRecs[5], "Know points 40");
                GuiLabel(layoutRecs[6], "Know points 80");
            }
          allObjIsExists[id_cell] = false; 
  return WindowBoxPopUpSelectTableActive; 
}

