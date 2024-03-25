#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

const T Milieu::white[] = {(T)255, (T)255, (T)255};
double Milieu::width = 640.;
double Milieu::height = 480.;
double Milieu::DIST_MAX_VOISINS = 100.;
double Milieu::DIST_COLLISION = 3.;

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          listeBestioles() {
    width = _width;
    height = _height;

    cout << "const Milieu" << endl;

    // Initialisation de la factorie
    bestioleFactory = new BestioleFactory(this, 0.1, 0.1, 0.1, 0.1);

    srand(time(NULL));
}

Milieu::~Milieu(void) {

    cout << "dest Milieu" << endl;
    for (auto it = listeBestioles.cbegin(); it != listeBestioles.cend();) {
        tuer((it++)->first);
    }
    // destruction de la factorie
    delete bestioleFactory;
}

void Milieu::step(void) {

    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        (it->second)->updatePos();
    }
    auto vaMourir = getVaMourir();

    for (int it : vaMourir) {
        tuer(it);
    }

    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        (it->second)->draw(*this);
    }
}

void Milieu::tuer(int idBestiole) {
    delete listeBestioles[idBestiole];
    listeBestioles.erase(idBestiole);
}

unique_ptr<std::map<int, IBestiole *>> Milieu::getVoisins(int idBestiole) {
    auto voisins = make_unique<std::map<int, IBestiole *>>();
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
        if (!(idBestiole == it->first) && it->second->getDistance(idBestiole) < DIST_MAX_VOISINS)
            (*voisins)[it->first] = it->second;
    return voisins;
}

IBestiole *Milieu::getBestiole(int idBestiole) {
    return listeBestioles[idBestiole];
}

void Milieu::addBestiole() {
    IBestiole *bestiole = bestioleFactory->naissance();
    listeBestioles[bestiole->getId()] = bestiole;
}

std::vector<int> Milieu::getVaMourir() {
    std::vector<int> vaMourir;
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        for (auto it2 = listeBestioles.begin(); it2 != listeBestioles.end(); ++it2) {
            if (it->first != it2->first && it->second->getDistance(it2->first) < DIST_COLLISION && it->second->collision()) {
                vaMourir.push_back(it->first);
                break;
            }
        }
    }
    return vaMourir;
}
