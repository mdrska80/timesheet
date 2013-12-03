#ifndef COMPMANAGER_H
#define COMPMANAGER_H

#include "Managers/tsmanager.h"

class TSManager;

// all computations are handled here
class CompManager
{
public:
    CompManager(TSManager* mgr);

    TSManager* manager;
};

#endif // COMPMANAGER_H
