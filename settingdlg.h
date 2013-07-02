#ifndef SETTINGDLG_H
#define SETTINGDLG_H

#include <QDialog>
#include <QString>

namespace Ui {
class SettingDlg;
}

class SettingDlg : public QDialog
{
    Q_OBJECT
    
public:
    QString dir;
    explicit SettingDlg(QWidget *parent = 0);
    ~SettingDlg();
    
private slots:
    void on_BtnBrowse_clicked();

    void on_BtnOK_clicked();

    void on_BtnCancel_clicked();

private:
    Ui::SettingDlg *ui;

signals:
    void my_setting_path(QString);
};

#endif // SETTINGDLG_H
