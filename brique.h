#ifndef BRIQUE_H
#define BRIQUE_H

#include <GL/glu.h>

class Brique
{
public:
    // Constructeur
    Brique(float x,float y);

    // Affichage du brique
    void Display();

private:

    float posx_;
    float posy_;
    bool disp_;
};

#endif // BRIQUE_H
