//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_PRODUCTB_H
#define ALTKLAUSUREN_PRODUCTB_H

#include "Product.h"
#include "Exceptions.h"

class ProductB : public Product{

public:
    ProductB();
    ~ProductB();

    int getType() override;

    std::string getName() override;

};


#endif //ALTKLAUSUREN_PRODUCTB_H
