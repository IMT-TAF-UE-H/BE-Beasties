#include "CompPrevoyante.h"
#include "Milieu.h"
#include <vector>

std::shared_ptr<ComportementPrevoyante> ComportementPrevoyante::instance = nullptr;

std::shared_ptr<IComportement> ComportementPrevoyante::getInstance() {
    if (instance == nullptr) {
        shared_ptr<ComportementPrevoyante> newShared(new ComportementPrevoyante());
        instance = std::move(newShared);
    }
    return instance;
}

tuple<double, double> ComportementPrevoyante::getDeplacement(int idBestiole, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    IBestiole* b = monMilieu->getBestiole(idBestiole);

    // Estimation des trajectoires des bestioles voisines

    auto voisins = monMilieu->getVoisins(idBestiole);

    double direction = 0;
    int count = 0;

    double posX;
    double posY;

    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (b->detecter(it->second)) {
            direction += it->second->getDirection();
            
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