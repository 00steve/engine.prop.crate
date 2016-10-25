#include "Crate.h"

Crate::Crate(){
    PhysicsWorld::NewBox(body,geom,double3(1,1,1),1,this);
}

Crate::~Crate()
{
    //dtor
}
