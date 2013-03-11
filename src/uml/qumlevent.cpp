/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qumlevent.h"
#include "qumlevent_p.h"

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

QUmlEventPrivate::QUmlEventPrivate()
{
}

QUmlEventPrivate::~QUmlEventPrivate()
{
}

/*!
    \class QUmlEvent

    \inmodule QtUml

    \brief An event is the specification of some occurrence that may potentially trigger effects by an object.
 */

QUmlEvent::QUmlEvent(QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlPackageableElement(*new QUmlEventPrivate, wrapper, parent)
{
    setPropertyData();
}

QUmlEvent::QUmlEvent(QUmlEventPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QUmlPackageableElement(dd, wrapper, parent)
{
    setPropertyData();
}

QUmlEvent::~QUmlEvent()
{
}

void QUmlEvent::setPropertyData()
{
    QUmlPackageableElement::setPropertyData();
}

QT_END_NAMESPACE

#include "moc_qumlevent.cpp"
