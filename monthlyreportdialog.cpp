#include "monthlyreportdialog.h"
#include "ui_monthlyreportdialog.h"

#include "Common/tscore.h"

MonthlyReportDialog::MonthlyReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonthlyReportDialog)
{
    ui->setupUi(this);


}

MonthlyReportDialog::~MonthlyReportDialog()
{
    delete ui;
}
