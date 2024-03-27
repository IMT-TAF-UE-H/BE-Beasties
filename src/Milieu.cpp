#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <random>
#include "GlobalConfig.h"

using namespace std;

// Initialisation des attributs statiques
const T Milieu::white[] = {(T)255, (T)255, (T)255};
double Milieu::width = 640.;
double Milieu::height = 480.;

/**
 * @brief Constructeur de la classe Milieu
 * 
 * Initialisation du milieu et des bestioles.
 * 
 * @param _width 
 * @param _height 
 */
Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          listeBestioles() {
    width = _width;
    height = _height;

    cout << "const Milieu" << endl;

    // Initialisation de la factory
    bestioleFactory = new BestioleFactory(this) 

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
    peupler(nbBestioles);
}

/**
 * @brief Destructeur de la classe Milieu
 * 
 */
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

/**
 * @brief Méthode de simulation d'une étape.
 * 
 * Cette méthode effectue une étape de simulation du milieu.
 * Les bestioles sont mises à jour, dessinées.
 * 
 * Des bestioles peuvent naître, mourir, se cloner.
 * 
 * La répartion des bestioles par comportement est loggée.
 */
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

    if ((double) std::rand() / (double)RAND_MAX <= probaNaissanceSpontanee) {
        cout << "Naissance spontanée" << endl;
        addBestiole();// Add the missing argument here
    }

    // Clonage

    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if ((double) std::rand() / (double)RAND_MAX <= probaClonage) {
            auto bestiole = it->second->clone();
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

/**
 * @brief Méthode qui enlève une bestiole du milieu
 * 
 * @param bestiole 
 */
void Milieu::tuer(int idBestiole) {
    listeBestioles.erase(idBestiole);
}

/**
 * @brief Méthode qui retourne les voisins d'une bestiole (sous forme de map)
 * 
 * @param idBestiole 
 * @return std::unique_ptr<std::map<int, std::shared_ptr<IBestiole>>> 
 */
unique_ptr<std::map<int, std::shared_ptr<IBestiole>>> Milieu::getVoisins(int idBestiole) {
    auto voisins = make_unique<std::map<int, std::shared_ptr<IBestiole>>>();
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
        if (!(idBestiole == it->first) && it->second->getDistance(idBestiole) < DIST_MAX_VOISINS)
            (*voisins)[it->first] = it->second;
    return voisins;
}

/**
 * @brief Méthode qui retourne une bestiole du milieu par son id
 * 
 * @param idBestiole 
 * @return std::shared_ptr<IBestiole> 
 */
std::shared_ptr<IBestiole> Milieu::getBestiole(int idBestiole) {
    return listeBestioles[idBestiole];
}

/**
 * @brief Méthode qui ajoute une bestiole au milieu
 * 
 * Comme il n'y a pas de paramètre, le comportement de la bestiole est choisi aléatoirement.
 * 
 */
void Milieu::addBestiole() {
    auto bestiole = bestioleFactory->naissance();
    listeBestioles[bestiole->getId()] = bestiole;
}

/**
 * @brief Méthode qui ajoute un nombre de bestioles au milieu
 * 
 * Méthode appelée lors de la création du milieu.
 * 
 * @param type 
 */
void Milieu::peupler(int nbBestioles) {
    for (int i = 0; i < nbBestioles; i++) {
        addBestiole();
    }
}

/**
 * @brief Méthode qui retourne les bestioles qui vont mourir
 * 
 * Les conditions de mort sont les collisions et la vieillesse.
 * 
 * @return std::vector<int> 
 */
std::vector<int> Milieu::getVaMourir() {
    std::vector<int> vaMourir;
    for (auto it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        for (auto it2 = listeBestioles.begin(); it2 != listeBestioles.end(); ++it2) {
            if ((it->first != it2->first && it->second->getDistance(it2->first) < DIST_COLLISION && it->second->collision()) || it->second->getVieRestante() <= 0) {
                vaMourir.push_back(it->first);
                break;
            }
        }
    }
    return vaMourir;
}

/**
 * @brief Méthode qui définit les limites du milieu
 * 
 * @param _DIST_MAX_VOISINS 
 * @param _DIST_COLLISION 
 * @param _probaNaissanceSpontanee 
 * @param _probaClonage 
 */

void Milieu::setLimites(double _DIST_MAX_VOISINS, double _DIST_COLLISION, double _probaNaissanceSpontanee, double _probaClonage, int _nbBestioles) {
    DIST_MAX_VOISINS = _DIST_MAX_VOISINS;
    DIST_COLLISION = _DIST_COLLISION;
    probaNaissanceSpontanee = _probaNaissanceSpontanee;
    probaClonage = _probaClonage;
    nbBestioles = _nbBestioles;
}