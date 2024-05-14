//
// Created by Claudia Steiner on 14.05.24.
//

#include "Machine.h"
#include "Factory.h"
#include <iostream>

Machine::Machine() {
}


Machine::~Machine() {
    std::cout << "Machine destroyed" << std::endl;
    delete &factory;
}



/*
 * Damit eine Maschine ein neu erstelltes Produkt
 * der Fabrik mithilfe der Methode addProdukt()
 * übergeben kann, benötigt die Maschine eine Referenz
 * auf die Fabrik. Mithilfe dieser Methode kann die entsprechende
 * Referenz der Maschine in der addMachine()-Methode übergeben werden
 */
void Machine::setFactory(Factory *f) {
    factory = f;
}


