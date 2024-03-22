#include "IComportement.h"
#include <memory>

/**
<<<<<<< HEAD
 * Prévoyante : 
 * 
 * Une bestiole dite prévoyante estime les trajectoires des bestioles autour d'elle 
 * et ajuste sa trajectoire pour éviter les collisions.
=======
 * Prévoyante :
 * une bestiole dite prévoyante estime les trajectoires des bestioles autour d’elle 
 * et ajuste sa trajectoire pour éviter d’éventuelles collisions.
 * 
 * Pour cela, elle estime la nouvelle position de ses voisins.
 * Ensuite, la direction correspondant à la trajectoire de chaque voisin est calculée.
 * Les directions sont triées et les intervalles entre chaque direction sont calculés.
 * 
 * La bestiole prévoyante choisit alors la direction qui maximise l’intervalle entre les directions des voisins.
 * Elle se dirige donc vers le centre de l’intervalle le plus grand.
>>>>>>> v1
 */

class ComportementPrevoyante : public IComportement {
    // Protection du constructeur car Singleton
protected:
    ComportementPrevoyante() {}

    static std::shared_ptr<ComportementPrevoyante> instance;

public:
    ~ComportementPrevoyante() {}
    // empecher la copie et l'affectation

    ComportementPrevoyante(ComportementPrevoyante &) = delete;
    void operator=(const ComportementPrevoyante &) = delete;

    static std::shared_ptr<IComportement> getInstance();

    tuple<double, double> getDeplacement(int idBestiole, Milieu *monMilieu) override;
};