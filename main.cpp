#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "mytype.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);


  QQmlApplicationEngine engine;
  //const QUrl url(u"qrc:/hello/main.qml"_qs);
  const QUrl url("qrc:/main.qml");

  //QQmlContext *context = engine.rootContext();
  //MyType *myType = new MyType(&engine); //NOLINT
  //context->setContextProperty(QStringLiteral("mytypemodel"),myType);
  engine.load(url);

  return app.exec();
}
