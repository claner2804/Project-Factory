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
    std::cout << "MachineB Destruktor machine b cpp" << std::endl;
}

//Produziert pro Zeitschritt 3 Einheiten von Produkt B.
void MachineB::tick() {
    std::cout << "Machine B tick" << std::endl;
    if (status > 0) {
        std::cout << "Machine B is still damaged" << std::endl;
        status--;
    } else if (status ==0) {
        int random = rand() % 100;
        //hat eine 5% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
        if (random < 5) {
            status = -1;
            throw MachineExplosionException("MachineB::tick Machine Explosion Exception");
            //hat eine 20% Wahrscheinlichkeit eine MachineFailureException zu werfen.
        } else if (random < 20) {
            status = 3;
            throw MachineFailureException("MachineB::tick Machine Failure Exception");
        } else {
            std::cout << "Machine A is producing" << std::endl;
            factory->addProduct(new ProductB());
            factory->addProduct(new ProductB());
            factory->addProduct(new ProductB());
        }
    }
}