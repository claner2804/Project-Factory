//
// Created by Claudia Steiner on 14.05.24.
//

#include "MachineA.h"
#include "ProductA.h"
#include <stdlib.h>

/*
 * MachineA:
▪ Produziert pro Zeitschritt 2 Einheiten von Produkt A.
▪ Hat eine 15% Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 2% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */

MachineA::MachineA() {
    std::cout << "MachineA created" << std::endl;
}

MachineA::~MachineA() {
    std::cout << "MachineA destroyed" << std::endl;
}


//Produziert pro Zeitschritt 2 Einheiten von Produkt A.
void MachineA::tick() {
    std::cout << "MachineA tick" << std::endl;
    if (status > 0) {
        std::cout << "Machine A is still damaged" << std::endl;
        status--;
    } else if (status ==0) {
    int random = rand() % 100;
    //hat eine 2% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
    if (random < 2) {
        status = -1;
        throw MachineExplosionException("MachineA::tick Machine Explosion Exception");
        //hat eine 15% Wahrscheinlichkeit eine MachineFailureException zu werfen.
    } else if (random < 15) {
        status = 3;
        throw MachineFailureException("MachineA::tick Machine Failure Exception");
    } else {
        std::cout << "Machine A is producing" << std::endl;
        factory->addProduct(new ProductA());
        factory->addProduct(new ProductA());
    }
}
}