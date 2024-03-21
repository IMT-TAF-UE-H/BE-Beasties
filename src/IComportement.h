#ifndef _I_COMPORTMENT_H_
#define _I_COMPORTMENT_H_

#include "Bestiole.h"
using namespace std;
#include <tuple>

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
};

# endif