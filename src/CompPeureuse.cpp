#include "CompPeureuse.h"
#include "Milieu.h"
#include <vector>

std::shared_ptr<ComportementPeureuse> ComportementPeureuse::instance = nullptr;

std::shared_ptr<IComportement> ComportementPeureuse::getInstance() {
    if (instance == nullptr) {
        shared_ptr<ComportementPeureuse> newShared(new ComportementPeureuse());
        instance = std::move(newShared);
    }
    return instance;
}

tuple<double, double> ComportementPeureuse::getDeplacement(int idBestiole, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    IBestiole* b = monMilieu->getBestiole(idBestiole);

    // Calcul de la direction moyenne des voisins

    bool voisinDetecte = false;
    auto voisins = monMilieu->getVoisins(idBestiole);

    double direction = 0;
    int count = 0;
    double vitesse = 0;

    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (b->detecter(it->first) && (it->second)->detectable()) {
            voisinDetecte = true;
            direction += it->second->getDirection();
            count++;
            break;
        }
    }
    // Lorsqu'il y a trop de voisins, la bestiole fuit
    if (count > MAX_COUNT) {
        direction /= count;
        cout << "Peureuse fuit" << endl;
        // direction opposée
        direction += M_PI;
        b->setDirection(direction);
        // doublement de la vitesse
        vitesse = 2 * b->getVitesse();
    } else {
        direction = b->getDirection();
        vitesse = b->getVitesse();
    }

    deltaX = cos(direction) * vitesse;
    deltaY = -sin(direction) * vitesse;



    return make_tuple(deltaX, deltaY);

}