#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI(void)
{
    s_list_model = new QStandardItemModel;
    s_list_model->setColumnCount(5);
    ui->tvList->setModel(s_list_model);

    QStringList list_header;
    list_header << "序号" << "里程" << "工作日" << "开始日期" << "结束日期";
    s_list_model->setHorizontalHeaderLabels(list_header);

    ui->tvList->setColumnWidth(0, 30);
    ui->tvList->setColumnWidth(1, 300);
    ui->tvList->setColumnWidth(2, 100);
    ui->tvList->setColumnWidth(3, 120);
    ui->tvList->setColumnWidth(4, 120);

    s_list_model->setItem(0, 0, new QStandardItem("1."));
    s_list_model->setItem(0, 1, new QStandardItem("初样"));
    s_list_model->setItem(0, 2, new QStandardItem("4个工作日"));
    s_list_model->item(0, 2)->setTextAlignment(Qt::AlignRight);
    s_list_model->setItem(0, 3, new QStandardItem("2018年3月1日"));
    s_list_model->item(0, 3)->setTextAlignment(Qt::AlignRight);
    s_list_model->setItem(0, 4, new QStandardItem("2018年3月4日"));
    s_list_model->item(0, 4)->setTextAlignment(Qt::AlignRight);

    s_model = new QStandardItemModel;
    s_model->setColumnCount(100);
    ui->tvSchedule->setModel(s_model);

    s_today = QDate::currentDate();
    int year = s_today.year();
    int month = s_today.month();
    int day = s_today.day();
    int daysinmonth = s_today.daysInMonth();
    qDebug() << year << month << day;
    qDebug() << daysinmonth;

    s_model->setItem(0, 0, new QStandardItem(QString::number(month) + "月"));
    s_model->item(0, 0)->setTextAlignment(Qt::AlignCenter);

    int pos = 0;
//    for(int i = day; i < daysinmonth + 1; ++i)
    for(int i = 1; i < daysinmonth + 1; ++i)
    {
        s_model->setItem(1, pos, new QStandardItem(QString::number(i)));
        s_model->item(1, pos)->setTextAlignment(Qt::AlignCenter);
        ++pos;
    }

    s_model->setItem(2, 0, new QStandardItem(""));
    s_model->item(2, 0)->setBackground(QBrush(QColor(173, 127, 168)));
    s_model->setItem(2, 1, new QStandardItem(""));
    s_model->item(2, 1)->setBackground(QBrush(QColor(173, 127, 168)));
    s_model->setItem(2, 2, new QStandardItem(""));
    s_model->item(2, 2)->setBackground(QBrush(QColor(173, 127, 168)));
    s_model->setItem(2, 3, new QStandardItem(""));
    s_model->item(2, 3)->setBackground(QBrush(QColor(173, 127, 168)));

    s_model->setItem(3, 0, new QStandardItem(""));
    s_model->setItem(3, 1, new QStandardItem(""));
    s_model->setItem(3, 2, new QStandardItem(""));
    s_model->setItem(3, 3, new QStandardItem(""));

    s_model->setItem(4, 4, new QStandardItem(""));
    s_model->item(4, 4)->setBackground(QBrush(QColor(173, 127, 168)));
    s_model->setItem(4, 5, new QStandardItem(""));
    s_model->item(4, 5)->setBackground(QBrush(QColor(173, 127, 168)));
    s_model->setItem(4, 6, new QStandardItem(""));
    s_model->item(4, 6)->setBackground(QBrush(QColor(173, 127, 168)));
    s_model->setItem(4, 7, new QStandardItem(""));
    s_model->item(4, 7)->setBackground(QBrush(QColor(173, 127, 168)));

    s_model->setItem(5, 4, new QStandardItem(""));
    s_model->setItem(5, 5, new QStandardItem(""));
    s_model->setItem(5, 6, new QStandardItem(""));
    s_model->setItem(5, 7, new QStandardItem(""));

    ui->tvSchedule->setSpan(0, 0, 1, 31);

//    ui->tvScedule->resizeColumnsToContents();
    for(int i = 0; i < 32; ++i)
    {
        ui->tvSchedule->setColumnWidth(i, 24);
    }

    ui->tvSchedule->setRowHeight(2, 15);
    ui->tvSchedule->setRowHeight(3, 15);
    ui->tvSchedule->setRowHeight(4, 15);
    ui->tvSchedule->setRowHeight(5, 15);

    setupWeekday();

    showMaximized();
    ui->splitter->setStretchFactor(0, 4);
    ui->splitter->setStretchFactor(1, 6);
}

void MainWindow::setupWeekday(void)
{
    int rows = s_model->rowCount();

    for(int i = 1; i < 32; ++i)
    {
        QDate date = QDate(s_today.year(), s_today.month(), i);
        int dayofweek = date.dayOfWeek();
        if(6 == dayofweek || 7 == dayofweek)
        {
//            for(int j = 1; j < rows; ++j)
            {
                s_model->item(1, i - 1)->setBackground(QBrush(QColor(182, 189, 186)));
            }
        }
    }
}
