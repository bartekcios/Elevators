#include "precompiled.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    CDriver oDriver = CDriver(3);

    return app.exec();
}
