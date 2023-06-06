#include "raygui.h"
//#include "Structs.cpp"
#include "buildObj.h"

//class BuildObj;
//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
//
std::vector<BuildObj> allObj;

void TableMin()
{
   
   BuildObj tableReserarch("tableResearch","src/tableResearch.gif", 4.5f);
   //tableReserarch.Draw();
   allObj.push_back(tableReserarch);
   
   //return "tableReserarch";
  
    
                
   
}
void TableMid()
{
    BuildObj tableReserarch("tableResearch2","src/tableResearch2.gif", 4.5f);
    //tableReserarch.Draw();
    allObj.push_back(tableReserarch);
    //return "tableResearch2"; 

}
void TableEnd()
{
    BuildObj tableReserarch("tableResearch3","src/tableResearch3.gif", 4.5f);
    //tableReserarch.Draw();
    allObj.push_back(tableReserarch);
    //return "tableResearch3"; 

}


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
static bool selectionBtn()
{
    
    // selectionBtn: controls initialization
    //----------------------------------------------------------------------------------
    bool WindowBoxPopUpSelectTableActive = true;
    
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
                std::cout << "window box coord: " << layoutRecs[0].x << " "<< layoutRecs[0].y << std::endl;
                
                if (GuiButton(layoutRecs[1], "Table light")) {
			TableMin();
		}
                if (GuiButton(layoutRecs[2], "Table medium")){ 
			TableMid();
		} 
                if (GuiButton(layoutRecs[3], "Table top")){ 
			TableEnd();
		} 
                GuiLabel(layoutRecs[4], "Know points 20");
                GuiLabel(layoutRecs[5], "Know points 40");
                GuiLabel(layoutRecs[6], "Know points 80");
            }
            

  return WindowBoxPopUpSelectTableActive; 
}

