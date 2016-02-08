#ifndef __drone__
#define __drone__
#include <iostream>
#include <string>

struct Position {
   int ew, ns;
};

struct Drone {
     Position cur;
     Position previous[50];
     unsigned int totalmoves;
     std::string direction;
     
     void forward();
     void backward();
     void left();
     void right();
     Position current();
     int totalDistance();
     int manhattanDistance();
     bool repeated();

     Drone();
};

#endif
