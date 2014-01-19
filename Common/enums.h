#ifndef ENUMS_H
#define ENUMS_H

enum FilterTypes
{
    FilterType_None = 1,
    FilterType_Valid = 2,
    FilterType_InValid = 3,

    FilterType_Today = 10,
    FilterType_Yesterday = 11,
    FilterType_All = 100
};

enum CompleterLoaderStates
{
    CompleterLoaderState_None = 0,
    CompleterLoaderState_Broken = 10,
    CompleterLoaderState_Loading = 20,
    CompleterLoaderState_OK = 100,
    CompleterLoaderState_Err = 1000
};

enum CompaniesList
{
    Unicorn = 0,
    Ka = 1,
    Autocont = 2,
    Bustec = 3
};


enum TSVersions
{
    // Initial version written in C++ nd MFC
    TSS_initial = 1,

    NET = 2,

    NET_Ka = 3,

    NET_Autocont = 4,

    // Version written in Autocont under GTK framework
    GTK_Autocont = 5,

    QT = 6
};


#endif // ENUMS_H

