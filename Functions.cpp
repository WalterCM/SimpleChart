
#include <cmath>
#include "Functions.hpp"
#include "VariablesHandler.hpp"


float Functions::triangular(float x, VariablesHandler variables)
{
    if (x > variables.getA() && x <= variables.getM())
        return (x - variables.getA()) / (variables.getM() - variables.getA());
    if (x > variables.getM() && x < variables.getB())
        return (variables.getB() - x) / (variables.getB() - variables.getM());
    else
        return 0;
}

float Functions::funcionR(float x, VariablesHandler variables) {
    if (x <= variables.getA())
        return 0;
    if (x > variables.getA())
        return 1 - (float)pow(e, - variables.getK() * pow(x - variables.getA(), 2));
}

float Functions::funcionG(float x, VariablesHandler variables) {
    if (x <= variables.getA())
        return 0;
    if (x > variables.getA() && x < variables.getM())
        return (x - variables.getA()) / (variables.getM() - variables.getA());
    else
        return 1;
}

float Functions::funcionS(float x, VariablesHandler variables) {
    if (x <= variables.getA())
        return 0;
    if (x > variables.getA() && x <= variables.getM())
        return 2 * (float)pow((x - variables.getA()) / (variables.getB() - variables.getA()), 2);
    if (x > variables.getM() && x < variables.getB())
        return 1 - 2 * (float)pow((x - variables.getB()) / (variables.getB() - variables.getA()), 2);
    else
        return 1;
}

float Functions::gausiana(float x, VariablesHandler variables) {
    return (float)pow(e, - variables.getK() * pow(x - variables.getM(), 2));
}

float Functions::trapezoidal(float x, VariablesHandler variables) {
    if (x <= variables.getA() || x >= variables.getD())
        return 0;
    if (x > variables.getA() && x <= variables.getB())
        return (x - variables.getA()) / (variables.getB() - variables.getA());
    if (x > variables.getB() && x < variables.getC())
        return  1;
    else
        return (variables.getD() - x) / (variables.getD() - variables.getC());
}

float Functions::pseudoExponencial(float x, VariablesHandler variables) {
    return 1 / (1 + variables.getK() * (float)pow(x - variables.getM(), 2));
}