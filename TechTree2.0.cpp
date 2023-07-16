#include "raygui.h"


// Checks if _SELECTBTN_ IF DECLARED
#ifndef _TECHTREE_
  
// Defines _SELECTBTN_ if above
// conditions fails
#define _TECHTREE_

bool Tech20Century = false;
bool Transistor = false;
bool Computer = false;
bool material = false;
bool Mathematics = false;
bool Being = false;
bool NaNtech = false;
bool QuatumTech = false;
bool ColdNuke = false;
bool WarpEngine = false;
bool NeuralNetwork = false;
bool ArtificialIntellect = false;
bool Robot = false;
bool Singularit = false;
//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
static void Tech20century()
{
    Tech20Century = true; 
}
static void Transistors()
{
    Transistor = true;
}
static void Computers()
{
    Computer = true;
}
static void Materials()
{
    material = true;
}
static void Math()
{
    Mathematics = true;
}
static void Understand_being()
{
    Being = true;
}
static void Nanotech()
{
    NaNtech = true;
}
static void Quatum()
{
    QuatumTech = true;
}
static void Cold_nuke()
{
    ColdNuke = true;
}
static void Warp()
{
    WarpEngine = true;
}
static void Comp1()
{

}
static void Comp2()
{

}
static void Comp3()
{

}
static void Comp4and1()
{

}
static void Comp4and2()
{

}
static void Comp4and3()
{

}
static void Comp4and4()
{

}
static void LabelButton018()
{

}
static void LabelButton019()
{

}
static void LabelButton020()
{

}
static void NeuralNet()
{
    NeuralNetwork = true;
}
static void AI()
{
    ArtificialIntellect = true;
}
static void Robots()
{
    Robot = true;
}
static void Singularity()
{
    Singularit = true;
}
static void one()
{

}
static void LabelButton026()
{

}
static void LabelButton027()
{

}
static void LabelButton028()
{

}


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
bool ShowHUDTechTree()
{
        

    // TechTree2.0: controls initialization
    //----------------------------------------------------------------------------------
    //bool WindowBox000Active = true;
    bool WindowBox000Active = true;
    bool WindowIsOpen = false;
    Rectangle layoutRecs[29] = {
        (Rectangle){ 240, 120, 720, 456 },
        (Rectangle){ 544, 176, 120, 24 },
        (Rectangle){ 544, 208, 120, 24 },
        (Rectangle){ 544, 240, 120, 24 },
        (Rectangle){ 440, 280, 120, 24 },
        (Rectangle){ 648, 280, 120, 24 },
        (Rectangle){ 648, 312, 120, 24 },
        (Rectangle){ 440, 312, 120, 24 },
        (Rectangle){ 544, 344, 120, 24 },
        (Rectangle){ 544, 376, 120, 24 },
        (Rectangle){ 544, 408, 120, 24 },
        (Rectangle){ 472, 176, 120, 24 },
        (Rectangle){ 472, 208, 120, 24 },
        (Rectangle){ 472, 240, 120, 24 },
        (Rectangle){ 368, 280, 120, 24 },
        (Rectangle){ 368, 312, 120, 24 },
        (Rectangle){ 776, 280, 120, 24 },
        (Rectangle){ 776, 312, 120, 24 },
        (Rectangle){ 672, 344, 120, 24 },
        (Rectangle){ 472, 376, 120, 16 },
        (Rectangle){ 672, 408, 120, 24 },
        (Rectangle){ 544, 440, 120, 24 },
        (Rectangle){ 440, 472, 120, 24 },
        (Rectangle){ 648, 472, 120, 24 },
        (Rectangle){ 544, 504, 120, 24 },
        (Rectangle){ 472, 440, 120, 24 },
        (Rectangle){ 368, 472, 120, 24 },
        (Rectangle){ 776, 472, 120, 24 },
        (Rectangle){ 568, 536, 120, 24 },
    };
      

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            
            if (WindowBox000Active)
            {
                
                WindowBox000Active = !GuiWindowBox(layoutRecs[0], "Tech tree"); 
           
   
                if (GuiButton(layoutRecs[1], "Tech 20 century")) Tech20century();
                if (Tech20Century){
                    if (GuiButton(layoutRecs[2], "Transistors")) Transistors();
                    if (GuiLabelButton(layoutRecs[12], "300 credit")) Comp2(); 
                }
                if (Transistor){
                    if (GuiButton(layoutRecs[3], "Computers")) Computers();
                    if (GuiLabelButton(layoutRecs[13], "500 credit")) Comp3(); 
                }
                if (Computer){
                    if (GuiButton(layoutRecs[4], "Materials")) Materials(); 
                    if (GuiLabelButton(layoutRecs[14], "700 credit")) Comp4and1();
                    if (GuiButton(layoutRecs[5], "Complex math")) Math();
                    if (GuiLabelButton(layoutRecs[16], "800 credit")) Comp4and3();
                }
                if (material) {
                    if (GuiButton(layoutRecs[7], "Nanomaterials")) Nanotech();
                    if (GuiLabelButton(layoutRecs[15], "900 credit")) Comp4and2();
                }
                if (Mathematics) {
                    if (GuiButton(layoutRecs[6], "Understand being")) Understand_being();
                    if (GuiLabelButton(layoutRecs[17], "900 credit")) Comp4and4();
                }
                if (NaNtech && Being){
                    if (GuiButton(layoutRecs[8], "Quantum physics")) Quatum();
                    if (GuiLabelButton(layoutRecs[18], "2000 credit")) LabelButton018();
                }
                if (QuatumTech){
                    if (GuiButton(layoutRecs[9], "Cold nuke synthes")) Cold_nuke();
                    if (GuiLabelButton(layoutRecs[19], "4000 credit")) LabelButton019(); 
                }
                if (ColdNuke) {
                    if (GuiButton(layoutRecs[10], "Warp drive")) Warp(); 
                    if (GuiLabelButton(layoutRecs[20], "10000 credit")) LabelButton020();  
                }
                if (WarpEngine) {
                    if (GuiButton(layoutRecs[21], "NEURAL NETWORKS")) NeuralNet(); 
                    if (GuiLabelButton(layoutRecs[25], "20000 credit")) one(); 
                }
                if (NeuralNetwork) {
                    if (GuiButton(layoutRecs[22], "AI")) AI(); 
                    if (GuiButton(layoutRecs[23], "Robots")) Robots();
                    if (GuiLabelButton(layoutRecs[26], "40000 credit")) LabelButton026(); 
                    if (GuiLabelButton(layoutRecs[27], "70000 credit")) LabelButton027(); 
                }
                if (ArtificialIntellect && Robot){
                    if (GuiButton(layoutRecs[24], "TECH SINGULARITY")) Singularity();
                    if (GuiLabelButton(layoutRecs[28], "100000 credit")) LabelButton028();
                }
                //if (GuiButton(layoutRecs[6], "Understand being")) Understand_being(); 
                //if (GuiButton(layoutRecs[7], "Nanomaterials")) Nanotech(); 
                //if (GuiButton(layoutRecs[8], "Quantum physics")) Quatum(); 
                //if (GuiButton(layoutRecs[9], "Cold nuke synthes")) Cold_nuke(); 
                //if (GuiButton(layoutRecs[10], "Warp drive")) Warp(); 
                if (GuiLabelButton(layoutRecs[11], "100 credit")) Comp1(); 
                //if (GuiLabelButton(layoutRecs[15], "900 credit")) Comp4and2();
    
                //if (GuiLabelButton(layoutRecs[16], "800 credit")) Comp4and3(); 
                //if (GuiLabelButton(layoutRecs[17], "900 credit")) Comp4and4(); 
                //if (GuiLabelButton(layoutRecs[18], "2000 credit")) LabelButton018(); 
                //if (GuiLabelButton(layoutRecs[19], "4000 credit")) LabelButton019(); 
                //if (GuiLabelButton(layoutRecs[20], "10000 credit")) LabelButton020(); 
                //if (GuiButton(layoutRecs[21], "NEURAL NETWORKS")) NeuralNet(); 
                //if (GuiButton(layoutRecs[22], "AI")) AI(); 
                //if (GuiButton(layoutRecs[23], "Robots")) Robots(); 
                //if (GuiButton(layoutRecs[24], "TECH SINGULARITY")) Singularity(); 
                //if (GuiLabelButton(layoutRecs[25], "20000 credit")) one(); 
                //if (GuiLabelButton(layoutRecs[26], "40000 credit")) LabelButton026(); 
                //if (GuiLabelButton(layoutRecs[27], "70000 credit")) LabelButton027(); 
                //if (GuiLabelButton(layoutRecs[28], "100000 credit")) LabelButton028();
               

            }
            //----------------------------------------------------------------------------------

      
   

    return WindowBox000Active;
}

#endif
