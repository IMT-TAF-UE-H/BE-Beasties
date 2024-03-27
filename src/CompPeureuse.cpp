#include "CompPeureuse.h"
#include "Milieu.h"
#include <vector>

int MAX_COUNT = 1;

std::shared_ptr<ComportementPeureuse> ComportementPeureuse::instance = nullptr;

/**
 * @brief Construction de l'objet Comportement Peureuse (Singleton)
 * 
 * @return std::shared_ptr<IComportement> 
 */
std::shared_ptr<IComportement> ComportementPeureuse::getInstance() {
    if (instance == nullptr) {
        shared_ptr<ComportementPeureuse> newShared(new ComportementPeureuse());
        instance = std::move(newShared);
    }
    return instance;
}

/**
 * @brief Calcul du déplacement de la bestiole selon le comportement peureuse
 * 
 * Dans le cas où la bestiole ne détecte pas de voisins, elle se déplace dans la direction actuelle.
 * 
 * @param idBestiole 
 * @param monMilieu 
 * @return tuple<double, double> 
 */
tuple<double, double> ComportementPeureuse::getDeplacement(int idBestiole, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    auto b = monMilieu->getBestiole(idBestiole);

    // Calcul de la direction moyenne des voisins

    auto voisins = monMilieu->getVoisins(idBestiole);

    double direction = 0;
    int count = 0;
    double vitesse = 0;

    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        if (b->detecter(it->first)) {
            double dir = b->getDirectionTo(it->second->getId());
            if (dir < 0) {
                dir += 2 * M_PI;
            }
            direction += dir;
            count++;
        }
    }
    // Lorsqu'il y a trop de voisins, la bestiole fuit
    if (count > MAX_COUNT) {
        direction /= count;
        // direction opposée
        direction += M_PI;
        b->setDirection(direction);
        // doublement de la vitesse
        vitesse = 2 * b->getVitesse();
        cout << "(" << idBestiole << "): je fuis" << endl;
    } else {
        direction = b->getDirection();
        vitesse = b->getVitesse();
    }

    deltaX = cos(direction) * vitesse;
    deltaY = -sin(direction) * vitesse;



    return make_tuple(deltaX, deltaY);

}

std::string ComportementPeureuse::getDescription() const {
    return description;
}