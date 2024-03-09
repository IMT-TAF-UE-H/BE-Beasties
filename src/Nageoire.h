#ifndef _NAGEOIRE_H_
#define _NAGEOIRE_H_

#include "Decorateur.h"

using namespace std;

/**
 * Un accessoire des bestioles.
 * Augmente la vitesse effective de la bestiole qui a une telle décoration.
 */
class Nageoire : public Decorateur {
private:
    /**
     * Augmentation de vitesse.
     * 1 < nu < NU_MAX
     */
    double nu;
    static const double NU_MAX;

public:
    Nageoire(shared_ptr<IBestiole> b);
    virtual bool updatePos() override;
};

#endif