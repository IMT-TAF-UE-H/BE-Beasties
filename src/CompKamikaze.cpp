#include "CompKamikaze.h"
#include "Milieu.h"
#include <vector>

std::shared_ptr<ComportementKamikaze> ComportementKamikaze::instance = nullptr;

/**
 * @brief Construction de l'objet Comportement Kamikaze (Singleton)
 * 
 * @return std::shared_ptr<IComportement> 
 */
std::shared_ptr<IComportement> ComportementKamikaze::getInstance() {
    if (instance == nullptr) {
        std::shared_ptr<ComportementKamikaze> newShared(new ComportementKamikaze());
        newShared->description = "Kamikaze";
        instance = std::move(newShared);
    }
    return instance;
}

/**
 * @brief Calcul du déplacement de la bestiole selon le comportement kamikaze
 * 
 * Dans le cas où la bestiole ne détecte pas de voisins, elle se déplace dans la direction actuelle.
 * 
 * @param idBestiole 
 * @param monMilieu 
 * @return tuple<double, double> 
 */
tuple<double, double> ComportementKamikaze::getDeplacement(int idBestiole, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    auto b = monMilieu->getBestiole(idBestiole);

    // trouve le voisin le plus proche et se dirige vers lui

    double distanceMin = 1000000;
    bool voisinDetecte = false;
    double dir = 0;

    auto voisins = monMilieu->getVoisins(idBestiole);
    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (b->detecter(it->first)) {
            double distance = it->second->getDistance(idBestiole);
            if (distance < distanceMin) {
                distanceMin = distance;
                voisinDetecte = true;
                dir = atan2(it->second->getY() - b->getY(), it->second->getX() - b->getX());
            }
        }
    }
    
    double vitesse = b->getVitesse();
    if (!voisinDetecte) {
        double direction = b->getDirection();
        deltaX = cos(direction) * vitesse;
        deltaY = -sin(direction) * vitesse;
    }
    else {
        cout << "(" << b->getId() << ") Kamikaze! " << endl;
        deltaX = cos(dir) * vitesse;
        deltaY = -sin(dir) * vitesse;
        b->setDirection(dir);
    }

    return make_tuple(deltaX, deltaY);
}

std::string ComportementKamikaze::getDescription() const {
    return description;
}
