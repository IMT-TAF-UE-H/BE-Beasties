#include "IComportement.h"
#include <memory>

/**
 * Prévoyante : 
 * 
 * Une bestiole dite prévoyante estime les trajectoires des bestioles autour d'elle 
 * et ajuste sa trajectoire pour éviter les collisions.
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