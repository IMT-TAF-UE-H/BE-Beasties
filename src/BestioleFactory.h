#ifndef BESTIOLEFACTORY_H
#define BESTIOLEFACTORY_H

#include "IBestiole.h"
#include "Milieu.h"


class Milieu;
class IBestiole;

class BestioleFactory {
public:
    // Constructeur 
    BestioleFactory(Milieu *m,);

    // Destructeur
    ~BestioleFactory(); 

    static void setLimites(double _p_kamikaze, double _p_peureuse, double _p_gregaire, double _p_prevoyante);

    // Méthode pour créer une bestiole
    // Remplacez "Bestiole" par le nom de votre classe de bestiole
    std::shared_ptr<IBestiole> naissance();
    std::shared_ptr<IBestiole> naissance(int type);

private:
    // Configuration de la factory
    static double repartition[5]; // Proportion de bestioles de chaque type
    Milieu *milieu; // Milieu dans lequel les bestioles évoluent

    static double p_carapace;
    static double p_nageoire;
    static double p_oreilles;
    static double p_yeux;
    static double p_camouflage;
    static int maxParDecorateur;


};

#endif // BESTIOLEFACTORY_H