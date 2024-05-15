//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_MACHINEA_H
#define ALTKLAUSUREN_MACHINEA_H

#include <iostream>
#include <exception>
#include "Machine.h"
#include "Exceptions.h"

/*
 * MachineA:
▪ Produziert pro Zeitschritt 2 Einheiten von Produkt A.
▪ Hat eine 15% Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 2% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */

class MachineA : public Machine{


public:
    MachineA();
    ~MachineA();

    //Produziert pro Zeitschritt 2 Einheiten von Produkt A.
    void tick() override;

    std::string getName() override {
        return "MachineA";
    }


};


#endif //ALTKLAUSUREN_MACHINEA_H
