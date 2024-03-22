#include "BestioleFactory.h"
#include "Carapace.h"
#include "Nageoire.h"
#include "Oreilles.h"
#include "Bestiole.h"

BestioleFactory::BestioleFactory(Milieu *m, double p_kamikaze, double p_peureuse, double p_gregaire, double p_prevoyante) {
    if (p_kamikaze + p_peureuse + p_gregaire + p_prevoyante > 1) {
        throw std::invalid_argument("La somme des probabilités doit être inférieure à 1");
    }
    repartition[0] = p_kamikaze;
    repartition[1] = p_peureuse;
    repartition[2] = p_gregaire;
    repartition[3] = p_prevoyante;
    repartition[4] = 1 - (p_kamikaze + p_peureuse + p_gregaire + p_prevoyante);

    milieu = m;
}

BestioleFactory::~BestioleFactory() {
    //dtor
}

IBestiole* BestioleFactory::naissance() {
    // Tirage aléatoire d'un type de bestiole suivant la répartition
    double r = (double)rand() / (double)RAND_MAX;
    int type = 0;
    while (r > repartition[type]) {
        r -= repartition[type];
        type++;
    }
    return naissance(type);
}

IBestiole* BestioleFactory::naissance(int type) {
    IBestiole *b = new Bestiole(milieu, type);
    // Ajout de décorateurs à la bestiole de façon aléatoire
    if (true) {
        b = new Carapace(b);
    }
    if (true) {
        b = new Nageoire(b);
    }
    if (true) {
        b = new Oreilles(b);
    }
    return b;
}