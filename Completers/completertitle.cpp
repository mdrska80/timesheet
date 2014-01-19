#include "completertitle.h"

CompleterTitle::CompleterTitle(QObject *parent) :
    QCompleter(parent)
{
    setCaseSensitivity(Qt::CaseInsensitive);
    state = CompleterLoaderState_None;      // to be sure
}

void CompleterTitle::ReloadCache()
{

}

CompleterLoaderStates CompleterTitle::GetState()
{
    return state;
}

void CompleterTitle::LoadAll()
{

}
