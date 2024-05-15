//
// Created by Claudia Steiner on 14.05.24.
//

#include "Factory.h"
#include "Machine.h"
#include "Product.h"
#include "Exceptions.h"
#include <unistd.h>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

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

Factory::~Factory(){

    // Gebe die Anzahl der Produkte A zurück
    std::cout << "Product A count: " << productsA.size() << std::endl;

    // Gebe die Anzahl der Produkte B zurück
    std::cout << "Product B count: " << productsB.size() << std::endl;

    // Gebe die Anzahl der Maschinen zurück
    std::cout << "Machine count: " << machines.size() << std::endl;

    //alle Maschinen löschen
    machines.clear();

    //alle Produkte A löschen
    for(auto& productPtr : productsA) {
        productPtr.reset();
    }
    std::cout << "Product A count: " << productsA.size() << std::endl;
    productsA.clear();







    std::cout << "Factory destroyed" << std::endl;
}










//Fügt eine neuen Maschine hinzu. Der Rückgabewert ist eine ID, die die jeweilige Maschine eindeutig identifiziert.
unsigned Factory::addMachine(Machine *m) {
    if (m) {

        //nextId wird auf 0 gesetzt
        static unsigned int nextId = 0;

        // Gebe den Namen der Maschine zurück
        std::cout << "Machine " << m->getName() << " added to Factory!" << std::endl;


        // Dies ist eine map mit der ID als Key und shared_ptr auf die Maschine m als Wert
        machines.insert({nextId, std::shared_ptr<Machine>(m)});

        return nextId++;

    }
}


//Gibt die Maschine mit der angegebenen ID zurück.
Machine *Factory::getMachine(unsigned int id) {

    // Wenn die Maschine nicht gefunden wird, wird eine Exception geworfen
    if (machines.find(id) == machines.end()) {
        throw UnknownMachineIDException("Machine *Factory::getMachine - Unknown Machine ID!");
    } else {
        return machines[id].get();
    }
}


//Entfernt die Maschine mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
void Factory::deleteMachine(unsigned int id) {
    if (machines.find(id) == machines.end()) {
        throw UnknownMachineIDException("Machine *Factory::deleteMachine - Unknown Machine ID!");
    } else {
        // Print a message
        std::cout << "Machine with ID " << id << " deleted" << std::endl;
        // Erase the shared_ptr from the map. The Machine object will be automatically deleted.
        machines.erase(id);
    }
}


//Übergibt ein neues Produkt der Fabrik.
// Die Fabrik muss dann den Typ des Produkts
// bestimmen und in das entsprechende Lager
// einsortieren. Wenn ein unbekanntes Produkt
// übergeben wird, dann soll eine MachineFailureException
// geworfen werden.
void Factory::addProduct(Product *p) {

    // Create a shared_ptr from the raw pointer
    std::shared_ptr<Product> productPtr(p);

    //wenn Produkttyp A
    if (p->getType() == 1) {

        // Füge Produkt hinzu zu Vector productsA, dieser ist mit shard_ptr auf die Produkte
        productsA.push_back(productPtr);

        //zähle die Anzahl der Produkte A
        productACount++;

        // Gebe den Namen des Produkts zurück
        std::cout << "Product " << p->getName() << " with type " << p->getType() << " added to Vector productsA." << std::endl;

        } else if (p->getType() == 2) {
        // Füge Produkt hinzu zu Vector productsB
        productsB.push_back(productPtr);

        //zähle die Anzahl der Produkte B
        productBCount++;

        // Gebe den Namen des Produkts zurück
        std::cout << "Product " << p->getName() << " with type " << p->getType() << " added to Vector productsB." << std::endl;

        } else { //wenn unbekannter Produkttyp
        throw MachineFailureException("Factory::addProduct Unknown product type!");
    }

}


//Gibt die Anzahl der im Lager vorhandenen Produkte A zurück.
unsigned Factory::getProductACount() {
    //oder auch: return productACount;
    return productsA.size();
}


//Gibt die Anzahl der im Lager vorhandenen Produkte B zurück.
unsigned Factory::getProductBCount() {
    //oder auch: return productBCount;
    return productsB.size();
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

    //solange die Iterationen größer gleich 1 sind
    while( iterations >= 1) {

        std::cout << "--------------------------------" << std::endl;

        // Gebe die aktuelle Iteration zurück
        std::cout << "Iteration: " << iterations << std::endl;

        // Durchlaufe alle Maschinen
        std::cout << "durchlaufe alle Maschinen..." << std::endl;

        //einen vektor erstellen mit den maschinen damit dann alle einfach gelöscht werden können
        std::vector<unsigned> machinesToRemove;

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
                std::cout << "Machine " << machine.second->getName() << " Explosion! Machine permanently broken and removed from factory." << std::endl;
                // Maschine in den Vektor hinzufügen, damit sie später einfach gelöscht werden kann
                machinesToRemove.push_back(machine.first);
            }
        }

        // wenn machinesToRemove nicht leer ist, dann lösche die Maschinen


        for (auto id : machinesToRemove) {
            std::cout << " Removing machine " << id << std::endl;
            deleteMachine(id);
        }

        if (iterations > 0) {
            //interationen runterzählen
            iterations --;
        }


        //für praktische Gründe eine Sekunde schlafen
        sleep(1);
    }
}






