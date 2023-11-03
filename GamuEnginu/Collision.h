#pragma once
#include "Box2D/Box2D.h"

namespace MyGameEngine
{
    class Collision
    {
    protected:
        b2Body* myRigidbody;
        b2Body* otherRigidbody;

    public:
        b2Body* GetMyRigidbody() const {
            return myRigidbody;
        }

        void SetMyRigidbody(b2Body* body) {
            myRigidbody = body;
        }

        b2Body* GetOtherRigidbody() const {
            return otherRigidbody;
        }

        void SetOtherRigidbody(b2Body* body) {
            otherRigidbody = body;
        }
    };
}
