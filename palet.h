#ifndef PALET_H
#define PALET_H

#include <GL/glu.h>

class Palet
{
public:
    Palet(float positionX);
    void Display();
    void UpdatePos(float position);
private:
    float posx_;

};

#endif // PALET_H
