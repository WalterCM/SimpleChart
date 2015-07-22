
#ifndef SIMPLECHART_FUZZY_LOGIC_FUNCTIONS_HPP
#define SIMPLECHART_FUZZY_LOGIC_FUNCTIONS_HPP

class VariablesHandler;

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
class Functions {
public:
    static float triangular(float, VariablesHandler);
    static float funcionR(float, VariablesHandler);
    static float funcionG(float, VariablesHandler);
    static float funcionS(float, VariablesHandler);
    static float gausiana(float, VariablesHandler);
    static float trapezoidal(float, VariablesHandler);
    static float pseudoExponencial(float, VariablesHandler);

};





#endif //SIMPLECHART_FUZZY_LOGIC_FUNCTIONS_HPP
