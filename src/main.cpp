#include <raylib.h>
#include "constants.h"
#include "walker.h"

int main()
{
    Walker walker(ORIGIN);    
    
    while (!walker.WalkerShouldClose())
    {
        walker.Walk();        
        walker.Draw();        
    }

    walker.Close();
    return 0;
}