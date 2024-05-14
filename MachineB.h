//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_MACHINEB_H
#define ALTKLAUSUREN_MACHINEB_H

#include <iostream>
#include "Machine.h"
#include "Exceptions.h"

/*
 * MachineB
▪ Produziert pro Zeitschritt 3 Einheiten von Produkt A.
▪ Hat eine 20% Wahrscheinlichkeit eine MachineFailureException zu werfen.
▪ Hat eine 5% Wahrscheinlichkeit eine MachineExplosionException zu werfen.
 */

class MachineB : public Machine{

public:
    MachineB();
    ~MachineB();

    void tick() override;

};


#endif //ALTKLAUSUREN_MACHINEB_H
