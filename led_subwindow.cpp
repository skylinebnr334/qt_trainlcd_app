#include "led_subwindow.h"
#include "ui_led_subwindow.h"

Led_SubWindow::Led_SubWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Led_SubWindow)
{
    ui->setupUi(this);
}
void Led_SubWindow::setMainwindow_label_info(QString val){
    ui->mainwindow_label_info->setText(val);
}

Led_SubWindow::~Led_SubWindow()
{
    delete ui;
}
