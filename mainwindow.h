#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settingdlg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_BtnSetting_clicked();

    void on_BtnNext_clicked();
    void receiveData(QString data);

    void on_actionRan_triggered();

    void on_actionSeq_triggered();

    void on_actionFile_Location_triggered();

private:
    Ui::MainWindow *ui;
    int mode;
    void getDataFromFile(QString dir);
public:
    SettingDlg settingDlg;
    QString directory;
    QStringList tmpList;
    int i;
};

#endif // MAINWINDOW_H
