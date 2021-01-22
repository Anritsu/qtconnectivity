/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtNfc module of the Qt Toolkit.
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

#ifndef QNEARFIELDTAGTYPE3_H
#define QNEARFIELDTAGTYPE3_H

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

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtNfc/QNearFieldTarget>

QT_BEGIN_NAMESPACE

class Q_AUTOTEST_EXPORT QNearFieldTagType3 : public QNearFieldTarget
{
    Q_OBJECT

public:
    explicit QNearFieldTagType3(QObject *parent = 0);

    Type type() const { return NfcTagType3; }

    quint16 systemCode();
    QList<quint16> services();
    int serviceMemorySize(quint16 serviceCode);

    virtual RequestId serviceData(quint16 serviceCode);
    virtual RequestId writeServiceData(quint16 serviceCode, const QByteArray &data);

    virtual RequestId check(const QMap<quint16, QList<quint16> > &serviceBlockList);
    virtual RequestId update(const QMap<quint16, QList<quint16> > &serviceBlockList,
                             const QByteArray &data);

protected:
    bool handleResponse(const QNearFieldTarget::RequestId &id, const QByteArray &response);
};

QT_END_NAMESPACE

#endif // QNEARFIELDTAGTYPE3_H
