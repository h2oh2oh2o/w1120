#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"information.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_GareaMoneyEdit_textChanged(const QString &arg1);

    void on_GareaSizeEdit_textChanged(const QString &arg1);

    void on_GareaPercent_currentIndexChanged(int index);

    void on_GareaYearCombo_currentIndexChanged(int index);

    void on_GareaRateEdit_textEdited(const QString &arg1);

    void on_GareaBeginBtn_clicked();

    void on_GareaRateEdit_textChanged(const QString &arg1);

    void on_SareaMoneyEdit_textEdited(const QString &arg1);

    void on_SareaSizeEdit_textEdited(const QString &arg1);

    void on_SareaPercent_currentIndexChanged(int index);

    void on_SareaYearCombo_currentIndexChanged(int index);

    void on_SareaRateEdit_textEdited(const QString &arg1);

    void on_SareaRateEdit_textChanged(const QString &arg1);

    void on_SareaBeginBtn_clicked();

    void on_SareaClearBtn_clicked();

    void on_MSMoneyEdit_textEdited(const QString &arg1);

    void on_MSRateEdit_textEdited(const QString &arg1);

    void on_MSRateEdit_textChanged(const QString &arg1);

    void on_MGMoneyEdit_textEdited(const QString &arg1);

    void on_MGRateEdit_textEdited(const QString &arg1);

    void on_MGRateEdit_textChanged(const QString &arg1);

    void on_MYearCombo_currentIndexChanged(int index);

    void on_MBeginBtn_clicked();

    void on_MClearBtn_clicked();

    void on_GmoneyEdit_textEdited(const QString &arg1);

    void on_GmoneyYearCombo_currentIndexChanged(int index);

    void on_GmoneyRateEdit_textEdited(const QString &arg1);

    void on_GmoneyRateEdit_textChanged(const QString &arg1);

    void on_GmoneyBeginBtn_clicked();

    void on_GmoneyClearBtn_clicked();

    void on_SmoneyEdit_textEdited(const QString &arg1);

    void on_SMoneyYearCombo_currentIndexChanged(int index);

    void on_SmoneyRateEdit_textEdited(const QString &arg1);

    void on_SmoneyRateEdit_textChanged(const QString &arg1);

    void on_SmoneyBeginBtn_clicked();

    void on_SmoneyClearBtn_clicked();

    void on_rateBack_clicked();

    void on_moneyBack_clicked();

    void on_GareaClearBtn_clicked();

    void on_GareaRateCombo_currentIndexChanged(int index);

    void on_SareaRateCombo_currentIndexChanged(int index);

    void on_MSRateCombo_currentIndexChanged(int index);

    void on_MGRateCombo_currentIndexChanged(int index);

    void on_GmoneyRateCombo_currentIndexChanged(int index);

    void on_SmoneyRateCombo_currentIndexChanged(int index);

    void on_GareaTypeCombo_currentIndexChanged(int index);

    void on_GareaWayCombo_currentIndexChanged(int index);

    void on_SareaTypeCombo_currentIndexChanged(int index);

    void on_SareaWayCombo_currentIndexChanged(int index);

    void on_MTypeCombo_currentIndexChanged(int index);

    void on_GmoneyTyepCombo_currentIndexChanged(int index);

    void on_GmoneyWayCombo_currentIndexChanged(int index);

    void on_SmoneyTypeCombo_currentIndexChanged(int index);

    void on_SmoneyWayCombo_currentIndexChanged(int index);

    void on_SareaMoneyEdit_textChanged(const QString &arg1);

    void on_SareaSizeEdit_textChanged(const QString &arg1);

    void on_GareaMoneyEdit_textEdited(const QString &arg1);

    void on_GareaSizeEdit_textEdited(const QString &arg1);

    void on_MSMoneyEdit_textChanged(const QString &arg1);

    void on_MGMoneyEdit_textChanged(const QString &arg1);

    void on_GmoneyEdit_textChanged(const QString &arg1);

    void on_SmoneyEdit_textChanged(const QString &arg1);

    void on_stackedWidget_currentChanged(int arg1);

    void on_historyBtn_clicked();

    void on_history2_clicked();

    void on_pushButton_clicked();

    void on_GareaClearBtn_2_clicked();

    void on_GareaClearBtn_3_clicked();

    void on_GareaClearBtn_4_clicked();

    void on_GareaClearBtn_5_clicked();

    void on_GareaClearBtn_6_clicked();

private:
    Ui::MainWindow *ui;
    information user;
    int i,last;
};
#endif // MAINWINDOW_H
