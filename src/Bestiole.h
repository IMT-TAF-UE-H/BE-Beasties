#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"

#include <IBestiole.h>
#include <iostream>
#include "IComportement.h"

using namespace std;

class Milieu;

class Bestiole : public IBestiole {

private:
    static int next;
    int identite;

    Milieu *milieu;
    IComportement *comportement;

    int vieRestante;

    double x, y;
    double direction;
    /**
     * doit être inférieure à la longueur et à la largeur du milieu
     */
    double vitesse;
    /**
     * Détermine la probabilité pour la bestiole de passer inaperçue
     * lorsque elle est dans le champ de vision d'une autre bestiole.
     * 0 < discretion < 1
     */
    double discretion;
    /**
     * Capacité de la bestiole à survivre à une collision.
     * 1 < resistance
    */
    double resistance;

    double taille;
    T *couleur;

    static const double MAX_VITESSE;

private:
    void bouge(int xLim, int yLim);

public:
    Bestiole(Milieu *milieu);
    Bestiole(const Bestiole &b);
    ~Bestiole(void);
    shared_ptr<IBestiole> clone() override;
    void updatePos() override;
    bool detectable() override;
    bool detecter(shared_ptr<IBestiole> b) override;
    bool collision(shared_ptr<IBestiole> b) override;
    double getVitesse() override;
    void setVitesse(double vitesse) override;
    double getResistance() override;
    void setResistance(double omega) override;
    double getDiscretion() override;
    void setDiscretion(double psi) override;
    double getX() const override;
    double getY() const override;
    double getDistance(shared_ptr<IBestiole> b) const override;
    double getDirection() const override;
    double getDirectionTo(shared_ptr<IBestiole> b) const override;
    int getId() const override;

    void draw(UImg &support);

    friend bool operator==(const Bestiole &b1, const Bestiole &b2);
};

#endif
