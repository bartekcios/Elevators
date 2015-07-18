#ifndef CDRIVER_H
#define CDRIVER_H

#include <string>

#include "celevator.h"
#include "cpassenger.h"

class CDriver
{
public:
    struct SFloor
    {
        IEnums::FLOOR m_eFloor;
        CElevator * m_apElevatorsOnFloor[];
        CPassenger * m_apPassengersOnFloor[];
    };

    struct SCreateElevator
    {
        const int m_iID;
        const HANDLE m_hDriver;
        const HANDLE m_hSyncHandle;
        const std::string m_sImageName;
    };

    struct SElevator
    {
        HANDLE m_hHandle;
        QString m_qsImageName;
    };

    CDriver(int a_iNoElevations);
    ~CDriver();

    bool handlePassenger(CPassenger * a_pPassenger);
    CElevator * getTheFastestElevator();
    IEnums::REQUEST_ANSWER SendRequest(CPassenger * a_pPassenger);
    bool HandleMessageFromQueue();
    QString GetImageName(HANDLE a_hElevator);
    bool ChangeImagePosition(QString a_qsImageName, IEnums::FLOOR a_ePosition);

private:
    bool m_fAllInitialized;
    SElevator * m_asElevators;
    int m_iElevatorsSize;
    SFloor m_aeFloors[IEnums::MAX_FLOORS];
};

#endif // CDRIVER_H
