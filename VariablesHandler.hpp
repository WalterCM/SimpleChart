
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
    void increase(int v)
    {
        switch(v) {
            case A:
                if (a + 0.1 < m)
                    a += 0.1;
                break;
            case B:
                if (b + 0.1 < c)
                    b += 0.1;
                break;
            case C:
                if (c + 0.1 < d)
                c += 0.1;
                break;
            case D:
                d += 0.1;
                break;
            case M:
                if (m + 0.1 < b)
                    m += 0.1;
                break;
            case K:
                k += 0.1;
                break;
            default:break;
        }
    }

    void decrease(int v)
    {
        switch(v) {
            case A:
                a -= 0.1;
                break;
            case B:
                if (b - 0.1 > m)
                    b -= 0.1;
                break;
            case C:
                if (c - 0.1 > b)
                    c -= 0.1;
                break;
            case D:
                if (d - 0.1 > c)
                    d -= 0.1;
                break;
            case M:
                if (m - 0.1 > a)
                    m -= 0.1;
                break;
            case K:
                k -= 0.1;
                break;
            default:break;
        }
    }

    std::array<std::string, SIMPLE_NUMBER_OPTIONS> getVariableString()
    {
        std::stringstream aString, bString, cString, dString, mString, kString;
        aString << std::fixed << std::setprecision(1) << a;
        bString << std::fixed << std::setprecision(1) << b;
        cString << std::fixed << std::setprecision(1) << c;
        dString << std::fixed << std::setprecision(1) << d;
        mString << std::fixed << std::setprecision(1) << m;
        kString << std::fixed << std::setprecision(1) << k;
        variableString[0] = aString.str();
        variableString[1] = bString.str();
        variableString[2] = cString.str();
        variableString[3] = dString.str();
        variableString[4] = mString.str();
        variableString[5] = kString.str();

        return variableString;
    }

    void randomize(Variable v)
    {
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
        }
    }

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
