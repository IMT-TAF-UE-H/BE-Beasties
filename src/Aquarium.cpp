#include "Aquarium.h"
#include "Camouflage.h"
#include "Carapace.h"
#include "Nageoire.h"
#include "Oreilles.h"
#include "Yeux.h"
#include <math.h>
#include <chrono>


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

   // Limites des attributs des décorateurs
   Camouflage::setLimites(0.3, 0.9);
   Carapace::setLimites(10., 2.);
   Nageoire::setLimites(3.);
   Oreilles::setLimites(5., 50., 0.8, 0.9);
   Yeux::setLimites(M_PI/6., 3.*M_PI/2., 5., 100., 0.8, 0.9);

}


Aquarium::~Aquarium( void )
{

   cout << "dest Aquarium" << endl;

   delete flotte;

}


void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }
      auto t0 = chrono::high_resolution_clock::now();
      flotte->step();
      display( *flotte );
      auto t1 = chrono::high_resolution_clock::now();

      int waitTime = delay - chrono::duration_cast<chrono::milliseconds>(t1-t0).count();
      if (waitTime>0) wait(waitTime);

   }

}
