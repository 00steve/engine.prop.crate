#ifndef CRATE_H
#define CRATE_H

#include <engine/physics/physical_single_body.h>
#include <engine/physics/physics_world.h>
#include <GL/gl.h>
#define dSINGLE
#include <ode/ode.h>


class Crate : public PhysicalSingleBody{
private:

    static string geometry;
    static List<double> lengths;
    static double density;

protected:

    virtual bool HandleMessage(NodeMessage message);

public:

    Crate();
    ~Crate();

    virtual void Update();
    void Draw();

};



#endif // CRATE_H
