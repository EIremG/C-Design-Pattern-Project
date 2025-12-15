#include "core/App.h"
#include "core/MenuController.h"
#include "core/IAppServices.h"
#include "tests/TestRunner.h"
#include <string>

int main(int argc, char** argv) {
    if (argc >= 2) {
        std::string arg = argv[1];
        if (arg == "-test") {
            return runAllTests(); // LLR39 :contentReference[oaicite:4]{index=4}
        }
    }

    MenuController menu;
    NullAppServices services;

    App app(services, menu);
    return app.run();
}
