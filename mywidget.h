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

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::myWidget *ui;//用指標連至有人機介面
};
#endif // MYWIDGET_H
