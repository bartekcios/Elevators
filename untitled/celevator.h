#ifndef CELEVATOR_H
#define CELEVATOR_H

#include <windows.h>
#include <stdio.h>
#include <QDeclarativeComponent>
#include <QDeclarativeView>

#include "ienums.h"

class CElevator
{
public:


    CElevator(const int a_iID, HANDLE a_hDriver, const HANDLE a_hSyncHandle, const std::string a_sImageName);
    ~CElevator();

    int GetWorkingTime();
    IEnums::REQUEST_ANSWER Sync(HANDLE a_hSyncHandle);

    IEnums::STATUS m_eCurrentStatus;
    const int m_iID;

private:
    bool ChangeImagePosition(IEnums::FLOOR a_eNewPosition);

    const int m_iMAX_PASSENGERS;
    int m_iCurrentNoPassengers;
    int m_iCurrentPosition;
    const HANDLE m_hDriver;
    const QString m_qsImageName;
    const HANDLE m_hOwnHandle;
};

#endif // CELEVATOR_H
