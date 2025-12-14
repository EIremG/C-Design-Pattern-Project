#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include "../devices/Light.h"
#include "../devices/TV.h"

class Configurator {
public:
    static void configureLight(Light*);
    static void configureTV(TV*);
};

#endif
