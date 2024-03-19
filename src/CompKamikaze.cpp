#include "CompKamikaze.h"
#include "Milieu.h"
#include <vector>

std::shared_ptr<ComportementKamikaze> ComportementKamikaze::instance = nullptr;

std::shared_ptr<IComportement> ComportementKamikaze::getInstance() {
    if (instance == nullptr) {
        shared_ptr<ComportementKamikaze> newShared(new ComportementKamikaze());
        instance = std::move(newShared);
    }
    return instance;
}

tuple<double, double> ComportementKamikaze::getDeplacement(IBestiole *b, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    // trouve le voisin le plus proche et se dirige vers lui

    double distanceMin = 1000000;

    auto voisins = monMilieu->getVoisins(b);
    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (!(b->getId() == it->first) && b->detecter(it->second) && (it->second)->detectable()) {
            double distance = b->getDistance(b);
            if (distance < distanceMin) {
                distanceMin = distance;
                deltaX = it->second->getX() - b->getX();
                deltaY = it->second->getY() - b->getY();
            }
        }
    }
    /*
    double dx = cos(direction) * vitesse;
     double dy = -sin(direction) * vitesse;
    */

    return make_tuple(deltaX, deltaY);
}
