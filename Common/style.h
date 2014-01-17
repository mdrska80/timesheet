#ifndef STYLE_H
#define STYLE_H

#include <QString>
#include "helper.h"

class Style
{
public:
    static QString get_style(bool dark);
    static QString set_textEdit_style();
};

#endif // STYLE_H
