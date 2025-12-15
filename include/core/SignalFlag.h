#ifndef SIGNALFLAG_H
#define SIGNALFLAG_H

#include <csignal>

class SignalFlag {
public:
    static void install();
    static bool shouldStop();

private:
    static volatile std::sig_atomic_t s_stop;
    static void handler(int);
};

#endif
