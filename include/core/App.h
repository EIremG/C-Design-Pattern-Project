#ifndef APP_H
#define APP_H

class IAppServices;
class MenuController;

class App {
public:
    App(IAppServices& services, MenuController& menu);
    int run();

private:
    IAppServices& m_services;
    MenuController& m_menu;

    void doShutdown();
};

#endif
