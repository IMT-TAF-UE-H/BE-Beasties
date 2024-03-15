#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include "Decorateur.h"

using namespace std;

/**
 * Un accessoire des bestioles.
 * Diminue la vitesse effective de la bestiole.
 * Augmente la probabilité qu'elle survive à une collision.
 */
class Carapace : public Decorateur {
private:
    /**
     * Résistance.
     * 1 < omega < OMEGA_MAX
     */
    double omega;
    /**
     * Réduction de vitesse.
     * 1 < eta < ETA_MAX
    */
    double eta;
    static double OMEGA_MAX;
    static double ETA_MAX;

public:
    Carapace(shared_ptr<IBestiole> b);
    Carapace(Carapace &c);
    ~Carapace();
    static void setLimites(double _OMEGA_MAX,
                           double _ETA_MAX);
    virtual shared_ptr<IBestiole> clone() override;
    virtual bool updatePos() override;
    virtual bool collision(shared_ptr<IBestiole> b) override;
};

#endif