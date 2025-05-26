#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

class IMediciones {
public:
    virtual void serializar(std::ofstream& out) const = 0;
    virtual void deserializar(std::ifstream& in) = 0;
    virtual ~IMediciones() = default;
};