#include "led_subwindow.h"
#include "ui_led_subwindow.h"

Led_SubWindow::Led_SubWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Led_SubWindow)
{
    ui->setupUi(this);
}

Led_SubWindow::~Led_SubWindow()
{
    delete ui;
}
