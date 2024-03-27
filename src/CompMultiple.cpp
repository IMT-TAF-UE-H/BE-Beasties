#include "CompMultiple.h"


#include "Milieu.h"
#include <vector>

#include <random>


std::shared_ptr<ComportementMultiple> ComportementMultiple::instance = nullptr;

/**
 * @brief Construction de l'objet Comportement Multiple (Singleton)
 * @return std::shared_ptr<IComportement> 
 */
std::shared_ptr<IComportement> ComportementMultiple::getInstance() {
    if (instance == nullptr) {
        std::shared_ptr<ComportementMultiple> newShared(new ComportementMultiple());
        std::vector<std::shared_ptr<IComportement>> tous_comportements_ = {
            ComportementGregaire::getInstance(),
            ComportementKamikaze::getInstance(),
            ComportementPeureuse::getInstance(),
            ComportementPrevoyante::getInstance()
        };
        newShared->tous_comportements = tous_comportements_;
        newShared->description = "Multiple";
        instance = std::move(newShared);
    }
    return instance;
}

/**
 * @brief Calcul du déplacement de la bestiole selon le comportement multiple
 * 
 * Le comportement multiple choisit aléatoirement un comportement parmi les comportements disponibles.
 * Le déplacement de la bestiole est alors calculé selon le comportement choisi.
 * Chaque appel à cette méthode peut donc donner un déplacement différent.
 * 
 * @param idBestiole 
 * @param monMilieu 
 * @return tuple<double, double> 
 */
tuple<double, double> ComportementMultiple::getDeplacement(int idBestiole, Milieu *monMilieu) {

    
    // Choisir un comportement aléatoire (possible de logger le comportement choisi)
    int comportement = rand() % tous_comportements.size();

    return tous_comportements[comportement]->getDeplacement(idBestiole, monMilieu);

}

std::string ComportementMultiple::getDescription() const {
    return description;
}