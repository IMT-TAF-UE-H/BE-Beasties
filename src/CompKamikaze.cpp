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

tuple<double, double> ComportementKamikaze::getDeplacement(IBestiole *b, Milieu &monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    // trouve le voisin le plus proche et se dirige vers lui

    double distanceMin = 1000000;

    for (auto it = monMilieu.getVoisins(b).begin(); it != monMilieu.getVoisins(b).end(); ++it) {
        if (!(b->getId() == (*it)->getId()) && b->detecter(*it) && (*it)->detectable()) {
            double distance = b->getDistance(b);
            if (distance < distanceMin) {
                distanceMin = distance;
                deltaX = (*it)->getX() - b->getX();
                deltaY = (*it)->getY() - b->getY();
            }
        }
    }
    /*
    double dx = cos(direction) * vitesse;
     double dy = -sin(direction) * vitesse;
    */

    return make_tuple(deltaX, deltaY);
}
