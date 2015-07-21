
#ifndef SIMPLECHART_VARIABLESHANDLER_HPP
#define SIMPLECHART_VARIABLESHANDLER_HPP

#include <cstdlib>
#include <ctime>

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
                a++;
                break;
            case B:
                b++;
                break;
            case C:
                c++;
                break;
            case D:
                d++;
                break;
            case M:
                m++;
                break;
            case K:
                k++;
                break;
            default:break;
        }
    }

    void decrease(int v)
    {
        switch(v) {
            case A:
                a--;
                break;
            case B:
                b--;
                break;
            case C:
                c--;
                break;
            case D:
                d--;
                break;
            case M:
                m--;
                break;
            case K:
                k--;
                break;
            default:break;
        }
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

    const float MAX_NUMBER = 6;
};

#endif //SIMPLECHART_VARIABLESHANDLER_HPP
