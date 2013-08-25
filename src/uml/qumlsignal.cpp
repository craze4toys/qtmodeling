/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
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
#include "qumlsignal.h"
#include "qumlsignal_p.h"

#include <QtUml/QUmlProperty>

QT_BEGIN_NAMESPACE

QUmlSignalPrivate::QUmlSignalPrivate()
{
}

/*!
    \class QUmlSignal

    \inmodule QtUml

    \brief A signal is a specification of send request instances communicated between objects. The receiving object handles the received request instances as specified by its receptions. The data carried by a send request (which was passed to it by the send invocation occurrence that caused that request) are represented as attributes of the signal. A signal is defined independently of the classifiers handling the signal occurrence.
 */

QUmlSignal::QUmlSignal(bool create_d_ptr) :
    QUmlClassifier(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlSignalPrivate);
}

// OWNED ATTRIBUTES

/*!
    The attributes owned by the signal.
 */
QList<QUmlProperty *> QUmlSignal::ownedAttribute() const
{
    // This is a read-write association end

    QM_D(const QUmlSignal);
    return d->ownedAttribute;
}

void QUmlSignal::addOwnedAttribute(QUmlProperty *ownedAttribute)
{
    // This is a read-write association end

    QM_D(QUmlSignal);
    if (!d->ownedAttribute.contains(ownedAttribute)) {
        d->ownedAttribute.append(ownedAttribute);
    }
}

void QUmlSignal::removeOwnedAttribute(QUmlProperty *ownedAttribute)
{
    // This is a read-write association end

    QM_D(QUmlSignal);
    if (d->ownedAttribute.contains(ownedAttribute)) {
        d->ownedAttribute.removeAll(ownedAttribute);
    }
}

QT_END_NAMESPACE

