
#ifndef SIMPLECHART_VARIABLESHANDLER_HPP
#define SIMPLECHART_VARIABLESHANDLER_HPP

#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include <iomanip>
#include "ProgramConstants.hpp"


enum Variable {
    A,
    B,
    C,
    D,
    M,
    K
};

class VariablesHandler {
public:
    VariablesHandler()
    {
        srand(time(0));
    }
    void increase(int v);
    void decrease(int v);

    std::array<std::string, SIMPLE_NUMBER_OPTIONS> getVariableString();

    void randomize(Variable v);

    float a = 1;
    float b = 3;
    float c = 4;
    float d = 5;
    float m = 2;
    float k = 1;
private:
    std::array<std::string, SIMPLE_NUMBER_OPTIONS> variableString;
    const float MAX_NUMBER = 6;
};

#endif //SIMPLECHART_VARIABLESHANDLER_HPP
