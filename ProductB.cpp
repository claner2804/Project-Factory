//
// Created by Claudia Steiner on 14.05.24.
//

#include "ProductB.h"


ProductB::ProductB() {
    std::cout << "ProductB created" << std::endl;
}

ProductB::~ProductB() {
    std::cout << "ProductB destroyed" << std::endl;
}

//getType() gibt in der Unter-Klasse B 2 zurück
int ProductB::getType() {
    return 2;
}

std::string ProductB::getName() {
    return "ProductB";
}