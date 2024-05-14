//
// Created by Claudia Steiner on 14.05.24.
//

#include "MachineB.h"
#include "ProductB.h"

/*
 * MachineB
▪ Produziert pro Zeitschritt 3 Einheiten von Produkt A.
▪ Hat eine 20% Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 5% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */

MachineB::MachineB() {
    std::cout << "MachineB created" << std::endl;
}

MachineB::~MachineB() {
    std::cout << "MachineB destroyed" << std::endl;
}

//Produziert pro Zeitschritt 3 Einheiten von Produkt A.
void MachineB::tick() {
    std::cout << "MachineB tick" << std::endl;
    int random = rand() % 100;
    //hat eine 20% Wahrscheinlichkeit eine MachineFailureException zu werfen.
    if (random < 20) {
        throw MachineFailureException("MachineB::tick Machine Failure Exception");
        //hat eine 5% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
    } else if (random < 25) {
        throw MachineExplosionException("MachineB::tick Machine Explosion Exception");
    }
    //produkt B wird um 3 erhöht
    factory->addProduct(new ProductB);
    factory->addProduct(new ProductB);
    factory->addProduct(new ProductB);
}