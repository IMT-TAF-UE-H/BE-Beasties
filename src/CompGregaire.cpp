#include "CompGregaire.h"
#include "Milieu.h"
#include <vector>

std::shared_ptr<ComportementGregaire> ComportementGregaire::instance = nullptr;

/**
 * @brief Construction de l'objet Comportement Gregaire (Singleton)
 * 
 * @return std::shared_ptr<IComportement> 
 */
std::shared_ptr<IComportement> ComportementGregaire::getInstance() {
    if (instance == nullptr) {
        shared_ptr<ComportementGregaire> newShared(new ComportementGregaire());
        instance = std::move(newShared);
    }
    return instance;
}

/**
 * @brief Calcul du déplacement de la bestiole selon le comportement grégaire
 * 
 * Dans le cas où la bestiole ne détecte pas de voisins, elle se déplace dans la direction actuelle.
 * 
 * @param idBestiole 
 * @param monMilieu 
 * @return tuple<double, double> 
 */
tuple<double, double> ComportementGregaire::getDeplacement(int idBestiole, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    auto b = monMilieu->getBestiole(idBestiole);

    // Calcul de la direction moyenne des voisins

    bool voisinDetecte = false;
    auto voisins = monMilieu->getVoisins(idBestiole);

    double direction = 0;
    int count = 0;

    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (b->detecter(it->first)) {
            voisinDetecte = true;
            direction += it->second->getDirection();
            count++;
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

std::string ComportementGregaire::getDescription() const {
    return description;
}
