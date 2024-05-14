//
// Created by Claudia Steiner on 14.05.24.
//

#include "Product.h"

Product::Product() {
    std::cout << "Product created" << std::endl;
}

Product::~Product() {
    std::cout << "Product destroyed" << std::endl;
}

//getType() gibt in der Basis-Klasse 0 zurück
int Product::getType() {
    return 0;
}


