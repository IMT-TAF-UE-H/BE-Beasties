#include "CompGregaire.h"
#include "Milieu.h"
#include <vector>

std::shared_ptr<ComportementGregaire> ComportementGregaire::instance = nullptr;

std::shared_ptr<IComportement> ComportementGregaire::getInstance() {
    if (instance == nullptr) {
        shared_ptr<ComportementGregaire> newShared(new ComportementGregaire());
        instance = std::move(newShared);
    }
    return instance;
}

tuple<double, double> ComportementGregaire::getDeplacement(IBestiole *b, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    // Calcul de la direction moyenne des voisins

    bool voisinDetecte = false;
    auto voisins = monMilieu->getVoisins(b);

    double direction = 0;
    int count = 0;

    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (!(b->getId() == it->first) && b->detecter(it->second) && (it->second)->detectable()) {
            voisinDetecte = true;
            direction += it->second->getDirection();
            count++;
            break;
        }
    }

    if (voisinDetecte) {
        direction /= count;
    } else {
        direction = b->getDirection();
    }

    double vitesse = b->getVitesse();
    deltaX = cos(direction) * vitesse;
    deltaY = -sin(direction) * vitesse;



    return make_tuple(deltaX, deltaY);
}
