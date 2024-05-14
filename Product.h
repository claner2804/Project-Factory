//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_PRODUCT_H
#define ALTKLAUSUREN_PRODUCT_H

#include <iostream>


class Product {

    //protected weil es von den Unterklassen geerbt wird
protected:
    int type; //TODO: braucht man das?


public:
    Product();
    ~Product();

    //mit 0 initialisieren
    //virtual weil es in den Unterklassen überschrieben wird
    virtual int getType();


};


#endif //ALTKLAUSUREN_PRODUCT_H
