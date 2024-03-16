#include "Milieu.h"

#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
double Milieu::width = 640.;
double Milieu::height = 480.;

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 )
{
   width = _width;
   height = _height;

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;
   // TODO tuer toutes les bestioles

}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (*it)->updatePos();
   }
   auto vaMourir = getVaMourir();

   for ( auto id = vaMourir.begin() ; id != vaMourir.end() ; ++id )
   {
      tuer(*id);
   }

   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (*it)->draw( *this );
   }

}

void Milieu::tuer(int idBestiole) {
   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if ((*it)->getId() == idBestiole) {
         // TODO tuer la bibitte
         break;
      }
   }
}

std::vector<IBestiole*> Milieu::getVoisins(IBestiole* b) {
   std::vector<IBestiole*> voisins;
   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b->getId() == (*it)->getId()) && b->detecter(*it) )
         voisins.push_back(*it);
   return voisins;
}

void Milieu::addBestiole(IBestiole *bestiole) {
   listeBestioles.push_back(bestiole);
}

std::vector<int> Milieu::getVaMourir() {
    return std::vector<int>(); // TODO implem
}
