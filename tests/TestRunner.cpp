#include "tests/TestRunner.h"
#include "tests/TinyTest.h"
#include "core/Input.h"

int runAllTests() {
    TinyTest t("test_report.txt");

    int v = 0;
    t.expectTrue(Input::parseInt("12", v) && v == 12, "parseInt valid");
    t.expectTrue(!Input::parseInt("12abc", v), "parseInt rejects trailing chars");
    t.expectTrue(!Input::parseInt("x", v), "parseInt rejects non-number");

    // Şimdilik bu kadar. Entegrasyonda her device sınıfı gelince
    // “2–3 test / device” ekleyeceğiz. :contentReference[oaicite:3]{index=3}

    return t.report();
}
