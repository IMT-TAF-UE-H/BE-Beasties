#ifndef _I_COMPORTMENT_H_
#define _I_COMPORTMENT_H_

#include "Bestiole.h"
using namespace std;
#include <tuple>

class IComportement {

public:
// sortie : DeltaX, DeltaY
virtual tuple<double, double> deplacement(IBestiole & b, const Milieu & monMilieu) = 0;
};

# endif