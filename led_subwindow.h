#ifndef LED_SUBWINDOW_H
#define LED_SUBWINDOW_H

#include <QMainWindow>

namespace Ui {
class Led_SubWindow;
}

class Led_SubWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Led_SubWindow(QWidget *parent = nullptr);
    ~Led_SubWindow();

private:
    Ui::Led_SubWindow *ui;
public slots:
    void setMainwindow_label_info(QString val);

};

#endif // LED_SUBWINDOW_H
