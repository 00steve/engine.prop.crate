#ifndef CRATE_H
#define CRATE_H


#include <engine/physics/physical_single_body.h>

class Crate : public PhysicalSingleBody {

protected:

    virtual void OnSetSettings();

public:

    Crate();
    ~Crate();

    virtual void Draw();

};



#endif // CRATE_H
