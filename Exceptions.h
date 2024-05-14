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
    FactoryException(const std::string& message) : std::runtime_error(message) {}
};

/*
class InvalidArgument : public RobotException {
public:
    using RobotException::RobotException;
};
 */



#endif //ALTKLAUSUREN_EXCEPTIONS_H
