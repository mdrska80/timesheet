#include "exportdialog.h"
#include "ui_exportdialog.h"
#include "Common/tscore.h"
#include "Data/entry.h"
#include "Common/helper.h"

ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);

    connect(ui->formatLineEdit, SIGNAL(textChanged()), this, SLOT(on_pushButton_2_clicked()));

    QString strFormat = "%date,%from,%to,%duration,%title";
    ui->formatLineEdit->setText(strFormat);
}

ExportDialog::~ExportDialog()
{
    delete ui;
}

void ExportDialog::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    QString strFormat = ui->formatLineEdit->text();

    int workingYear = TSCore::I().workingYear;
    int workingMonth =  TSCore::I().workingMonth;


    QDate dt;
    dt.setDate(workingYear, workingMonth, 1);
    int pocetDniVMesici = dt.daysInMonth();

    for (int i = 1;i<=pocetDniVMesici;i++)
    {
        QDate dtx(workingYear, workingMonth,i);

        QTime tFrom;
        QTime tTo;
        bool ok = TSCore::I().entriesStorage.dochazka.GetFromToByDate(dtx, tFrom, tTo);

        if (!ok)
            TSCore::I().entriesStorage.GetFromToByDate(dtx,tFrom,tTo);

        QString line = "";
        if (dtx.dayOfWeek() == 6 || dtx.dayOfWeek() == 7)
        {
            line += ",,,,,X";
        }
        else
        {
            QTime roundedFrom = Helper::RoundTimeUp(tFrom);
            QTime roundedTo = Helper::RoundTimeUp(tTo);

            line += roundedFrom.toString("hh:mm");
            line += ",";
            line += roundedTo.toString("hh:mm");
            line += ",,,";
            line += Helper::GetSecsAshhmm(Helper::GetDuration(roundedFrom, roundedTo));
        }

        ui->textEdit->append(line);
    }
}
