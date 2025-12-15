#include "core/App.h"
#include "core/MenuController.h"
#include "core/AppServices.h"
#include <string>
#include "../tests/TestRunner.h"

int main(int argc, char** argv) {
    if (argc >= 2) {
        std::string arg = argv[1];
        if (arg == "-test") {
            return runAllTests(); // LLR39 :contentReference[oaicite:4]{index=4}
        }
    }

    MenuController menu;
    AppServices services;

    App app(services, menu);
    return app.run();
}
