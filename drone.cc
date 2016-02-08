#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "drone.h"

// Constructor
Drone::Drone(): totalmoves(0), direction("N") {
   this->cur.ns = 0;
   this->cur.ew = 0;
   for (int i=0; i < 50; i++) {
	previous[i].ew = 0;
	previous[i].ns = 0;
   }
}
// Methods
void Drone::forward() {
   (this->previous)[this->totalmoves] = this->cur;

   if (this->direction == "N") {
	(this->cur).ns++;
	this->totalmoves++;
   } else if  (this->direction == "S") {
	(this->cur).ns--;
	this->totalmoves++;
   } else if  (this->direction == "E") {
        (this->cur).ew++;
        this->totalmoves++;
   } else { // move West
        (this->cur).ew--;
        this->totalmoves++;
   }
}

void Drone::backward() {
   (this->previous)[totalmoves] = this->cur;

   if (this->direction == "N") {
        (this->cur).ns--;
        this->totalmoves++;
   } else if  (this->direction == "S") {
        (this->cur).ns++;
        this->totalmoves++;
   } else if  (this->direction == "E") {
        (this->cur).ew--;
        this->totalmoves++;
   } else { // move East
        (this->cur).ew++;
        this->totalmoves++;
   }
}

void Drone::left() {
   if (this->direction == "N") {
        (this->direction) = "W";
   } else if  (this->direction == "W") {
        (this->direction) = "S";
   } else if  (this->direction == "S") {
        (this->direction) = "E";
   } else { // move from E to N
        (this->direction) = "N";
   }
} 

void Drone::right() {
   if (this->direction == "N") {
        (this->direction) = "E";
   } else if  (this->direction == "E") {
        (this->direction) = "S";
   } else if  (this->direction == "S") {
        (this->direction) = "W";
   } else { // move from W to N
        (this->direction) = "N";
   }
}


Position Drone::current() {
   return this->cur;
}

int Drone::totalDistance() {
   return this->totalmoves;
}

int Drone::manhattanDistance() {
   return abs((this->cur).ew) + abs((this->cur).ns);
}

bool Drone::repeated() {
   if (this->previous[1].ns == 0 && this->previous[1].ew == 0) { return false;}
   for (int i = 0; i < 50; i++) {
	if (this->cur.ns == this->previous[i].ns &&
	    this->cur.ew == this->previous[i].ew) {
	   return true;
   	}
   }
   return false;
}

