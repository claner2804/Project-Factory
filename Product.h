//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_PRODUCT_H
#define ALTKLAUSUREN_PRODUCT_H

#include <iostream>
#include "Exceptions.h"


class Product {

public:
    Product();
    ~Product();

    //mit 0 initialisieren
    //virtual weil es in den Unterklassen überschrieben wird
    virtual int getType();

    //getName() gibt den Namen des Produkts zurück
    virtual std::string getName() = 0;



};


#endif //ALTKLAUSUREN_PRODUCT_H
