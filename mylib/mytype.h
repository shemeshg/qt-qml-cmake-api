//
// Created by Larry on 2022/2/1.
//

#ifndef HELLO_MYTYPE_H
#define HELLO_MYTYPE_H

#include <QObject>
#include <qqmlregistration.h>
#include <iostream>
#include <QtQuick/QQuickItem>
#include <QQmlEngineExtensionPlugin>

class MyType : public QObject
{

    Q_OBJECT
        Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    QML_ELEMENT

signals:
    void nameChanged();

public:
    MyType(QObject *parent=nullptr);

    //explicit MyType(QObject *parent = nullptr);
    QString name() const {
        return "FROM BACKEND";
    };

    void setName(const QString &name){
        m_name = name;
        emit nameChanged();
    }

private:
    QString m_name;

};

#endif //HELLO_MYTYPE_H
