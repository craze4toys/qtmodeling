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
#include "qumltimeconstraint.h"
#include "qumltimeconstraint_p.h"

#include <QtUml/QUmlTimeInterval>

QT_BEGIN_NAMESPACE

QUmlTimeConstraintPrivate::QUmlTimeConstraintPrivate() :
    firstEvent(true),
    specification(0)
{
}

/*!
    \class QUmlTimeConstraint

    \inmodule QtUml

    \brief A time constraint is a constraint that refers to a time interval.
 */

QUmlTimeConstraint::QUmlTimeConstraint(bool create_d_ptr) :
    QUmlIntervalConstraint(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlTimeConstraintPrivate);
}

// OWNED ATTRIBUTES

/*!
    The value of firstEvent is related to constrainedElement. If firstEvent is true, then the corresponding observation event is the first time instant the execution enters constrainedElement. If firstEvent is false, then the corresponding observation event is the last time instant the execution is within constrainedElement.
 */
bool QUmlTimeConstraint::firstEvent() const
{
    // This is a read-write property

    QM_D(const QUmlTimeConstraint);
    return d->firstEvent;
}

void QUmlTimeConstraint::setFirstEvent(bool firstEvent)
{
    // This is a read-write property

    QM_D(QUmlTimeConstraint);
    if (d->firstEvent != firstEvent) {
        d->firstEvent = firstEvent;
    }
}

/*!
    A condition that must be true when evaluated in order for the constraint to be satisfied.
 */
QUmlTimeInterval *QUmlTimeConstraint::specification() const
{
    // This is a read-write association end

    QM_D(const QUmlTimeConstraint);
    return d->specification;
}

void QUmlTimeConstraint::setSpecification(QUmlTimeInterval *specification)
{
    // This is a read-write association end

    QM_D(QUmlTimeConstraint);
    if (d->specification != specification) {
        d->specification = specification;
    }
}

QT_END_NAMESPACE

