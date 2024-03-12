#ifndef _DECORATEUR_H_
#define _DECORATEUR_H_

#include "IBestiole.h"

using namespace std;

/**
 * Classe abstraite regroupant les accessoires et les capteurs.
 */
class Decorateur : public IBestiole {
protected:
    std::shared_ptr<IBestiole> bestiole;

public:
    virtual shared_ptr<IBestiole> clone() override = 0;
    virtual bool updatePos() override {
        return bestiole->updatePos();
    }
    virtual bool detectable() override {
        return bestiole->detectable();
    }
    virtual bool detecter(shared_ptr<IBestiole> b) override {
        return bestiole->detecter(b);
    }
    virtual bool collision(shared_ptr<IBestiole> b) override {
        return bestiole->collision(b);
    }
    virtual double getVitesse() override {
        return bestiole->getVitesse();
    }
    virtual void setVitesse(double vitesse) override {
        return bestiole->setVitesse(vitesse);
    }
    virtual double getResistance() override {
        return bestiole->getResistance();
    }
    virtual void setResistance(double omega) override {
        return bestiole->setResistance(omega);
    }
    virtual double getDiscretion() override {
        return bestiole->getDiscretion();
    }
    virtual void setDiscretion(double psi) override {
        return bestiole->setDiscretion(psi);
    }
    inline friend ostream& operator<<(ostream& os, const Decorateur& dt);
};

inline ostream& operator<<(ostream& os, const Decorateur& dt)
{
    os << dt.bestiole;
    return os;
}

#endif