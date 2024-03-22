#ifndef BESTIOLEFACTORY_H
#define BESTIOLEFACTORY_H

#include "IBestiole.h"
#include "Milieu.h"


class Milieu;

class BestioleFactory {
public:
    // Constructeur 
    BestioleFactory(Milieu *m, double p_kamikaze, double p_peureuse, double p_gregaire, double p_prevoyante); 

    // Destructeur
    ~BestioleFactory(); 

    // Méthode pour créer une bestiole
    // Remplacez "Bestiole" par le nom de votre classe de bestiole
    IBestiole* naissance();
    IBestiole* naissance(int type);

private:
    // Configuration de la factory
    double repartition[5]; // Proportion de bestioles de chaque type
    Milieu *milieu; // Milieu dans lequel les bestioles évoluent


};

#endif // BESTIOLEFACTORY_H