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
    IBestiole* bestiole;

public:
    virtual ~Decorateur() {
        delete bestiole;
    };
    virtual IBestiole* clone() override = 0;
    virtual void updatePos() override {
        bestiole->updatePos();
    }
    virtual bool detectable() override {
        return bestiole->detectable();
    }
    virtual bool detecter(int idBestiole) override {
        return bestiole->detecter(idBestiole);
    }
    virtual bool collision(int idBestiole) override {
        return bestiole->collision(idBestiole);
    }
    virtual void draw(UImg &support) override {
        bestiole->draw(support);
    }
    virtual double getVitesse() override {
        return bestiole->getVitesse();
    }
    virtual void setVitesse(double vitesse) override {
        bestiole->setVitesse(vitesse);
    }
    virtual double getResistance() override {
        return bestiole->getResistance();
    }
    virtual void setResistance(double resistance) override {
        bestiole->setResistance(resistance);
    }
    virtual double getDiscretion() override {
        return bestiole->getDiscretion();
    }
    virtual void setDiscretion(double discretion) override {
        bestiole->setDiscretion(discretion);
    }
    virtual double getX() const override {
        return bestiole->getX();
    }
    virtual double getY() const override {
        return bestiole->getY();
    }
    virtual double getDistance(int idBestiole) const override {
        return bestiole->getDistance(idBestiole);
    }
    virtual double getDirection() const override {
        return bestiole->getDirection();
    }
    virtual void setDirection(double direction) override {
        return bestiole->setDirection(direction);
    }
    virtual double getDirectionTo(int idBestiole) const override {
        return bestiole->getDirectionTo(idBestiole);
    }
    virtual int getId() const override {
        return bestiole->getId();
    }
};

#endif