//
// Created by Claudia Steiner on 14.05.24.
//

#include "Factory.h"
#include "Machine.h"
#include "Product.h"
#include "Exceptions.h"

/*
 * Die Klasse Factory repräsentiert die Fabrik und
 * implementiert die Simulation. Sie verwaltet die Maschinen,
 * d.h. sie übernimmt für diese die Object Ownership.
 * Da immer wieder neue Maschinen hinzugefügt und alte entfernt
 * werden, soll die Maschinenverwaltung über einen
 * dynamische Datencontainer erfolgen. Wählen Sie
 * selbstständig einen passenden Datencontainer aus.
 *
 * Des Weiteren verwaltet auch die Fabrik auch die Lager
 * der Produkte, d.h. auch hier übernimmt sie für diese
 * die Object Ownership. Für jeden Produkttypen soll es
 * ein eigenes Lager geben, die durch separate dynamische
 * Datencontainer repräsentiert werden. Wählen Sie selbstständig
 * passende Datencontainer aus.
 */

Factory::Factory() {
    std::cout << "Factory created" << std::endl;
}

Factory::~Factory() {
    std::cout << "Factory destroyed" << std::endl;
}

//Fügt eine neuen Maschine hinzu. Der Rückgabewert ist eine ID, die die jeweilige Maschine eindeutig identifiziert.
unsigned Factory::addMachine(Machine *m) {
    // Füge Maschine hinzu
    machines.insert(std::make_pair(machines.size(), m));

    // Gebe die ID der Maschine zurück
    unsigned id = machines.size() - 1;
    return id;
}


//Gibt die Maschine mit der angegebenen ID zurück.
Machine *Factory::getMachine(unsigned int id) {
    // Get machine with id
    return machines.at(id);
}


//Entfernt die Maschine mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
void Factory::deleteMachine(unsigned int id) {
    // Lösche Maschine
    machines.erase(id);

    // Gebe die ID der gelöschten Maschine zurück
    std::cout << "Machine with ID " << id << " deleted" << std::endl;

    // Gibt alle damit verbundenen Ressourcen wieder frei
    delete machines.at(id);
}


//Übergibt ein neues Produkt der Fabrik.
// Die Fabrik muss dann den Typ des Produkts
// bestimmen und in das entsprechende Lager
// einsortieren. Wenn ein unbekanntes Produkt
// übergeben wird, dann soll eine MachineFailureException
// geworfen werden.
void Factory::addProduct(Product *p) {
    //wenn Produkttyp A
    if (p->getType() == 1) {
        // Füge Produkt hinzu zu Vector productsA
        productsA[p->getName()].push_back(p);

        // Gebe den Namen des Produkts zurück
        std::cout << "Product " << p->getName() << " with type " << p->getType() << " added to Vector productsA." << std::endl;

        } else if (p->getType() == 2) {
        // Füge Produkt hinzu zu Vector productsB
        productsB[p->getName()].push_back(p);

        // Gebe den Namen des Produkts zurück
        std::cout << "Product " << p->getName() << " with type " << p->getType() << " added to Vector productsB." << std::endl;

        } else { //wenn unbekannter Produkttyp
        throw MachineFailureException("Unknown product type!");
    }

}



