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

tuple<double, double> ComportementGregaire::getDeplacement(int idBestiole, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    IBestiole* b = monMilieu->getBestiole(idBestiole);

    // Calcul de la direction moyenne des voisins

    bool voisinDetecte = false;
    auto voisins = monMilieu->getVoisins(idBestiole);

    double direction = 0;
    int count = 0;

    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (b->detecter(it->first) && (it->second)->detectable()) {
            voisinDetecte = true;
            direction += it->second->getDirection();
            count++;
            break;
        }
    }

    if (voisinDetecte) {
        direction /= count;
        b->setDirection(direction);
    } else {
        direction = b->getDirection();
    }

    double vitesse = b->getVitesse();
    deltaX = cos(direction) * vitesse;
    deltaY = -sin(direction) * vitesse;



    return make_tuple(deltaX, deltaY);
}
