#include "IComportement.h"
#include <memory>

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

    tuple<double, double> getDeplacement(IBestiole *b, Milieu *monMilieu) override;
};