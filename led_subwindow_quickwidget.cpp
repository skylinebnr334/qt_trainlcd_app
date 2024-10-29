#include "led_subwindow_quickwidget.h"

Led_SubWindow_QuickWidget::Led_SubWindow_QuickWidget(QWidget *parent):QQuickWidget(parent) {

    this->setSource(QUrl("qrc:/led_subwindow_quick.qml"));
}
