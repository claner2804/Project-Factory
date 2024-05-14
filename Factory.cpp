//
// Created by Claudia Steiner on 14.05.24.
//

#include "Factory.h"
#include "Machine.h"
#include "Product.h"
#include "Exceptions.h"
#include <unistd.h>

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


    for (auto &machine : machines) {
        delete machine.second;
    }
    // Lösche alle Produkte A
    for (auto &product : productsA) {
        for (auto &p : product.second) {
            delete p;
        }
    }
    // Lösche alle Produkte B
    for (auto &product : productsB) {
        for (auto &p : product.second) {
            delete p;
        }
    }
}

//Fügt eine neuen Maschine hinzu. Der Rückgabewert ist eine ID, die die jeweilige Maschine eindeutig identifiziert.
unsigned Factory::addMachine(Machine *m) {
    if (m) {

        // Setze die Referenz der Maschine auf die Fabrik
        m->setFactory(this);

        // Gebe den Namen der Maschine zurück
        std::cout << "Machine " << m->getName() << " added to Factory!" << std::endl;

        // Füge Maschine hinzu zu Map machines
        machines.insert(std::make_pair(machines.size(), m));

        // Gebe die ID der Maschine zurück
        unsigned id = machines.size() - 1;
        return id;

    }
}


//Gibt die Maschine mit der angegebenen ID zurück.
Machine *Factory::getMachine(unsigned int id) {
    // Get machine with id
    return machines.at(id);
}


//Entfernt die Maschine mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
void Factory::deleteMachine(unsigned int id) {
    // Delete machine from memory
    delete machines.at(id);

    // Remove machine from map
    machines.erase(id);

    // Print the ID of the deleted machine
    std::cout << "Machine with ID " << id << " deleted" << std::endl;
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


//Gibt die Anzahl der im Lager vorhandenen Produkte A zurück.
unsigned Factory::getProductACount() {
    // Gebe die Anzahl der Produkte A zurück
    return productsA["ProductA"].size();
}


//Gibt die Anzahl der im Lager vorhandenen Produkte B zurück.
unsigned Factory::getProductBCount() {
    // Gebe die Anzahl der Produkte B zurück
    return productsB["ProductB"].size();
}



//Diese Methode implementiert die Zeitschleife.
// Der Eingabeparameter iterations gibt an, nach wievielen
// Iterationen die Zeitschleife abgebrochen werden soll
// (0 bedeutet, dass die Schleife nie abgebrochen wird).

/*
 *In jeder Iteration der Zeitschleife wird für jede
 * einzelne Maschine die tick()-Methode aufgerufen.
 * In der tick()-Methode werden dann die entsprechenden
 * Produkte erzeugt und der Fabrik mithilfe der
 * addProduct()-Methode übergeben. Mit einer
 * gewissen Wahrscheinlichkeit kann es passieren,
 * dass es zu einem Fehler kommt (d.h. es werden keine Produkte
 * erzeugt).
 * Ein Machine Failure (repräsentiert durch eine MachineFailureException)
 * bedeutet, dass die betreffende Maschine für die nächsten 3 Ticks
 * keine Produkte produzieren kann. Eine Machine Explosion
 * (repräsentiert durch eine MachineExplosionException) bedeutet,
 * dass die entsprechende Machine permanent kaputt ist und aus der
 * Fabrik entfernt werden muss.
 *
 * Lassen Sie aus praktischen Gründen nach jeder
 * Iteration die Zeitschleife mindestens eine Sekunde
 * schlafen (mit sleep()).
 */

void Factory::run(unsigned int iterations) {

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Event-Loop started" << std::endl;
    // Schleife
    while( iterations >= 1) {

        std::cout << "--------------------------------" << std::endl;

        // Gebe die aktuelle Iteration zurück
        std::cout << "Iteration: " << iterations << std::endl;

        // Durchlaufe alle Maschinen
        std::cout << "durchlaufe alle Maschinen..." << std::endl;

        for (auto &machine : machines) {
            try {
                std::cout << " --->  " << machine.second->getName() << " wird geprüft!" << std::endl;
                // Rufe tick() Methode auf
                machine.second->tick();
            } catch (const MachineFailureException& e) {
                // Ausgabe der Fehlermeldung
                std::cout << "Machine " << machine.second->getName() << " Failure! No products will be produced for the next 3 ticks." << std::endl;
            } catch (const MachineExplosionException& e) {
                // Ausgabe der Fehlermeldung
                std::cout << "Machine " << machine.second << " Explosion! Machine permanently broken and removed from factory." << std::endl;
                // Entferne Maschine
                deleteMachine(machine.first);
            }
        }

        //interationen runterzählen
        iterations --;
        //für praktische Gründe eine Sekunde schlafen
        sleep(1);
    }
}




