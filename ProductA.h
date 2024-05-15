//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_PRODUCTA_H
#define ALTKLAUSUREN_PRODUCTA_H


#include "Product.h"
#include "Exceptions.h"

class ProductA : public Product {

    //protected weil es von den Unterklassen geerbt wird

public:
    ProductA();
    ~ProductA();

    int getType() override;

    //getName() gibt den Namen des Produkts zurück
    std::string getName() override;

};


#endif //ALTKLAUSUREN_PRODUCTA_H
