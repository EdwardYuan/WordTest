#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtGlobal>
#include <QTextStream>
#include <QMessageBox>
#include <cstdlib>
#include <QFileDialog>
#include <qnamespace.h>

#define random(x) (rand()%x)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mode = 0;
    ui->setupUi(this);
    ui->txtWord->setText("Welcome, now let's start the test, A U READY? ");
    i = 0;
//    QObject::connect(&settingDlg, SIGNAL(my_setting_path(QString)), this, SLOT(receiveData(QString)));
//    directory = "/home/edward/Desktop/GRE/wordlist16.txt";
    getDataFromFile(directory);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnSetting_clicked()
{
//    settingDlg.showNormal();
}

void MainWindow::on_BtnNext_clicked()
{
    if (directory == "")
    {
        openFileLocation();
        getDataFromFile(directory);
    }
    else DoNext();
}

void MainWindow::on_btnPrev_clicked()
{
    if (directory == "")
    {
        openFileLocation();
        getDataFromFile(directory);
    }
    else DoPrev();
}

void MainWindow::DoPrev()
{
    QMessageBox msg;
    if (mode == 0)
    {
        if ((j <= 0) || (j > tmpList.count() - 1))
        {
            msg.setWindowTitle("Inform");
            msg.setInformativeText("You have finished all the words, return to the first one. ");
            msg.exec();
            j = tmpList.count() - 1;
            ui->txtWord->setText(tmpList[j]);
        }
        else if ((j <= tmpList.count() - 1) && (j > 0))
        {
            ui->txtWord->setText(tmpList[j-1]);
            --j;
        }

    } else if (mode == 1)
    {
        ui->txtWord->setText(tmpList[j]);
    }
    ui->txtWord->setAlignment(Qt::AlignHCenter);
}

//void MainWindow::receiveData(QString data)
//{
//    directory = data;
//    getDataFromFile(directory);
//}

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
        tmpList.clear();
        while(!in.atEnd())
        {
            line = in.readLine();
            tmpList << line;
        }
    }
}

void MainWindow::DoNext()
{
    QMessageBox msg;
    if (mode == 0)
    {
        if (i <= tmpList.count() - 1)
        {
            ui->txtWord->setText(tmpList[i]);
            j = i;
            i++;
        } else
        {
            msg.setWindowTitle("Inform");
            msg.setInformativeText("You have finished all the words, return to the first one. ");
            msg.exec();
            i = 0;
            ui->txtWord->setText(tmpList[i]);
        }
    } else if (mode == 1)
    {
        i = random(tmpList.count());
        j = i;
        ui->txtWord->setText(tmpList[i]);
    } else msg.setInformativeText("Error!");
    ui->txtWord->setAlignment(Qt::AlignHCenter);
}

void MainWindow::on_actionRan_triggered()
{
    mode = 1;
}

void MainWindow::on_actionSeq_triggered()
{
    mode = 0;
}

void MainWindow::on_actionFile_Location_triggered()
{
    openFileLocation();
}

void MainWindow::openFileLocation()
{
    directory = QFileDialog::getOpenFileName(this,
                    tr("Find Files"), QDir::currentPath());

                   if (!directory.isEmpty()) {
                       getDataFromFile(directory);
     //                  ui->txtPath->setText(directory);
                   }
}

void MainWindow::KeyPressEvent(QKeyEvent *e)
{
    switch (e->key())
        {
            case Qt::Key_Left : DoPrev(); break;
            case Qt::Key_Right : DoNext(); break;
        }
}



