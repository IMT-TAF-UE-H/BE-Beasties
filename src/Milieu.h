#ifndef _MILIEU_H_
#define _MILIEU_H_

#include "IBestiole.h"
#include "UImg.h"
#include "BestioleFactory.h"

#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class BestioleFactory;


class IBestiole;

class Milieu : public UImg {

private:
    static const T white[];
    static double DIST_MAX_VOISINS;
    static double DIST_COLLISION;
    static double probaNaissanceSpontanee;
    static double probaClonage;
    static int nbBestioles;

    std::map<int, std::shared_ptr<IBestiole>> listeBestioles;

public:
    static double width, height;

public:
    Milieu(int _width, int _height, ofstream &logFile);
    ~Milieu(void);

    void step();
    void tuer(int idBestiole);

    unique_ptr<std::map<int, std::shared_ptr<IBestiole>>> getVoisins(int idBestiole);
    std::shared_ptr<IBestiole> getBestiole(int idBestiole);
    void addBestiole();
    void peupler(int nbBestioles);

    static void setLimites(double _DIST_MAX_VOISINS, double _DIST_COLLISION, double _probaNaissanceSpontanee, double _probaClonage, int _nbBestioles);

private:
    std::vector<int> getVaMourir();
    BestioleFactory* bestioleFactory;
    ofstream& logFile;
};

#endif
