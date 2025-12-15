#include "core/SignalFlag.h"

volatile std::sig_atomic_t SignalFlag::s_stop = 0;

void SignalFlag::handler(int) {
    s_stop = 1;
}

void SignalFlag::install() {
    std::signal(SIGINT, SignalFlag::handler);
}

bool SignalFlag::shouldStop() {
    return s_stop != 0;
}
