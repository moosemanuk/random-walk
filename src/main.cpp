#include <raylib.h>
#include "constants.h"
#include "walker.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Random Walk");
    SetTargetFPS(TARGET_FPS);

    Walker walker;
    int steps = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();        
        walker.Walk();
        steps++;
        Vector2 position = walker.GetPosition();
        DrawText(TextFormat("(%03i, %03i)", position.x, position.y), 10, 10, 5, WHITE);        
        DrawText(TextFormat("Steps: %03i", steps), 10, 20, 5, WHITE);        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}