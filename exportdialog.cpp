#include "exportdialog.h"
#include "ui_exportdialog.h"
#include "Common/tscore.h"
#include "Data/entry.h"
#include "Common/helper.h"
#include "Common/entriesanalyzer.h"


ExportDialog::ExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExportDialog)
{
    ui->setupUi(this);
    on_pushButton_2_clicked();
}

ExportDialog::~ExportDialog()
{
    delete ui;
}

void ExportDialog::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();

    int workingYear = TSCore::I().workingYear;
    int workingMonth =  TSCore::I().workingMonth;


    QDate dt;
    dt.setDate(workingYear, workingMonth, 1);
    int pocetDniVMesici = dt.daysInMonth();

    int globalniOdchylka = 0;
    QString odchylkaString = "";
    QString odchylkaZnamenko = "";

    bool overMidnightWorkDetected = false;
    double celyFond = 0;

    for (int i = 1;i<=pocetDniVMesici;i++)
    {
        QDate dtx(workingYear, workingMonth,i);

        QTime tFrom;
        QTime tTo;

        QTime tFrom2;
        QTime tTo2;
        TSCore::I().entriesStorage.GetFromToByDate(dtx,tFrom2,tTo2);
        if (dtx.dayOfWeek() == 6 || dtx.dayOfWeek() == 7)
            ui->textEdit_3->append("-");
        else
        {
            if (tFrom == QTime(23,59,59))
                ui->textEdit_3->append("-");
            else
                ui->textEdit_3->append(tFrom2.toString("hh:mm")+", "+tTo2.toString("hh:mm"));
        }

        bool ok = TSCore::I().entriesStorage.dochazka.GetFromToByDate(dtx, tFrom, tTo);
        QTime roundedFromScan = Helper::RoundTimeUp(tFrom);
        QTime roundedToScan = Helper::RoundTimeDown(tTo);
        ui->textEdit_4->append(roundedFromScan.toString("hh:mm")+", "+roundedToScan.toString("hh:mm"));

        if (!ok)
            TSCore::I().entriesStorage.GetFromToByDate(dtx,tFrom,tTo);

        QTime entryOvertime = TSCore::I().entriesStorage.GetOvertimeForDay(dtx);
        if (QTime(0,0,0).secsTo(entryOvertime) > 0)
        {
            overMidnightWorkDetected = true;
        }

        QString mins = 0;
        QString znamenko = "";

        QString line = "";
        //if (dtx.dayOfWeek() == 6 || dtx.dayOfWeek() == 7)
        if (false)
        {
            line += ",,,,X";
            //mins = "-";
        }
        else
        {
            QTime roundedFrom = Helper::RoundTimeUp(tFrom);
            QTime roundedTo = Helper::RoundTimeDown(tTo);

            line += roundedFrom.toString("hh:mm");
            line += ",";
            if (overMidnightWorkDetected)
                line += roundedFrom.addSecs(8.5*60*60).toString("hh:mm");
            else
                line += roundedTo.toString("hh:mm");

            line += ",,,";

            if (overMidnightWorkDetected)
                line += "<b>08:00</b>";
            else
            {
                // 30 minutes*60 = in seconds
                int halfHourInSecs = 30*60;
                int sPodleFondu = Helper::GetDuration(roundedFrom, roundedTo)-halfHourInSecs;

                // oba casy jsou nenulove!
                if (sPodleFondu!=-halfHourInSecs)
                celyFond += sPodleFondu;

//                line += "<b>"+Helper::GetSecsAshhmm(sPodleFondu)+"</b>";

                QString message = QString("<b>%1</b>")
                        .arg(Helper::GetSecsAshhmm(sPodleFondu));
                        //.arg(celyFond/3600);

                line += message;
            }

            int secs = 0;

            if (overMidnightWorkDetected)
            {
                secs = Helper::GetDuration(roundedFrom, QTime(23,59,59));
                secs += 1; //to je ta sekunda co nahore chybi
//                secs += entryOvertime.hour()*3660+entryOvertime.minute()*60+entryOvertime.second();

            }
            else
                secs = Helper::GetDuration(roundedFrom, roundedTo);

            secs += Helper::TimeToSecs(entryOvertime);


            secs = secs-8.5*60*60;

            if (-secs != 8.5*60*60)
            globalniOdchylka += secs;

            znamenko = "";
            if (secs < 0)
            {
                secs *= -1;
                znamenko = "-";
            }

            mins = "-";
            if (secs != 8.5*60*60)
            {
                mins = znamenko+Helper::GetSecsAshhmm(secs);
            }
        }

        odchylkaZnamenko = "<font color='lightgreen'>";
        int gloOdch = globalniOdchylka;
        if (gloOdch <0)
        {
            gloOdch *= -1;
            odchylkaZnamenko = "<font color='red'>-";
        }

        odchylkaString = odchylkaZnamenko+Helper::GetSecsAshhmm(gloOdch);

        if (mins == "-")
        {
            odchylkaString = "<font>";
        }

        if (Helper::TimeToSecs(entryOvertime) == 0)
            ui->textEdit_2->append(mins+", \t"+odchylkaString+"</font>");
        else
            ui->textEdit_2->append(mins+", \t"+odchylkaString+"</font> <font color='lightblue'>(+"+Helper::GetSecsAsMin(Helper::TimeToSecs(entryOvertime))+")</font>");


        ui->textEdit->append(line);
        overMidnightWorkDetected = false;

    }

    EntryFileInfo efi;
    EntriesAnalyzer an = EntriesAnalyzer(&TSCore::I().entriesStorage.entries, &efi);

    QString message = QString("<br/><br/><span style='font-weight:600; color:#ffff00;'>Pracovni fond: %1h</span>")
            .arg(celyFond/3600);

    ui->textEdit->append(message);
}
