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

#ifndef SERVICEDISCOVERYBROADCASTRECEIVER_H
#define SERVICEDISCOVERYBROADCASTRECEIVER_H

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

#include "android/androidbroadcastreceiver_p.h"
#include <QtCore/QList>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothUuid>

QT_BEGIN_NAMESPACE

class QBluetoothDeviceInfo;

class ServiceDiscoveryBroadcastReceiver : public AndroidBroadcastReceiver
{
    Q_OBJECT
public:
    ServiceDiscoveryBroadcastReceiver(QObject* parent = nullptr);
    virtual void onReceive(JNIEnv *env, jobject context, jobject intent);
    virtual void onReceiveLeScan(JNIEnv *, jobject, jint, jbyteArray) {}

    static QList<QBluetoothUuid> convertParcelableArray(const QAndroidJniObject &obj);

signals:
    void uuidFetchFinished(const QBluetoothAddress &addr, const QList<QBluetoothUuid> &serviceUuid);
};

QT_END_NAMESPACE
#endif // SERVICEDISCOVERYBROADCASTRECEIVER_H
