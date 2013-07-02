#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtGlobal>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txtWord->setText("Welcome, now let's start the test, A U READY? ");
    ui->BtnMode->setEnabled(false);
    i = 0;
    QObject::connect(&settingDlg, SIGNAL(my_setting_path(QString)), this, SLOT(receiveData(QString)));
    directory = "/home/edward/Desktop/GRE/wordlist16.txt";
    getDataFromFile(directory);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnSetting_clicked()
{
    settingDlg.showNormal();
}

void MainWindow::on_BtnNext_clicked()
{
    QMessageBox msg;
    if (i <= tmpList.count() - 1)
    {
     ui->txtWord->setText(tmpList[i]);
    i++;
    } else
    {
        msg.setWindowTitle("Inform");
        msg.setInformativeText("You have finished all the words, return to the first one. ");
        msg.exec();
        i = 0;
        ui->txtWord->setText(tmpList[i]);
    }
}

void MainWindow::receiveData(QString data)
{
    directory = data;
    getDataFromFile(directory);
}

void MainWindow::getDataFromFile(QString dir)
{
    QFile wordFile(dir);
    if(wordFile.exists())
    {
        if(!wordFile.open(QIODevice::ReadOnly))
        {
//            qDebug() << "wordFile Cannot open file for Reading";
        }
        QTextStream in(&wordFile);
        QString line;
        while(!in.atEnd())
        {
            line = in.readLine();
            tmpList << line;
        }
    }
}
