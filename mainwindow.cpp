#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton1,&QPushButton::clicked,[&](){
        QMessageBox msgBox(this);
        msgBox.setText("aaaaa");
        msgBox.exec();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
