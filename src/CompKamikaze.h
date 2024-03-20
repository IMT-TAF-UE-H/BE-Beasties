#include "IComportement.h"
#include <memory>

/**
 * Kamikaze : 
 * 
 * Une bestiole dite kamikaze est attirée par la bestiole la plus proche.
 * Elle tente de l’attaquer en cherchant à provoquer une collision.
 * 
 * Si aucune bestiole n’est détectée, elle se déplace dans sa direction courante, avec la vitesse courante.
 */

class ComportementKamikaze : public IComportement {
    // Protection du constructeur car Singleton
protected:
    ComportementKamikaze() {}

    static std::shared_ptr<ComportementKamikaze> instance;

public:
    ~ComportementKamikaze() {}
    // empecher la copie et l'affectation

    ComportementKamikaze(ComportementKamikaze &) = delete;
    void operator=(const ComportementKamikaze &) = delete;

    static std::shared_ptr<IComportement> getInstance();

    tuple<double, double> getDeplacement(int idBestiole, Milieu *monMilieu) override;
};