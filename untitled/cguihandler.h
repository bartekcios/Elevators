#ifndef CGUIHANDLER_H
#define CGUIHANDLER_H

#include <windows.h>
#include <QtCore>
#include <QQmlApplicationEngine>
#include <QTimer>


class CGUIHandler : public QObject
{
    Q_OBJECT
public:
    struct CreateDriverThread
    {
        const int m_iNoElevators;
    };

    CGUIHandler(int a_iNoElevators, QQmlApplicationEngine * a_pEngine);
    bool Init();
    bool StartUpdateRoutine();

public slots:
    void upd();

private:
    HANDLE m_hDriver;
    const int m_iNoElevators;
    const QQmlApplicationEngine * m_pEngine;
    QTimer * m_pTimer;
};

#endif // CGUIHANDLER_H
