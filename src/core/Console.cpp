#include "core/Console.h"
#include <iostream>

#ifdef _WIN32
#include <cstdlib>
#else
#include <cstdlib>
#endif

void Console::clear() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Console::pause() {
    std::cout << "\n(Devam etmek için ENTER)\n";
    std::cin.ignore(1000000, '\n');
    std::cin.get();
}
