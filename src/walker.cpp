#include "walker.h"
#include "constants.h"

Walker::Walker()
{
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;
}

void Walker::Walk()
{
    // flip two coins
    // head/heads - go up
    // head/tails - go right
    // tails/heads - go left
    // tails/tails - go down

    int coin1 = GetRandomValue(1, 2); //(1 = heads / 2 = tails)
    int coin2 = GetRandomValue(1, 2);

    if (position.x > 0 && position.x < SCREEN_WIDTH && position.y > 0 && position.y < SCREEN_HEIGHT)
    {
        switch (coin1)
        {
        case 1:
            switch (coin2)
            {
            case 1:
                DrawLine(position.x, position.y, position.x, position.y - STEP, UP);
                this->position.y = position.y - STEP;
                break;
            case 2:
                DrawLine(position.x, position.y, position.x + STEP, position.y, RIGHT);
                this->position.x = position.x + STEP;
                break;
            }
            break;
        case 2:
            switch (coin2)
            {
            case 1:
                DrawLine(position.x, position.y, position.x - STEP, position.y, LEFT);
                this->position.x = position.x - STEP;
                break;
            case 2:
                DrawLine(position.x, position.y, position.x, position.y + STEP, DOWN);
                this->position.y = position.y + STEP;
                break;
            }
            break;
        }        
    }
    
}

void Walker::Reset()
{
    this->position.x = SCREEN_WIDTH / 2;
    this->position.y = SCREEN_HEIGHT / 2;    
    ClearBackground(BACKGROUND);
}

Vector2 Walker::GetPosition()
{
    return position;
}
