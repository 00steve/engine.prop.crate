
#include "crate.h"

string Crate::geometry = "box";
List<double> Crate::lengths = List<double>(3,new double[3]{1,1,1});
//Crate::lengths.Push(1);
//Crate::lengths.Push(1);
//Crate::lengths.Push(1);
double Crate::density = 1;


Crate::Crate(){
}

Crate::~Crate(){
}

bool Crate::HandleMessage(NodeMessage message){
    cout << "Crate::HandleMessage - " << message.code << endl;
    switch(message.code){
    case MESSAGE_REGISTER_PHYSICS_OFFER: {
            VarMap *physics = new VarMap();
            physics->Add<string>(&geometry,"crate.geometry");
            physics->Add<List<double> >(&lengths,"crate.lengths");
            physics->Add<double>(&density,"crate.density");
            physics->Add<double3>(&position,"crate.position");
            cout << "position : " << position.x << "," << position.y << "," << position.z << endl;
            CreateAndSendMessage(message.sender,MESSAGE_REGISTER_PHYSICS_REQUEST,(void*)physics);
            return true;
        }

    case MESSAGE_REGISTER_PHYSICS_FINISHED: {
            cout << "successfully created physics object\n";
            PhysicsGroup *pGroup = (PhysicsGroup*) message.data;
            body = pGroup->body["crate"];
            geom = pGroup->geom["crate"];
            return true;
        }
    }
    return PhysicalSingleBody::HandleMessage(message);
}

void Crate::Update(){
    PhysicalSingleBody::Update();
}

void Crate::Draw(){

        //cout << " draw crate\n";
        glPushMatrix();
        //glTranslated(cratePosition.x,cratePosition.y,cratePosition.z);
        glMultMatrixf(gl_matrix);

        double3 d = double3(1,1,1);
        glBegin(GL_TRIANGLE_FAN);


			glColor3f(d.x,d.y,d.z);
			glVertex3d(d.x*.5,d.y*.5,d.z*.5);
            glColor3f(d.x,d.y*-1,d.z);
			glVertex3d(d.x*.5,d.y*-.5,d.z*.5);



            glColor3f(d.x,d.y*-1,d.z*-1);
			glVertex3d(d.x*.5,d.y*-.5,d.z*-.5);
            glColor3f(d.x,d.y,d.z*-1);
			glVertex3d(d.x*.5,d.y*.5,d.z*-.5);
            glColor3f(d.x*-1,d.y,d.z*-1);
			glVertex3d(d.x*-.5,d.y*.5,d.z*-.5);
            glColor3f(d.x*-1,d.y,d.z);
			glVertex3d(d.x*-.5,d.y*.5,d.z*.5);
            glColor3f(d.x*-1,d.y*-1,d.z);
			glVertex3d(d.x*-.5,d.y*-.5,d.z*.5);




            glColor3f(d.x,d.y*-1,d.z);
			glVertex3d(d.x*.5,d.y*-.5,d.z*.5);
		glEnd();
        glColor3f(1,1,0);
		glBegin(GL_TRIANGLE_FAN);


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

    glPopMatrix();

}
