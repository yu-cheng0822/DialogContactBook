#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class myWidget;//有人機介面
}
QT_END_NAMESPACE

class myWidget : public QWidget//沒有人機介面
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();

private:
    Ui::myWidget *ui;//用指標連至有人機介面
};
#endif // MYWIDGET_H
