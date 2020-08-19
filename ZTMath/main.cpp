#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pagestate.h"
#include "plusoperation.h"
#include "minusoperation.h"
#include "multoperation.h"
#include "divoperation.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    PageState page;
    Operation operation;
    PlusOperation plus;
    MinusOperation minus;
    MultOperation mult;
    DivOperation div;

    engine.rootContext()->setContextProperty("page", &page);
    engine.rootContext()->setContextProperty("operation", &operation);
    // Class PlusOperation: public QObject
    engine.rootContext()->setContextProperty("plus", &plus);
    engine.rootContext()->setContextProperty("minus", &minus);
    engine.rootContext()->setContextProperty("mult", &mult);
    engine.rootContext()->setContextProperty("div", &div);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
            return -1;

    return app.exec();
}
