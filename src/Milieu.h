#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "IBestiole.h"
#include "UImg.h"
#include "BestioleFactory.h"

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class BestioleFactory;

class IBestiole;

class Milieu : public UImg {

private:
    static const T white[];
    static double DIST_MAX_VOISINS;
    static double DIST_COLLISION;

    std::map<int, IBestiole*> listeBestioles;

public:
    static double width, height;

public:
    Milieu(int _width, int _height);
    ~Milieu(void);

    void step();
    void tuer(int idBestiole);

    unique_ptr<std::map<int, IBestiole*>> getVoisins(int idBestiole);
    IBestiole* getBestiole(int idBestiole);
    void addBestiole();

private:
    std::vector<int> getVaMourir();
    BestioleFactory* bestioleFactory;
};

#endif
