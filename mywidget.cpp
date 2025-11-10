#include "mywidget.h"
#include "ui_mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    QStringList ColTotle;
    ui->setupUi(this);//透過友人機介面的mywidget(*ui)來安裝自己(this)的人機介面
    ui->tableWidget->setColumnCount(4);
    ColTotle<<QStringLiteral("學號")<<QStringLiteral("班級")<<QStringLiteral("姓名")<<QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels(ColTotle);
}

myWidget::~myWidget()
{
    delete ui;
}
