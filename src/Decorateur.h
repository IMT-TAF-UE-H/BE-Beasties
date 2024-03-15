#ifndef _DECORATEUR_H_
#define _DECORATEUR_H_

#include <iostream>

#include "IBestiole.h"
#include "Milieu.h"

using namespace std;

/**
 * Classe abstraite regroupant les accessoires et les capteurs.
 */
class Decorateur : public IBestiole {
protected:
    std::shared_ptr<IBestiole> bestiole;

public:
    virtual shared_ptr<IBestiole> clone() override = 0;
    virtual void updatePos() override {
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
    virtual void draw(UImg &support) override {
        return bestiole->draw(support);
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
    virtual double getX() const override {
        return bestiole->getX();
    }
    virtual double getY() const override {
        return bestiole->getY();
    }
    virtual double getDistance(shared_ptr<IBestiole> b) const override {
        return bestiole->getDistance(b);
    }
    virtual double getDirection() const override {
        return bestiole->getDirection();
    }
    virtual double getDirectionTo(shared_ptr<IBestiole> b) const override {
        return bestiole->getDirectionTo(b);
    }
    virtual int getId() const override {
        return bestiole->getId();
    }
    inline friend ostream& operator<<(ostream& os, const Decorateur& dt);
};

inline ostream& operator<<(ostream& os, const Decorateur& dt)
{
    // os << dt.bestiole;
    os << "[TODO : operator<< de la bestiole]";
    return os;
}

#endif