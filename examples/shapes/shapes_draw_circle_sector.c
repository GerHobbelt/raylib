/*******************************************************************************************
*
*   raylib [shapes] example - draw circle sector (with gui options)
*
*   Example originally created with raylib 2.5, last time updated with raylib 2.5
*
*   Example contributed by Vlad Adrian (@demizdor) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2018-2024 Vlad Adrian (@demizdor) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"                 // Required for GUI controls

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    RL_InitWindow(screenWidth, screenHeight, "raylib [shapes] example - draw circle sector");

    RL_Vector2 center = {(RL_GetScreenWidth() - 300)/2.0f, RL_GetScreenHeight()/2.0f };

    float outerRadius = 180.0f;
    float startAngle = 0.0f;
    float endAngle = 180.0f;
    float segments = 10.0f;
    float minSegments = 4;

    RL_SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!RL_WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // NOTE: All variables update happens inside GUI control functions
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        RL_BeginDrawing();

            RL_ClearBackground(RL_RAYWHITE);

            RL_DrawLine(500, 0, 500, RL_GetScreenHeight(), RL_Fade(RL_LIGHTGRAY, 0.6f));
            RL_DrawRectangle(500, 0, RL_GetScreenWidth() - 500, RL_GetScreenHeight(), RL_Fade(RL_LIGHTGRAY, 0.3f));

            RL_DrawCircleSector(center, outerRadius, startAngle, endAngle, (int)segments, RL_Fade(RL_MAROON, 0.3f));
            RL_DrawCircleSectorLines(center, outerRadius, startAngle, endAngle, (int)segments, RL_Fade(RL_MAROON, 0.6f));

            // Draw GUI controls
            //------------------------------------------------------------------------------
            GuiSliderBar((RL_Rectangle){ 600, 40, 120, 20}, "StartAngle", NULL, &startAngle, 0, 720);
            GuiSliderBar((RL_Rectangle){ 600, 70, 120, 20}, "EndAngle", NULL, &endAngle, 0, 720);

            GuiSliderBar((RL_Rectangle){ 600, 140, 120, 20}, "Radius", NULL, &outerRadius, 0, 200);
            GuiSliderBar((RL_Rectangle){ 600, 170, 120, 20}, "Segments", NULL, &segments, 0, 100);
            //------------------------------------------------------------------------------

            minSegments = truncf(ceilf((endAngle - startAngle) / 90));
            RL_DrawText(RL_TextFormat("MODE: %s", (segments >= minSegments)? "MANUAL" : "AUTO"), 600, 200, 10, (segments >= minSegments)? RL_MAROON : RL_DARKGRAY);

            RL_DrawFPS(10, 10);

        RL_EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    RL_CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}