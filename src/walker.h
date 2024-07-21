#pragma once
#include <raylib.h>

class Walker{
    private:
        Vector2 position;
        
    public:
        Walker();
        void Walk();  
        void Reset(); 
        Vector2 GetPosition();     
                
};