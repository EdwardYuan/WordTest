#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>

#define MAX_WORD_COUNT 1000

//#include "settingdlg.h"

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
//    void receiveData(QString data);

    void on_actionRan_triggered();

    void on_actionSeq_triggered();

    void on_actionFile_Location_triggered();

    void on_btnPrev_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *curFile;
    int mode;
    void getDataFromFile(QString dir);
    void DoPrev();
    void DoNext();
    void openFileLocation();
    void init_rand_arr();
protected:
    void KeyPressEvent(QKeyEvent *e);
public:
//    SettingDlg settingDlg;
    QString directory;
    QStringList tmpList;
    int i, j, k;  // k is the index of array rand_j
    int rand_j[MAX_WORD_COUNT];
};

#endif // MAINWINDOW_H
