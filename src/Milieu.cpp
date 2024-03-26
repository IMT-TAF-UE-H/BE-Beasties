#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <random>
#include "GlobalConfig.h"

using namespace std;

const T Milieu::white[] = {(T)255, (T)255, (T)255};
double Milieu::width = 640.;
double Milieu::height = 480.;
double Milieu::DIST_MAX_VOISINS = std::stod(GlobalConfig::getInstance().getConfig("DIST_MAX_VOISINS")); 
double Milieu::DIST_COLLISION = std::stod(GlobalConfig::getInstance().getConfig("DIST_COLLISION"));
double Milieu::probaNaissanceSpontanee = std::stod(GlobalConfig::getInstance().getConfig("probaNaissanceSpontanee")); // Pourcentage
double Milieu::probaClonage = std::stod(GlobalConfig::getInstance().getConfig("probaClonage")); // Pourcentage 

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          listeBestioles() {
    width = _width;
    height = _height;

    cout << "const Milieu" << endl;

    // Initialisation de la factory
    double p_kamikaze = std::stod(GlobalConfig::getInstance().getConfig("p_kamikaze"));
    double p_peureuse = std::stod(GlobalConfig::getInstance().getConfig("p_peureuse"));
    double p_gregaire = std::stod(GlobalConfig::getInstance().getConfig("p_gregaire"));
    double p_prevoyante = std::stod(GlobalConfig::getInstance().getConfig("p_prevoyante"));
    bestioleFactory = new BestioleFactory(this, p_kamikaze, p_peureuse, p_gregaire, p_prevoyante); 

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

    srand(time(NULL));

    // peuplement du milieu
    int nbBestioles = std::stoi(GlobalConfig::getInstance().getConfig("nbBestioles"));
    peupler(nbBestioles);
}

Milieu::~Milieu(void) {

    cout << "dest Milieu" << endl;

    for (auto it = listeBestioles.cbegin(); it != listeBestioles.cend();) {
        tuer((it++)->first);
    }
    // fermeture du fichier de log
    logFile.close();

    // destruction de la factorie
    delete bestioleFactory;
}

void Milieu::step(void) {


    int comportements[5] = {0, 0, 0, 0, 0};

    // Remplissage de l'image de fond
    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);
    
    // Mise à jour des positions
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        (it->second)->updatePos();

    }

    // Tuer les bestioles (collision et vieillesse)
    auto vaMourir = getVaMourir();

    for (int it : vaMourir) {
        tuer(it);
    }

    // Naissance spontanée

    // random double entre 0 et 1
    if (std::rand() / (double) RAND_MAX < probaNaissanceSpontanee) {
        cout << "Naissance spontanée" << endl;
        addBestiole();// Add the missing argument here
    }

    // Clonage

    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if (std::rand() / (double) RAND_MAX < probaClonage) {
            cout << "Clonage" << endl;
            IBestiole *bestiole = it->second->clone();
            listeBestioles[bestiole->getId()] = bestiole;
        }
    }


    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        (it->second)->draw(*this);

        // log des comportements
        std::string comportement = it->second->getComportement();
        if (comportement == "Peureuse") {
            comportements[0]++;
        } else if (comportement == "Gregaire") {
            comportements[1]++;
        } else if (comportement == "Kamikaze") {
            comportements[2]++;
        } else if (comportement == "Prevoyante") {
            comportements[3]++;
        } else {
            comportements[4]++;
        }
    }

    // log des comportements dans le fichier de log (CSV)
    logFile << comportements[0] << "," << comportements[1] << "," << comportements[2] << "," << comportements[3] << ","
            << comportements[4] << endl;


}

void Milieu::tuer(int idBestiole) {
    delete listeBestioles[idBestiole];
    listeBestioles.erase(idBestiole);
}

unique_ptr<std::map<int, IBestiole *>> Milieu::getVoisins(int idBestiole) {
    auto voisins = make_unique<std::map<int, IBestiole *>>();
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
        if (!(idBestiole == it->first) && it->second->getDistance(idBestiole) < DIST_MAX_VOISINS)
            (*voisins)[it->first] = it->second;
    return voisins;
}

IBestiole *Milieu::getBestiole(int idBestiole) {
    return listeBestioles[idBestiole];
}

void Milieu::addBestiole() {
    IBestiole *bestiole = bestioleFactory->naissance();
    listeBestioles[bestiole->getId()] = bestiole;
}

void Milieu::peupler(int nbBestioles) {
    for (int i = 0; i < nbBestioles; i++) {
        addBestiole();
    }
}

std::vector<int> Milieu::getVaMourir() {
    std::vector<int> vaMourir;
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        for (auto it2 = listeBestioles.begin(); it2 != listeBestioles.end(); ++it2) {
            if (it->first != it2->first && it->second->getDistance(it2->first) < DIST_COLLISION && it->second->collision()) {
                vaMourir.push_back(it->first);
                break;
            }
        }
    }
    return vaMourir;
}
