
#include <cmath>
#include "Functions.hpp"
#include "VariablesHandler.hpp"

float Functions::triangular(float x, VariablesHandler variables)
{

if (x > variables.a && x <= variables.m)    return (x - variables.a) / (variables.m - variables.a);
if (x > variables.m && x < variables.b)     return (variables.b - x) / (variables.b - variables.m);
else                                        return 0;
}

float Functions::funcionR(float x, VariablesHandler variables) {
    if (x <= variables.a) return 0;
    if (x > variables.a)  return 1 - (float)pow(e, - variables.k * pow(x - variables.a, 2));
}

float Functions::funcionG(float x, VariablesHandler variables) {
    if (x <= variables.a)                   return 0;
    if (x > variables.a && x < variables.m) return (x - variables.a) / (variables.m - variables.a);
    else                                    return 1;
}

float Functions::funcionS(float x, VariablesHandler variables) {
    if (x <= variables.a)                           return 0;
    if (x > variables.a && x <= variables.m)        return 2 * (float)pow((x - variables.a) / (variables.b - variables.a), 2);
    if (x > variables.m && x < variables.b)         return 1 - 2 * (float)pow((x - variables.b) / (variables.b - variables.a), 2);
    else                                            return 1;
}

float Functions::gausiana(float x, VariablesHandler variables) {
    return (float)pow(e, - variables.k * pow(x - variables.m, 2));
}

float Functions::trapezoidal(float x, VariablesHandler variables) {
    if (x <= variables.a || x >= variables.d)   return 0;
    if (x > variables.a && x <= variables.b)    return (x - variables.a) / (variables.b - variables.a);
    if (x > variables.b && x < variables.c)     return  1;
    else                                        return (variables.d - x) / (variables.d - variables.c);
}

float Functions::pseudoExponencial(float x, VariablesHandler variables) {
    return 1 / (1 + variables.k * (float)pow(x - variables.m, 2));
}