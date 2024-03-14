#include <Camouflage.h>
#include <Carapace.h>
#include <Nageoire.h>
#include <Oreilles.h>
#include <Yeux.h>

using namespace std;

void testSetLimites() {
    cout << "Initialisation des limites" << endl;
    Camouflage::setLimites(0.1, 0.9);
    Carapace::setLimites(5, 5);
    Nageoire::setLimites(5);
    Oreilles::setLimites(1, 5, 0.1, 0.9);
    Yeux::setLimites(0.5, 3, 1, 5, 0.1, 0.9);
}

int main(int argc, char const *argv[]) {
    cout << "Début des tests" << endl;
    testSetLimites();
    cout << "Fin des tests" << endl;
    return 0;
}
