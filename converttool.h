#ifndef CONVERTTOOL_H
#define CONVERTTOOL_H

#include <QObject>

#define SystemImpedance 50 //系统阻抗默认为50Ω
class ConvertTool : public QObject
{
    Q_OBJECT
    Q_ENUMS(CalType)
public:
    explicit ConvertTool(QObject *parent = nullptr);

//    Q_INVOKABLE QString calc(QString calStr, int type);


    enum CalType {
        CalType_dBm2mW = 0,
        CalType_mW2dBm,
        CalType_dBm2Watt,
        CalType_Watt2dBm,
        CalType_dBm2Vrms,
        CalType_Vrms2dBm,
        CalType_dBm2dBmV,
        CalType_dBmV2dBm,
        CalType_dBm2dBuV,
        CalType_dBuV2dBm
    };
    Q_INVOKABLE QString calc(QString calStr, CalType type);

signals:

};

#endif // CONVERTTOOL_H
