#include "settingdlg.h"
#include "ui_settingdlg.h"
#include"QFileDialog"
#include"settingdlg.h"

SettingDlg::SettingDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDlg)
{
    ui->setupUi(this);
}

SettingDlg::~SettingDlg()
{
    delete ui;
}

void SettingDlg::on_BtnBrowse_clicked()
{
     dir = QFileDialog::getOpenFileName(this,
                                    tr("Find Files"), QDir::currentPath());

         if (!dir.isEmpty()) {
             ui->txtPath->setText(dir);
         }
}

void SettingDlg::on_BtnOK_clicked()
{
    emit my_setting_path(ui->txtPath->text());
    this->close();
}

void SettingDlg::on_BtnCancel_clicked()
{
    this->close();
}


