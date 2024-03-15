#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "IBestiole.h"
#include "UImg.h"

#include <iostream>
#include <vector>

using namespace std;

class Milieu : public UImg {

private:
    static const T white[];

    std::vector<IBestiole*> listeBestioles;

public:
    static double width, height;

public:
    Milieu(int _width, int _height);
    ~Milieu(void);

    void step();
    void tuer(int idBestiole);

    std::vector<IBestiole*> getVoisins(IBestiole* b);
    void addBestiole(IBestiole* bestiole);

private:
    std::vector<int> getVaMourir();
};

#endif
