#include <raylib.h>
#include "constants.h"
#include "walker.h"

int main()
{
    Walker walker(ORIGIN);    
    
    while (!walker.WalkerShouldClose())
    {
        if(IsKeyPressed(KEY_SPACE))
        {
            walker.Reset();
        }
        walker.Walk();        
        walker.Draw();        
    }

    walker.Close();
    return 0;
}