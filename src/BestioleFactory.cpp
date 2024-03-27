#include "BestioleFactory.h"
#include "Carapace.h"
#include "Nageoire.h"
#include "Oreilles.h"
#include "Yeux.h"
#include "Camouflage.h"
#include "Bestiole.h"
#include "GlobalConfig.h"

double BestioleFactory::repartition[5];
double BestioleFactory::p_carapace;
double BestioleFactory::p_nageoire;
double BestioleFactory::p_oreilles;
double BestioleFactory::p_yeux;
double BestioleFactory::p_camouflage;
int BestioleFactory::maxParDecorateur;

/**
 * @brief Constructeur de la classe BestioleFactory
 * 
 * Les probabilités de répartition des types de bestioles sont passées en paramètre.
 * La probabilité de la dernière classe (Multiple) est calculée automatiquement.
 * 
 */
BestioleFactory::BestioleFactory(Milieu *m) { 
    milieu = m;
}

/**
 * @brief Destructeur de la classe BestioleFactory
 * 
 */
BestioleFactory::~BestioleFactory() {
    //dtor
}

/**
 * @brief Définit les probabilités de répartition des types de bestioles
 * 
 * @param _p_kamikaze 
 * @param _p_peureuse 
 * @param _p_gregaire 
 * @param _p_prevoyante 
 */

void BestioleFactory::setLimites(double _p_kamikaze, double _p_peureuse, double _p_gregaire, double _p_prevoyante, double _p_carapace, double _p_nageoire, double _p_oreilles, double _p_yeux, double _p_camouflage, int _maxParDecorateur) {
    repartition[0] = _p_kamikaze;
    repartition[1] = _p_peureuse;
    repartition[2] = _p_gregaire;
    repartition[3] = _p_prevoyante;
    repartition[4] = 1 - _p_kamikaze - _p_peureuse - _p_gregaire - _p_prevoyante;
    p_carapace = _p_carapace;
    p_nageoire = _p_nageoire;
    p_oreilles = _p_oreilles;
    p_yeux = _p_yeux;
    p_camouflage = _p_camouflage;
    maxParDecorateur = _maxParDecorateur;
}

/**
 * @brief Crée une nouvelle bestiole
 * 
 * La méthode tire aléatoirement un type de bestiole suivant la répartition des probabilités.
 * 
 * @return std::shared_ptr<IBestiole> 
 */
std::shared_ptr<IBestiole> BestioleFactory::naissance() {
    // Tirage aléatoire d'un type de bestiole suivant la répartition
    double r = (double)rand() / (double)RAND_MAX;
    int type = 0;
    while (r > repartition[type]) {
        r -= repartition[type];
        type++;
    }
    return naissance(type);
}

/**
 * @brief Crée une nouvelle bestiole
 * 
 * La méthode crée une bestiole du type passé en paramètre.
 * 
 * @param type 
 * @return std::shared_ptr<IBestiole> 
 */
std::shared_ptr<IBestiole> BestioleFactory::naissance(int type) {
    std::shared_ptr<IBestiole> b = make_shared<Bestiole>(milieu, type);
    // Ajout de décorateurs à la bestiole de façon aléatoire

    int nb = 0;
    while (rand() / (double)RAND_MAX < p_carapace && nb++ < maxParDecorateur) {
        b = make_shared<Carapace>(b);
    }
    nb = 0;
    while (rand() / (double)RAND_MAX < p_nageoire && nb++ < maxParDecorateur) {
        b = make_shared<Nageoire>(b);
    }
    nb = 0;
    while (rand() / (double)RAND_MAX < p_oreilles && nb++ < maxParDecorateur) {
        b = make_shared<Oreilles>(b);
    }
    nb = 0;
    while (rand() / (double)RAND_MAX < p_yeux && nb++ < maxParDecorateur) {
        b = make_shared<Yeux>(b);
    }
    nb = 0;
    while (rand() / (double)RAND_MAX < p_camouflage && nb++ < maxParDecorateur) {
        b = make_shared<Camouflage>(b);
    }

    return b;
}