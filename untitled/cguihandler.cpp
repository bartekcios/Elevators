#include "cguihandler.h"

#include "cdriver.h"

DWORD WINAPI DriverThread(LPVOID lpParameter)
{
    CGUIHandler::CreateDriverThread & sCreateDriverThread = *((CGUIHandler::CreateDriverThread*)lpParameter);
    CDriver oDriver(sCreateDriverThread.m_iNoElevators);

    return 0;
}

CGUIHandler::CGUIHandler(int a_iNoElevators, QQmlApplicationEngine *a_pEngine):
    m_hDriver(nullptr),
    m_iNoElevators(a_iNoElevators),
    m_pEngine(a_pEngine),
    m_pTimer(nullptr)
{

}

bool CGUIHandler::Init()
{
    bool fRetVal = false;

    CreateDriverThread sCreateDriverThread = {m_iNoElevators};

    m_hDriver = CreateThread(0, 0, DriverThread, &sCreateDriverThread, 0, 0 );
    if(0 != m_hDriver)
    {
        fRetVal = true;
        qDebug("CGUIHandler::Init: Driver thread created");
    }
    else
    {
        qDebug("[WRN]CGUIHandler::Init Driver thread not created");
    }

    return fRetVal;
}

bool CGUIHandler::StartUpdateRoutine()
{
    m_pTimer = new QTimer(this);

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(upd()));

    m_pTimer->start(1000);
}



void CGUIHandler::upd()
{
    qDebug("sadfasd----------------------");
    m_pTimer->start(1000);
}

