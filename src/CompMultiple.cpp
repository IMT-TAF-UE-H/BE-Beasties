#include "CompMultiple.h"


#include "Milieu.h"
#include <vector>

#include <random>



std::shared_ptr<IComportement> ComportementMultiple::getInstance() {
    static std::shared_ptr<IComportement> instance = std::make_shared<ComportementMultiple>();
    return instance;
}

tuple<double, double> ComportementMultiple::getDeplacement(int idBestiole, Milieu *monMilieu) {

    
    // Choisir un comportement aléatoire (possible de logger le comportement choisi)
    int comportement = rand() % tous_comportements.size();


    IBestiole* b = monMilieu->getBestiole(idBestiole);
    return tous_comportements[comportement]->getDeplacement(idBestiole, monMilieu);

}