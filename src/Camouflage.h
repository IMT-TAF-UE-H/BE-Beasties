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
    static double PSI_MIN;
    static double PSI_MAX;

public:
    Camouflage(shared_ptr<IBestiole> b);
    Camouflage(Camouflage &c);
    ~Camouflage();
    static void setLimites(double _PSI_MIN, double _PSI_MAX);
    virtual shared_ptr<IBestiole> clone() override;
    virtual bool detectable() override;
};

#endif