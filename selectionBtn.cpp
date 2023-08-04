#include "raygui.h"
//#include "Structs.cpp"
#include "buildObj.h"
//#include "Scene.cpp"

//class BuildObj;
//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
//
std::vector<BuildObj> allObj;
//int Knowledge_Point = 0;
//BuildObj allObj[10];
bool allObjIsExists[10] = {false};
bool WindowBoxPopUpSelectTableActive = false;
bool isSelectedTable = false;
int chooseTable = NULL;

int AmountMinTable = 0;
int AmountMidTable = 0;
int AmountTopTable = 0;
void TableMin(int id_cell, BuildObj obj)
{
      //BuildObj tableReserarchMin("tableResearch","src/tableResearch.gif", 4.5f);
   
   //tableReserarch.Draw();
   //allObj.push_back(obj);
   allObjIsExists[id_cell] = true;
   //return "tableReserarch";
   AmountMinTable++; 
  
   allObj[id_cell] = obj;
   allObj[id_cell].SetPosObj(150 + 100 * id_cell, 440);
   allObj[id_cell].SetPosRect(150 + 100 * id_cell, 440);
   isSelectedTable = true;
   //chooseTable = id_cell; 
   //allObj.insert(allObj.begin() + id_cell, obj);
  	    

}
   //allObj.insert(allObj.begin() + id_cell, obj);
   //return tableReserarch;
   
   

void TableMid(int id_cell, BuildObj obj)
{
    //BuildObj tableReserarchMid("tableResearch2","src/tableResearch2.gif", 4.5f);
       //tableReserarch.Draw();
    //allObj.push_back(obj);
   
    allObjIsExists[id_cell] = true;
    //return "tableResearch2";
    AmountMidTable++; 
    allObj[id_cell] = obj;
    allObj[id_cell].SetPosObj(150 + 100 * id_cell, 440);
    allObj[id_cell].SetPosRect(150 + 100 * id_cell, 440);
    isSelectedTable = true;
    //chooseTable = id_cell; 
    //allObj.insert(allObj.begin() + id_cell, obj);
    //return tableReserarch; 
}
void TableEnd(int id_cell, BuildObj obj)
{
    //BuildObj tableReserarchTop("tableResearch3","src/tableResearch3.gif", 4.5f);
        //tableReserarch.Draw();
    //allObj.push_back(obj);
    AmountTopTable++; 
    allObjIsExists[id_cell] = true;
    //return "tableResearch3"; 
    //allObj.insert(allObj.begin() + id_cell, obj);
    
    allObj[id_cell] = obj;
    allObj[id_cell].SetPosObj(150 + 100 * id_cell, 440);
    allObj[id_cell].SetPosRect(150 + 100 * id_cell, 440);  
    isSelectedTable = true;
    //chooseTable = id_cell; 
    //return tableReserarch; 
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

    
    // selectionBtn: controls initialization
    //----------------------------------------------------------------------------------
    //bool WindowBoxPopUpSelectTableActive = true;
    //cell[id_cell].SetPosObj(99999999.0f, 9999999999.0f);  
    Rectangle layoutRecs[7] = {
        (Rectangle){ 344, 352, 256, 128 },
        (Rectangle){ 352, 384, 120, 24 },
        (Rectangle){ 352, 416, 120, 24 },
        (Rectangle){ 352, 448, 120, 24 },
        (Rectangle){ 480, 384, 120, 24 },
        (Rectangle){ 480, 416, 120, 24 },
        (Rectangle){ 480, 448, 120, 24 },
    };
     
    // raygui: controls drawing
            //----------------------------------------------------------------------------------
            if (WindowBoxPopUpSelectTableActive)
            {
                

                WindowBoxPopUpSelectTableActive = !GuiWindowBox(layoutRecs[0], "Select table");
                //std::cout << "window box coord: " << layoutRecs[0].x << " "<< layoutRecs[0].y << std::endl;
               
                
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

