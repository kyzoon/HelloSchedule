#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QDate>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *s_list_model;
    QStandardItemModel *s_model;
    QDate s_today;

private:
    void setupUI(void);
    void setupWeekday(void);
};

#endif // MAINWINDOW_H
