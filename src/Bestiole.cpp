#include "Bestiole.h"

#include "Milieu.h"

#include <cmath>
#include <cstdlib>
#include "CompGregaire.h"
#include "CompKamikaze.h"
#include "CompPeureuse.h"
#include "CompPrevoyante.h"
#include "CompMultiple.h"
#include "GlobalConfig.h"

int Bestiole::next = 0; // initialisation du compteur d'identifiant

/**
 * @brief Constructeur par défaut de la classe Bestiole
 * 
 * Initialisation des attributs et du comportement de la Bestiole.
 * 
 * @param _milieu 
 * @param type 
 */
Bestiole::Bestiole(Milieu *_milieu, int type) {

    identite = ++next; // incrémentation du compteur d'identifiant
    
    cout << "(" << identite << "): const. par defaut Bestiole" << endl;

    // comportement = ComportementKamikaze::getInstance();
    // comportement = ComportementGregaire::getInstance();
    //comportement = ComportementPeureuse::getInstance();
    //comportement = ComportementPrevoyante::getInstance(); 
    //comportement = ComportementMultiple::getInstance();

    switch (type) {
        case 0:
            comportement = ComportementKamikaze::getInstance();
            break;
        case 1:
            comportement = ComportementPeureuse::getInstance();
            break;
        case 2:
            comportement = ComportementGregaire::getInstance();
            break;
        case 3:
            comportement = ComportementPrevoyante::getInstance();
            break;
        case 4:
            comportement = ComportementMultiple::getInstance();
            break;
        default:
            comportement = ComportementMultiple::getInstance();
            break;
    }


    milieu = _milieu;
    vieRestante = vieMin + (rand() % (vieMax - vieMin));
    taille = 8.;
    x = Milieu::width * (rand() / (double)RAND_MAX);
    y = Milieu::height * (rand() / (double)RAND_MAX);
    direction = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
    vitesse = MIN_VITESSE + (MAX_VITESSE - MIN_VITESSE) * (rand() / (double)RAND_MAX);

    couleur = new T[3];
    couleur[0] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);
    couleur[1] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);
    couleur[2] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);

    discretion = 0.; 
    resistance = 1.;
}

/**
 * @brief Constructeur par copie de la classe Bestiole
 * 
 * Sert au clonage spontané des Bestioles.
 * Noter que la position de la nouvelle Bestiole est aléatoire pour éviter les collisions.
 * 
 * @param b 
 */
Bestiole::Bestiole(const Bestiole &b) {

    identite = ++next;

    cout << "(" << b.getId() << "): const Bestiole par copie" << endl;

    // nouveaux attributs
    x = Milieu::width * (rand() / (double)RAND_MAX);
    y = Milieu::height * (rand() / (double)RAND_MAX);
    vieRestante = 1000;
    // attributs conservés
    taille = b.taille;
    direction = b.direction;
    vitesse = b.vitesse;
    couleur = new T[3];
    memcpy(couleur, b.couleur, 3 * sizeof(T));
    milieu = b.milieu;
    comportement = b.comportement;
    discretion = b.discretion;
    resistance = b.resistance;
}

/**
 * @brief Destructeur de la classe Bestiole
 * 
 * Destruction de la Bestiole.
 * 
 */
Bestiole::~Bestiole(void) {

    cout << "(" << getId() << "): dest Bestiole" << endl;

    delete[] couleur;
}

std::shared_ptr<IBestiole> Bestiole::clone() {
    return make_shared<Bestiole>(*this);
}

/**
 * @brief Mise à jour de la position de la Bestiole
 * 
 * Calcul du déplacement de la Bestiole en fonction de son comportement.
 * Gestions des collisions avec les bords du milieu.
 * 
 */
void Bestiole::updatePos() {

    double nx, ny;

    auto delta = comportement->getDeplacement(getId(), milieu);

    nx = x + get<0>(delta);
    ny = y + get<1>(delta);

    if (nx < 0) {
        direction = M_PI - direction;
        nx = -nx;
    } else if (nx > Milieu::width) {
        direction = M_PI - direction;
        nx = 2 * Milieu::width - nx;
    }

    if (ny < 0) {
        direction = -direction;
        ny = -ny;
    } else if (ny > Milieu::height) {
        direction = -direction;
        ny = 2 * Milieu::height - ny;
    }

    x = nx;
    y = ny;
    vieRestante--;
}

/**
 * @brief Détection d'une autre Bestiole
 * 
 * @param idBestiole 
 * @return true 
 * @return false 
 */
bool Bestiole::detecter(int idBestiole) {
    return false;
}

/**
 * @brief Gestion des collisions
 * 
 * @return true 
 * @return false 
 */
bool Bestiole::collision() {
    return (double)rand()/(double)RAND_MAX < 1./resistance;
}

/**
 * @brief Setter des limites de la Bestiole
 * 
 * @param _MAX_VITESSE 
 * @param _MIN_VITESSE 
 * @param _vieMax 
 * @param _vieMin 
 */

void Bestiole::setLimites(double _MAX_VITESSE, double _MIN_VITESSE, int _vieMax, int _vieMin) {
    MAX_VITESSE = _MAX_VITESSE;
    MIN_VITESSE = _MIN_VITESSE;
    vieMax = _vieMax;
    vieMin = _vieMin;
}

/**
 * @brief Getter de la vitesse de la Bestiole
 * 
 * @return double 
 */
double Bestiole::getVitesse() {
    return vitesse;
}

/**
 * @brief Setter de la vitesse de la Bestiole
 * 
 * @param _vitesse 
 */
void Bestiole::setVitesse(double _vitesse) {
    vitesse = _vitesse;
}

/**
 * @brief Getter de la résistance de la Bestiole
 * 
 * @return double 
 */
double Bestiole::getResistance() {
    return resistance;
}

/**
 * @brief Setter de la résistance de la Bestiole
 * 
 * @param _resistance 
 */
void Bestiole::setResistance(double _resistance) {
    resistance = _resistance;
}

/**
 * @brief Getter de la discrétion de la Bestiole
 * 
 * @return double 
 */
double Bestiole::getDiscretion() const {
    return discretion;
}

/**
 * @brief Setter de la discrétion de la Bestiole
 * 
 * @param _discretion 
 */
void Bestiole::setDiscretion(double _discretion) {
    discretion = _discretion;
}

/**
 * @brief Dessin de la Bestiole
 * 
 * Se sert de la classe UImg pour dessiner la Bestiole.
 * 
 * @param support 
 */
void Bestiole::draw(UImg &support) {

    double xt = x + cos(direction) * taille / 2.1;
    double yt = y - sin(direction) * taille / 2.1;

    support.draw_ellipse(x, y, taille, taille / 5., -direction / M_PI * 180., couleur);
    support.draw_circle(xt, yt, taille / 2., couleur);
}

/**
 * @brief Opérateur d'égalité
 * 
 * Vérifie si deux Bestioles sont identiques en comparant leurs identifiants.
 * 
 * @param b1 
 * @param b2 
 * @return true 
 * @return false 
 */
bool operator==(const Bestiole &b1, const Bestiole &b2) {

    return (b1.identite == b2.identite);
}

/**
 * @brief Getter de la position x de la Bestiole
 * 
 * @return double 
 */
double Bestiole::getX() const {
    return x;
}

/**
 * @brief Getter de la position y de la Bestiole
 * 
 * @return double 
 */
double Bestiole::getY() const {
    return y;
}

/**
 * @brief Calcul de la distance entre la Bestiole et une autre Bestiole
 * 
 * Distance euclidienne entre la Bestiole et une autre Bestiole.
 * 
 * @param idBestiole 
 * @return double 
 */
double Bestiole::getDistance(int idBestiole) const {
    auto b = milieu->getBestiole(idBestiole);
    return sqrt((x - b->getX()) * (x - b->getX()) + (y - b->getY()) * (y - b->getY()));
}

/**
 * @brief Getter de la direction de la Bestiole
 * 
 * @return double 
 */
double Bestiole::getDirection() const {
    return direction;
}

/**
 * @brief Setter de la direction de la Bestiole
 * 
 * @param _direction 
 */
void Bestiole::setDirection(double _direction) {
    direction = _direction;
}

/**
 * @brief Calcul de la direction de la Bestiole vers une autre Bestiole
 * 
 * Utilisation de la fonction atan2 pour calculer la direction de la Bestiole vers une autre Bestiole.
 * atan2 renvoie l'angle en radians entre l'axe des abscisses et le point (x, y).
 * 
 * @param idBestiole 
 * @return double 
 */
double Bestiole::getDirectionTo(int idBestiole) const {
    auto b = milieu->getBestiole(idBestiole);
    return fmod(-atan2((b->getY() - y), b->getX() - x), 2 * M_PI);
}

/**
 * @brief Getter de l'identifiant de la Bestiole
 * 
 * @return int 
 */
int Bestiole::getId() const {
    return identite;
}

/**
 * @brief Getter du milieu de la Bestiole
 * 
 * @return Milieu* 
 */
Milieu* Bestiole::getMilieu() {
    return milieu;
}

/**
 * @brief Getter du comportement de la Bestiole
 * 
 * La chaine de caractères retournée est le nom du comportement de la Bestiole.
 * 
 * @return string 
 */
string Bestiole::getComportement() const {
    return comportement->getDescription();
}

/**
 * @brief Getter de la vie restante de la Bestiole
 * 
 * @return int 
 */
int Bestiole::getVieRestante() const {
    return vieRestante;
}