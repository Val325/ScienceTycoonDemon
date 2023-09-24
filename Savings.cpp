//#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"

static void Button0();
static void Button1();
static void Button2();

void SaveDataBtn(void)
{
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
            ClearBackground(BLACK);
            // raygui: controls drawing
            //----------------------------------------------------------------------------------

            //----------------------------------------------------------------------------------
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

}

static void Button0()
{
}
static void Button1()
{
}
static void Button2()
{
}

