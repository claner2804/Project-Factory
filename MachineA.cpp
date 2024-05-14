//
// Created by Claudia Steiner on 14.05.24.
//

#include "MachineA.h"

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
    int random = rand() % 100;
    //hat eine 15% Wahrscheinlichkeit eine MachineFailureException zu werfen.
    if (random < 15) {
        throw MachineFailureException("MachineA::tick Machine Failure Exception");
        //hat eine 2% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
    } else if (random < 17) {
        throw MachineExplosionException("MachineA::tick Machine Explosion Exception");
    }
    //produkt A wird um 2 erhöht
    //todo: this->productA += 2;
}
