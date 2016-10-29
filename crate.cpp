#include "crate.h"


Crate::Crate(){
    PhysicsWorld::NewBox(body,geom,double3(1,1,1),1,this);
}

Crate::~Crate()
{
    //dtor
}


void Crate::Draw(){
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLE_FAN);

        double3 d = double3(.5,.5,.5);

        glColor3f(d.x*-1,d.y*-1,d.z*-1);
        glVertex3d(d.x*-.5,d.y*-.5,d.z*-.5);
        glColor3f(d.x*-1,d.y,d.z*-1);
        glVertex3d(d.x*-.5,d.y*.5,d.z*-.5);
        glColor3f(d.x,d.y,d.z*-1);
        glVertex3d(d.x*.5,d.y*.5,d.z*-.5);
        glColor3f(d.x,d.y*-1,d.z*-1);
        glVertex3d(d.x*.5,d.y*-.5,d.z*-.5);
        glColor3f(d.x,d.y*-1,d.z);
        glVertex3d(d.x*.5,d.y*-.5,d.z*.5);
        glColor3f(d.x*-1,d.y*-1,d.z);
        glVertex3d(d.x*-.5,d.y*-.5,d.z*.5);
        glColor3f(d.x*-1,d.y,d.z);
        glVertex3d(d.x*-.5,d.y*.5,d.z*.5);
        glColor3f(d.x*-1,d.y,d.z*-1);
        glVertex3d(d.x*-.5,d.y*.5,d.z*-.5);
    glEnd();
}
