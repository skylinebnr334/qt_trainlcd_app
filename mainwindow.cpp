#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    subwindow=new Led_SubWindow(this);


    QObject::connect(ui->pushButton1,&QPushButton::clicked,[&](){
        QMessageBox msgBox(this);
        msgBox.setText("aaaaa");
        msgBox.exec();

    });
    QObject::connect(ui->pushButton2,&QPushButton::clicked,[&](){
        subwindow->setMainwindow_label_info(QDateTime::currentDateTime().time().toString("HH:mm:ss"));
    });
    subwindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
