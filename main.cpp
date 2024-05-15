#include <iostream>
#include "Machine.h"
#include "Factory.h"
#include "Machine.h"
#include "MachineA.h"
#include "MachineB.h"
#include <ctime>
#include "Product.h"
#include "ProductA.h"
#include "ProductB.h"


int main() {

    std::srand(std::time(nullptr));


    Factory factory;

    MachineA* m1 = new MachineA();
    m1->setFactory(&factory);

    MachineB* m2 = new MachineB();
    m2->setFactory(&factory);


    factory.run(1);





    return 0;
}
