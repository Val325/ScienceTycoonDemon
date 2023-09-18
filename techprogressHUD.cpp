#include "raygui.h"

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
// Button: Button001 logic
static void Button001()
{
    // TODO: Implement control logic
}
// Button: Button002 logic
static void Button002()
{
    // TODO: Implement control logic
}
// Button: Button003 logic
static void Button003()
{
    // TODO: Implement control logic
}
// Button: Button004 logic
static void Button004()
{
    // TODO: Implement control logic
}
// Button: Button005 logic
static void Button005()
{
    // TODO: Implement control logic
}
// Button: Button006 logic
static void Button006()
{
    // TODO: Implement control logic
}
// Button: Button007 logic
static void Button007()
{
    // TODO: Implement control logic
}
// Button: Button008 logic
static void Button008()
{
    // TODO: Implement control logic
}
// Button: Button009 logic
static void Button009()
{
    // TODO: Implement control logic
}


bool showTechTree(){
   // layout_tech_tree: controls initialization
    //----------------------------------------------------------------------------------
    // Define controls variables


    // Define controls rectangles
    Rectangle layoutRecs[10] = {
        (Rectangle){ 240, 120, 720, 456 },    // WindowBox: WindowBox000
        (Rectangle){ 544, 176, 120, 24 },    // Button: Button001
        (Rectangle){ 544, 208, 120, 24 },    // Button: Button002
        (Rectangle){ 544, 240, 120, 24 },    // Button: Button003
        (Rectangle){ 440, 280, 120, 24 },    // Button: Button004
        (Rectangle){ 648, 280, 120, 24 },    // Button: Button005
        (Rectangle){ 648, 312, 120, 24 },    // Button: Button006
        (Rectangle){ 440, 312, 120, 24 },    // Button: Button007
        (Rectangle){ 544, 344, 120, 24 },    // Button: Button008
        (Rectangle){ 544, 376, 120, 24 },    // Button: Button009
    };
    //----------------------------------------------------------------------------------
    // raygui: controls drawing
            //----------------------------------------------------------------------------------
            // Draw controls
            //if (WindowBox000Active)
            //{//WindowBox000Active = !GuiWindowBox(layoutRecs[0], "SAMPLE TEXT");

                WindowBox000Active = !GuiWindowBox(layoutRecs[0], "Tech tree");
                if (GuiButton(layoutRecs[1], "ADVANCED COMPUTERS")) Button001(); 
                if (GuiButton(layoutRecs[2], "ADVANCED MEDICINE")) Button002(); 
                if (GuiButton(layoutRecs[3], "NANOTECHNOLOGY")) Button003(); 
                if (GuiButton(layoutRecs[4], "ADVANCED MATERIALS")) Button004(); 
                if (GuiButton(layoutRecs[5], "PATTERNS WORLD")) Button005(); 
                if (GuiButton(layoutRecs[6], "UNDERSTAND BEING")) Button006(); 
                if (GuiButton(layoutRecs[7], "NEURAL NETWORKS")) Button007(); 
                if (GuiButton(layoutRecs[8], "AI")) Button008(); 
                if (GuiButton(layoutRecs[9], "TECH SINGULARITY")) Button009(); 
            //}
            //----------------------------------------------------------------------------------
    return WindowBox000Active;
}

