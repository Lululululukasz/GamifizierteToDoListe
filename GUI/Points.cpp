#include "Points.h"

//Whith this one you can use the points class with "Points::getinstance()" its always the same instance.
Points& Points::getinstance(){
    static Points instance;
    return instance;
}

//these two add and subtract points from the variables, you can add a multiplier variable if you want if not set it to 1
//nORd decides if you want to change the normal or default points.
void Points::addPoints(unsigned int newpoints, double multi, char nORd) {
    if(nORd == 'n'){
        this->nPoints += static_cast<unsigned int>(newpoints * multi);
    }else if(nORd == 'd'){
        this->dPoints += static_cast<unsigned int>(newpoints * multi);
    }
}
void Points::subPoints(unsigned int leavepoints, char nORd) {
    if(nORd == 'n'){
        if(this->nPoints >= leavepoints){
            this->nPoints -= leavepoints;
        }else{
            this->nPoints = 0;
        }
    }else if(nORd == 'd'){
        if(this->dPoints >= leavepoints){
            this->dPoints -= leavepoints;
        }else{
            this->dPoints = 0;
        }
    }
}

unsigned int Points::getNPoints() {return nPoints;}
unsigned int Points::getDPoints() {return dPoints;}

void Points::setNPoints(unsigned int newpoints) {nPoints = newpoints;}
void Points::setDPoints(unsigned int newpoints) {dPoints = newpoints;}