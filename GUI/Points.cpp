#include "Points.h"

Points::Points(unsigned int np, unsigned int dp) : nPoints{np}, dPoints{dp}{}

void Points::addPoints(unsigned int newpoints, double multi, char nORd) {
    if(nORd == 'n'){
        this->nPoints += static_cast<unsigned int>(newpoints * multi);
    }else if(nORd == 'd'){
        this->dPoints += static_cast<unsigned int>(newpoints * multi);
    }
}

unsigned int * Points::getNPoints() {return &nPoints;}
unsigned int * Points::getDPoints() {return &dPoints;}

