
#include <iostream>
#include "Program.hpp"

int main()
{
    try {
        Program program;
        program.run();
    } catch (std::exception& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}

