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

#ifndef QNDEFRECORD_P_H
#define QNDEFRECORD_P_H

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

#include "qtnfcglobal.h"

#include <QtCore/QSharedData>
#include <QtCore/QByteArray>

QT_BEGIN_NAMESPACE

class QNdefRecordPrivate : public QSharedData
{
public:
    QNdefRecordPrivate() : QSharedData()
    {
        typeNameFormat = 0; //TypeNameFormat::Empty
    }

    unsigned int typeNameFormat : 3;

    QByteArray type;
    QByteArray id;
    QByteArray payload;
};

QT_END_NAMESPACE

#endif // QNDEFRECORD_P_H
