#include "IComportement.h"
#include <memory>

/**
 * Gregaire : 
 * 
 * Une bestiole dite gr ́egaire ajuste sa direction sur la direction moyenne des bestioles environnantes.
 * 
 * Si aucune bestiole n’est détectée, elle se déplace dans sa direction courante, avec la vitesse courante.
 */

class ComportementGregaire : public IComportement {
    // Protection du constructeur car Singleton
protected:
    ComportementGregaire() {}

    static std::shared_ptr<ComportementGregaire> instance;

public:
    ~ComportementGregaire() {}
    // empecher la copie et l'affectation

    ComportementGregaire(ComportementGregaire &) = delete;
    void operator=(const ComportementGregaire &) = delete;

    static std::shared_ptr<IComportement> getInstance();

    tuple<double, double> getDeplacement(IBestiole *b, Milieu *monMilieu) override;
};