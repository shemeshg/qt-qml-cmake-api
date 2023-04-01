#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QQmlContext>
using namespace Qt::Literals::StringLiterals;

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);


  QQmlApplicationEngine engine;


  QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
      &app, []() { QCoreApplication::exit(-1); },
      Qt::QueuedConnection);

  //QQmlContext *context = engine.rootContext();
  //MyType *myType = new MyType(&engine); //NOLINT
  //context->setContextProperty(QStringLiteral("mytypemodel"),myType);

  engine.loadFromModule("hello", "Main");

  return app.exec();
}
