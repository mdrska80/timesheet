#ifndef DIALOGTESTER_H
#define DIALOGTESTER_H

#include <QDialog>

namespace Ui {
class DialogTester;
}

class DialogTester : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTester(QWidget *parent = 0);
    ~DialogTester();

private slots:
    void on_pushButton_clicked();
    void on_filteredTextChnged(QString changedText);

private:
    Ui::DialogTester *ui;
};

#endif // DIALOGTESTER_H
