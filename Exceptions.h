//
// Created by Claudia Steiner on 14.05.24.
//

#ifndef ALTKLAUSUREN_EXCEPTIONS_H
#define ALTKLAUSUREN_EXCEPTIONS_H

#include <stdexcept>
#include <string>
#include <iostream>

//klasse FactoryException erbt von runtime_error und gibt die Fehlermeldung dessen Konstruktor
class FactoryException : public std::runtime_error {
public:
    explicit FactoryException(const std::string& message) : std::runtime_error(message) {}
};


class MachineFailureException : public FactoryException {
public:
    explicit MachineFailureException(const std::string& message) : FactoryException(message) {}

};


class MachineExplosionException : public FactoryException {
public:
    explicit MachineExplosionException(const std::string& message) : FactoryException(message) {}
};


#endif //ALTKLAUSUREN_EXCEPTIONS_H
