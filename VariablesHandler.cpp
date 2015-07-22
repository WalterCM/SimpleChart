
#include "VariablesHandler.hpp"
#include "Functions.hpp"

VariablesHandler::VariablesHandler(int function)
{
    srand(time(0));
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
    else {
        int i;
        for (i = 0; w != index[i]; i++);
        if (variable[index[i]] + VARIABLE_DELTA <= variable[index[i + 1]])
            variable[w] += VARIABLE_DELTA;
    }
}

void VariablesHandler::decrease(int v)
{
    int w = index[v];
    if (w == index.front() || w == A || w == K)
        variable[w] -= VARIABLE_DELTA;
    else {
        int i;
        for (i = 0; w != index[i]; i++);
        if (variable[index[i]] - VARIABLE_DELTA >= variable[index[i - 1]])
            variable[w] -= VARIABLE_DELTA;
    }
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

void VariablesHandler::randomize(Variable v)
{/*
    switch(v) {
        case A:
            a = rand() % (int)m;
            break;
        case B:
            b = rand() % (int)(c - m) + m;
            break;
        case C:
            c = rand() % (int)(d - b) + b;
            break;
        case D:
            d = rand() % (int)(MAX_NUMBER - c) + c;
            break;
        case M:
            m = rand() % (int)(b - a) + a;
            break;
        case K:
            k = rand() % (int)(MAX_NUMBER);
            break;
    }*/
}


