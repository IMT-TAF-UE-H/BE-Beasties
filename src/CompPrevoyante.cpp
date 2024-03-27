#include "CompPrevoyante.h"
#include "Milieu.h"
#include <vector>

std::shared_ptr<ComportementPrevoyante> ComportementPrevoyante::instance = nullptr;

/**
 * @brief Construction de l'objet Comportement Prevoyante (Singleton)
 * 
 * @return std::shared_ptr<IComportement> 
 */
std::shared_ptr<IComportement> ComportementPrevoyante::getInstance() {
    if (instance == nullptr) {
        shared_ptr<ComportementPrevoyante> newShared(new ComportementPrevoyante());
        instance = std::move(newShared);
    }
    return instance;
}

/**
 * @brief Calcul du déplacement de la bestiole selon le comportement prevoyante
 * 
 * Dans le cas où la bestiole ne détecte pas de voisins, elle se déplace dans la direction actuelle.
 * 
 * @param idBestiole 
 * @param monMilieu 
 * @return tuple<double, double> 
 */
tuple<double, double> ComportementPrevoyante::getDeplacement(int idBestiole, Milieu *monMilieu) {
    double deltaX = 0;
    double deltaY = 0;

    auto b = monMilieu->getBestiole(idBestiole);

    // Estimation de la nouvelle position des voisins

    bool voisinDetecte = false;
    auto voisins = monMilieu->getVoisins(idBestiole);

    vector<double> directions;
    double posX_voisin, posY_voisin, direction_voisin, vitesse_voisin;

    double posX = b->getX();
    double posY = b->getY();

    for (auto it = voisins->begin(); it != voisins->end(); ++it) {
        int idVoisin = it->first;
        auto voisin = it->second;
        if (b->detecter(idVoisin)) {
            voisinDetecte = true;
            posX_voisin = voisin->getX();
            posY_voisin = voisin->getY();
            direction_voisin = voisin->getDirection();
            vitesse_voisin = voisin->getVitesse();
            posX_voisin += cos(direction_voisin) * vitesse_voisin;
            posY_voisin -= sin(direction_voisin) * vitesse_voisin;

            // Calcul de la direction du voisin (vers sa position estimée)

            double dir = atan2(posY_voisin - posY, posX_voisin - posX);
            if (dir < 0) {
                dir += 2 * M_PI;
            }
            directions.push_back(dir);

        }
    }

    // Trier les directions
    vector<double> intervalles;
    double direction;
    double interval;
    double maxInterval = 0;
    int indexMaxInterval = 0;



    if (voisinDetecte) {
        sort(directions.begin(), directions.end());
        
        // Générer les intervalles
        
        for (int i = 0; i < (int)directions.size() - 1; i++) {
            interval = directions[i + 1] - directions[i];
            if (interval < 0) {
                interval += 2 * M_PI;
            }
            intervalles.push_back(interval);
        }

        interval = directions[0] - directions[directions.size() - 1] + 2 * M_PI;
        intervalles.push_back(interval);

        // Aller dans la direction qui correspond au centre de l'intervalle le plus grand

        for (int i = 0; i < (int)intervalles.size(); i++) {
            if (intervalles[i] > maxInterval) {
                maxInterval = intervalles[i];
                indexMaxInterval = i;
            }
        }

        direction = directions[indexMaxInterval] + intervalles[indexMaxInterval] / 2;

    }
    else {
        direction = b->getDirection();
    }

    deltaX = cos(direction) * b->getVitesse();
    deltaY = -sin(direction) * b->getVitesse();

    b->setDirection(direction);

    return make_tuple(deltaX, deltaY);

}

std::string ComportementPrevoyante::getDescription() const {
    return description;
}