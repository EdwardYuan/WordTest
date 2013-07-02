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

private:
    Ui::MainWindow *ui;
    void getDataFromFile(QString dir);
public:
    SettingDlg settingDlg;
    QString directory;
    QStringList tmpList;
    int i;
};

#endif // MAINWINDOW_H
