#include "style.h"

QString Style::get_style(bool dark)
{

    QString style;
    Helper::getSharePath();
    QString share_path = Helper::getSharePath();

    if(!dark)
        Helper::read_file_into_str(share_path + "standard.css", &style);

    else{
        Helper::read_file_into_str(share_path + "dark.css", &style);
        style.replace("<<SHARE_PATH>>", share_path);
    }

    return style;
}
