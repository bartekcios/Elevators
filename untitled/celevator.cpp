#include "celevator.h"

CElevator::CElevator(const int a_iID, HANDLE a_hDriver, const HANDLE a_hSyncHandle, const std::string a_sImageName):
    m_iID(a_iID),
    m_iMAX_PASSENGERS(8),
    m_iCurrentNoPassengers(0),
    m_iCurrentPosition(0),
    m_hDriver(a_hDriver),
    m_qsImageName(QString::fromUtf8(a_sImageName.c_str())),
    m_hOwnHandle(GetActiveWindow())
{
    Sync(a_hSyncHandle);

    Sleep(m_iID*5000);
    printf("CElevator::CElevator: Elevator %d after sleep, try set image height\n", m_iID);
    fflush(stdout);
    ChangeImagePosition(IEnums::EIGHTH_FLOOR);
}

CElevator::~CElevator()
{

}

int CElevator::GetWorkingTime()
{
    int iRetVal = 0;

    return iRetVal;
}

IEnums::REQUEST_ANSWER CElevator::Sync(HANDLE a_hSyncHandle)
{
    IEnums::REQUEST_ANSWER oRetVal = IEnums::RA_INVALID;

    bool fSetEventRet = SetEvent(a_hSyncHandle);

    if(false != fSetEventRet)
    {
        printf("CElevator::Sync: Elevator %d set event\n", m_iID);
        fflush(stdout);
    }
    else
    {
        printf("[WRN]CElevator::Sync: Elevator %d set event Error %d\n", m_iID, (int)GetLastError());
        fflush(stdout);
    }


    return oRetVal;
}

bool CElevator::ChangeImagePosition(IEnums::FLOOR a_eNewPosition)
{
    bool fRetVal = false;

    PostMessage((HWND)m_hDriver, IEnums::M_CHANGE_IMAGE_POSITION, a_eNewPosition, (LPARAM)m_hOwnHandle);




    return fRetVal;
}
