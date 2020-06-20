#include "information.h"

information::information()
{
    PerMoney=0.0;
    Size=0.0;
    Percent=0.0;
    month=0;
    rentMoney=0.0;
    rate=0.0;
    lessMoney=0.0;
    averageMoney=0.0;
    firstMoney=0.0;
    allMoney=0.0;
    rateMoney=0.0;
    SFMoney=0.0;
    srate=0.0;
    grate=0.0;
    saverageMoney=0.0;
    gaverageMoney=0.0;
    srentMoney=0.0;
    grentMoney=0.0;

}

void information::setmonth(int a)
{
    month=(25-a)*12;
}
int information::getmonth()
{
    return month;
}
double information::getrentMoney()
{
    return rentMoney;
}
void information::setrentMoney(bool a)
{
    if(a)
    rentMoney=(Size*PerMoney*Percent)/10.0;
}
void information::setrentMoney(double a)
{
    rentMoney=a*10000.0;
}
void information::setaverageMoney()
{
    averageMoney=(rentMoney*(rate/12.0)*pow(1+rate/12.0,month))/(pow(1+rate/12.0,month)-1);

}
void information::setaverageMoney(double a)
{
    averageMoney=a;
}
void information::setsaveragemoney()
{
    saverageMoney=(srentMoney*10000*(srate/12.0)*pow(1+srate/12.0,month))/(pow(1+srate/12.0,month)-1);
}
void information::setgaveragemoney()
{
    gaverageMoney=(grentMoney*10000*(grate/12.0)*pow(1+grate/12.0,month))/(pow(1+grate/12.0,month)-1);
}
void information::setsrentMoney(double a)
{
    srentMoney=a;
}
double information::getsrentMoney()
{
    return srentMoney;
}
double information::getsaveragemoney()
{
    return saverageMoney;
}
void information::setgrentMoney(double a)
{
    grentMoney=a;
}
double information::getgrentMoney()
{
    return grentMoney;
}
double information::getgaveragemoney()
{
    return gaverageMoney;
}
double information::getaverageMoney()
{
    return averageMoney;
}
void information::setfirstMoney()
{
    double a;
    a=rentMoney/month;
    firstMoney=a+rentMoney*rate/12.0;
}
void information::setsfirstMoney()
{
    double a;
    a=srentMoney*10000/month;
    sfirstMoney=a+srentMoney*10000*srate/12.0;
}
double information::getsfirstMoney()
{
    return  sfirstMoney;
}
void information::setgfirstMoney()
{
    double a;
    a=grentMoney*10000/month;
    gfirstMoney=a+grentMoney*10000*grate/12.0;
}
double information::getgfirstMoney()
{
    return  gfirstMoney;
}
double information::getfirstMoney()
{
    return firstMoney;
}
void information::rsetallMoney()
{
    allMoney=month*averageMoney;
}
double information::getallMoney()
{
    return allMoney;
}
void information::msetallMoney()
{
    allMoney=rentMoney+(month+1)*rentMoney*(rate/12.0)/2.0;
}
void information::setsallMoney()
{
    sallMoney=srentMoney*10000+(month+1)*srentMoney*10000*(srate/12.0)/2.0;
}
double information::getsallMoney()
{
    return  sallMoney;
}
double information::getgallMoney()
{
    return  gallMoney;
}
void information::setgallMoney()
{
    gallMoney=grentMoney*10000+(month+1)*grentMoney*10000*(grate/12.0)/2.0;
}
void information::setrateMoney()
{
    rateMoney=allMoney-rentMoney;
}
double information::getrateMoney()
{
    return rateMoney;
}
void information::setlessMoney()
{
    lessMoney=rentMoney*rate/12.0-(rentMoney-rentMoney/month)*rate/12.0;
}
void information::setslessMoney()
{
    slessMoney=srentMoney*10000*srate/12.0-(srentMoney*10000-srentMoney*10000/month)*srate/12.0;
}
double information::getslessMoney()
{
    return  slessMoney;
}
void information::setglessMoney()
{
    glessMoney=grentMoney*10000*grate/12.0-(grentMoney*10000-grentMoney*10000/month)*grate/12.0;
}
double information::getglessMoney()
{
    return glessMoney;
}
double information::getlessMoney()
{
    return lessMoney;
}
void information::setrate(double a)
{
    rate=a/100.0;
}
double information::getrate()
{
    return rate;
}
void information::setSF()
{
    SFMoney=Size*PerMoney*(1.0-Percent/10.0);
}
double information::getSF()
{
    return SFMoney;
}
void information::setPercent(int a)
{
    Percent=8.0-a/2.0;
}
void information::setSize(double a)
{
    Size=a;
}
void information::setPerMoney(double a)
{
    PerMoney=a;
}
void information::setsrate(double a)
{
    srate=a/100.0;
}
void information::setgrate(double a)
{
    grate=a/100.0;
}
double information::getsrate()
{
    return srate;
}
double information::getgrate()
{
    return grate;
}
double information::getsize()
{
    return Size;
}
double information::getperMoney()
{
    return PerMoney;
}
