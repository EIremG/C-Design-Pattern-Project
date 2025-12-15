#include "core/Console.h"
#include <cstdlib>

namespace Console {
    void clear() {
#ifdef _WIN32
        std::system("cls");
#else
        std::system("clear");
#endif
    }
}
