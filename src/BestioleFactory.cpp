#include "BestioleFactory.h"

BestioleFactory::BestioleFactory() {
    //ctor
}

BestioleFactory::~BestioleFactory() {
    //dtor
}

Bestiole* BestioleFactory::naissanceSpontanee() {
    return new Bestiole();
}

Bestiole* BestioleFactory::naissanceForcee() {
    return new Bestiole();
}

std::vector<Bestiole*> BestioleFactory::peupler() {
    std::vector<Bestiole*> pop;
    for (int i = 0; i < 10; i++) {
        pop.push_back(naissanceSpontanee());
    }
    return pop;
}
```