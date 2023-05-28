/*******************************************************************************************
*
*   SelectionBtn v1.0.0 - Tool Description
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
static void TableUpdate();
static void TableEnd();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "selectionBtn");

    // selectionBtn: controls initialization
    //----------------------------------------------------------------------------------
    bool WindowBoxPopUpSelectTableActive = true;

    Rectangle layoutRecs[5] = {
        (Rectangle){ 344, 352, 224, 96 },
        (Rectangle){ 352, 384, 120, 24 },
        (Rectangle){ 352, 416, 120, 24 },
        (Rectangle){ 480, 384, 120, 24 },
        (Rectangle){ 480, 416, 120, 24 },
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
            if (WindowBoxPopUpSelectTableActive)
            {
                WindowBoxPopUpSelectTableActive = !GuiWindowBox(layoutRecs[0], "Table");
                if (GuiButton(layoutRecs[1], "Update")) TableUpdate(); 
                if (GuiButton(layoutRecs[2], "TableSell")) TableEnd(); 
                GuiLabel(layoutRecs[3], "Know points 50");
                GuiLabel(layoutRecs[4], "Get 20 points");
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
static void TableUpdate()
{
    // TODO: Implement control logic
}
static void TableEnd()
{
    // TODO: Implement control logic
}

