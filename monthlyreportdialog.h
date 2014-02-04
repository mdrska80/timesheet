#ifndef MONTHLYREPORTDIALOG_H
#define MONTHLYREPORTDIALOG_H

#include <QDialog>

namespace Ui {
class MonthlyReportDialog;
}

class MonthlyReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MonthlyReportDialog(QWidget *parent = 0);
    ~MonthlyReportDialog();

private:
    Ui::MonthlyReportDialog *ui;
};

#endif // MONTHLYREPORTDIALOG_H
