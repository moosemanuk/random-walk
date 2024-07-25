#include "walker.h"
#include "constants.h"

Walker::Walker(Vector2 origin)
{
    points.push_back(origin);
    position.x = origin.x;
    position.y = origin.y;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Random Walk");
    SetTargetFPS(TARGET_FPS);
}

void Walker::Walk()
{
    int randommove = GetRandomValue(1,4);

    if(position.x > 0 && position.x < SCREEN_WIDTH && position.y > 0 && position.y < SCREEN_HEIGHT)
    {
        switch(randommove){
            case 1:
                points.push_back({position.x, position.y - STEP});
                position.y = position.y - STEP;
                break;
            case 2:
                points.push_back({position.x + STEP, position.y});
                position.x = position.x + STEP;            
                break;
            case 3:
                points.push_back({position.x - STEP, position.y});
                position.x = position.x - STEP;
                break;
            case 4:
                points.push_back({position.x, position.y + STEP});
                position.y = position.y + STEP;
                break;    
        }
    }        
}

void Walker::Draw()
{
    BeginDrawing();        
    ClearBackground(BACKGROUND);
    for(int i = 0; i < (int)points.size() - 1 ; i++)
    {
        Color strokeColour = RAYWHITE;
        if(points[i].x > points[i+1].x)
        {
            strokeColour = LEFT;
        }
        if(points[i].x < points[i+1].x)
        {
            strokeColour = RIGHT;
        }
        if(points[i].y > points[i+1].y)
        {
            strokeColour = UP;
        }
        if(points[i].y > points[i+1].y)
        {
            strokeColour = DOWN;
        }
        
        DrawLineEx(points[i], points[i+1], STROKE, strokeColour);        
    }
    
    EndDrawing();
}

void Walker::Reset()
{
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;    
    ClearBackground(BACKGROUND);
}

bool Walker::WalkerShouldClose()
{
    return WindowShouldClose();
}

void Walker::Close()
{
    CloseWindow();
}

Vector2 Walker::GetPosition()
{
    return position;
}
