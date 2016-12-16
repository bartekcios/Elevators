#include "precompiled.h"

using namespace std;

void upd()
{
    qDebug("update bicz");
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CGUIHandler oGUIHandler(3, &engine);
    oGUIHandler.StartUpdateRoutine();
    //oGUIHandler.Init();


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
