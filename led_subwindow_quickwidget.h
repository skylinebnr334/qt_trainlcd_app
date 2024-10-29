#ifndef LED_SUBWINDOW_QUICKWIDGET_H
#define LED_SUBWINDOW_QUICKWIDGET_H

#include <QtQuickWidgets/QQuickWidget>
#include <QQmlEngine>

class Led_SubWindow_QuickWidget : public QQuickWidget
{
    Q_OBJECT
private:

public:
    explicit Led_SubWindow_QuickWidget(QWidget *parent = nullptr);
};

#endif // LED_SUBWINDOW_QUICKWIDGET_H
