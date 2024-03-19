#include "Aquarium.h"
#include "Bestiole.h"
#include "Milieu.h"

#include <iostream>

using namespace std;

int main() {

    Aquarium ecosysteme(640, 480, 30);
    Milieu* milieu = ecosysteme.getMilieu();

    for (int i = 1; i <= 30; ++i) {
      IBestiole* b = new Bestiole(milieu);
      milieu->addBestiole(b);
    }
    ecosysteme.run();

    return 0;
}
