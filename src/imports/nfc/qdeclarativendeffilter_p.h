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

#ifndef QDECLARATIVENDEFFILTER_P_H
#define QDECLARATIVENDEFFILTER_P_H

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

#include <QtCore/QObject>
#include <qqmlndefrecord.h>

class QDeclarativeNdefFilter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QQmlNdefRecord::TypeNameFormat typeNameFormat READ typeNameFormat WRITE setTypeNameFormat NOTIFY typeNameFormatChanged)
    Q_PROPERTY(int minimum READ minimum WRITE setMinimum NOTIFY minimumChanged)
    Q_PROPERTY(int maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
public:
    explicit QDeclarativeNdefFilter(QObject *parent = 0);

    QString type() const;
    void setType(const QString &t);

    QQmlNdefRecord::TypeNameFormat typeNameFormat() const;
    void setTypeNameFormat(QQmlNdefRecord::TypeNameFormat format);

    int minimum() const;
    void setMinimum(int value);

    int maximum() const;
    void setMaximum(int value);

signals:
    void typeChanged();
    void minimumChanged();
    void maximumChanged();
    void typeNameFormatChanged();

private:
    QString m_type;
    int m_minimum;
    int m_maximum;
    QQmlNdefRecord::TypeNameFormat m_typeNameFormat;
};

#endif // QDECLARATIVENDEFFILTER_P_H
