//
// Created by Jan Ole Weighardt on 26.05.23.
//

#include "Xp.h"

using namespace std;
using namespace todolib;
int Xp::xpZahl=0;

void Xp::xpFunc(bool xpBool) {
    if (xpBool== true){
        xpZahl++;
    }else{
        xpZahl--;
    };
};