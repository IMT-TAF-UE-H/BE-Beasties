#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include "Decorateur.h"

using namespace std;

/**
 * Un accessoire des bestioles.
 * Augmente la probabilité que la bestiole soit indétectable.
 */
class Camouflage : public Decorateur {
private:
    /**
     * Probabilité de discrétion.
     * 0 < PSI_MIN < psi < PSI_MAX < 1
     */
    double psi;
    static const double PSI_MIN;
    static const double PSI_MAX;

public:
    Camouflage(shared_ptr<IBestiole> b);
    virtual bool detectable() override;
};

#endif