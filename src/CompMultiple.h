#ifndef _COMPMULTIPLE_H
#define _COMPMULTIPLE_H

#include "IComportement.h"
#include <memory>

#include "CompGregaire.h"
#include "CompKamikaze.h"
#include "CompPeureuse.h"
#include "CompPrevoyante.h"

/**
 * Multiple :
 * 
 * une bestiole dite à personnalités multiples adopte successivement d’autres comportements 
 * choisis aléatoirement au cours du temps. Néanmoins, elle reste une bestiole à personnalités multiples
 */

class ComportementMultiple : public IComportement {
    // Protection du constructeur car Singleton
protected: 
    ComportementMultiple() {}

    static std::shared_ptr<ComportementMultiple> instance;
    string description = "Multiple"; 

    std::vector<std::shared_ptr<IComportement>> tous_comportements;

    
public:
    ~ComportementMultiple() {}
    // empecher la copie et l'affectation

    ComportementMultiple(ComportementMultiple &) = delete;
    void operator=(const ComportementMultiple &) = delete;

    static std::shared_ptr<IComportement> getInstance();

    tuple<double, double> getDeplacement(int idBestiole, Milieu *monMilieu) override;
    std::string getDescription() const override;
};

#endif