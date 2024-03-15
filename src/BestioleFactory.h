#ifndef BESTIOLEFACTORY_H
#define BESTIOLEFACTORY_H

#include "IBestiole.h"

class BestioleFactory {
public:
    // Constructeur par défaut
    BestioleFactory();

    // Méthode pour créer une bestiole
    // Remplacez "Bestiole" par le nom de votre classe de bestiole
    IBestiole* naissanceSpontanee();
    IBestiole* naissanceForcee();
    std::vector<IBestiole*> peupler();

    

    // Autres méthodes de la factory...

private:
    // Attributs de la factory...

};

#endif // BESTIOLEFACTORY_H