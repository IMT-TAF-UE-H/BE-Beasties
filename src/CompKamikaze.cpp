#include "CompKamikaze.h"
#include <vector>

std::shared_ptr<ComportementKamikaze> ComportementKamikaze::instance = nullptr;

std::shared_ptr<ComportementKamikaze> ComportementKamikaze::getInstance() {
    if (instance == nullptr) {
        instance = make_shared<ComportementKamikaze>();
    }
    return instance;
}

tuple<double, double> ComportementKamikaze::getDeplacement(IBestiole & b, Milieu *monMilieu) {
   double deltaX = 0;
   double deltaY = 0;

    // trouve le voisin le plus proche et se dirige vers lui

   double distanceMin = 1000000;
   
   for ( std::vector<IBestiole>::iterator it = monMilieu->getVoisins(b).begin() ; it != monMilieu->getVoisins(b).end() ; ++it )
   {
      if ( !(b == *it) && b.jeTeVois(*it) )
      {
         double distance = b.getDistance(b)
         if (distance < distanceMin) {
            distanceMin = distance;
            deltaX = it->getX() - b.getX();
            deltaY = it->getY() - b.getY();
         }
      }
   }
   /*
   double dx = cos(direction) * vitesse;
    double dy = -sin(direction) * vitesse;
   */
    
   return make_tuple(deltaX, deltaY);

}
