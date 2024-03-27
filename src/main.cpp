#include "Aquarium.h"
#include "Bestiole.h"
#include "Carapace.h"
#include "GlobalConfig.h"
#include "Milieu.h"
#include "Nageoire.h"
#include "Oreilles.h"

#include <iostream>

using namespace std;

void initLogger(ofstream &logFile, const char *conf_name) {

    // Initialisation du fichier de log
    cout << "Ouverture du fichier de log" << endl;
    if (remove("log.csv") != 0) {
        cout << "Erreur lors de la suppression du fichier de log" << endl;
    }
    // if already open, close it
    if (logFile.is_open()) {
        logFile.close();
    }

    logFile.open("log.csv", ios::out);
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
    const char *conf_name;
    if (argc > 1) conf_name = argv[1]; else conf_name = "default";

    ofstream logger;
    initLogger(logger, conf_name);

    // C40x480 pixels, 30ms de délai Création de l'écosystème
    int width = std::stoi(GlobalConfig::getInstance().getConfig("width"));
    int height = std::stoi(GlobalConfig::getInstance().getConfig("height"));
    int delay = std::stoi(GlobalConfig::getInstance().getConfig("delay"));
    Aquarium ecosysteme(width, height, delay, logger);
    ecosysteme.run(); // Lancement de la simulation

    return 0;
}
