/*******************************************************************************************
*
*   Main gui v1.0.0 - Tool Description
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


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Main gui");

    // Main gui: controls initialization
    //----------------------------------------------------------------------------------
    float ProgressBarTechValue = 0.0f;

    Rectangle layoutRecs[6] = {
        (Rectangle){ 32, 72, 120, 16 },
        (Rectangle){ 152, 24, 112, 16 },
        (Rectangle){ 32, 24, 120, 16 },
        (Rectangle){ 32, 96, 120, 16 },
        (Rectangle){ 32, 120, 120, 16 },
        (Rectangle){ 32, 48, 120, 16 },
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
            GuiStatusBar(layoutRecs[0], "TAB");
            ProgressBarTechValue = GuiProgressBar(layoutRecs[1], NULL, NULL, ProgressBarTechValue, 0, 1);
            GuiStatusBar(layoutRecs[2], "Tech progress");
            GuiStatusBar(layoutRecs[3], "Money");
            GuiStatusBar(layoutRecs[4], "Knowledge");
            GuiStatusBar(layoutRecs[5], "Level");
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

