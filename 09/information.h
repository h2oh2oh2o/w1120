#ifndef INFORMATION_H
#define INFORMATION_H
#include<cmath>

class information
{
public:
    information();
    void setmonth(int a);
    int getmonth();
    double getrentMoney();
    void setrentMoney(bool a);
    void setrentMoney(double a);
    void setaverageMoney();
    double getaverageMoney();
    void setfirstMoney();
    double getfirstMoney();
    void rsetallMoney();
    void msetallMoney();
    double getallMoney();
    void setrateMoney();
    double getrateMoney();
    void setlessMoney();
    double getlessMoney();
    void setrate(double a);
    double getrate();
    void setSF();
    double getSF();
    void setPerMoney(double a);
    void setSize(double a);
    void setPercent(int a);
    void setsrate(double a);
    void setgrate(double a);
    double getsrate();
    double getgrate();
    double getsize();
    double getperMoney();
    void setsaveragemoney();
    void setgaveragemoney();
    double getsaveragemoney();
    double getgaveragemoney();
    void setsrentMoney(double a);
    double getsrentMoney();
    void setgrentMoney(double a);
    double getgrentMoney();
    void setaverageMoney(double a);
    void setsfirstMoney();
    void setgfirstMoney();
    double getsfirstMoney();
    double getgfirstMoney();
    void setslessMoney();
    void setglessMoney();
    double getslessMoney();
    double getglessMoney();
    void setsallMoney();
    void setgallMoney();
    double getsallMoney();
    double getgallMoney();
private:
    double PerMoney;
    double Size;
    double Percent;
    int month;
    double rentMoney;
    double rate;
    double lessMoney;
    double averageMoney;
    double firstMoney;
    double allMoney;
    double rateMoney;
    double SFMoney;
    double srate,grate;
    double saverageMoney;
    double gaverageMoney;
    double srentMoney;
    double grentMoney;
    double sfirstMoney;
    double gfirstMoney;
    double slessMoney;
    double glessMoney;
    double gallMoney;
    double sallMoney;
};

#endif // INFORMATION_H
