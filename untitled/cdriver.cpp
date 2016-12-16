#include "cdriver.h"

#include "celevator.h"
#include "cpassenger.h"

DWORD WINAPI ElevatorThread(LPVOID lpParameter)
{
    CDriver::SCreateElevatorThread & sCreateElevatorThread = *(CDriver::SCreateElevatorThread*)lpParameter;
    CElevator * pElevator = new CElevator(sCreateElevatorThread.m_iID, sCreateElevatorThread.m_hDriver, sCreateElevatorThread.m_hSyncHandle, sCreateElevatorThread.m_sImageName);
    if(0 != pElevator)
    {

    }
    return 0;
}

CDriver::CDriver(int a_iNoElevations):
    m_fAllInitialized(true),
    m_asElevators(new SElevator[a_iNoElevations]),
    m_iElevatorsSize(a_iNoElevations)
{

    for(int i = 0; i< m_iElevatorsSize;i++)
    {
        HANDLE hSyncHandle = CreateEvent(0, true, false, 0);
        std::string sImageName = "imageElevator" + i;
        SCreateElevatorThread sCreateElevator = {i, GetActiveWindow(),hSyncHandle, sImageName};

        m_asElevators[i].m_hHandle = CreateThread(0, 0, ElevatorThread, &sCreateElevator, 0, 0);
        DWORD dWaitRetVal = WaitForSingleObject(hSyncHandle, 10);
        if(WAIT_OBJECT_0 == dWaitRetVal)
        {
            printf("CDriver::CDriver: Elevator %d synchronized \n", i);
            fflush(stdout);
        }
        else
        {
            printf("[WRN]CDriver::CDriver: Elevator %d NOT synchronized \n", i);
            fflush(stdout);
            m_asElevators[i].m_hHandle = 0;
            m_fAllInitialized = false;
        }
    }
}

CDriver::~CDriver()
{
    bool fClosed = false;
    std::string sCorrectlyNotCorrectly = "";
    for(int i = 0;i< m_iElevatorsSize;i++)
    {
        if(0 != m_asElevators[i].m_hHandle)
        {
            fClosed = CloseHandle(m_asElevators[i].m_hHandle);

            sCorrectlyNotCorrectly = (false != fClosed)?"correctly":"NOT correctly";

            printf("CDriver::~CDriver: Elevator thread %d closed %s \n", i, sCorrectlyNotCorrectly.c_str());
            fflush(stdout);
        }
        else
        {
            printf("[WRN]CDriver::~CDriver: Elevator thread %d has null handle\n", i);
            fflush(stdout);
        }
    }
    delete[] m_asElevators;
}

bool CDriver::handlePassenger(CPassenger * a_pPassenger)
{
    bool retVal = false;

    if(0 != a_pPassenger)
    {
        CElevator * pElevator;
        pElevator = getTheFastestElevator();

        IEnums::REQUEST_ANSWER eAnswer = SendRequest(a_pPassenger);

        if(IEnums::RA_ACCEPTED == eAnswer)
        {
            retVal = true;
        }
        else if(IEnums::RA_IN_PROGRESS == eAnswer)
        {
            //resend
        }
        else
        {
            retVal = false;
        }
        printf("CDriver::handlePassenger: Passenger id: %d, Elevator id : %d, Elevators answer : %d\n", a_pPassenger->m_iID, pElevator->m_iID, eAnswer);
        fflush(stdout);
    }
    else
    {
        printf("[WRN]CDriver::handlePassenger: Passenger null pointer\n");
        fflush(stdout);
    }

    return retVal;
}

CElevator * CDriver::getTheFastestElevator()
{
    CElevator * retVal = 0;
    /*
    int iCurrentTime = 99999999;
    int iTheFastestTime = 99999999;
    int iTheFastestID = -1;


    for(int i=0; i < m_iElevatorsSize;i++)
    {
        iCurrentTime = m_apElevators[i]->getWorkingTime();
        if(iTheFastestTime > iCurrentTime)
        {
            iTheFastestTime = iCurrentTime;
            iTheFastestID = i;
        }
    }

    if(-1 != iTheFastestID)
    {
        retVal = m_apElevators[iTheFastestID];
    }
    */
    return retVal;
}

IEnums::REQUEST_ANSWER CDriver::SendRequest(CPassenger * a_pPassenger)
{
    IEnums::REQUEST_ANSWER retVal = IEnums::RA_INVALID;

    if(0 != a_pPassenger)
    {

    }

    return retVal;
}

bool CDriver::HandleMessageFromQueue()
{
    bool fRetVal = false;
    MSG sMessage;
    fRetVal = PeekMessage(&sMessage, GetActiveWindow(), IEnums::M_CHANGE_IMAGE_POSITION, IEnums::M_GET_TIME_TO_FREE, PM_REMOVE);

    if(false != fRetVal)
    {
        IEnums::MESSAGE eMessage = (IEnums::MESSAGE)sMessage.message;
        switch(eMessage)
        {
        case IEnums::M_CHANGE_IMAGE_POSITION:
        {
            QString qsImageName = GetImageName((HANDLE)sMessage.lParam);
            IEnums::FLOOR eNewPosition = (IEnums::FLOOR)sMessage.wParam;

            //ChangeImagePosition(qsImageName, eNewPosition);
            break;
        }
        case IEnums::M_GET_STATUS:
        {
            break;
        }
        case IEnums::M_SET_STATUS:
        {
            break;
        }
        case IEnums::M_GET_TIME_TO_FREE:
        {
            break;
        }
        default:
        {
        }
        }
    }

    return fRetVal;
}

QString CDriver::GetImageName(HANDLE a_hElevator)
{
    QString qsRetVal = "";

    for(int i=0;i<m_iElevatorsSize;i++)
    {
        if(m_asElevators[i].m_hHandle == a_hElevator)
        {
            qsRetVal = m_asElevators[i].m_qsImageName;
            break;
        }
    }
    return qsRetVal;
}
