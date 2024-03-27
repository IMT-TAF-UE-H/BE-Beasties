#ifndef _I_COMPORTMENT_H_
#define _I_COMPORTMENT_H_

using namespace std;
#include <tuple>
#include "Milieu.h"
#include <string>   

class Milieu;

/*
* Interface qui peut représenter un comportement de bestiole.
*
* On a 4 comportements possibles : Gregaire, Peureuse, Kamikaze, Prevoyante 
* Il y a également un comportement random qui peut prendre n'importe quel comportement 
*/

class IComportement {


public:
// sortie : DeltaX, DeltaY
virtual tuple<double, double> getDeplacement(int idBestiole, Milieu * monMilieu) = 0;
virtual std::string getDescription() const = 0;
};

# endif