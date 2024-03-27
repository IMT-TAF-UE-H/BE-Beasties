#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>

#include "Milieu.h"

using namespace std;
using namespace cimg_library;


class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte;

   static int delay;
   static int width;
   static int height;

public :
   Aquarium( ofstream &logFile );
   ~Aquarium( void );

   static void setLimites( int _width, int _height, int _delay );

   Milieu* getMilieu( void ) { return flotte; }

   void run( void );

};


#endif
