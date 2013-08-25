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
#include "qumldurationinterval.h"
#include "qumldurationinterval_p.h"

#include <QtUml/QUmlDuration>

QT_BEGIN_NAMESPACE

QUmlDurationIntervalPrivate::QUmlDurationIntervalPrivate() :
    max(0),
    min(0)
{
}

/*!
    \class QUmlDurationInterval

    \inmodule QtUml

    \brief A duration interval defines the range between two durations.
 */

QUmlDurationInterval::QUmlDurationInterval(bool create_d_ptr) :
    QUmlInterval(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlDurationIntervalPrivate);
}

// OWNED ATTRIBUTES

/*!
    Refers to the Duration denoting the maximum value of the range.
 */
QUmlDuration *QUmlDurationInterval::max() const
{
    // This is a read-write association end

    QM_D(const QUmlDurationInterval);
    return d->max;
}

void QUmlDurationInterval::setMax(QUmlDuration *max)
{
    // This is a read-write association end

    QM_D(QUmlDurationInterval);
    if (d->max != max) {
        d->max = max;
    }
}

/*!
    Refers to the Duration denoting the minimum value of the range.
 */
QUmlDuration *QUmlDurationInterval::min() const
{
    // This is a read-write association end

    QM_D(const QUmlDurationInterval);
    return d->min;
}

void QUmlDurationInterval::setMin(QUmlDuration *min)
{
    // This is a read-write association end

    QM_D(QUmlDurationInterval);
    if (d->min != min) {
        d->min = min;
    }
}

QT_END_NAMESPACE

