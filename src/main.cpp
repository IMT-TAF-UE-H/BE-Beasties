#include "Aquarium.h"
#include "Bestiole.h"
#include "Milieu.h"
#include "Oreilles.h"

#include <iostream>

using namespace std;

int main() {

    Aquarium ecosysteme(640, 480, 30);
    Milieu* milieu = ecosysteme.getMilieu();

    for (int i = 1; i <= 30; ++i) {
      IBestiole* b = new Oreilles(new Bestiole(milieu));
      cout << b->getId() << endl;
      milieu->addBestiole(b);
      cout << "aaaaaaaaa" << endl;
    }
    ecosysteme.run();

    return 0;
}
