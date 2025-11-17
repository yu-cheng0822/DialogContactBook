#include "mywidget.h"
#include "ui_mywidget.h"
#include<QFile>
#include<QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QFileInfo>
#include <QFileDialog>
QString mFilename = "C:/Users/user/Desktop/ex/getSaveFileName.txt";
void Write(QString Filename,QString str){
    QFile mFile(Filename);
    if(!mFile.open(QFile::WriteOnly|QFile::Text)){
        qDebug()<<"could not open file for write";
        return;
    }
    QTextStream out(&mFile);
    out<<str;
    mFile.flush();
    mFile.close();

}
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

void myWidget::on_pushButton_3_clicked()
{
    QTableWidgetItem *inputRow1,*inputRow2,*inputRow3,*inputRow4;

    inputRow1 = new QTableWidgetItem(QString(ui->lineEdit->text()));
    inputRow2 = new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    inputRow3 = new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    inputRow4 = new QTableWidgetItem(QString(ui->lineEdit_4->text()));

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,inputRow1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,inputRow2);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,2,inputRow3);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,inputRow4);

}


void myWidget::on_pushButton_4_clicked()
{
    QString saveFile="";
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            saveFile+=ui->tableWidget->item(i,j)->text()+",";

        }
        saveFile+="\n";

    }
    Write(mFilename,saveFile);
}


void myWidget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("選擇要匯入的檔案"),
        QString(), tr("CSV Files (*.csv *.txt);;All Files (*.*)")
        );
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "could not open file for read";
        return;
    }

    QTextStream in(&file);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    in.setCodec("UTF-8");
#endif

    ui->tableWidget->setRowCount(0);
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(',', Qt::KeepEmptyParts);
        if (!parts.isEmpty() && parts.last().isEmpty()) parts.removeLast();
        if (!parts.isEmpty()) parts[0].remove(QChar(0xFEFF));

        ui->tableWidget->insertRow(row);
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            ui->tableWidget->setItem(row, col,
                                     new QTableWidgetItem(col < parts.size() ? parts.at(col) : QString()));
        }
        ++row;
    }
    file.close();
    ui->tableWidget->resizeColumnsToContents();
}

void myWidget::on_pushButton_2_clicked()
{
    QString saveFile="";
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            saveFile+=ui->tableWidget->item(i,j)->text()+",";

        }
        saveFile+="\n";

    }
    Write(mFilename,saveFile);
    close();
}

