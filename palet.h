#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>

class palet
{
public:
    palet(float x,float y);
    void Display();

private:
    float posx_;
    float posy_;
};

#endif // PALET_H
