#ifndef BOULE_H
#define BOULE_H

#include <GL/glu.h>

class Boule
{
public:
    Boule(float x,float y);

    void Display();

private:
    float posx_;
    float posy_;
};

#endif // BOULE_H
