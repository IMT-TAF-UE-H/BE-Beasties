#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

const T Milieu::white[] = {(T)255, (T)255, (T)255};
double Milieu::width = 640.;
double Milieu::height = 480.;
double Milieu::DIST_MAX_VOISINS = height / 10.;

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          listeBestioles() {
    width = _width;
    height = _height;
    DIST_MAX_VOISINS = height / 10.;

    cout << "const Milieu" << endl;

    srand(time(NULL));
}

Milieu::~Milieu(void) {

    cout << "dest Milieu" << endl;
    for (auto it = listeBestioles.cbegin(); it != listeBestioles.cend();) {
        tuer((it++)->first);
    }
}

void Milieu::step(void) {

    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        (it->second)->updatePos();
    }
    auto vaMourir = getVaMourir();

    for (auto it = vaMourir.begin(); it != vaMourir.end();) {
        tuer((it++)->first);
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

/**
 * Temporaire dans l'attente de la factory
 * TODO à dégager
 */
void Milieu::addBestiole(IBestiole *bestiole) {
    // ERROR : gros problème ici depuis que j'ai ajouté la fonction setDirection
    // C'est pas forcément lié directement, mais là on tient qqch de sombre.
    // TODO fix avant de dégager cette fonction
    // cout << "print pour éviter un segfault" << endl;
    listeBestioles[bestiole->getId()] = bestiole;
}

std::map<int, IBestiole *> Milieu::getVaMourir() {
    std::map<int, IBestiole *> vaMourir;
    // TODO implem
    return vaMourir;
}
