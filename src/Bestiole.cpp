#include "Bestiole.h"

#include "Milieu.h"

#include <cmath>
#include <cstdlib>

const double Bestiole::MAX_VITESSE = 10.;

int Bestiole::next = 0;

Bestiole::Bestiole(Milieu *_milieu) {

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par defaut" << endl;

    milieu = _milieu;
    vieRestante = 1000;
    taille = 8.;
    x = Milieu::width * rand() / (double)RAND_MAX;
    y = Milieu::height * rand() / (double)RAND_MAX;
    direction = static_cast<double>(rand()) / RAND_MAX * 2. * M_PI;
    vitesse = static_cast<double>(rand()) / RAND_MAX * MAX_VITESSE;

    couleur = new T[3];
    couleur[0] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);
    couleur[1] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);
    couleur[2] = static_cast<int>(static_cast<double>(rand()) / RAND_MAX * 255.);
}

Bestiole::Bestiole(const Bestiole &b) {

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par copie" << endl;

    x = b.x;
    y = b.y;
    taille = b.taille;
    direction = b.direction;
    vitesse = b.vitesse;
    couleur = new T[3];
    memcpy(couleur, b.couleur, 3 * sizeof(T));
    milieu = b.milieu;
}

Bestiole::~Bestiole(void) {

    delete[] couleur;

    cout << "dest Bestiole" << endl;
}

shared_ptr<IBestiole> Bestiole::clone() {
    return make_shared<Bestiole>(this);
}

void Bestiole::updatePos() {

    double nx, ny;

    auto delta = comportement->deplacement(*this, *milieu);

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

    x, y = nx, ny;
    vieRestante--;
}

bool Bestiole::detectable() {
    return rand() < discretion * RAND_MAX;
}

bool Bestiole::detecter(shared_ptr<IBestiole> b) {
    return false;
}

bool Bestiole::collision(shared_ptr<IBestiole> b) {
    return rand() * resistance > RAND_MAX;
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

double Bestiole::getDistance(shared_ptr<IBestiole> b) const {
    return sqrt((x - b->getX()) * (x - b->getX()) + (y - b->getY()) * (y - b->getY()));
}

double Bestiole::getDirection() const {
    return direction;
}

double Bestiole::getDirectionTo(shared_ptr<IBestiole> b) const {
    return atan2(b->getY() - y, b->getX() - x);
}

int Bestiole::getId() const {
    return identite;
}