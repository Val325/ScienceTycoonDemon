/*******************************************************************************************
*
*   LayoutTechTree v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------
static void Button001();                // Button: Button001 logic
static void Button002();                // Button: Button002 logic
static void Button003();                // Button: Button003 logic
static void Button004();                // Button: Button004 logic
static void Button005();                // Button: Button005 logic
static void Button006();                // Button: Button006 logic
static void Button007();                // Button: Button007 logic
static void Button008();                // Button: Button008 logic
static void Button009();                // Button: Button009 logic

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "layout_tech_tree");

    // layout_tech_tree: controls initialization
    //----------------------------------------------------------------------------------
    // Define controls variables
    bool WindowBox000Active = true;            // WindowBox: WindowBox000

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

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR))); 

            // raygui: controls drawing
            //----------------------------------------------------------------------------------
            // Draw controls
            if (WindowBox000Active)
            {
                WindowBox000Active = !GuiWindowBox(layoutRecs[0], "SAMPLE TEXT");
                if (GuiButton(layoutRecs[1], "SAMPLE TEXT")) Button001(); 
                if (GuiButton(layoutRecs[2], "SAMPLE TEXT")) Button002(); 
                if (GuiButton(layoutRecs[3], "SAMPLE TEXT")) Button003(); 
                if (GuiButton(layoutRecs[4], "SAMPLE TEXT")) Button004(); 
                if (GuiButton(layoutRecs[5], "SAMPLE TEXT")) Button005(); 
                if (GuiButton(layoutRecs[6], "SAMPLE TEXT")) Button006(); 
                if (GuiButton(layoutRecs[7], "SAMPLE TEXT")) Button007(); 
                if (GuiButton(layoutRecs[8], "SAMPLE TEXT")) Button008(); 
                if (GuiButton(layoutRecs[9], "SAMPLE TEXT")) Button009(); 
            }
            //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

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

