#include <iostream>
#include "Machine.h"
#include "Factory.h"
#include "Machine.h"
#include "MachineA.h"
#include "MachineB.h"
#include "Product.h"
#include "ProductA.h"
#include "ProductB.h"


int main() {

    Factory factory;

    MachineA machineA;
    MachineB machineB;

    factory.addMachine(&machineA);
    factory.addMachine(&machineB);




    factory.run(2);



    return 0;
}
