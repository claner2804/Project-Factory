cmake_minimum_required(VERSION 3.27)
project(Altklausuren)

set(CMAKE_CXX_STANDARD 17)

add_executable(Altklausuren main.cpp
        Factory.h
        Factory.cpp
        Machine.h
        Machine.cpp
        MachineA.h
        MachineA.cpp
        MachineB.h
        MachineB.cpp
        Product.h
        Product.cpp
        ProductA.h
        ProductA.cpp
        ProductB.h
        ProductB.cpp
        Exceptions.h)
