#pragma once
#include <raylib.h>
#include <vector>

class Walker
{
    private:        
        Vector2 position;
        std::vector<Vector2> points;
        int steps;
        
    public:
        Walker(Vector2 origin);
        void Walk();
        void Draw();  
        void Reset(); 
        bool WalkerShouldClose();
        void Close();
        Vector2 GetPosition() const;     
                
};