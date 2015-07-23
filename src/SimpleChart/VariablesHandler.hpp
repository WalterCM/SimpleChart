
#ifndef SIMPLECHART_VARIABLESHANDLER_HPP
#define SIMPLECHART_VARIABLESHANDLER_HPP

#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include <iomanip>
#include <vector>
#include "../ProgramConstants.hpp"


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
    VariablesHandler(int function, int scale);

    void increase(int v);
    void decrease(int v);
    void randomize(int v);

    void fixM();
    void setScale(int scale);

    float getA() {  return variable[A]; }
    float getB() {  return variable[B]; }
    float getC() {  return variable[C]; }
    float getD() {  return variable[D]; }
    float getM() {  return variable[M]; }
    float getK() {  return variable[K]; }

    std::vector<std::string> getVariableString();
    std::vector<int> index;
private:
    int function;
    float variable[6] = {1, 3, 4, 5, 2, 1};
    int maxRandom;
    int minRandom;
};

#endif //SIMPLECHART_VARIABLESHANDLER_HPP
