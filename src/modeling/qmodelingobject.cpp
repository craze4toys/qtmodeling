/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtModeling module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "qmodelingobject.h"
#include "qmodelingobject_p.h"

QT_BEGIN_NAMESPACE

QHash< QString, QHash< QString, QHash<QtModeling::MetaPropertyDataRole, QVariant> > > QModelingObjectPrivate::propertyDataHash;

QModelingObjectPrivate::QModelingObjectPrivate()
{
}

QModelingObjectPrivate::~QModelingObjectPrivate()
{
    qDeleteAll(groupProperties);
}

QModelingObject::~QModelingObject()
{
}

bool QModelingObject::isPropertyModified(QMetaProperty metaProperty) const
{
    Q_D(const QModelingObject);
    return d->modifiedResettableProperties.contains(QString::fromLatin1(metaProperty.name()));
}

QVariant QModelingObject::propertyData(QString className, QMetaProperty metaProperty, QtModeling::MetaPropertyDataRole role)
{
    return QModelingObjectPrivate::propertyDataHash[className][QString::fromLatin1(metaProperty.name())][role];
}

int QModelingObject::propertyGroupIndex(QMetaProperty metaProperty) const
{
    Q_D(const QModelingObject);
    int groupIndex = 0;
    foreach (QString group, d->propertyGroups) {
        foreach (QMetaProperty *metaPropertyPointer, d->groupProperties.values(group))
            if (metaPropertyPointer->name() == metaProperty.name())
                return groupIndex;
        ++groupIndex;
    }
    return -1;
}

const QStringList &QModelingObject::propertyGroups() const
{
    Q_D(const QModelingObject);
    return d->propertyGroups;
}

const QStringList &QModelingObject::modifiedResettableProperties() const
{
    Q_D(const QModelingObject);
    return d->modifiedResettableProperties;
}

QModelingObject::QModelingObject()
{
}
