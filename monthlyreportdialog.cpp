#include "monthlyreportdialog.h"
#include "ui_monthlyreportdialog.h"

#include "Common/tscore.h"

MonthlyReportDialog::MonthlyReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonthlyReportDialog)
{
    ui->setupUi(this);

    PersistentStorage_XML* storage = &TSCore::I().entriesStorage;

    QList<float> list;


    list = storage->GetSpectrum();


    ui->spectrum->set_spectrum(list);


}

MonthlyReportDialog::~MonthlyReportDialog()
{
    delete ui;
}
