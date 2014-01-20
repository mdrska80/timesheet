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
    Undefined = 0,
    Unicorn = 1,
    Ka = 2,
    Autocont = 3,
    Bustec = 4
};


enum TSVersions
{
    // Initial version written in C++ nd MFC
    TSS_initial = 1,

    NET = 2,

    NET_Ka = 3,

    NET_WPF_Ka = 4,

    NET_Autocont = 5,

    // Version written in Autocont under GTK framework
    GTK_Autocont = 6,

    QT = 7
};


#endif // ENUMS_H

