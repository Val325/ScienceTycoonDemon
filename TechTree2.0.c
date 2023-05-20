/*******************************************************************************************
*
*   TechTree2.0 v1.0.0 - Tool Description
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
static void Tech20century();
static void Transistors();
static void Computers();
static void Materials();
static void Math();
static void Understand being();
static void Nanotech]();
static void Quatum();
static void Cold nuke();
static void Warp();
static void Comp1();
static void Comp2();
static void Comp3();
static void Comp4and1();
static void Comp4and2();
static void Comp4and3();
static void Comp4and4();
static void LabelButton018();
static void LabelButton019();
static void LabelButton020();
static void NeuralNet();
static void AI();
static void Robots();
static void Singularity();
static void 1();
static void LabelButton026();
static void LabelButton027();
static void LabelButton028();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "TechTree2.0");

    // TechTree2.0: controls initialization
    //----------------------------------------------------------------------------------
    bool WindowBox000Active = true;

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
            if (WindowBox000Active)
            {
                WindowBox000Active = !GuiWindowBox(layoutRecs[0], "Tech tree");
                if (GuiButton(layoutRecs[1], "Tech 20 century")) Tech20century(); 
                if (GuiButton(layoutRecs[2], "Transistors")) Transistors(); 
                if (GuiButton(layoutRecs[3], "Computers")) Computers(); 
                if (GuiButton(layoutRecs[4], "Materials")) Materials(); 
                if (GuiButton(layoutRecs[5], "Complex math")) Math(); 
                if (GuiButton(layoutRecs[6], "Understand being")) Understand being(); 
                if (GuiButton(layoutRecs[7], "Nanomaterials")) Nanotech](); 
                if (GuiButton(layoutRecs[8], "Quantum physics")) Quatum(); 
                if (GuiButton(layoutRecs[9], "Cold nuke synthes")) Cold nuke(); 
                if (GuiButton(layoutRecs[10], "Warp drive")) Warp(); 
                if (GuiLabelButton(layoutRecs[11], "Completed")) Comp1(); 
                if (GuiLabelButton(layoutRecs[12], "Completed")) Comp2(); 
                if (GuiLabelButton(layoutRecs[13], "Completed")) Comp3(); 
                if (GuiLabelButton(layoutRecs[14], "Completed")) Comp4and1(); 
                if (GuiLabelButton(layoutRecs[15], "Completed")) Comp4and2(); 
                if (GuiLabelButton(layoutRecs[16], "Completed")) Comp4and3(); 
                if (GuiLabelButton(layoutRecs[17], "Completed")) Comp4and4(); 
                if (GuiLabelButton(layoutRecs[18], "Completed")) LabelButton018(); 
                if (GuiLabelButton(layoutRecs[19], "Completed")) LabelButton019(); 
                if (GuiLabelButton(layoutRecs[20], "Completed")) LabelButton020(); 
                if (GuiButton(layoutRecs[21], "NEURAL NETWORKS")) NeuralNet(); 
                if (GuiButton(layoutRecs[22], "AI")) AI(); 
                if (GuiButton(layoutRecs[23], "Robots")) Robots(); 
                if (GuiButton(layoutRecs[24], "TECH SINGULARITY")) Singularity(); 
                if (GuiLabelButton(layoutRecs[25], "Completed")) 1(); 
                if (GuiLabelButton(layoutRecs[26], "Completed")) LabelButton026(); 
                if (GuiLabelButton(layoutRecs[27], "Completed")) LabelButton027(); 
                if (GuiLabelButton(layoutRecs[28], "END GAME")) LabelButton028(); 
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
static void Tech20century()
{
    // TODO: Implement control logic
}
static void Transistors()
{
    // TODO: Implement control logic
}
static void Computers()
{
    // TODO: Implement control logic
}
static void Materials()
{
    // TODO: Implement control logic
}
static void Math()
{
    // TODO: Implement control logic
}
static void Understand being()
{
    // TODO: Implement control logic
}
static void Nanotech]()
{
    // TODO: Implement control logic
}
static void Quatum()
{
    // TODO: Implement control logic
}
static void Cold nuke()
{
    // TODO: Implement control logic
}
static void Warp()
{
    // TODO: Implement control logic
}
static void Comp1()
{
    // TODO: Implement control logic
}
static void Comp2()
{
    // TODO: Implement control logic
}
static void Comp3()
{
    // TODO: Implement control logic
}
static void Comp4and1()
{
    // TODO: Implement control logic
}
static void Comp4and2()
{
    // TODO: Implement control logic
}
static void Comp4and3()
{
    // TODO: Implement control logic
}
static void Comp4and4()
{
    // TODO: Implement control logic
}
static void LabelButton018()
{
    // TODO: Implement control logic
}
static void LabelButton019()
{
    // TODO: Implement control logic
}
static void LabelButton020()
{
    // TODO: Implement control logic
}
static void NeuralNet()
{
    // TODO: Implement control logic
}
static void AI()
{
    // TODO: Implement control logic
}
static void Robots()
{
    // TODO: Implement control logic
}
static void Singularity()
{
    // TODO: Implement control logic
}
static void 1()
{
    // TODO: Implement control logic
}
static void LabelButton026()
{
    // TODO: Implement control logic
}
static void LabelButton027()
{
    // TODO: Implement control logic
}
static void LabelButton028()
{
    // TODO: Implement control logic
}

