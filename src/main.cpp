#include "Aquarium.h"
#include "Bestiole.h"
#include "Carapace.h"
#include "GlobalConfig.h"
#include "Milieu.h"
#include "Nageoire.h"
#include "Oreilles.h"

#include <iostream>

using namespace std;

void initLogger(ofstream &logFile, string conf_name) {

    // Initialisation du fichier de log
    const char* log_addr = ("logs/"+conf_name+".csv").c_str();
    cout << "Ouverture du fichier de log" << endl;
    if (remove(log_addr) != 0) {
        cout << "Erreur lors de la suppression du fichier de log" << endl;
    }
    // if already open, close it
    if (logFile.is_open()) {
        logFile.close();
    }

    logFile.open(log_addr, ios::out);
    cout << "Fichier de log ouvert" << endl;
    // Entête du fichier de log
    logFile << "Peureuse,Gregaire,Kamikaze,Prevoyante,Multiple\n";
}

/**
 * @brief Main
 *
 * Crée un aquarium et lance la simulation.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
    std::string conf_name = "default";
    if (argc > 1) conf_name = argv[1];

    ofstream logger;
    initLogger(logger, conf_name);

    // C40x480 pixels, 30ms de délai Création de l'écosystème
    GlobalConfig::loadConfigFromFile("default.conf");
    GlobalConfig::setLimites();
    Aquarium ecosysteme;
    ecosysteme.run(); // Lancement de la simulation

    return 0;
}
