#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_

#include "UImg.h"

#include <IBestiole.h>
#include <iostream>

#include "Milieu.h"
#include "IComportement.h"

using namespace std;

class IComportement;

/**
 * Classe Bestiole qui implémente l'interface IBestiole. 
 */

class Bestiole : public IBestiole {

private:
    static int next;
    int identite;

    Milieu *milieu;
    shared_ptr<IComportement> comportement;

    int vieRestante;

    double x, y; // position de la bestiole
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

public:
    Bestiole(Milieu *milieu, int type); // constructeur par défaut
    Bestiole(const Bestiole &b); // constructeur par copie
    ~Bestiole(void) override; // destructeur
    IBestiole* clone() override; // clone
    void updatePos() override; // mise à jour de la position
    bool detecter(int idBestiole) override;
    bool collision() override;
    double getVitesse() override;
    void setVitesse(double vitesse) override;
    double getResistance() override;
    void setResistance(double resistance) override;
    double getDiscretion() const override;
    void setDiscretion(double discretion) override;
    double getX() const override;
    double getY() const override;
    double getDistance(int idBestiole) const override;
    double getDirection() const override;
    void setDirection(double direction) override;
    double getDirectionTo(int idBestiole) const override;
    int getId() const override;
    Milieu *getMilieu() override;

    void draw(UImg &support);

    friend bool operator==(const Bestiole &b1, const Bestiole &b2);
};

#endif
