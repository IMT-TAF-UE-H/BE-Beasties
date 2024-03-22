#include "IComportement.h"
#include <memory>

/**
 * Peureuse :
 *  lorsque le nombre de bestioles autour d’une bestiole dite peureuse devient trop important, celle-ci fuit `a vive allure dans la direction opposée avant de reprendre sa vitesse de croisière
 */

const int MAX_COUNT = 3;

class ComportementPeureuse : public IComportement {
    // Protection du constructeur car Singleton
protected:
    ComportementPeureuse() {}

    static std::shared_ptr<ComportementPeureuse> instance;

public:
    ~ComportementPeureuse() {}
    // empecher la copie et l'affectation

    ComportementPeureuse(ComportementPeureuse &) = delete;
    void operator=(const ComportementPeureuse &) = delete;

    static std::shared_ptr<IComportement> getInstance();

    tuple<double, double> getDeplacement(int idBestiole, Milieu *monMilieu) override;
};
