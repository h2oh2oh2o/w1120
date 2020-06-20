#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStackedWidget>
#include<QComboBox>
#include<QLineEdit>
#include<QValidator>
#include<QMessageBox>
#include<QRadioButton>
#include<QGroupBox>
#include<QDebug>
#include<QString>
#include<QDialog>
#include<QDateTime>
#include"information.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowIcon(QIcon(":/new/prefix1/logo"));
    setFixedSize(750,800);
    setWindowTitle("房贷计算器");
    QString button_style="QPushButton{background-color:white;\
                          color:black;   border-radius: 10px;  border: 2px groove gray;\
                          border-style: outset;}"
                          "QPushButton:hover{background-color:red; color: white;}"
                          "QPushButton:pressed{background-color:red;\
                          border-style: inset; }";
    ui->GareaBeginBtn->setStyleSheet(button_style);
    ui->GareaClearBtn->setStyleSheet(button_style);
    ui->GareaClearBtn_2->setStyleSheet(button_style);
    ui->SareaBeginBtn->setStyleSheet(button_style);
    ui->SareaClearBtn->setStyleSheet(button_style);
    ui->GareaClearBtn_3->setStyleSheet(button_style);
    ui->MBeginBtn->setStyleSheet(button_style);
    ui->MClearBtn->setStyleSheet(button_style);
    ui->GareaClearBtn_4->setStyleSheet(button_style);
    ui->GmoneyBeginBtn->setStyleSheet(button_style);
    ui->GmoneyClearBtn->setStyleSheet(button_style);
    ui->GareaClearBtn_5->setStyleSheet(button_style);
    ui->SmoneyBeginBtn->setStyleSheet(button_style);
    ui->SmoneyClearBtn->setStyleSheet(button_style);
    ui->GareaClearBtn_6->setStyleSheet(button_style);
    ui->rateBack->setStyleSheet(button_style);
    ui->history2->setStyleSheet(button_style);
    ui->moneyBack->setStyleSheet(button_style);
    ui->historyBtn->setStyleSheet(button_style);
    ui->pushButton->setStyleSheet(button_style);
    QString combo_style="QComboBox{background-color:white;\
                        color:black;   border-radius: 10px;  border: 2px groove gray;\
                        border-style: outset;}";
    ui->GareaTypeCombo->setStyleSheet(combo_style);
    ui->GareaWayCombo->setStyleSheet(combo_style);
    ui->GareaPercent->setStyleSheet(combo_style);
    ui->GareaYearCombo->setStyleSheet(combo_style);
    ui->GareaRateCombo->setStyleSheet(combo_style);
    ui->SareaTypeCombo->setStyleSheet(combo_style);
    ui->SareaWayCombo->setStyleSheet(combo_style);
    ui->SareaPercent->setStyleSheet(combo_style);
    ui->SareaYearCombo->setStyleSheet(combo_style);
    ui->SareaRateCombo->setStyleSheet(combo_style);
    ui->MTypeCombo->setStyleSheet(combo_style);
    ui->MSRateCombo->setStyleSheet(combo_style);
    ui->MGRateCombo->setStyleSheet(combo_style);
    ui->MYearCombo->setStyleSheet(combo_style);
    ui->GmoneyTyepCombo->setStyleSheet(combo_style);
    ui->GmoneyWayCombo->setStyleSheet(combo_style);
    ui->GmoneyYearCombo->setStyleSheet(combo_style);
    ui->GmoneyRateCombo->setStyleSheet(combo_style);
    ui->SmoneyTypeCombo->setStyleSheet(combo_style);
    ui->SmoneyWayCombo->setStyleSheet(combo_style);
    ui->SMoneyYearCombo->setStyleSheet(combo_style);
    ui->SmoneyRateCombo->setStyleSheet(combo_style);
    QString edit_style="QLineEdit{border-radius: 10px;  border: 2px groove gray;\
                       border-style: inset;}";
    ui->GareaMoneyEdit->setStyleSheet(edit_style);
    ui->GareaSizeEdit->setStyleSheet(edit_style);
    ui->GareaRateEdit->setStyleSheet(edit_style);
    ui->SareaSizeEdit->setStyleSheet(edit_style);
    ui->SareaMoneyEdit->setStyleSheet(edit_style);
    ui->SareaRateEdit->setStyleSheet(edit_style);
    ui->MSMoneyEdit->setStyleSheet(edit_style);
    ui->MGMoneyEdit->setStyleSheet(edit_style);
    ui->MSRateEdit->setStyleSheet(edit_style);
    ui->MGRateEdit->setStyleSheet(edit_style);
    ui->GmoneyEdit->setStyleSheet(edit_style);
    ui->GmoneyRateEdit->setStyleSheet(edit_style);
    ui->SmoneyEdit->setStyleSheet(edit_style);
    ui->SmoneyRateEdit->setStyleSheet(edit_style);
    //上一页last
    last=0;
    //设置默认的页面
    ui->stackedWidget->setCurrentIndex(0);
    //利率输入框中可以输入的类型
    QDoubleValidator *control2=new QDoubleValidator(0,10,2,this);
    control2->setNotation(QDoubleValidator::StandardNotation);
    ui->GareaRateEdit->setValidator(control2);
    ui->SareaRateEdit->setValidator(control2);
    ui->MSRateEdit->setValidator(control2);
    ui->MGRateEdit->setValidator(control2);
    ui->GmoneyRateEdit->setValidator(control2);
    ui->SmoneyRateEdit->setValidator(control2);
    //给公积金、单价面积页面利息设置默认值
    ui->GareaRateEdit->setText("3.25");
    //给商业、单价面积页面利率设置默认值
    ui->SareaRateEdit->setText("4.75");
    //给公积金、总额页面利息设置默认值
    ui->GmoneyRateEdit->setText("3.25");
    //给商业、总额页面商业利率设置默认值
    ui->SmoneyRateEdit->setText("4.75");
    //给组合页面公积金利息设置默认值
    ui->MGRateEdit->setText("3.25");
    //给组合页面商业利率设置默认值
    ui->MSRateEdit->setText("3.25");
    //设置各页面计算方式的默认值
    ui->GareaRateBtn->setChecked(true);
    ui->SareaRateBtn->setChecked(true);
    ui->MRateBtn->setChecked(true);
    ui->GMoneyRateBtn->setChecked(true);
    ui->SMoneyRateBtn->setChecked(true);
    //设置每个页面贷款类别选项的默认值
    ui->GareaTypeCombo->setCurrentIndex(0);
    ui->GmoneyTyepCombo->setCurrentIndex(0);
    ui->SareaTypeCombo->setCurrentIndex(1);
    ui->SmoneyTypeCombo->setCurrentIndex(1);
    ui->MTypeCombo->setCurrentIndex(2);
    //设置每个页面计算方式选项的默认值
    ui->GareaWayCombo->setCurrentIndex(0);
    ui->GmoneyWayCombo->setCurrentIndex(1);
    ui->SareaWayCombo->setCurrentIndex(0);
    ui->SmoneyWayCombo->setCurrentIndex(1);
    //限制输入框中提示的内容
    ui->GareaMoneyEdit->setPlaceholderText("请输入房屋单价");
    ui->GareaSizeEdit->setPlaceholderText("请输入房屋面积");
    ui->SareaMoneyEdit->setPlaceholderText("请输入房屋单价");
    ui->SareaSizeEdit->setPlaceholderText("请输入房屋面积");
    ui->GmoneyEdit->setPlaceholderText("请输入贷款总额");
    ui->SmoneyEdit->setPlaceholderText("请输入贷款总额");
    ui->MGMoneyEdit->setPlaceholderText("请输入公积金贷款总额");
    ui->MSMoneyEdit->setPlaceholderText("请输入商业贷款总额");
    //限制输入框中可以输入的格式
    QDoubleValidator *control=new QDoubleValidator(0,1000,2,this);
    QDoubleValidator *control1=new QDoubleValidator(0,100000,2,this);
    control->setNotation(QDoubleValidator::StandardNotation);
    control1->setNotation(QDoubleValidator::StandardNotation);
    ui->GareaMoneyEdit->setValidator(control1);
    ui->GareaSizeEdit->setValidator(control);
    ui->SareaMoneyEdit->setValidator(control1);
    ui->SareaSizeEdit->setValidator(control);
    ui->GmoneyEdit->setValidator(control1);
    ui->SmoneyEdit->setValidator(control1);
    ui->MGMoneyEdit->setValidator(control1);
    ui->MSMoneyEdit->setValidator(control1);
    //初始化按揭成数、按揭年数、贷款利率
    user.setPercent(ui->GareaPercent->currentIndex());
    user.setmonth(ui->GareaYearCombo->currentIndex());
    user.setrate(ui->GareaRateEdit->text().toDouble());
    user.setsrate(ui->MSRateEdit->text().toDouble());
    user.setgrate(ui->MGRateEdit->text().toDouble());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GareaMoneyEdit_textChanged(const QString &arg1)
{
    user.setPerMoney(arg1.toDouble());
}

void MainWindow::on_GareaSizeEdit_textChanged(const QString &arg1)
{
    user.setSize(arg1.toDouble());
}

void MainWindow::on_GareaPercent_currentIndexChanged(int index)
{
    user.setPercent(index);
}

void MainWindow::on_GareaYearCombo_currentIndexChanged(int index)
{
    user.setmonth(index);
    if(index<20)
    {
        switch (ui->GareaRateCombo->currentIndex()) {
        case 0: {ui->GareaRateEdit->setText("3.25");break;}
        case 1: {ui->GareaRateEdit->setText("3.25");break;}
        case 2: {ui->GareaRateEdit->setText("3.57");break;}
        case 3: {ui->GareaRateEdit->setText("3.41");break;}
        case 4: {ui->GareaRateEdit->setText("2.76");break;}
        case 5: {ui->GareaRateEdit->setText("2.28");break;}
        case 6: {ui->GareaRateEdit->setText("3.25");break;}
        case 7: {ui->GareaRateEdit->setText("3.57");break;}
        case 8: {ui->GareaRateEdit->setText("2.76");break;}
        case 9: {ui->GareaRateEdit->setText("2.28");break;}
        case 10: {ui->GareaRateEdit->setText("3.25");break;}
        case 11: {ui->GareaRateEdit->setText("3.85");break;}
        case 12: {ui->GareaRateEdit->setText("2.98");break;}
        case 13: {ui->GareaRateEdit->setText("2.45");break;}
        case 14: {ui->GareaRateEdit->setText("3.5");break;}
        case 15: {ui->GareaRateEdit->setText("4.13");break;}
        case 16: {ui->GareaRateEdit->setText("3.19");break;}
        case 17: {ui->GareaRateEdit->setText("2.63");break;}
        case 18: {ui->GareaRateEdit->setText("3.75");break;}
        case 19: {ui->GareaRateEdit->setText("4.4");break;}
        case 20: {ui->GareaRateEdit->setText("3.4");break;}
        case 21: {ui->GareaRateEdit->setText("2.8");break;}
        case 22: {ui->GareaRateEdit->setText("4");break;}
        case 23: {ui->GareaRateEdit->setText("4.25");break;}
        case 24: {ui->GareaRateEdit->setText("4.25");break;}
        case 25: {ui->GareaRateEdit->setText("4.25");break;}
        case 26: {ui->GareaRateEdit->setText("4.25");break;}
        case 27: {ui->GareaRateEdit->setText("4.5");break;}
        case 28: {ui->GareaRateEdit->setText("4.5");break;}
        case 29: {ui->GareaRateEdit->setText("4.5");break;}
        case 30: {ui->GareaRateEdit->setText("4.5");break;}
        case 31: {ui->GareaRateEdit->setText("4.7");break;}
        case 32: {ui->GareaRateEdit->setText("4.7");break;}
        case 33: {ui->GareaRateEdit->setText("4.7");break;}
        case 34: {ui->GareaRateEdit->setText("4.7");break;}
        }
    }
    else
    {
        switch (ui->GareaRateCombo->currentIndex()) {
        case 0: {ui->GareaRateEdit->setText("2.75");break;}
        case 1: {ui->GareaRateEdit->setText("2.75");break;}
        case 2: {ui->GareaRateEdit->setText("3.03");break;}
        case 3: {ui->GareaRateEdit->setText("2.89");break;}
        case 4: {ui->GareaRateEdit->setText("2.34");break;}
        case 5: {ui->GareaRateEdit->setText("2.75");break;}
        case 6: {ui->GareaRateEdit->setText("3.03");break;}
        case 7: {ui->GareaRateEdit->setText("2.34");break;}
        case 8: {ui->GareaRateEdit->setText("1.93");break;}
        case 9: {ui->GareaRateEdit->setText("2.75");break;}
        case 10: {ui->GareaRateEdit->setText("3.3");break;}
        case 11: {ui->GareaRateEdit->setText("2.55");break;}
        case 12: {ui->GareaRateEdit->setText("2.1");break;}
        case 13: {ui->GareaRateEdit->setText("3");break;}
        case 14: {ui->GareaRateEdit->setText("3.57");break;}
        case 15: {ui->GareaRateEdit->setText("2.76");break;}
        case 16: {ui->GareaRateEdit->setText("2.28");break;}
        case 17: {ui->GareaRateEdit->setText("3.25");break;}
        case 18: {ui->GareaRateEdit->setText("3.85");break;}
        case 19: {ui->GareaRateEdit->setText("2.97");break;}
        case 20: {ui->GareaRateEdit->setText("2.45");break;}
        case 21: {ui->GareaRateEdit->setText("3.5");break;}
        case 22: {ui->GareaRateEdit->setText("3.75");break;}
        case 23: {ui->GareaRateEdit->setText("3.75");break;}
        case 24: {ui->GareaRateEdit->setText("3.75");break;}
        case 25: {ui->GareaRateEdit->setText("3.75");break;}
        case 26: {ui->GareaRateEdit->setText("3.75");break;}
        case 27: {ui->GareaRateEdit->setText("4");break;}
        case 28: {ui->GareaRateEdit->setText("4");break;}
        case 29: {ui->GareaRateEdit->setText("4");break;}
        case 30: {ui->GareaRateEdit->setText("4");break;}
        case 31: {ui->GareaRateEdit->setText("4.2");break;}
        case 32: {ui->GareaRateEdit->setText("4.2");break;}
        case 33: {ui->GareaRateEdit->setText("4.2");break;}
        case 34: {ui->GareaRateEdit->setText("4.2");break;}
        }
    }
}
void MainWindow::on_GareaRateEdit_textChanged(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}
void MainWindow::on_GareaRateEdit_textEdited(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}

void MainWindow::on_GareaBeginBtn_clicked()
{
    last=ui->stackedWidget->currentIndex();
    i=ui->stackedWidget->currentIndex();
    ui->rShowSf->show();
    ui->mShowSf->show();
    user.setSF();
    user.setrentMoney(true);
    user.setaverageMoney();
    if((user.getsize()==0.0)|(user.getperMoney()==0.0)|(user.getrate()==0.0))
    {
        QString text;
        if(user.getsize()==0.0&&user.getperMoney()==0.0)
        {
            text="请输入正确的房屋面积和单价";
        }
        else if(user.getsize()==0.0)
        {
            text="请输入正确的房屋面积";
        }
        else if(user.getperMoney()==0.0)
        {
            text="请输入正确的房屋单价";
        }
        else if(user.getrate()==0.0)
        {
            if(ui->GareaRateEdit->text()=="")
                text="请输入贷款利率";
            else
                text="利率输入不合法，请重新输入";
        }
        QMessageBox::warning(this,"warning",text);
    }
    else
    {
        if(ui->GareaRateBtn->isChecked())
        {
            user.rsetallMoney();
            user.setrateMoney();
            ui->rShowSf_2->setText(QString::number(user.getSF(),'f',2));
            ui->rShowYg->setText(QString::number(user.getaverageMoney(),'f',2));
            ui->rShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->rShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->rShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->rShowYs->setText(QString::number(user.getmonth(),'f',0));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：公积金贷款  还款方式：等额本息  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首付：%1元\n").arg(QString::number(user.getSF(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月月供：%1元\n").arg(QString::number(user.getaverageMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth(),'f',0)));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(5);
        }
        else
        {
            user.setfirstMoney();
            user.msetallMoney();
            user.setlessMoney();
            user.setrateMoney();
            ui->mShowSf_2->setText(QString::number(user.getSF(),'f',2));
            ui->mShowYg->setText(QString::number(user.getfirstMoney(),'f',2));
            ui->mShowDj->setText(QString::number(user.getlessMoney(),'f',2));
            ui->mShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->mShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->mShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->mShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：公积金贷款  还款方式：等额本金  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首付：%1元\n").arg(QString::number(user.getSF(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首月月供：%1元\n").arg(QString::number(user.getfirstMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月递减：%1元\n").arg(QString::number(user.getlessMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth(),'f',0)));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(6);
        }
    }
}

void MainWindow::on_GareaClearBtn_clicked()
{
    int result;
    QMessageBox *ask=new QMessageBox(this);
    ask->setWindowTitle("提示");
    ask->setText("确定要清空数据吗");
    ask->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    ask->button(QMessageBox::Yes)->setText("确定");
    ask->button(QMessageBox::No)->setText("取消");
    result=ask->exec();
    if(result==QMessageBox::Yes)
    {
        ui->GareaMoneyEdit->setText("");
        ui->GareaSizeEdit->setText("");
        ui->GareaPercent->setCurrentIndex(0);
        ui->GareaYearCombo->setCurrentIndex(0);
        ui->GareaRateCombo->setCurrentIndex(0);
        ui->GareaRateEdit->setText("3.25");
        ui->GareaRateBtn->click();
    }
    else
    {
        ask->close();
    }
}

void MainWindow::on_SareaMoneyEdit_textEdited(const QString &arg1)
{
    user.setPerMoney(arg1.toDouble());
}

void MainWindow::on_SareaSizeEdit_textEdited(const QString &arg1)
{
    user.setSize(arg1.toDouble());
}

void MainWindow::on_SareaPercent_currentIndexChanged(int index)
{
    user.setPercent(index);
}

void MainWindow::on_SareaYearCombo_currentIndexChanged(int index)
{
    user.setmonth(index);
    if(index<20)
    {
        switch (ui->SareaRateCombo->currentIndex()) {
        case 0: {ui->SareaRateEdit->setText("4.75");break;}
        case 1: {ui->SareaRateEdit->setText("4.85");break;}
        case 2: {ui->SareaRateEdit->setText("5.39");break;}
        case 3: {ui->SareaRateEdit->setText("5.15");break;}
        case 4: {ui->SareaRateEdit->setText("4.17");break;}
        case 5: {ui->SareaRateEdit->setText("3.43");break;}
        case 6: {ui->SareaRateEdit->setText("4.9");break;}
        case 7: {ui->SareaRateEdit->setText("5.67");break;}
        case 8: {ui->SareaRateEdit->setText("4.38");break;}
        case 9: {ui->SareaRateEdit->setText("3.61");break;}
        case 10: {ui->SareaRateEdit->setText("5.15");break;}
        case 11: {ui->SareaRateEdit->setText("5.94");break;}
        case 12: {ui->SareaRateEdit->setText("4.59");break;}
        case 13: {ui->SareaRateEdit->setText("3.78");break;}
        case 14: {ui->SareaRateEdit->setText("5.4");break;}
        case 15: {ui->SareaRateEdit->setText("6.22");break;}
        case 16: {ui->SareaRateEdit->setText("4.8");break;}
        case 17: {ui->SareaRateEdit->setText("3.96");break;}
        case 18: {ui->SareaRateEdit->setText("5.65");break;}
        case 19: {ui->SareaRateEdit->setText("6.49");break;}
        case 20: {ui->SareaRateEdit->setText("5.01");break;}
        case 21: {ui->SareaRateEdit->setText("4.13");break;}
        case 22: {ui->SareaRateEdit->setText("5.9");break;}
        case 23: {ui->SareaRateEdit->setText("6.7");break;}
        case 24: {ui->SareaRateEdit->setText("5.2");break;}
        case 25: {ui->SareaRateEdit->setText("4.3");break;}
        case 26: {ui->SareaRateEdit->setText("6.15");break;}
        case 27: {ui->SareaRateEdit->setText("7.21");break;}
        case 28: {ui->SareaRateEdit->setText("5.57");break;}
        case 29: {ui->SareaRateEdit->setText("4.59");break;}
        case 30: {ui->SareaRateEdit->setText("6.55");break;}
        case 31: {ui->SareaRateEdit->setText("7.48");break;}
        case 32: {ui->SareaRateEdit->setText("5.78");break;}
        case 33: {ui->SareaRateEdit->setText("4.76");break;}
        case 34: {ui->SareaRateEdit->setText("6.8");break;}
        }
    }
    else
    {
        switch (ui->SareaRateCombo->currentIndex()) {
        case 0: {ui->SareaRateEdit->setText("4.05 ");break;}
        case 1: {ui->SareaRateEdit->setText("4.2");break;}
        case 2: {ui->SareaRateEdit->setText("5.23");break;}
        case 3: {ui->SareaRateEdit->setText("4.99");break;}
        case 4: {ui->SareaRateEdit->setText("4.04");break;}
        case 5: {ui->SareaRateEdit->setText("3.33");break;}
        case 6: {ui->SareaRateEdit->setText("4.75");break;}
        case 7: {ui->SareaRateEdit->setText("5.5");break;}
        case 8: {ui->SareaRateEdit->setText("4.25");break;}
        case 9: {ui->SareaRateEdit->setText("3.5");break;}
        case 10: {ui->SareaRateEdit->setText("5");break;}
        case 11: {ui->SareaRateEdit->setText("5.78");break;}
        case 12: {ui->SareaRateEdit->setText("4.46");break;}
        case 13: {ui->SareaRateEdit->setText("3.68");break;}
        case 14: {ui->SareaRateEdit->setText("5.25");break;}
        case 15: {ui->SareaRateEdit->setText("6.05");break;}
        case 16: {ui->SareaRateEdit->setText("4.68");break;}
        case 17: {ui->SareaRateEdit->setText("3.85");break;}
        case 18: {ui->SareaRateEdit->setText("5.5");break;}
        case 19: {ui->SareaRateEdit->setText("6.33");break;}
        case 20: {ui->SareaRateEdit->setText("4.89");break;}
        case 21: {ui->SareaRateEdit->setText("4.03");break;}
        case 22: {ui->SareaRateEdit->setText("5.75");break;}
        case 23: {ui->SareaRateEdit->setText("6.6");break;}
        case 24: {ui->SareaRateEdit->setText("5.1");break;}
        case 25: {ui->SareaRateEdit->setText("4.2");break;}
        case 26: {ui->SareaRateEdit->setText("6");break;}
        case 27: {ui->SareaRateEdit->setText("7.04");break;}
        case 28: {ui->SareaRateEdit->setText("5.44");break;}
        case 29: {ui->SareaRateEdit->setText("4.48");break;}
        case 30: {ui->SareaRateEdit->setText("6.4");break;}
        case 31: {ui->SareaRateEdit->setText("7.32");break;}
        case 32: {ui->SareaRateEdit->setText("5.65");break;}
        case 33: {ui->SareaRateEdit->setText("4.66");break;}
        case 34: {ui->SareaRateEdit->setText("6.65");break;}
        }
    }
}

void MainWindow::on_SareaRateEdit_textEdited(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}

void MainWindow::on_SareaRateEdit_textChanged(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}

void MainWindow::on_SareaBeginBtn_clicked()
{
    last=ui->stackedWidget->currentIndex();
    i=ui->stackedWidget->currentIndex();
    ui->rShowSf->show();
    ui->mShowSf->show();
    user.setSF();
    user.setrentMoney(true);
    user.setaverageMoney();
    if((user.getsize()==0.0)|(user.getperMoney()==0.0)|(user.getrate()==0.0))
    {
        QString text;
        if((user.getsize()==0.0)&&(user.getperMoney()==0.0))
        {
            text="请输入正确的房屋单价和面积";
        }
        else if(user.getsize()==0.0)
        {
            text="请输入正确的房屋面积";
        }
        else if(user.getperMoney()==0.0)
        {
            text="请输入正确的房屋单价";
        }
        else if(user.getrate()==0.0)
        {
            if(ui->SareaRateEdit->text()=="")
                text="请输入贷款利率";
            else
                text="利率输入不合法，请重新输入";
        }
        QMessageBox::warning(this,"warning",text);
    }
    else
    {
        if(ui->SareaRateBtn->isChecked())
        {
            user.rsetallMoney();
            user.setrateMoney();
            ui->rShowSf_2->setText(QString::number(user.getSF(),'f',2));
            ui->rShowYg->setText(QString::number(user.getaverageMoney(),'f',2));
            ui->rShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->rShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->rShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->rShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：商业贷款  还款方式：等额本息  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首付：%1元\n").arg(QString::number(user.getSF(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月月供：%1元\n").arg(QString::number(user.getaverageMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth())));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(5);
        }
        else
        {
            user.msetallMoney();
            user.setfirstMoney();
            user.setlessMoney();
            user.setrateMoney();
            ui->mShowSf_2->setText(QString::number(user.getSF(),'f',2));
            ui->mShowYg->setText(QString::number(user.getfirstMoney(),'f',2));
            ui->mShowDj->setText(QString::number(user.getlessMoney(),'f',2));
            ui->mShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->mShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->mShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->mShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：商业贷款  还款方式：等额本金  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首付：%1元\n").arg(QString::number(user.getSF(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首月月供：%1元\n").arg(QString::number(user.getfirstMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月递减：%1元\n").arg(QString::number(user.getlessMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth())));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(6);
        }
    }
}

void MainWindow::on_SareaClearBtn_clicked()
{
    int result;
    QMessageBox *ask=new QMessageBox(this);
    ask->setWindowTitle("提示");
    ask->setText("确定要清空数据吗");
    ask->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    ask->button(QMessageBox::Yes)->setText("确定");
    ask->button(QMessageBox::No)->setText("取消");
    result=ask->exec();
    if(result==QMessageBox::Yes)
    {
        ui->SareaMoneyEdit->setText("");
        ui->SareaSizeEdit->setText("");
        ui->SareaYearCombo->setCurrentIndex(0);
        ui->SareaPercent->setCurrentIndex(0);
        ui->SareaRateCombo->setCurrentIndex(0);
        ui->SareaRateEdit->setText("4.75");
        ui->SareaRateBtn->click();
    }
    else
    {
        ask->close();
    }
}

void MainWindow::on_MSMoneyEdit_textEdited(const QString &arg1)
{
    user.setsrentMoney(arg1.toDouble());
}

void MainWindow::on_MSRateEdit_textEdited(const QString &arg1)
{
    user.setsrate(arg1.toDouble());
}

void MainWindow::on_MSRateEdit_textChanged(const QString &arg1)
{
    user.setsrate(arg1.toDouble());
}

void MainWindow::on_MGMoneyEdit_textEdited(const QString &arg1)
{
    user.setgrentMoney(arg1.toDouble());
}

void MainWindow::on_MGRateEdit_textEdited(const QString &arg1)
{
    user.setgrate(arg1.toDouble());
}

void MainWindow::on_MGRateEdit_textChanged(const QString &arg1)
{
    user.setgrate(arg1.toDouble());
}

void MainWindow::on_MYearCombo_currentIndexChanged(int index)
{
    user.setmonth(index);
    if(index<20)
    {
        switch (ui->MSRateCombo->currentIndex()) {
        case 0: {ui->MSRateEdit->setText("3.25");break;}
        case 1: {ui->MSRateEdit->setText("3.25");break;}
        case 2: {ui->MSRateEdit->setText("3.57");break;}
        case 3: {ui->MSRateEdit->setText("3.41");break;}
        case 4: {ui->MSRateEdit->setText("2.76");break;}
        case 5: {ui->MSRateEdit->setText("2.28");break;}
        case 6: {ui->MSRateEdit->setText("3.25");break;}
        case 7: {ui->MSRateEdit->setText("3.57");break;}
        case 8: {ui->MSRateEdit->setText("2.76");break;}
        case 9: {ui->MSRateEdit->setText("2.28");break;}
        case 10: {ui->MSRateEdit->setText("3.25");break;}
        case 11: {ui->MSRateEdit->setText("3.85");break;}
        case 12: {ui->MSRateEdit->setText("2.98");break;}
        case 13: {ui->MSRateEdit->setText("2.45");break;}
        case 14: {ui->MSRateEdit->setText("3.5");break;}
        case 15: {ui->MSRateEdit->setText("4.13");break;}
        case 16: {ui->MSRateEdit->setText("3.19");break;}
        case 17: {ui->MSRateEdit->setText("2.63");break;}
        case 18: {ui->MSRateEdit->setText("3.75");break;}
        case 19: {ui->MSRateEdit->setText("4.4");break;}
        case 20: {ui->MSRateEdit->setText("3.4");break;}
        case 21: {ui->MSRateEdit->setText("2.8");break;}
        case 22: {ui->MSRateEdit->setText("4");break;}
        case 23: {ui->MSRateEdit->setText("4.25");break;}
        case 24: {ui->MSRateEdit->setText("4.25");break;}
        case 25: {ui->MSRateEdit->setText("4.25");break;}
        case 26: {ui->MSRateEdit->setText("4.25");break;}
        case 27: {ui->MSRateEdit->setText("4.5");break;}
        case 28: {ui->MSRateEdit->setText("4.5");break;}
        case 29: {ui->MSRateEdit->setText("4.5");break;}
        case 30: {ui->MSRateEdit->setText("4.5");break;}
        case 31: {ui->MSRateEdit->setText("4.7");break;}
        case 32: {ui->MSRateEdit->setText("4.7");break;}
        case 33: {ui->MSRateEdit->setText("4.7");break;}
        case 34: {ui->MSRateEdit->setText("4.7");break;}
        }
        switch (ui->MGRateCombo->currentIndex()) {
        case 0: {ui->MGRateEdit->setText("3.25");break;}
        case 1: {ui->MGRateEdit->setText("3.25");break;}
        case 2: {ui->MGRateEdit->setText("3.57");break;}
        case 3: {ui->MGRateEdit->setText("3.41");break;}
        case 4: {ui->MGRateEdit->setText("2.76");break;}
        case 5: {ui->MGRateEdit->setText("2.28");break;}
        case 6: {ui->MGRateEdit->setText("3.25");break;}
        case 7: {ui->MGRateEdit->setText("3.57");break;}
        case 8: {ui->MGRateEdit->setText("2.76");break;}
        case 9: {ui->MGRateEdit->setText("2.28");break;}
        case 10: {ui->MGRateEdit->setText("3.25");break;}
        case 11: {ui->MGRateEdit->setText("3.85");break;}
        case 12: {ui->MGRateEdit->setText("2.98");break;}
        case 13: {ui->MGRateEdit->setText("2.45");break;}
        case 14: {ui->MGRateEdit->setText("3.5");break;}
        case 15: {ui->MGRateEdit->setText("4.13");break;}
        case 16: {ui->MGRateEdit->setText("3.19");break;}
        case 17: {ui->MGRateEdit->setText("2.63");break;}
        case 18: {ui->MGRateEdit->setText("3.75");break;}
        case 19: {ui->MGRateEdit->setText("4.4");break;}
        case 20: {ui->MGRateEdit->setText("3.4");break;}
        case 21: {ui->MGRateEdit->setText("2.8");break;}
        case 22: {ui->MGRateEdit->setText("4");break;}
        case 23: {ui->MGRateEdit->setText("4.25");break;}
        case 24: {ui->MGRateEdit->setText("4.25");break;}
        case 25: {ui->MGRateEdit->setText("4.25");break;}
        case 26: {ui->MGRateEdit->setText("4.25");break;}
        case 27: {ui->MGRateEdit->setText("4.5");break;}
        case 28: {ui->MGRateEdit->setText("4.5");break;}
        case 29: {ui->MGRateEdit->setText("4.5");break;}
        case 30: {ui->MGRateEdit->setText("4.5");break;}
        case 31: {ui->MGRateEdit->setText("4.7");break;}
        case 32: {ui->MGRateEdit->setText("4.7");break;}
        case 33: {ui->MGRateEdit->setText("4.7");break;}
        case 34: {ui->MGRateEdit->setText("4.7");break;}
        }
    }
    else
    {
        switch (ui->MSRateCombo->currentIndex()) {
        case 0: {ui->MSRateEdit->setText("2.75");break;}
        case 1: {ui->MSRateEdit->setText("2.75");break;}
        case 2: {ui->MSRateEdit->setText("3.03");break;}
        case 3: {ui->MSRateEdit->setText("2.89");break;}
        case 4: {ui->MSRateEdit->setText("2.34");break;}
        case 5: {ui->MSRateEdit->setText("1.93");break;}
        case 6: {ui->MSRateEdit->setText("2.75");break;}
        case 7: {ui->MSRateEdit->setText("3.03");break;}
        case 8: {ui->MSRateEdit->setText("2.34");break;}
        case 9: {ui->MSRateEdit->setText("1.93");break;}
        case 10: {ui->MSRateEdit->setText("2.75");break;}
        case 11: {ui->MSRateEdit->setText("3.3");break;}
        case 12: {ui->MSRateEdit->setText("2.55");break;}
        case 13: {ui->MSRateEdit->setText("2.1");break;}
        case 14: {ui->MSRateEdit->setText("3");break;}
        case 15: {ui->MSRateEdit->setText("3.57");break;}
        case 16: {ui->MSRateEdit->setText("2.76");break;}
        case 17: {ui->MSRateEdit->setText("2.28");break;}
        case 18: {ui->MSRateEdit->setText("3.25");break;}
        case 19: {ui->MSRateEdit->setText("3.85");break;}
        case 20: {ui->MSRateEdit->setText("2.97");break;}
        case 21: {ui->MSRateEdit->setText("2.45");break;}
        case 22: {ui->MSRateEdit->setText("3.5");break;}
        case 23: {ui->MSRateEdit->setText("3.75");break;}
        case 24: {ui->MSRateEdit->setText("3.75");break;}
        case 25: {ui->MSRateEdit->setText("3.75");break;}
        case 26: {ui->MSRateEdit->setText("3.75");break;}
        case 27: {ui->MSRateEdit->setText("4");break;}
        case 28: {ui->MSRateEdit->setText("4");break;}
        case 29: {ui->MSRateEdit->setText("4");break;}
        case 30: {ui->MSRateEdit->setText("4");break;}
        case 31: {ui->MSRateEdit->setText("4.2");break;}
        case 32: {ui->MSRateEdit->setText("4.2");break;}
        case 33: {ui->MSRateEdit->setText("4.2");break;}
        case 34: {ui->MSRateEdit->setText("4.2");break;}
        }
        switch (ui->MGRateCombo->currentIndex()) {
        case 0: {ui->MGRateEdit->setText("2.75");break;}
        case 1: {ui->MGRateEdit->setText("2.75");break;}
        case 2: {ui->MGRateEdit->setText("3.03");break;}
        case 3: {ui->MGRateEdit->setText("2.89");break;}
        case 4: {ui->MGRateEdit->setText("2.34");break;}
        case 5: {ui->MGRateEdit->setText("1.93");break;}
        case 6: {ui->MGRateEdit->setText("2.75");break;}
        case 7: {ui->MGRateEdit->setText("3.03");break;}
        case 8: {ui->MGRateEdit->setText("2.34");break;}
        case 9: {ui->MGRateEdit->setText("1.93");break;}
        case 10: {ui->MGRateEdit->setText("2.75");break;}
        case 11: {ui->MGRateEdit->setText("3.3");break;}
        case 12: {ui->MGRateEdit->setText("2.55");break;}
        case 13: {ui->MGRateEdit->setText("2.1");break;}
        case 14: {ui->MGRateEdit->setText("3");break;}
        case 15: {ui->MGRateEdit->setText("3.57");break;}
        case 16: {ui->MGRateEdit->setText("2.76");break;}
        case 17: {ui->MGRateEdit->setText("2.28");break;}
        case 18: {ui->MGRateEdit->setText("3.25");break;}
        case 19: {ui->MGRateEdit->setText("3.85");break;}
        case 20: {ui->MGRateEdit->setText("2.97");break;}
        case 21: {ui->MGRateEdit->setText("2.45");break;}
        case 22: {ui->MGRateEdit->setText("3.5");break;}
        case 23: {ui->MGRateEdit->setText("3.75");break;}
        case 24: {ui->MGRateEdit->setText("3.75");break;}
        case 25: {ui->MGRateEdit->setText("3.75");break;}
        case 26: {ui->MGRateEdit->setText("3.75");break;}
        case 27: {ui->MGRateEdit->setText("4");break;}
        case 28: {ui->MGRateEdit->setText("4");break;}
        case 29: {ui->MGRateEdit->setText("4");break;}
        case 30: {ui->MGRateEdit->setText("4");break;}
        case 31: {ui->MGRateEdit->setText("4.2");break;}
        case 32: {ui->MGRateEdit->setText("4.2");break;}
        case 33: {ui->MGRateEdit->setText("4.2");break;}
        case 34: {ui->MGRateEdit->setText("4.2");break;}
        }
    }
}

void MainWindow::on_MBeginBtn_clicked()
{
    last=ui->stackedWidget->currentIndex();
    i=ui->stackedWidget->currentIndex();
    ui->rShowSf->hide();
    ui->mShowSf->hide();
    user.setrentMoney(user.getsrentMoney()+user.getgrentMoney());
    if((user.getsrentMoney()==0.0)|(user.getgrentMoney()==0.0)|(user.getsrate()==0.0)|(user.getgrate()==0.0))
    {
        QString text;
        if((user.getsrentMoney()==0.0)&&(user.getgrentMoney()==0.0))
        {
            text="请输入正确的商业贷款和公积金贷款金额";
        }
        else if(user.getsrentMoney()==0.0)
        {
            text="请输入正确的商业贷款额";
        }
        else if(user.getgrentMoney()==0.0)
        {
            text="请输入正确的公积金贷款额";
        }
        else if((user.getsrate()==0.0)|(user.getgrate()==0.0))
        {
            if(user.getsrate()==0.0&&user.getgrate()==0.0)
            {
                if(ui->MSRateEdit->text()==""&&ui->MGRateEdit->text()=="")
                    text="请输入商业贷款及公积金贷款的利率";
                else
                    text="请输入正确的商业贷款及公积金贷款利率";
            }
            else if(user.getsrate()==0.0)
            {
                if(ui->MSRateEdit->text()=="")
                    text="请输入商业贷款利率";
                else
                    text="请输入正确的商业贷款利率";
            }
            else
            {
                if(ui->MGRateEdit->text()=="")
                    text="请输入公积金贷款利率";
                else
                    text="请输入正确的公积金贷款利率";
            }
        }
        QMessageBox::warning(this,"warning",text);
    }
    else
    {
        if(ui->MRateBtn->isChecked())
        {
            user.setsaveragemoney();
            user.setgaveragemoney();
            user.setaverageMoney(user.getsaveragemoney()+user.getgaveragemoney());
            user.rsetallMoney();
            user.setrateMoney();
            ui->rShowYg->setText(QString::number(user.getaverageMoney(),'f',2));
            ui->rShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->rShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->rShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->rShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：组合贷款  还款方式：等额本息  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月月供：%1元\n").arg(QString::number(user.getaverageMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth())));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(5);
        }
        else
        {
            user.setsallMoney();
            user.setgallMoney();
            user.setsfirstMoney();
            user.setgfirstMoney();
            user.setslessMoney();
            user.setglessMoney();
            user.setrateMoney();
            ui->mShowYg->setText(QString::number(user.getsfirstMoney()+user.getgfirstMoney(),'f',2));
            ui->mShowDj->setText(QString::number(user.getslessMoney()+user.getglessMoney(),'f',2));
            ui->mShowDkze->setText(QString::number(user.getrentMoney(),'f',0));
            ui->mShowLx->setText(QString::number(user.getgallMoney()+user.getsallMoney()-user.getrentMoney(),'f',2));
            ui->mShowHkze->setText(QString::number(user.getsallMoney()+user.getgallMoney(),'f',2));
            ui->mShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：组合贷款  还款方式：等额本金  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首月月供：%1元\n").arg(QString::number(user.getfirstMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月递减：%1元\n").arg(QString::number(user.getlessMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth())));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(6);
        }
    }
}

void MainWindow::on_MClearBtn_clicked()
{
    int result;
    QMessageBox *ask=new QMessageBox(this);
    ask->setWindowTitle("提示");
    ask->setText("确定要清空数据吗");
    ask->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    ask->button(QMessageBox::Yes)->setText("确定");
    ask->button(QMessageBox::No)->setText("取消");
    result=ask->exec();
    if(result==QMessageBox::Yes)
    {
        ui->MSMoneyEdit->setText("");
        ui->MSRateCombo->setCurrentIndex(0);
        ui->MGMoneyEdit->setText("");
        ui->MSRateCombo->setCurrentIndex(0);
        ui->MYearCombo->setCurrentIndex(0);
        ui->MSRateEdit->setText("3.25");
        ui->MGRateEdit->setText("3.25");
        ui->MRateBtn->click();
    }
    else
    {
        ask->close();
    }
}

void MainWindow::on_GmoneyEdit_textEdited(const QString &arg1)
{
    user.setrentMoney(arg1.toDouble());
}

void MainWindow::on_GmoneyYearCombo_currentIndexChanged(int index)
{
    user.setmonth(index);
    if(index<20)
    {
        switch (ui->GmoneyRateCombo->currentIndex()) {
        case 0: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 1: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 2: {ui->GmoneyRateEdit->setText("3.57");break;}
        case 3: {ui->GmoneyRateEdit->setText("3.41");break;}
        case 4: {ui->GmoneyRateEdit->setText("2.76");break;}
        case 5: {ui->GmoneyRateEdit->setText("2.28");break;}
        case 6: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 7: {ui->GmoneyRateEdit->setText("3.57");break;}
        case 8: {ui->GmoneyRateEdit->setText("2.76");break;}
        case 9: {ui->GmoneyRateEdit->setText("2.28");break;}
        case 10: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 11: {ui->GmoneyRateEdit->setText("3.85");break;}
        case 12: {ui->GmoneyRateEdit->setText("2.98");break;}
        case 13: {ui->GmoneyRateEdit->setText("2.45");break;}
        case 14: {ui->GmoneyRateEdit->setText("3.5");break;}
        case 15: {ui->GmoneyRateEdit->setText("4.13");break;}
        case 16: {ui->GmoneyRateEdit->setText("3.19");break;}
        case 17: {ui->GmoneyRateEdit->setText("2.63");break;}
        case 18: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 19: {ui->GmoneyRateEdit->setText("4.4");break;}
        case 20: {ui->GmoneyRateEdit->setText("3.4");break;}
        case 21: {ui->GmoneyRateEdit->setText("2.8");break;}
        case 22: {ui->GmoneyRateEdit->setText("4");break;}
        case 23: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 24: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 25: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 26: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 27: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 28: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 29: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 30: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 31: {ui->GmoneyRateEdit->setText("4.7");break;}
        case 32: {ui->GmoneyRateEdit->setText("4.7");break;}
        case 33: {ui->GmoneyRateEdit->setText("4.7");break;}
        case 34: {ui->GmoneyRateEdit->setText("4.7");break;}
        }
    }
    else
    {
        switch (ui->GmoneyRateCombo->currentIndex()) {
        case 0: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 1: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 2: {ui->GmoneyRateEdit->setText("3.03");break;}
        case 3: {ui->GmoneyRateEdit->setText("2.89");break;}
        case 4: {ui->GmoneyRateEdit->setText("2.34");break;}
        case 5: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 6: {ui->GmoneyRateEdit->setText("3.03");break;}
        case 7: {ui->GmoneyRateEdit->setText("2.34");break;}
        case 8: {ui->GmoneyRateEdit->setText("1.93");break;}
        case 9: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 10: {ui->GmoneyRateEdit->setText("3.3");break;}
        case 11: {ui->GmoneyRateEdit->setText("2.55");break;}
        case 12: {ui->GmoneyRateEdit->setText("2.1");break;}
        case 13: {ui->GmoneyRateEdit->setText("3");break;}
        case 14: {ui->GmoneyRateEdit->setText("3.57");break;}
        case 15: {ui->GmoneyRateEdit->setText("2.76");break;}
        case 16: {ui->GmoneyRateEdit->setText("2.28");break;}
        case 17: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 18: {ui->GmoneyRateEdit->setText("3.85");break;}
        case 19: {ui->GmoneyRateEdit->setText("2.97");break;}
        case 20: {ui->GmoneyRateEdit->setText("2.45");break;}
        case 21: {ui->GmoneyRateEdit->setText("3.5");break;}
        case 22: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 23: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 24: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 25: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 26: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 27: {ui->GmoneyRateEdit->setText("4");break;}
        case 28: {ui->GmoneyRateEdit->setText("4");break;}
        case 29: {ui->GmoneyRateEdit->setText("4");break;}
        case 30: {ui->GmoneyRateEdit->setText("4");break;}
        case 31: {ui->GmoneyRateEdit->setText("4.2");break;}
        case 32: {ui->GmoneyRateEdit->setText("4.2");break;}
        case 33: {ui->GmoneyRateEdit->setText("4.2");break;}
        case 34: {ui->GmoneyRateEdit->setText("4.2");break;}
        }
    }
}

void MainWindow::on_GmoneyRateEdit_textEdited(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}

void MainWindow::on_GmoneyRateEdit_textChanged(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}

void MainWindow::on_GmoneyBeginBtn_clicked()
{
    last=ui->stackedWidget->currentIndex();
    i=ui->stackedWidget->currentIndex();
    ui->rShowSf->hide();
    ui->mShowSf->hide();
    user.setaverageMoney();
    QString text;
    if((user.getrentMoney()==0.0)|(user.getrate()==0.0))
    {
        if(user.getrentMoney()==0.0)
        {
            text="请输入正确的贷款总额";
        }
        else if(user.getrate()==0.0)
        {
            if(ui->GmoneyRateEdit->text()=="")
                text="请输入贷款利率";
            else
                text="利率输入不合法，请重新输入";
        }
        QMessageBox::warning(this,"warning",text);
    }
    else
    {
        if(ui->GMoneyRateBtn->isChecked())
        {
            user.rsetallMoney();
            user.setrateMoney();
            ui->rShowYg->setText(QString::number(user.getaverageMoney(),'f',2));
            ui->rShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->rShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->rShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->rShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：公积金贷款  还款方式：等额本息  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月月供：%1元\n").arg(QString::number(user.getaverageMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth())));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(5);
        }
        else
        {
            user.setfirstMoney();
            user.msetallMoney();
            user.setrateMoney();
            user.setlessMoney();
            ui->mShowYg->setText(QString::number(user.getfirstMoney(),'f',0));
            ui->mShowDj->setText(QString::number(user.getlessMoney(),'f',0));
            ui->mShowDkze->setText(QString::number(user.getrentMoney(),'f',0));
            ui->mShowLx->setText(QString::number(user.getrateMoney(),'f',0));
            ui->mShowHkze->setText(QString::number(user.getallMoney(),'f',0));
            ui->mShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：公积金贷款  还款方式：等额本金  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',0)));
            ui->textBrowser->insertPlainText(tr("首月月供：%1元\n").arg(QString::number(user.getfirstMoney(),'f',0)));
            ui->textBrowser->insertPlainText(tr("每月递减：%1元\n").arg(QString::number(user.getlessMoney(),'f',0)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',0)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',0)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth(),'f',0)));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(6);
        }
    }
}

void MainWindow::on_GmoneyClearBtn_clicked()
{
    int result;
    QMessageBox *ask=new QMessageBox(this);
    ask->setWindowTitle("提示");
    ask->setText("确定要清空数据吗");
    ask->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    ask->button(QMessageBox::Yes)->setText("确定");
    ask->button(QMessageBox::No)->setText("取消");
    result=ask->exec();
    if(result==QMessageBox::Yes)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        ask->close();
    }
}

void MainWindow::on_SmoneyEdit_textEdited(const QString &arg1)
{
    user.setrentMoney(arg1.toDouble());
}

void MainWindow::on_SMoneyYearCombo_currentIndexChanged(int index)
{
    user.setmonth(index);
    if(index<20)
    {
        switch (ui->SmoneyRateCombo->currentIndex()) {
        case 0: {ui->SmoneyRateEdit->setText("4.75");break;}
        case 1: {ui->SmoneyRateEdit->setText("4.85");break;}
        case 2: {ui->SmoneyRateEdit->setText("5.39");break;}
        case 3: {ui->SmoneyRateEdit->setText("5.15");break;}
        case 4: {ui->SmoneyRateEdit->setText("4.17");break;}
        case 5: {ui->SmoneyRateEdit->setText("3.43");break;}
        case 6: {ui->SmoneyRateEdit->setText("4.9");break;}
        case 7: {ui->SmoneyRateEdit->setText("5.67");break;}
        case 8: {ui->SmoneyRateEdit->setText("4.38");break;}
        case 9: {ui->SmoneyRateEdit->setText("3.61");break;}
        case 10: {ui->SmoneyRateEdit->setText("5.15");break;}
        case 11: {ui->SmoneyRateEdit->setText("5.94");break;}
        case 12: {ui->SmoneyRateEdit->setText("4.59");break;}
        case 13: {ui->SmoneyRateEdit->setText("3.78");break;}
        case 14: {ui->SmoneyRateEdit->setText("5.4");break;}
        case 15: {ui->SmoneyRateEdit->setText("6.22");break;}
        case 16: {ui->SmoneyRateEdit->setText("4.8");break;}
        case 17: {ui->SmoneyRateEdit->setText("3.96");break;}
        case 18: {ui->SmoneyRateEdit->setText("5.65");break;}
        case 19: {ui->SmoneyRateEdit->setText("6.49");break;}
        case 20: {ui->SmoneyRateEdit->setText("5.01");break;}
        case 21: {ui->SmoneyRateEdit->setText("4.13");break;}
        case 22: {ui->SmoneyRateEdit->setText("5.9");break;}
        case 23: {ui->SmoneyRateEdit->setText("6.7");break;}
        case 24: {ui->SmoneyRateEdit->setText("5.2");break;}
        case 25: {ui->SmoneyRateEdit->setText("4.3");break;}
        case 26: {ui->SmoneyRateEdit->setText("6.15");break;}
        case 27: {ui->SmoneyRateEdit->setText("7.21");break;}
        case 28: {ui->SmoneyRateEdit->setText("5.57");break;}
        case 29: {ui->SmoneyRateEdit->setText("4.59");break;}
        case 30: {ui->SmoneyRateEdit->setText("6.55");break;}
        case 31: {ui->SmoneyRateEdit->setText("7.48");break;}
        case 32: {ui->SmoneyRateEdit->setText("5.78");break;}
        case 33: {ui->SmoneyRateEdit->setText("4.76");break;}
        case 34: {ui->SmoneyRateEdit->setText("6.8");break;}
        }
    }
    else
    {
        switch (ui->SmoneyRateCombo->currentIndex()) {
        case 0: {ui->SmoneyRateEdit->setText("4.05 ");break;}
        case 1: {ui->SmoneyRateEdit->setText("4.2");break;}
        case 2: {ui->SmoneyRateEdit->setText("5.23");break;}
        case 3: {ui->SmoneyRateEdit->setText("4.99");break;}
        case 4: {ui->SmoneyRateEdit->setText("4.04");break;}
        case 5: {ui->SmoneyRateEdit->setText("3.33");break;}
        case 6: {ui->SmoneyRateEdit->setText("4.75");break;}
        case 7: {ui->SmoneyRateEdit->setText("5.5");break;}
        case 8: {ui->SmoneyRateEdit->setText("4.25");break;}
        case 9: {ui->SmoneyRateEdit->setText("3.5");break;}
        case 10: {ui->SmoneyRateEdit->setText("5");break;}
        case 11: {ui->SmoneyRateEdit->setText("5.78");break;}
        case 12: {ui->SmoneyRateEdit->setText("4.46");break;}
        case 13: {ui->SmoneyRateEdit->setText("3.68");break;}
        case 14: {ui->SmoneyRateEdit->setText("5.25");break;}
        case 15: {ui->SmoneyRateEdit->setText("6.05");break;}
        case 16: {ui->SmoneyRateEdit->setText("4.68");break;}
        case 17: {ui->SmoneyRateEdit->setText("3.85");break;}
        case 18: {ui->SmoneyRateEdit->setText("5.5");break;}
        case 19: {ui->SmoneyRateEdit->setText("6.33");break;}
        case 20: {ui->SmoneyRateEdit->setText("4.89");break;}
        case 21: {ui->SmoneyRateEdit->setText("4.03");break;}
        case 22: {ui->SmoneyRateEdit->setText("5.75");break;}
        case 23: {ui->SmoneyRateEdit->setText("6.6");break;}
        case 24: {ui->SmoneyRateEdit->setText("5.1");break;}
        case 25: {ui->SmoneyRateEdit->setText("4.2");break;}
        case 26: {ui->SmoneyRateEdit->setText("6");break;}
        case 27: {ui->SmoneyRateEdit->setText("7.04");break;}
        case 28: {ui->SmoneyRateEdit->setText("5.44");break;}
        case 29: {ui->SmoneyRateEdit->setText("4.48");break;}
        case 30: {ui->SmoneyRateEdit->setText("6.4");break;}
        case 31: {ui->SmoneyRateEdit->setText("7.32");break;}
        case 32: {ui->SmoneyRateEdit->setText("5.65");break;}
        case 33: {ui->SmoneyRateEdit->setText("4.66");break;}
        case 34: {ui->SmoneyRateEdit->setText("6.65");break;}
        }
    }
}

void MainWindow::on_SmoneyRateEdit_textEdited(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}

void MainWindow::on_SmoneyRateEdit_textChanged(const QString &arg1)
{
    user.setrate(arg1.toDouble());
}

void MainWindow::on_SmoneyBeginBtn_clicked()
{
    last=ui->stackedWidget->currentIndex();
    i=ui->stackedWidget->currentIndex();
    ui->rShowSf->hide();
    ui->mShowSf->hide();
    user.setaverageMoney();
    QString text;
    if((user.getrentMoney()==0.0)|(user.getrate()==0.0))
    {
        if(user.getrentMoney()==0.0)
        {
            text="请输入正确的贷款总额";
        }
        else if(user.getrate()==0.0)
        {
            if(ui->SmoneyRateEdit->text()=="")
                text="请输入贷款利率";
            else
                text="利率输入不合法，请重新输入";
        }
        QMessageBox::warning(this,"warning",text);
    }
    else
    {
        if(ui->SMoneyRateBtn->isChecked())
        {
            user.rsetallMoney();
            user.setrateMoney();
            ui->rShowYg->setText(QString::number(user.getaverageMoney(),'f',2));
            ui->rShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->rShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->rShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->rShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：商业贷款  还款方式：等额本息  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月月供：%1元\n").arg(QString::number(user.getaverageMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth())));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(5);
        }
        else
        {
            user.setfirstMoney();
            user.msetallMoney();
            user.setlessMoney();
            user.setrateMoney();
            ui->mShowYg->setText(QString::number(user.getfirstMoney(),'f',2));
            ui->mShowDj->setText(QString::number(user.getlessMoney(),'f',2));
            ui->mShowDkze->setText(QString::number(user.getrentMoney(),'f',2));
            ui->mShowLx->setText(QString::number(user.getrateMoney(),'f',2));
            ui->mShowHkze->setText(QString::number(user.getallMoney(),'f',2));
            ui->mShowYs->setText(QString::number(user.getmonth()));
            QDateTime time=QDateTime::currentDateTime();
            ui->textBrowser->insertPlainText(time.toString("yyyy.MM.dd hh:mm:ss"));
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText(tr("贷款方式：公积金贷款  还款方式：等额本金  "));
            ui->textBrowser->insertPlainText(tr("贷款利率：%1%\n").arg(QString::number(user.getrate()*100,'f',2)));
            ui->textBrowser->insertPlainText(tr("贷款总额：%1元\n").arg(QString::number(user.getrentMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("首月月供：%1元\n").arg(QString::number(user.getfirstMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("每月递减：%1元\n").arg(QString::number(user.getlessMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("支付利息：%1\n").arg(QString::number(user.getrateMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款总额：%1元\n").arg(QString::number(user.getallMoney(),'f',2)));
            ui->textBrowser->insertPlainText(tr("还款月数：%1个月\n").arg(QString::number(user.getmonth())));
            ui->textBrowser->insertPlainText("-----------------------------------------------------------------\n");
            ui->textBrowser->moveCursor(QTextCursor::End);
            ui->stackedWidget->setCurrentIndex(6);
        }
    }
}

void MainWindow::on_SmoneyClearBtn_clicked()
{
    int result;
    QMessageBox *ask=new QMessageBox(this);
    ask->setWindowTitle("提示");
    ask->setText("确定要清空数据吗");
    ask->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    ask->button(QMessageBox::Yes)->setText("确定");
    ask->button(QMessageBox::No)->setText("取消");
    result=ask->exec();
    if(result==QMessageBox::Yes)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ask->close();
    }
}

void MainWindow::on_rateBack_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(i);
}

void MainWindow::on_moneyBack_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(i);
}

void MainWindow::on_GareaRateCombo_currentIndexChanged(int index)
{
    if(ui->GareaYearCombo->currentIndex()<20)
    {
        switch (index) {
        case 0: {ui->GareaRateEdit->setText("3.25");break;}
        case 1: {ui->GareaRateEdit->setText("3.25");break;}
        case 2: {ui->GareaRateEdit->setText("3.57");break;}
        case 3: {ui->GareaRateEdit->setText("3.41");break;}
        case 4: {ui->GareaRateEdit->setText("2.76");break;}
        case 5: {ui->GareaRateEdit->setText("2.28");break;}
        case 6: {ui->GareaRateEdit->setText("3.25");break;}
        case 7: {ui->GareaRateEdit->setText("3.57");break;}
        case 8: {ui->GareaRateEdit->setText("2.76");break;}
        case 9: {ui->GareaRateEdit->setText("2.28");break;}
        case 10: {ui->GareaRateEdit->setText("3.25");break;}
        case 11: {ui->GareaRateEdit->setText("3.85");break;}
        case 12: {ui->GareaRateEdit->setText("2.98");break;}
        case 13: {ui->GareaRateEdit->setText("2.45");break;}
        case 14: {ui->GareaRateEdit->setText("3.5");break;}
        case 15: {ui->GareaRateEdit->setText("4.13");break;}
        case 16: {ui->GareaRateEdit->setText("3.19");break;}
        case 17: {ui->GareaRateEdit->setText("2.63");break;}
        case 18: {ui->GareaRateEdit->setText("3.75");break;}
        case 19: {ui->GareaRateEdit->setText("4.4");break;}
        case 20: {ui->GareaRateEdit->setText("3.4");break;}
        case 21: {ui->GareaRateEdit->setText("2.8");break;}
        case 22: {ui->GareaRateEdit->setText("4");break;}
        case 23: {ui->GareaRateEdit->setText("4.25");break;}
        case 24: {ui->GareaRateEdit->setText("4.25");break;}
        case 25: {ui->GareaRateEdit->setText("4.25");break;}
        case 26: {ui->GareaRateEdit->setText("4.25");break;}
        case 27: {ui->GareaRateEdit->setText("4.5");break;}
        case 28: {ui->GareaRateEdit->setText("4.5");break;}
        case 29: {ui->GareaRateEdit->setText("4.5");break;}
        case 30: {ui->GareaRateEdit->setText("4.5");break;}
        case 31: {ui->GareaRateEdit->setText("4.7");break;}
        case 32: {ui->GareaRateEdit->setText("4.7");break;}
        case 33: {ui->GareaRateEdit->setText("4.7");break;}
        case 34: {ui->GareaRateEdit->setText("4.7");break;}
        }
    }
    else
    {
        switch (index) {
        case 0: {ui->GareaRateEdit->setText("2.75");break;}
        case 1: {ui->GareaRateEdit->setText("2.75");break;}
        case 2: {ui->GareaRateEdit->setText("3.03");break;}
        case 3: {ui->GareaRateEdit->setText("2.89");break;}
        case 4: {ui->GareaRateEdit->setText("2.34");break;}
        case 5: {ui->GareaRateEdit->setText("2.75");break;}
        case 6: {ui->GareaRateEdit->setText("3.03");break;}
        case 7: {ui->GareaRateEdit->setText("2.34");break;}
        case 8: {ui->GareaRateEdit->setText("1.93");break;}
        case 9: {ui->GareaRateEdit->setText("2.75");break;}
        case 10: {ui->GareaRateEdit->setText("3.3");break;}
        case 11: {ui->GareaRateEdit->setText("2.55");break;}
        case 12: {ui->GareaRateEdit->setText("2.1");break;}
        case 13: {ui->GareaRateEdit->setText("3");break;}
        case 14: {ui->GareaRateEdit->setText("3.57");break;}
        case 15: {ui->GareaRateEdit->setText("2.76");break;}
        case 16: {ui->GareaRateEdit->setText("2.28");break;}
        case 17: {ui->GareaRateEdit->setText("3.25");break;}
        case 18: {ui->GareaRateEdit->setText("3.85");break;}
        case 19: {ui->GareaRateEdit->setText("2.97");break;}
        case 20: {ui->GareaRateEdit->setText("2.45");break;}
        case 21: {ui->GareaRateEdit->setText("3.5");break;}
        case 22: {ui->GareaRateEdit->setText("3.75");break;}
        case 23: {ui->GareaRateEdit->setText("3.75");break;}
        case 24: {ui->GareaRateEdit->setText("3.75");break;}
        case 25: {ui->GareaRateEdit->setText("3.75");break;}
        case 26: {ui->GareaRateEdit->setText("3.75");break;}
        case 27: {ui->GareaRateEdit->setText("4");break;}
        case 28: {ui->GareaRateEdit->setText("4");break;}
        case 29: {ui->GareaRateEdit->setText("4");break;}
        case 30: {ui->GareaRateEdit->setText("4");break;}
        case 31: {ui->GareaRateEdit->setText("4.2");break;}
        case 32: {ui->GareaRateEdit->setText("4.2");break;}
        case 33: {ui->GareaRateEdit->setText("4.2");break;}
        case 34: {ui->GareaRateEdit->setText("4.2");break;}
        }
    }
}

void MainWindow::on_SareaRateCombo_currentIndexChanged(int index)
{
    if(ui->SareaYearCombo->currentIndex()<20)
    {
        switch (index) {
        case 0: {ui->SareaRateEdit->setText("4.75");break;}
        case 1: {ui->SareaRateEdit->setText("4.85");break;}
        case 2: {ui->SareaRateEdit->setText("5.39");break;}
        case 3: {ui->SareaRateEdit->setText("5.15");break;}
        case 4: {ui->SareaRateEdit->setText("4.17");break;}
        case 5: {ui->SareaRateEdit->setText("3.43");break;}
        case 6: {ui->SareaRateEdit->setText("4.9");break;}
        case 7: {ui->SareaRateEdit->setText("5.67");break;}
        case 8: {ui->SareaRateEdit->setText("4.38");break;}
        case 9: {ui->SareaRateEdit->setText("3.61");break;}
        case 10: {ui->SareaRateEdit->setText("5.15");break;}
        case 11: {ui->SareaRateEdit->setText("5.94");break;}
        case 12: {ui->SareaRateEdit->setText("4.59");break;}
        case 13: {ui->SareaRateEdit->setText("3.78");break;}
        case 14: {ui->SareaRateEdit->setText("5.4");break;}
        case 15: {ui->SareaRateEdit->setText("6.22");break;}
        case 16: {ui->SareaRateEdit->setText("4.8");break;}
        case 17: {ui->SareaRateEdit->setText("3.96");break;}
        case 18: {ui->SareaRateEdit->setText("5.65");break;}
        case 19: {ui->SareaRateEdit->setText("6.49");break;}
        case 20: {ui->SareaRateEdit->setText("5.01");break;}
        case 21: {ui->SareaRateEdit->setText("4.13");break;}
        case 22: {ui->SareaRateEdit->setText("5.9");break;}
        case 23: {ui->SareaRateEdit->setText("6.7");break;}
        case 24: {ui->SareaRateEdit->setText("5.2");break;}
        case 25: {ui->SareaRateEdit->setText("4.3");break;}
        case 26: {ui->SareaRateEdit->setText("6.15");break;}
        case 27: {ui->SareaRateEdit->setText("7.21");break;}
        case 28: {ui->SareaRateEdit->setText("5.57");break;}
        case 29: {ui->SareaRateEdit->setText("4.59");break;}
        case 30: {ui->SareaRateEdit->setText("6.55");break;}
        case 31: {ui->SareaRateEdit->setText("7.48");break;}
        case 32: {ui->SareaRateEdit->setText("5.78");break;}
        case 33: {ui->SareaRateEdit->setText("4.76");break;}
        case 34: {ui->SareaRateEdit->setText("6.8");break;}
        }
    }
    else
    {
        switch (index) {
        case 0: {ui->SareaRateEdit->setText("4.05 ");break;}
        case 1: {ui->SareaRateEdit->setText("4.2");break;}
        case 2: {ui->SareaRateEdit->setText("5.23");break;}
        case 3: {ui->SareaRateEdit->setText("4.99");break;}
        case 4: {ui->SareaRateEdit->setText("4.04");break;}
        case 5: {ui->SareaRateEdit->setText("3.33");break;}
        case 6: {ui->SareaRateEdit->setText("4.75");break;}
        case 7: {ui->SareaRateEdit->setText("5.5");break;}
        case 8: {ui->SareaRateEdit->setText("4.25");break;}
        case 9: {ui->SareaRateEdit->setText("3.5");break;}
        case 10: {ui->SareaRateEdit->setText("5");break;}
        case 11: {ui->SareaRateEdit->setText("5.78");break;}
        case 12: {ui->SareaRateEdit->setText("4.46");break;}
        case 13: {ui->SareaRateEdit->setText("3.68");break;}
        case 14: {ui->SareaRateEdit->setText("5.25");break;}
        case 15: {ui->SareaRateEdit->setText("6.05");break;}
        case 16: {ui->SareaRateEdit->setText("4.68");break;}
        case 17: {ui->SareaRateEdit->setText("3.85");break;}
        case 18: {ui->SareaRateEdit->setText("5.5");break;}
        case 19: {ui->SareaRateEdit->setText("6.33");break;}
        case 20: {ui->SareaRateEdit->setText("4.89");break;}
        case 21: {ui->SareaRateEdit->setText("4.03");break;}
        case 22: {ui->SareaRateEdit->setText("5.75");break;}
        case 23: {ui->SareaRateEdit->setText("6.6");break;}
        case 24: {ui->SareaRateEdit->setText("5.1");break;}
        case 25: {ui->SareaRateEdit->setText("4.2");break;}
        case 26: {ui->SareaRateEdit->setText("6");break;}
        case 27: {ui->SareaRateEdit->setText("7.04");break;}
        case 28: {ui->SareaRateEdit->setText("5.44");break;}
        case 29: {ui->SareaRateEdit->setText("4.48");break;}
        case 30: {ui->SareaRateEdit->setText("6.4");break;}
        case 31: {ui->SareaRateEdit->setText("7.32");break;}
        case 32: {ui->SareaRateEdit->setText("5.65");break;}
        case 33: {ui->SareaRateEdit->setText("4.66");break;}
        case 34: {ui->SareaRateEdit->setText("6.65");break;}
        }
    }
}

void MainWindow::on_MSRateCombo_currentIndexChanged(int index)
{
    if(ui->MYearCombo->currentIndex()<20)
    {
        switch (index) {
        case 0: {ui->MSRateEdit->setText("3.25");break;}
        case 1: {ui->MSRateEdit->setText("3.25");break;}
        case 2: {ui->MSRateEdit->setText("3.57");break;}
        case 3: {ui->MSRateEdit->setText("3.41");break;}
        case 4: {ui->MSRateEdit->setText("2.76");break;}
        case 5: {ui->MSRateEdit->setText("2.28");break;}
        case 6: {ui->MSRateEdit->setText("3.25");break;}
        case 7: {ui->MSRateEdit->setText("3.57");break;}
        case 8: {ui->MSRateEdit->setText("2.76");break;}
        case 9: {ui->MSRateEdit->setText("2.28");break;}
        case 10: {ui->MSRateEdit->setText("3.25");break;}
        case 11: {ui->MSRateEdit->setText("3.85");break;}
        case 12: {ui->MSRateEdit->setText("2.98");break;}
        case 13: {ui->MSRateEdit->setText("2.45");break;}
        case 14: {ui->MSRateEdit->setText("3.5");break;}
        case 15: {ui->MSRateEdit->setText("4.13");break;}
        case 16: {ui->MSRateEdit->setText("3.19");break;}
        case 17: {ui->MSRateEdit->setText("2.63");break;}
        case 18: {ui->MSRateEdit->setText("3.75");break;}
        case 19: {ui->MSRateEdit->setText("4.4");break;}
        case 20: {ui->MSRateEdit->setText("3.4");break;}
        case 21: {ui->MSRateEdit->setText("2.8");break;}
        case 22: {ui->MSRateEdit->setText("4");break;}
        case 23: {ui->MSRateEdit->setText("4.25");break;}
        case 24: {ui->MSRateEdit->setText("4.25");break;}
        case 25: {ui->MSRateEdit->setText("4.25");break;}
        case 26: {ui->MSRateEdit->setText("4.25");break;}
        case 27: {ui->MSRateEdit->setText("4.5");break;}
        case 28: {ui->MSRateEdit->setText("4.5");break;}
        case 29: {ui->MSRateEdit->setText("4.5");break;}
        case 30: {ui->MSRateEdit->setText("4.5");break;}
        case 31: {ui->MSRateEdit->setText("4.7");break;}
        case 32: {ui->MSRateEdit->setText("4.7");break;}
        case 33: {ui->MSRateEdit->setText("4.7");break;}
        case 34: {ui->MSRateEdit->setText("4.7");break;}
        }
    }
    else
    {
        switch (index) {
        case 0: {ui->MSRateEdit->setText("2.75");break;}
        case 1: {ui->MSRateEdit->setText("2.75");break;}
        case 2: {ui->MSRateEdit->setText("3.03");break;}
        case 3: {ui->MSRateEdit->setText("2.89");break;}
        case 4: {ui->MSRateEdit->setText("2.34");break;}
        case 5: {ui->MSRateEdit->setText("1.93");break;}
        case 6: {ui->MSRateEdit->setText("2.75");break;}
        case 7: {ui->MSRateEdit->setText("3.03");break;}
        case 8: {ui->MSRateEdit->setText("2.34");break;}
        case 9: {ui->MSRateEdit->setText("1.93");break;}
        case 10: {ui->MSRateEdit->setText("2.75");break;}
        case 11: {ui->MSRateEdit->setText("3.3");break;}
        case 12: {ui->MSRateEdit->setText("2.55");break;}
        case 13: {ui->MSRateEdit->setText("2.1");break;}
        case 14: {ui->MSRateEdit->setText("3");break;}
        case 15: {ui->MSRateEdit->setText("3.57");break;}
        case 16: {ui->MSRateEdit->setText("2.76");break;}
        case 17: {ui->MSRateEdit->setText("2.28");break;}
        case 18: {ui->MSRateEdit->setText("3.25");break;}
        case 19: {ui->MSRateEdit->setText("3.85");break;}
        case 20: {ui->MSRateEdit->setText("2.97");break;}
        case 21: {ui->MSRateEdit->setText("2.45");break;}
        case 22: {ui->MSRateEdit->setText("3.5");break;}
        case 23: {ui->MSRateEdit->setText("3.75");break;}
        case 24: {ui->MSRateEdit->setText("3.75");break;}
        case 25: {ui->MSRateEdit->setText("3.75");break;}
        case 26: {ui->MSRateEdit->setText("3.75");break;}
        case 27: {ui->MSRateEdit->setText("4");break;}
        case 28: {ui->MSRateEdit->setText("4");break;}
        case 29: {ui->MSRateEdit->setText("4");break;}
        case 30: {ui->MSRateEdit->setText("4");break;}
        case 31: {ui->MSRateEdit->setText("4.2");break;}
        case 32: {ui->MSRateEdit->setText("4.2");break;}
        case 33: {ui->MSRateEdit->setText("4.2");break;}
        case 34: {ui->MSRateEdit->setText("4.2");break;}
        }
    }
}

void MainWindow::on_MGRateCombo_currentIndexChanged(int index)
{
    if(ui->MYearCombo->currentIndex()<20)
    {
        switch (index) {
        case 0: {ui->MGRateEdit->setText("3.25");break;}
        case 1: {ui->MGRateEdit->setText("3.25");break;}
        case 2: {ui->MGRateEdit->setText("3.57");break;}
        case 3: {ui->MGRateEdit->setText("3.41");break;}
        case 4: {ui->MGRateEdit->setText("2.76");break;}
        case 5: {ui->MGRateEdit->setText("2.28");break;}
        case 6: {ui->MGRateEdit->setText("3.25");break;}
        case 7: {ui->MGRateEdit->setText("3.57");break;}
        case 8: {ui->MGRateEdit->setText("2.76");break;}
        case 9: {ui->MGRateEdit->setText("2.28");break;}
        case 10: {ui->MGRateEdit->setText("3.25");break;}
        case 11: {ui->MGRateEdit->setText("3.85");break;}
        case 12: {ui->MGRateEdit->setText("2.98");break;}
        case 13: {ui->MGRateEdit->setText("2.45");break;}
        case 14: {ui->MGRateEdit->setText("3.5");break;}
        case 15: {ui->MGRateEdit->setText("4.13");break;}
        case 16: {ui->MGRateEdit->setText("3.19");break;}
        case 17: {ui->MGRateEdit->setText("2.63");break;}
        case 18: {ui->MGRateEdit->setText("3.75");break;}
        case 19: {ui->MGRateEdit->setText("4.4");break;}
        case 20: {ui->MGRateEdit->setText("3.4");break;}
        case 21: {ui->MGRateEdit->setText("2.8");break;}
        case 22: {ui->MGRateEdit->setText("4");break;}
        case 23: {ui->MGRateEdit->setText("4.25");break;}
        case 24: {ui->MGRateEdit->setText("4.25");break;}
        case 25: {ui->MGRateEdit->setText("4.25");break;}
        case 26: {ui->MGRateEdit->setText("4.25");break;}
        case 27: {ui->MGRateEdit->setText("4.5");break;}
        case 28: {ui->MGRateEdit->setText("4.5");break;}
        case 29: {ui->MGRateEdit->setText("4.5");break;}
        case 30: {ui->MGRateEdit->setText("4.5");break;}
        case 31: {ui->MGRateEdit->setText("4.7");break;}
        case 32: {ui->MGRateEdit->setText("4.7");break;}
        case 33: {ui->MGRateEdit->setText("4.7");break;}
        case 34: {ui->MGRateEdit->setText("4.7");break;}
        }
    }
    else
    {
        switch (index) {
        case 0: {ui->MGRateEdit->setText("2.75");break;}
        case 1: {ui->MGRateEdit->setText("2.75");break;}
        case 2: {ui->MGRateEdit->setText("3.03");break;}
        case 3: {ui->MGRateEdit->setText("2.89");break;}
        case 4: {ui->MGRateEdit->setText("2.34");break;}
        case 5: {ui->MGRateEdit->setText("1.93");break;}
        case 6: {ui->MGRateEdit->setText("2.75");break;}
        case 7: {ui->MGRateEdit->setText("3.03");break;}
        case 8: {ui->MGRateEdit->setText("2.34");break;}
        case 9: {ui->MGRateEdit->setText("1.93");break;}
        case 10: {ui->MGRateEdit->setText("2.75");break;}
        case 11: {ui->MGRateEdit->setText("3.3");break;}
        case 12: {ui->MGRateEdit->setText("2.55");break;}
        case 13: {ui->MGRateEdit->setText("2.1");break;}
        case 14: {ui->MGRateEdit->setText("3");break;}
        case 15: {ui->MGRateEdit->setText("3.57");break;}
        case 16: {ui->MGRateEdit->setText("2.76");break;}
        case 17: {ui->MGRateEdit->setText("2.28");break;}
        case 18: {ui->MGRateEdit->setText("3.25");break;}
        case 19: {ui->MGRateEdit->setText("3.85");break;}
        case 20: {ui->MGRateEdit->setText("2.97");break;}
        case 21: {ui->MGRateEdit->setText("2.45");break;}
        case 22: {ui->MGRateEdit->setText("3.5");break;}
        case 23: {ui->MGRateEdit->setText("3.75");break;}
        case 24: {ui->MGRateEdit->setText("3.75");break;}
        case 25: {ui->MGRateEdit->setText("3.75");break;}
        case 26: {ui->MGRateEdit->setText("3.75");break;}
        case 27: {ui->MGRateEdit->setText("4");break;}
        case 28: {ui->MGRateEdit->setText("4");break;}
        case 29: {ui->MGRateEdit->setText("4");break;}
        case 30: {ui->MGRateEdit->setText("4");break;}
        case 31: {ui->MGRateEdit->setText("4.2");break;}
        case 32: {ui->MGRateEdit->setText("4.2");break;}
        case 33: {ui->MGRateEdit->setText("4.2");break;}
        case 34: {ui->MGRateEdit->setText("4.2");break;}
        }
    }
}

void MainWindow::on_GmoneyRateCombo_currentIndexChanged(int index)
{
    if(ui->GmoneyYearCombo->currentIndex()<20)
    {
        switch (index) {
        case 0: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 1: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 2: {ui->GmoneyRateEdit->setText("3.57");break;}
        case 3: {ui->GmoneyRateEdit->setText("3.41");break;}
        case 4: {ui->GmoneyRateEdit->setText("2.76");break;}
        case 5: {ui->GmoneyRateEdit->setText("2.28");break;}
        case 6: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 7: {ui->GmoneyRateEdit->setText("3.57");break;}
        case 8: {ui->GmoneyRateEdit->setText("2.76");break;}
        case 9: {ui->GmoneyRateEdit->setText("2.28");break;}
        case 10: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 11: {ui->GmoneyRateEdit->setText("3.85");break;}
        case 12: {ui->GmoneyRateEdit->setText("2.98");break;}
        case 13: {ui->GmoneyRateEdit->setText("2.45");break;}
        case 14: {ui->GmoneyRateEdit->setText("3.5");break;}
        case 15: {ui->GmoneyRateEdit->setText("4.13");break;}
        case 16: {ui->GmoneyRateEdit->setText("3.19");break;}
        case 17: {ui->GmoneyRateEdit->setText("2.63");break;}
        case 18: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 19: {ui->GmoneyRateEdit->setText("4.4");break;}
        case 20: {ui->GmoneyRateEdit->setText("3.4");break;}
        case 21: {ui->GmoneyRateEdit->setText("2.8");break;}
        case 22: {ui->GmoneyRateEdit->setText("4");break;}
        case 23: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 24: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 25: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 26: {ui->GmoneyRateEdit->setText("4.25");break;}
        case 27: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 28: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 29: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 30: {ui->GmoneyRateEdit->setText("4.5");break;}
        case 31: {ui->GmoneyRateEdit->setText("4.7");break;}
        case 32: {ui->GmoneyRateEdit->setText("4.7");break;}
        case 33: {ui->GmoneyRateEdit->setText("4.7");break;}
        case 34: {ui->GmoneyRateEdit->setText("4.7");break;}
        }
    }
    else
    {
        switch (index) {
        case 0: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 1: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 2: {ui->GmoneyRateEdit->setText("3.03");break;}
        case 3: {ui->GmoneyRateEdit->setText("2.89");break;}
        case 4: {ui->GmoneyRateEdit->setText("2.34");break;}
        case 5: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 6: {ui->GmoneyRateEdit->setText("3.03");break;}
        case 7: {ui->GmoneyRateEdit->setText("2.34");break;}
        case 8: {ui->GmoneyRateEdit->setText("1.93");break;}
        case 9: {ui->GmoneyRateEdit->setText("2.75");break;}
        case 10: {ui->GmoneyRateEdit->setText("3.3");break;}
        case 11: {ui->GmoneyRateEdit->setText("2.55");break;}
        case 12: {ui->GmoneyRateEdit->setText("2.1");break;}
        case 13: {ui->GmoneyRateEdit->setText("3");break;}
        case 14: {ui->GmoneyRateEdit->setText("3.57");break;}
        case 15: {ui->GmoneyRateEdit->setText("2.76");break;}
        case 16: {ui->GmoneyRateEdit->setText("2.28");break;}
        case 17: {ui->GmoneyRateEdit->setText("3.25");break;}
        case 18: {ui->GmoneyRateEdit->setText("3.85");break;}
        case 19: {ui->GmoneyRateEdit->setText("2.97");break;}
        case 20: {ui->GmoneyRateEdit->setText("2.45");break;}
        case 21: {ui->GmoneyRateEdit->setText("3.5");break;}
        case 22: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 23: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 24: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 25: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 26: {ui->GmoneyRateEdit->setText("3.75");break;}
        case 27: {ui->GmoneyRateEdit->setText("4");break;}
        case 28: {ui->GmoneyRateEdit->setText("4");break;}
        case 29: {ui->GmoneyRateEdit->setText("4");break;}
        case 30: {ui->GmoneyRateEdit->setText("4");break;}
        case 31: {ui->GmoneyRateEdit->setText("4.2");break;}
        case 32: {ui->GmoneyRateEdit->setText("4.2");break;}
        case 33: {ui->GmoneyRateEdit->setText("4.2");break;}
        case 34: {ui->GmoneyRateEdit->setText("4.2");break;}
        }
    }
}

void MainWindow::on_SmoneyRateCombo_currentIndexChanged(int index)
{
    if(ui->SMoneyYearCombo->currentIndex()<20)
    {
        switch (index) {
        case 0: {ui->SmoneyRateEdit->setText("4.75");break;}
        case 1: {ui->SmoneyRateEdit->setText("4.85");break;}
        case 2: {ui->SmoneyRateEdit->setText("5.39");break;}
        case 3: {ui->SmoneyRateEdit->setText("5.15");break;}
        case 4: {ui->SmoneyRateEdit->setText("4.17");break;}
        case 5: {ui->SmoneyRateEdit->setText("3.43");break;}
        case 6: {ui->SmoneyRateEdit->setText("4.9");break;}
        case 7: {ui->SmoneyRateEdit->setText("5.67");break;}
        case 8: {ui->SmoneyRateEdit->setText("4.38");break;}
        case 9: {ui->SmoneyRateEdit->setText("3.61");break;}
        case 10: {ui->SmoneyRateEdit->setText("5.15");break;}
        case 11: {ui->SmoneyRateEdit->setText("5.94");break;}
        case 12: {ui->SmoneyRateEdit->setText("4.59");break;}
        case 13: {ui->SmoneyRateEdit->setText("3.78");break;}
        case 14: {ui->SmoneyRateEdit->setText("5.4");break;}
        case 15: {ui->SmoneyRateEdit->setText("6.22");break;}
        case 16: {ui->SmoneyRateEdit->setText("4.8");break;}
        case 17: {ui->SmoneyRateEdit->setText("3.96");break;}
        case 18: {ui->SmoneyRateEdit->setText("5.65");break;}
        case 19: {ui->SmoneyRateEdit->setText("6.49");break;}
        case 20: {ui->SmoneyRateEdit->setText("5.01");break;}
        case 21: {ui->SmoneyRateEdit->setText("4.13");break;}
        case 22: {ui->SmoneyRateEdit->setText("5.9");break;}
        case 23: {ui->SmoneyRateEdit->setText("6.7");break;}
        case 24: {ui->SmoneyRateEdit->setText("5.2");break;}
        case 25: {ui->SmoneyRateEdit->setText("4.3");break;}
        case 26: {ui->SmoneyRateEdit->setText("6.15");break;}
        case 27: {ui->SmoneyRateEdit->setText("7.21");break;}
        case 28: {ui->SmoneyRateEdit->setText("5.57");break;}
        case 29: {ui->SmoneyRateEdit->setText("4.59");break;}
        case 30: {ui->SmoneyRateEdit->setText("6.55");break;}
        case 31: {ui->SmoneyRateEdit->setText("7.48");break;}
        case 32: {ui->SmoneyRateEdit->setText("5.78");break;}
        case 33: {ui->SmoneyRateEdit->setText("4.76");break;}
        case 34: {ui->SmoneyRateEdit->setText("6.8");break;}
        }
    }
    else
    {
        switch (index) {
        case 0: {ui->SmoneyRateEdit->setText("4.05 ");break;}
        case 1: {ui->SmoneyRateEdit->setText("4.2");break;}
        case 2: {ui->SmoneyRateEdit->setText("5.23");break;}
        case 3: {ui->SmoneyRateEdit->setText("4.99");break;}
        case 4: {ui->SmoneyRateEdit->setText("4.04");break;}
        case 5: {ui->SmoneyRateEdit->setText("3.33");break;}
        case 6: {ui->SmoneyRateEdit->setText("4.75");break;}
        case 7: {ui->SmoneyRateEdit->setText("5.5");break;}
        case 8: {ui->SmoneyRateEdit->setText("4.25");break;}
        case 9: {ui->SmoneyRateEdit->setText("3.5");break;}
        case 10: {ui->SmoneyRateEdit->setText("5");break;}
        case 11: {ui->SmoneyRateEdit->setText("5.78");break;}
        case 12: {ui->SmoneyRateEdit->setText("4.46");break;}
        case 13: {ui->SmoneyRateEdit->setText("3.68");break;}
        case 14: {ui->SmoneyRateEdit->setText("5.25");break;}
        case 15: {ui->SmoneyRateEdit->setText("6.05");break;}
        case 16: {ui->SmoneyRateEdit->setText("4.68");break;}
        case 17: {ui->SmoneyRateEdit->setText("3.85");break;}
        case 18: {ui->SmoneyRateEdit->setText("5.5");break;}
        case 19: {ui->SmoneyRateEdit->setText("6.33");break;}
        case 20: {ui->SmoneyRateEdit->setText("4.89");break;}
        case 21: {ui->SmoneyRateEdit->setText("4.03");break;}
        case 22: {ui->SmoneyRateEdit->setText("5.75");break;}
        case 23: {ui->SmoneyRateEdit->setText("6.6");break;}
        case 24: {ui->SmoneyRateEdit->setText("5.1");break;}
        case 25: {ui->SmoneyRateEdit->setText("4.2");break;}
        case 26: {ui->SmoneyRateEdit->setText("6");break;}
        case 27: {ui->SmoneyRateEdit->setText("7.04");break;}
        case 28: {ui->SmoneyRateEdit->setText("5.44");break;}
        case 29: {ui->SmoneyRateEdit->setText("4.48");break;}
        case 30: {ui->SmoneyRateEdit->setText("6.4");break;}
        case 31: {ui->SmoneyRateEdit->setText("7.32");break;}
        case 32: {ui->SmoneyRateEdit->setText("5.65");break;}
        case 33: {ui->SmoneyRateEdit->setText("4.66");break;}
        case 34: {ui->SmoneyRateEdit->setText("6.65");break;}
        }
    }
}

void MainWindow::on_GareaTypeCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==1)
    {
        ui->SareaRateBtn->click();
        ui->stackedWidget->setCurrentIndex(1);
    }
    if(index==2)
    {
        ui->MRateBtn->click();
        ui->stackedWidget->setCurrentIndex(2);
    }
    ui->GareaTypeCombo->setCurrentIndex(0);
}

void MainWindow::on_GareaWayCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==1)
    {
        if(ui->GareaRateBtn->isChecked())
        {
            ui->GMoneyRateBtn->click();
        }
        else
        {
            ui->GMoneyMoneyBtn->click();
        }
        ui->stackedWidget->setCurrentIndex(3);
    }
    ui->GareaWayCombo->setCurrentIndex(0);
}

void MainWindow::on_SareaTypeCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==0)
    {
        ui->GareaRateBtn->click();
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(index==2)
    {
        ui->MRateBtn->click();
        ui->stackedWidget->setCurrentIndex(2);
    }
    ui->SareaTypeCombo->setCurrentIndex(1);
}

void MainWindow::on_SareaWayCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==1)
    {
        if(ui->SareaRateBtn->isChecked())
        {
            ui->SMoneyRateBtn->click();
        }
        else
        {
            ui->SMoneyMoneyBtn->click();
        }
        ui->stackedWidget->setCurrentIndex(4);
    }
    ui->SareaWayCombo->setCurrentIndex(0);
}

void MainWindow::on_MTypeCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==0)
    {
        ui->GareaRateBtn->click();
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(index==1)
    {
        ui->SareaRateBtn->click();
        ui->stackedWidget->setCurrentIndex(1);
    }
    ui->MTypeCombo->setCurrentIndex(2);
}

void MainWindow::on_GmoneyTyepCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==1)
    {
        ui->SareaRateBtn->click();
        ui->stackedWidget->setCurrentIndex(1);
    }
    if(index==2)
    {
        ui->MRateBtn->click();
        ui->stackedWidget->setCurrentIndex(2);
    }
    ui->GmoneyTyepCombo->setCurrentIndex(0);
}

void MainWindow::on_GmoneyWayCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==0)
    {
        if(ui->GMoneyRateBtn->isChecked())
        {
            ui->GareaRateBtn->click();
        }
        else
        {
            ui->GareaMoneyBtn->click();
        }
        ui->stackedWidget->setCurrentIndex(0);
    }
    ui->GmoneyWayCombo->setCurrentIndex(1);
}

void MainWindow::on_SmoneyTypeCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==0)
    {
        ui->GareaRateBtn->click();
        ui->stackedWidget->setCurrentIndex(0);
    }
    if(index==2)
    {
        ui->MRateBtn->click();
        ui->stackedWidget->setCurrentIndex(2);
    }
    ui->SmoneyTypeCombo->setCurrentIndex(1);
}

void MainWindow::on_SmoneyWayCombo_currentIndexChanged(int index)
{
    last=ui->stackedWidget->currentIndex();
    if(index==0)
    {
        if(ui->SMoneyRateBtn->isChecked())
        {
            ui->SareaRateBtn->click();
        }
        else
        {
            ui->SareaMoneyBtn->click();
        }
        ui->stackedWidget->setCurrentIndex(1);
    }
    ui->SmoneyWayCombo->setCurrentIndex(1);
}


void MainWindow::on_SareaMoneyEdit_textChanged(const QString &arg1)
{
    user.setPerMoney(arg1.toDouble());
}

void MainWindow::on_SareaSizeEdit_textChanged(const QString &arg1)
{
    user.setSize(arg1.toDouble());
}

void MainWindow::on_GareaMoneyEdit_textEdited(const QString &arg1)
{
    user.setPerMoney(arg1.toDouble());
}

void MainWindow::on_GareaSizeEdit_textEdited(const QString &arg1)
{
    user.setSize(arg1.toDouble());
}

void MainWindow::on_MSMoneyEdit_textChanged(const QString &arg1)
{
    user.setsrentMoney(arg1.toDouble());
}

void MainWindow::on_MGMoneyEdit_textChanged(const QString &arg1)
{
    user.setgrentMoney(arg1.toDouble());
}

void MainWindow::on_GmoneyEdit_textChanged(const QString &arg1)
{
    user.setrentMoney(arg1.toDouble());
}

void MainWindow::on_SmoneyEdit_textChanged(const QString &arg1)
{
    user.setrentMoney(arg1.toDouble());
}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    if(ui->stackedWidget->currentIndex()!=5&&ui->stackedWidget->currentIndex()!=6)
    {
        switch (last) {
        case 0:{ui->GareaMoneyEdit->setText("");
                ui->GareaSizeEdit->setText("");
                ui->GareaPercent->setCurrentIndex(0);
                ui->GareaRateCombo->setCurrentIndex(0);
                ui->GareaYearCombo->setCurrentIndex(0);
                break;}
        case 1:{ui->SareaMoneyEdit->setText("");
                ui->SareaSizeEdit->setText("");
                ui->SareaPercent->setCurrentIndex(0);
                ui->SareaYearCombo->setCurrentIndex(0);
                ui->SareaRateCombo->setCurrentIndex(0);
                break;}
        case 2:{ui->MSMoneyEdit->setText("");
                ui->MGMoneyEdit->setText("");
                ui->MYearCombo->setCurrentIndex(0);
                ui->MSRateCombo->setCurrentIndex(0);
                ui->MGRateCombo->setCurrentIndex(0);
                ui->MRateBtn->click();
                break;}
        case 3:{ui->GmoneyEdit->setText("");
                ui->GmoneyYearCombo->setCurrentIndex(0);
                ui->GmoneyRateCombo->setCurrentIndex(0);
                break;}
        case 4:{ui->SmoneyEdit->setText("");
                ui->SMoneyYearCombo->setCurrentIndex(0);
                ui->SmoneyRateCombo->setCurrentIndex(0);
                break;}
        }
    }
    switch (arg1) {
    case 0:{
            user.setrate(ui->GareaRateEdit->text().toDouble());
            user.setPerMoney(ui->GareaMoneyEdit->text().toDouble());
            user.setPercent(ui->GareaPercent->currentIndex());
            user.setmonth(ui->GareaYearCombo->currentIndex());
            user.setSize(ui->GareaSizeEdit->text().toDouble());
            break;}
    case 1:{user.setrate(ui->SareaRateEdit->text().toDouble());
            user.setPerMoney(ui->SareaMoneyEdit->text().toDouble());
            user.setPercent(ui->SareaPercent->currentIndex());
            user.setmonth(ui->SareaYearCombo->currentIndex());
            user.setSize(ui->SareaSizeEdit->text().toDouble());
            break;}
    case 2:{user.setsrate(ui->MSRateEdit->text().toDouble());
            user.setgrate(ui->MGRateEdit->text().toDouble());
            user.setmonth(ui->MYearCombo->currentIndex());
            user.setsrentMoney(ui->MSMoneyEdit->text().toDouble());
            user.setgrentMoney(ui->MGMoneyEdit->text().toDouble());
            break;}
    case 3:{user.setrate(ui->GmoneyRateEdit->text().toDouble());
            user.setrentMoney(ui->GmoneyEdit->text().toDouble());
            user.setmonth(ui->GmoneyYearCombo->currentIndex());
            break;}
    case 4:{user.setrate(ui->SmoneyRateEdit->text().toDouble());
            user.setrentMoney(ui->SmoneyEdit->text().toDouble());
            user.setmonth(ui->SMoneyYearCombo->currentIndex());
            break;}
    }
}


void MainWindow::on_historyBtn_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_history2_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(last);
}

void MainWindow::on_GareaClearBtn_2_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_GareaClearBtn_3_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_GareaClearBtn_4_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_GareaClearBtn_5_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_GareaClearBtn_6_clicked()
{
    last=ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(7);
}
