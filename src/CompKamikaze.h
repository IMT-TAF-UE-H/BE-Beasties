#include "IComportement.h"
#include <memory>


class ComportementKamikaze : public IComportement {
// Protection du constructeur car Singleton
protected:
    ComportementKamikaze() {}
    ~ComportementKamikaze() {}

    static std::shared_ptr<ComportementKamikaze> instance;
public:
    // empecher la copie et l'affectation

    ComportementKamikaze(ComportementKamikaze const&) = delete;
    void operator=(ComportementKamikaze const&) = delete;

    static std::shared_ptr<ComportementKamikaze> getInstance() {};

    tuple<double, double> getDeplacement(IBestiole & b, Milieu * monMilieu) {}
};