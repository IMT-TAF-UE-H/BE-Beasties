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
    static double NU_MAX;

public:
    Nageoire(shared_ptr<IBestiole> b);
    Nageoire(Nageoire &n);
    ~Nageoire();
    static void setLimites(double _NU_MAX);
    virtual shared_ptr<IBestiole> clone() override;
    virtual bool updatePos() override;
};

#endif