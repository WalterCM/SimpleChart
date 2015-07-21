
#ifndef SIMPLECHART_FUNCTIONS_HPP
#define SIMPLECHART_FUNCTIONS_HPP

#include <cstdlib>
#include <ctime>

enum Function {
    Triangular,
    FuncionR,
    FuncionG,
    FuncionS,
    Gausiana,
    Trapezoidal,
    PseudoExponencial
};

const float e = 2.71828f;

static float triangular(float x, VariablesHandler variables) {

    if (x > variables.a && x <= variables.m)    return (x - variables.a) / (variables.m - variables.a);
    if (x > variables.m && x < variables.b)     return (variables.b - x) / (variables.b - variables.m);
    else                                        return 0;
}

static float funcionR(float x, VariablesHandler variables) {
    if (x <= variables.a) return 0;
    if (x > variables.a)  return 1 - (float)pow(e, - variables.k * pow(x - variables.a, 2));
}

static float funcionG(float x, VariablesHandler variables) {
    if (x <= variables.a)                   return 0;
    if (x > variables.a && x < variables.m) return (x - variables.a) / (variables.m - variables.a);
    else                                    return 1;
}

static float funcionS(float x, VariablesHandler variables) {
    if (x <= variables.a)                           return 0;
    if (x > variables.a && x <= variables.m)        return 2 * (float)pow((x - variables.a) / (variables.b - variables.a), 2);
    if (x > variables.m && x < variables.b)         return 1 - 2 * (float)pow((x - variables.b) / (variables.b - variables.a), 2);
    else                                            return 1;
}

static float gausiana(float x, VariablesHandler variables) {
    return (float)pow(e, - variables.k * pow(x - variables.m, 2));
}

static float trapezoidal(float x, VariablesHandler variables) {
    if (x <= variables.a || x >= variables.d)   return 0;
    if (x > variables.a && x <= variables.b)    return (x - variables.a) / (variables.b - variables.a);
    if (x > variables.b && x < variables.c)     return  1;
    else                                        return (variables.d - x) / (variables.d - variables.c);
}

static float pseudoExponencial(float x, VariablesHandler variables) {
    return 1 / (1 + variables.k * (float)pow(x - variables.m, 2));
}

#endif //SIMPLECHART_FUNCTIONS_HPP
