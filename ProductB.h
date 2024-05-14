//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_PRODUCTB_H
#define ALTKLAUSUREN_PRODUCTB_H

#include "Product.h"

class ProductB : public Product{

public:
    ProductB();
    ~ProductB();

    int getType() override;

};


#endif //ALTKLAUSUREN_PRODUCTB_H
