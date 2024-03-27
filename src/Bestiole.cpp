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

const double Bestiole::MAX_VITESSE = std::stod(GlobalConfig::getInstance().getConfig("MAX_VITESSE"));
const double Bestiole::MIN_VITESSE = std::stod(GlobalConfig::getInstance().getConfig("MIN_VITESSE"));

int Bestiole::next = 0; // initialisation du compteur d'identifiant

Bestiole::Bestiole(Milieu *_milieu, int type) {

    identite = ++next; // incrémentation du compteur d'identifiant
    
    cout << "const Bestiole (" << identite << ") par defaut" << endl;

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
    vieRestante = 1000; // TODO mettre en paramètre ou random
    taille = 8.;
    x = Milieu::width * (rand() / (double)RAND_MAX);
    y = Milieu::height * (rand() / (double)RAND_MAX);
    direction = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
    vitesse = MIN_VITESSE + (MAX_VITESSE - MIN_VITESSE) * (rand() / (double)RAND_MAX);

    couleur = new T[3];
    couleur[0] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);
    couleur[1] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);
    couleur[2] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);

    discretion = 0.; // TODO mettre du random ?
    resistance = 1.;
}

Bestiole::Bestiole(const Bestiole &b) {

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par copie" << endl;

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

Bestiole::~Bestiole(void) {

    cout << "dest Bestiole (" << getId() << ')' << endl;

    delete[] couleur;
}

std::shared_ptr<IBestiole> Bestiole::clone() {
    return make_shared<Bestiole>(*this);
}

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

bool Bestiole::detecter(int idBestiole) {
    return false;
}

bool Bestiole::collision() {
    return (double)rand()/(double)RAND_MAX < 1./resistance;
}

double Bestiole::getVitesse() {
    return vitesse;
}

void Bestiole::setVitesse(double _vitesse) {
    vitesse = _vitesse;
}

double Bestiole::getResistance() {
    return resistance;
}

void Bestiole::setResistance(double _resistance) {
    resistance = _resistance;
}

double Bestiole::getDiscretion() const {
    return discretion;
}

void Bestiole::setDiscretion(double _discretion) {
    discretion = _discretion;
}

void Bestiole::draw(UImg &support) {

    double xt = x + cos(direction) * taille / 2.1;
    double yt = y - sin(direction) * taille / 2.1;

    support.draw_ellipse(x, y, taille, taille / 5., -direction / M_PI * 180., couleur);
    support.draw_circle(xt, yt, taille / 2., couleur);
}

bool operator==(const Bestiole &b1, const Bestiole &b2) {

    return (b1.identite == b2.identite);
}

double Bestiole::getX() const {
    return x;
}

double Bestiole::getY() const {
    return y;
}

double Bestiole::getDistance(int idBestiole) const {
    auto b = milieu->getBestiole(idBestiole);
    return sqrt((x - b->getX()) * (x - b->getX()) + (y - b->getY()) * (y - b->getY()));
}

double Bestiole::getDirection() const {
    return direction;
}

void Bestiole::setDirection(double _direction) {
    direction = _direction;
}

double Bestiole::getDirectionTo(int idBestiole) const {
    auto b = milieu->getBestiole(idBestiole);
    return atan2(b->getY() - y, b->getX() - x);
}

int Bestiole::getId() const {
    return identite;
}

Milieu* Bestiole::getMilieu() {
    return milieu;
}

string Bestiole::getComportement() const {
    return comportement->getDescription();
}