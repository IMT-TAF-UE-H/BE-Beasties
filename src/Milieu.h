#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "IBestiole.h"
#include "UImg.h"

#include <iostream>
#include <map>

using namespace std;

class Milieu : public UImg {

private:
    static const T white[];
    static const double DIST_MAX_VOISINS;

    std::map<int, IBestiole*> listeBestioles;

public:
    static double width, height;

public:
    Milieu(int _width, int _height);
    ~Milieu(void);

    void step();
    void tuer(int idBestiole);

    std::map<int, IBestiole*> getVoisins(IBestiole* b);
    void addBestiole(IBestiole* bestiole);

private:
    std::map<int, IBestiole*> getVaMourir();
};

#endif
