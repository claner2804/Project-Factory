//
// Created by Claudia Steiner on 14.05.24.
//

#include "ProductA.h"


ProductA::ProductA() {
    std::cout << "ProductA created" << std::endl;
}

ProductA::~ProductA() {
    std::cout << "ProductA destroyed" << std::endl;
}

//getType() gibt in der Unter-Klasse B 2 zurück
int ProductA::getType() {
    return 1;
}