#ifndef TIMESHEETLIST_H
#define TIMESHEETLIST_H

#include <QWidget>

namespace Ui {
class TimesheetList;
}

class TimesheetList : public QWidget
{
    Q_OBJECT
    
public:
    explicit TimesheetList(QWidget *parent = 0);
    ~TimesheetList();
    
private:
    Ui::TimesheetList *ui;
};

#endif // TIMESHEETLIST_H
