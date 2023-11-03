#pragma once
#include <Box2D/Box2D.h>

namespace MyGameEngine
{
    class ICollisionable
    {
    public:
        virtual void BeginCollision(b2Contact* contact) = 0;
        virtual void EndCollision(b2Contact* contact) = 0;
    };
}