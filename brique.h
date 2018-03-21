#ifndef BRIQUE_H
#define BRIQUE_H

#include <GL/glu.h>

class brique
{
public:
    brique(float x,float y);

    void Display();

private:
    float posx_;
    float posy_;
    bool disp_;
};

#endif // BRIQUE_H
