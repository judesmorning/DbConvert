#include "converttool.h"
#include <QtMath>
#include <QDebug>

ConvertTool::ConvertTool(QObject *parent)
    : QObject{parent}
{

}

QString ConvertTool::calc(QString calStr, CalType type)
{
    float calNum = calStr.toFloat();
    QString retStr;

    switch (type) {
    case CalType_dBm2mW:
    {
        float mWatt = pow(10, calNum/10);
        retStr = QString::number(mWatt);
        break;
    }
    case CalType_mW2dBm:
    {
        float dBm = 10*log10(calNum);
        retStr = QString::number(dBm);
        break;
    }
    case CalType_dBm2Watt:
    {
        float watt = pow(10, calNum/10)/1000;
        retStr = QString::number(watt);
        break;
    }
    case CalType_Watt2dBm:
    {
        float dBm = 10*log10(calNum*1000);
        retStr = QString::number(dBm);
        break;
    }
    case CalType_dBm2Vrms:
    {
        float vRms = pow(10, (calNum-30)/20)*sqrt(SystemImpedance);
        retStr = QString::number(vRms);
        break;
    }
    case CalType_Vrms2dBm:
    {
        float dBm = 30 + 20*log10(calNum/sqrt(SystemImpedance));
        retStr = QString::number(dBm);
        break;
    }
    case CalType_dBm2dBmV:
    {
        float dBmv = calNum + 30 + 20*log10(sqrt(SystemImpedance));
        retStr = QString::number(dBmv);
        break;
    }
    case CalType_dBmV2dBm:
    {
        float dBm = calNum - 30 - 20*log10(sqrt(SystemImpedance));
        retStr = QString::number(dBm);
        break;
    }
    case CalType_dBm2dBuV:
    {
        float dBuv = calNum + 90 + 20*log10(sqrt(SystemImpedance));
        retStr = QString::number(dBuv);
        break;
    }
    case CalType_dBuV2dBm:
    {
        float dBm = calNum - 90 - 20*log10(sqrt(SystemImpedance));
        retStr = QString::number(dBm);
        break;
    }

    default:
        retStr = "Convert Failed!";
        break;
    }

    return calStr+"\n"+retStr;
}
