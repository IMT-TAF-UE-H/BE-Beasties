#include "CompMultiple.h"


#include "Milieu.h"
#include <vector>

#include <random>


std::shared_ptr<ComportementMultiple> ComportementMultiple::instance = nullptr;

std::shared_ptr<IComportement> ComportementMultiple::getInstance() {
    cout << "ComportementMultiple::getInstance()" << endl;
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
    cout << "ComportementMultiple::getInstance() - end" << endl;
    return instance;
}


tuple<double, double> ComportementMultiple::getDeplacement(int idBestiole, Milieu *monMilieu) {

    
    // Choisir un comportement aléatoire (possible de logger le comportement choisi)
    int comportement = rand() % tous_comportements.size();


    IBestiole* b = monMilieu->getBestiole(idBestiole);
    return tous_comportements[comportement]->getDeplacement(idBestiole, monMilieu);

}

std::string ComportementMultiple::getDescription() const {
    return description;
}