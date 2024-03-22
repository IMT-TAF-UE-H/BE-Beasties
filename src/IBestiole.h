#ifndef _I_BESTIOLE_H_
#define _I_BESTIOLE_H_

#include <memory>
#include "UImg.h"
#include "Milieu.h"

using namespace std;

class Milieu;

/**
 * Interface qui peut représenter une bestiole avec ou sans accessoires et capteurs.
 */
class IBestiole {
public:
    virtual ~IBestiole() = default;
    /**
     * Renvoie un clone de la bestiole, avec les mêmes caractéristiques, décorateurs et comportement.
     */
    virtual IBestiole* clone() = 0;
    /**
     * Calcule la nouvelle position, et la modifie en place.
     * Renvoie l'état de décès de la bestiole (true=mort).
     */
    virtual void updatePos() = 0;
    
    /**
     * Détermine si une autre bestiole voisine peut être détectée.
     */
    virtual bool detecter(int idBestiole) = 0;
    /**
     * Détermine si une collision avec une autre bestiole voisine est mortelle.
     */
    virtual bool collision() = 0;
    virtual void draw(UImg &support) = 0;

    // Getters et setters
    virtual double getVitesse() = 0;
    virtual void setVitesse(double vitesse) = 0;
    virtual double getResistance() = 0;
    virtual void setResistance(double resistance) = 0;
    virtual double getDiscretion() const = 0;
    virtual void setDiscretion(double discretion) = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getDistance(int idBestiole) const = 0;
    virtual double getDirection() const = 0;
    virtual void setDirection(double direction) = 0;
    virtual double getDirectionTo(int idBestiole) const = 0;
    virtual int getId() const = 0;
    virtual Milieu* getMilieu() = 0;
};

#endif