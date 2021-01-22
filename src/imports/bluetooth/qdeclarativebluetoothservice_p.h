/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtBluetooth module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
****************************************************************************/

#ifndef QDECLARATIVEBLUETOOTHSERVICE_P_H
#define QDECLARATIVEBLUETOOTHSERVICE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QObject>
#include <qqml.h>
#include <qbluetoothserviceinfo.h>
#include "qdeclarativebluetoothsocket_p.h"

class QDeclarativeBluetoothSocket;

QT_USE_NAMESPACE

class QDeclarativeBluetoothServicePrivate;

class QDeclarativeBluetoothService : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_PROPERTY(QString deviceName READ deviceName NOTIFY detailsChanged)
    Q_PROPERTY(QString deviceAddress READ deviceAddress WRITE setDeviceAddress NOTIFY detailsChanged)
    Q_PROPERTY(QString serviceName READ serviceName WRITE setServiceName NOTIFY detailsChanged)
    Q_PROPERTY(QString serviceDescription READ serviceDescription WRITE setServiceDescription NOTIFY detailsChanged)
    Q_PROPERTY(QString serviceUuid READ serviceUuid WRITE setServiceUuid NOTIFY detailsChanged)
    Q_PROPERTY(Protocol serviceProtocol READ serviceProtocol WRITE setServiceProtocol NOTIFY detailsChanged)
    Q_PROPERTY(bool registered READ isRegistered WRITE setRegistered NOTIFY registeredChanged)
    Q_INTERFACES(QQmlParserStatus)

public:
    /// TODO: Merge/Replace with QBluetoothServiceInfo::Protocol in Qt 6
    enum Protocol {
        RfcommProtocol = QBluetoothServiceInfo::RfcommProtocol,
        L2CapProtocol = QBluetoothServiceInfo::L2capProtocol,
        UnknownProtocol = QBluetoothServiceInfo::UnknownProtocol
    };
    Q_ENUM(Protocol)

    explicit QDeclarativeBluetoothService(QObject *parent = 0);
    explicit QDeclarativeBluetoothService(const QBluetoothServiceInfo &service,
                                          QObject *parent = 0);
    ~QDeclarativeBluetoothService();

    QString deviceName() const;
    QString deviceAddress() const;
    QString serviceName() const;
    QString serviceDescription() const;
    QString serviceUuid() const;
    Protocol serviceProtocol() const;
    bool isRegistered() const;

    QBluetoothServiceInfo *serviceInfo() const;

    Q_INVOKABLE QDeclarativeBluetoothSocket *nextClient();
    Q_INVOKABLE void assignNextClient(QDeclarativeBluetoothSocket *dbs);

    // From QDeclarativeParserStatus
    void classBegin() {}
    void componentComplete();

    void setServiceName(const QString &name);
    void setDeviceAddress(const QString &address);
    void setServiceDescription(const QString &description);
    void setServiceUuid(const QString &uuid);
    void setServiceProtocol(QDeclarativeBluetoothService::Protocol protocol);
    void setRegistered(bool registered);

signals:
    void detailsChanged();
    void registeredChanged();
    void newClient();

private slots:
    void new_connection();

private:
    QDeclarativeBluetoothServicePrivate* d;
    friend class QDeclarativeBluetoothServicePrivate;

};

QML_DECLARE_TYPE(QDeclarativeBluetoothService)

#endif // QDECLARATIVEBLUETOOTHSERVICE_P_H
