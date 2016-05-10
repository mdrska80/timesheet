#include "style.h"
#include <QDir>

QString Style::get_style(bool dark)
{

    QString style;
    //Helper::getSharePath();
    QString share_path = QDir::currentPath()+"/Data/";

    if(!dark)
        Helper::read_file_into_str(share_path + "standard.css", &style);

    else{
        Helper::read_file_into_str(share_path + "dark.css", &style);
        style.replace("<<SHARE_PATH>>", share_path);
    }

    return style;
}

QString Style::set_textEdit_style()
{
    QString style = "";

    style += "QTextEdit { border: 1px solid #2B2B2B; border-radius: 4px;background-color: #525252; } ";
    style += "QTextEdit::focus { border-radius: 4px; border: 1px solid #e8841a; } ";
    style += "QTextEdit:read-only { border-radius: 4px; border: 1px solid #2B2B2B; } ";
    style += "QTextEdit:disabled { border-radius: 4px; border: 1px solid #2B2B2B; background-color: #383838; color: #525252; }";

    return style;

}
