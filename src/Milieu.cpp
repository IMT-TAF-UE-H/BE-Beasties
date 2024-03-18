#include "Milieu.h"

#include <cstdlib>
#include <ctime>

using namespace std;

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
double Milieu::width = 640.;
double Milieu::height = 480.;
const double Milieu::DIST_MAX_VOISINS = height/10.;

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 )
{
   width = _width;
   height = _height;

   cout << "const Milieu" << endl;

   srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;
   for ( auto it = listeBestioles.cbegin() ; it != listeBestioles.cend() ;)
   {
      tuer((it++)->first);
   }

}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (it->second)->updatePos();
   }
   auto vaMourir = getVaMourir();

   for ( auto it = vaMourir.begin() ; it != vaMourir.end() ;)
   {
      tuer((it++)->first);
   }

   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (it->second)->draw( *this );
   }

}

void Milieu::tuer(int idBestiole) {
   delete listeBestioles[idBestiole];
   listeBestioles.erase(idBestiole);
}

map<int, IBestiole*> Milieu::getVoisins(IBestiole* b) {
   std::map<int, IBestiole*> voisins;
   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b->getId() == it->first) && b->getDistance(it->second) < DIST_MAX_VOISINS )
         voisins.insert(std::pair<int, IBestiole*>(it->first, it->second));
   return voisins;
}

void Milieu::addBestiole(IBestiole *bestiole) {
   listeBestioles.insert(std::pair<int, IBestiole*>(bestiole->getId(), bestiole));
   cout << "taille du dictionaire : " << listeBestioles.size() << endl;
}

std::map<int, IBestiole*> Milieu::getVaMourir() {
   std::map<int, IBestiole*> vaMourir;
   // TODO implem
   return vaMourir;
}
