#ifndef LED_SUBWINDOW_QUICKWIDGET_H
#define LED_SUBWINDOW_QUICKWIDGET_H

#include <QtQuickWidgets/QQuickWidget>

class Led_SubWindow_QuickWidget : public QQuickWidget
{
    Q_OBJECT
public:
    explicit Led_SubWindow_QuickWidget(QWidget *parent = nullptr);
    ~Led_SubWindow_QuickWidget() override;
};

#endif // LED_SUBWINDOW_QUICKWIDGET_H
