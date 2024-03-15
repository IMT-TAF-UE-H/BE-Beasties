#ifndef _I_BESTIOLE_H_
#define _I_BESTIOLE_H_

#include <memory>

using namespace std;

/**
 * Interface qui peut représenter une bestiole avec ou sans accessoires et capteurs.
 */
class IBestiole {
public:
    /**
     * Renvoie un clone de la bestiole, avec les mêmes caractéristiques, décorateurs et comportement.
     */
    virtual shared_ptr<IBestiole> clone() = 0;
    /**
     * Calcule la nouvelle position, et la modifie en place.
     * Renvoie l'état de décès de la bestiole (true=mort).
     */
    virtual void updatePos() = 0;
    /**
     * Détermine si la bestiole peut être détectée à cette itération.
     */
    virtual bool detectable() = 0;
    /**
     * Détermine si une autre bestiole voisine peut être détectée.
     */
    virtual bool detecter(shared_ptr<IBestiole> b) = 0;
    /**
     * Détermine si une collision avec une autre bestiole voisine est mortelle.
     */
    virtual bool collision(shared_ptr<IBestiole> b) = 0;
    virtual void draw(UImg &support) = 0;
    virtual double getVitesse() = 0;
    virtual void setVitesse(double vitesse) = 0;
    virtual double getResistance() = 0;
    virtual void setResistance(double omega) = 0;
    virtual double getDiscretion() = 0;
    virtual void setDiscretion(double psi) = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double getDistance(shared_ptr<IBestiole> b) const = 0;
    virtual double getDirection() const = 0;
    virtual double getDirectionTo(shared_ptr<IBestiole> b) const = 0;
    virtual int getId() const = 0;
};

#endif