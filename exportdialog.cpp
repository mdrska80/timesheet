#include "exportdialog.h"
#include "ui_exportdialog.h"
#include "Common/tscore.h"
#include "Data/entry.h"

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

    int cnt = TSCore::I().entriesStorage.entries.size();

    for(int i = 0; i < cnt; i++)
    {
        Entry *e = TSCore::I().entriesStorage.entries[i];
        QString line = strFormat;


        line = line.replace("%date", e->date.toString("dd.MM.yyyy"));
        line = line.replace("%from", e->from.toString("hh:mm"));
        line = line.replace("%to", e->to.toString("hh:mm"));
        line = line.replace("%duration", e->GetDurationAshhmm());
        line = line.replace("%title", e->title);
        line = line.replace("%description", e->description);

        ui->textEdit->append(line);
    }
}
