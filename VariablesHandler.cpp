
#include "VariablesHandler.hpp"
#include "Functions.hpp"

VariablesHandler::VariablesHandler(int function)
{
    srand(time(0));
    this->function = function;
    switch (function) {
        case Triangular:
            index.push_back(A);
            index.push_back(M);
            index.push_back(B);
            break;
        case FuncionR:
            index.push_back(A);
            index.push_back(K);
            break;
        case FuncionG:
            index.push_back(A);
            index.push_back(M);
            break;
        case FuncionS:
            index.push_back(A);
            index.push_back(M);
            index.push_back(B);
            break;
        case Gausiana:
            index.push_back(M);
            index.push_back(K);
            break;
        case Trapezoidal:
            index.push_back(A);
            index.push_back(B);
            index.push_back(C);
            index.push_back(D);
            break;
        case PseudoExponencial:
            index.push_back(M);
            index.push_back(K);
            break;
        default:break;
    }

}

void VariablesHandler::increase(int v)
{
    int w = index[v];
    if (w == index.back() || w == K)
        variable[w] += VARIABLE_DELTA;
    else
        if (variable[index[v]] + VARIABLE_DELTA <= variable[index[v + 1]] || index[v + 1] == K)
            variable[w] += VARIABLE_DELTA;
    if (function == FuncionS)
        fixM();
}

void VariablesHandler::decrease(int v)
{
    int w = index[v];
    if (w == index.front() || w == A || w == K)
        variable[w] -= VARIABLE_DELTA;
    else
        if (variable[index[v]] - VARIABLE_DELTA >= variable[index[v - 1]])
            variable[w] -= VARIABLE_DELTA;
    if (function == FuncionS)
        fixM();
}

void VariablesHandler::randomize(int v)
{
    int w = index[v];
    if (w == K || (w == index.front() && index[v + 1] == K)) {
        variable[w] = (rand() % (MAX_RANDOM - MIN_RANDOM) + MIN_RANDOM) / 10.0f;
    } else if (w == index.back() || index[v + 1] == K) {
        int minRandom = (int) (variable[index[v - 1]] * 10);
        variable[w] = (rand() % (MAX_RANDOM - minRandom) + minRandom) / 10.0f;
    } else if (w == index.front()) {
        int maxRandom = (int) (variable[index[v + 1]] * 10);
        variable[w] = (rand() % (maxRandom - MIN_RANDOM) + MIN_RANDOM) / 10.0f;
    } else {
        int minRandom = (int) (variable[index[v - 1]] * 10);
        int maxRandom = (int) (variable[index[v + 1]] * 10);
        variable[w] = (rand() % (maxRandom - minRandom) + minRandom) / 10.0f;
    }

    if (function == FuncionS)
        fixM();
}

float VariablesHandler::fixM()
{
    variable[M] = (variable[A] + variable[B]) / 2;
}

std::vector<std::string> VariablesHandler::getVariableString()
{
    std::vector<std::string> variableString;
    for (int i = 0; i < index.size(); i++) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) << variable[index[i]];
        variableString.push_back(ss.str());
    }

    return variableString;
}





