#include "timesheetlist.h"
#include "ui_timesheetlist.h"

TimesheetList::TimesheetList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimesheetList)
{
    ui->setupUi(this);
}

TimesheetList::~TimesheetList()
{
    delete ui;
}
