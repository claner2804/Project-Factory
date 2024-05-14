//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_FACTORY_H
#define ALTKLAUSUREN_FACTORY_H

#include "Product.h"
#include <iostream>
#include "Exceptions.h"
#include <vector>
#include <memory>
#include <map>
#include "Machine.h"


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

//Forward declaration
class Machine;

class Factory {
private:
    //Datencontainer für Maschinen, Map weil ID
    std::map<unsigned, Machine*> machines;

    //Datencontainer für Produkte A und B, Vectoren
    std::map<std::string, std::vector<Product*>> productsA;

    std::map<std::string, std::vector<Product*>> productsB;


public:
    Factory();
    ~Factory();

    //Fügt eine neuen Maschine hinzu. Der Rückgabewert ist eine ID, die die jeweilige Maschine eindeutig identifiziert.
    unsigned addMachine(Machine* m);

    //Gibt die Maschine mit der angegebenen ID zurück.
    Machine* getMachine(unsigned id);

    //Entfernt die Maschine mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
    void deleteMachine(unsigned id);

    //Übergibt ein neues Produkt der Fabrik.
    // Die Fabrik muss dann den Typ des Produkts
    // bestimmen und in das entsprechende Lager
    // einsortieren. Wenn ein unbekanntes Produkt
    // übergeben wird, dann soll eine MachineFailureException
    // geworfen werden.
    void addProduct(Product* p);



};


#endif //ALTKLAUSUREN_FACTORY_H
