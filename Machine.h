//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_MACHINE_H
#define ALTKLAUSUREN_MACHINE_H

#include <iostream>
#include "Product.h"
#include "Factory.h"
#include "Exceptions.h"

class Machine {
protected:
    Factory* factory;

public:
    Machine();
    virtual ~Machine();

    //Simuliert das Produzieren von Produkten
    // (siehe Ablauf Zeitschleife)
    virtual void tick() = 0;

    virtual std::string getName() = 0;


    /*
     * Damit eine Maschine ein neu erstelltes Produkt
     * der Fabrik mithilfe der Methode addProdukt()
     * übergeben kann, benötigt die Maschine eine Referenz
     * auf die Fabrik. Mithilfe dieser Methode kann die entsprechende
     * Referenz der Maschine in der addMachine()-Methode übergeben werden
     */
    void setFactory(Factory* f);




};


#endif //ALTKLAUSUREN_MACHINE_H
