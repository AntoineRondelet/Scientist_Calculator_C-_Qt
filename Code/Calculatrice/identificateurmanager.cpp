#include "identificateurmanager.h"


// -- Singleton -- //

IdentificateurManager::Handler IdentificateurManager::handler;

IdentificateurManager& IdentificateurManager::getInstance() {
    if(handler.instance == nullptr)
        handler.instance = new IdentificateurManager;
    return *handler.instance;
}

void IdentificateurManager::libererInstance() {
    delete handler.instance;
    handler.instance=nullptr;
}
