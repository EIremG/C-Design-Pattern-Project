#include "TestRunner.h"
#include "TinyTest.h"
#include "DeviceTests.h"
#include "core/Input.h"

int runAllTests() {
    TinyTest t("test_report.txt");

    int v = 0;
    t.expectTrue(Input::parseInt("12", v) && v == 12, "parseInt valid");
    t.expectTrue(!Input::parseInt("12abc", v), "parseInt rejects trailing chars");
    t.expectTrue(!Input::parseInt("x", v), "parseInt rejects non-number");

    // Dev B tests
    runDeviceTests(t);

    return t.report();
}
