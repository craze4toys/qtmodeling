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
#include "qumladdstructuralfeaturevalueaction.h"
#include "qumladdstructuralfeaturevalueaction_p.h"

#include <QtUml/QUmlInputPin>

QT_BEGIN_NAMESPACE

QUmlAddStructuralFeatureValueActionPrivate::QUmlAddStructuralFeatureValueActionPrivate() :
    insertAt(0),
    isReplaceAll(false)
{
}

/*!
    \class QUmlAddStructuralFeatureValueAction

    \inmodule QtUml

    \brief An add structural feature value action is a write structural feature action for adding values to a structural feature.
 */

QUmlAddStructuralFeatureValueAction::QUmlAddStructuralFeatureValueAction(bool create_d_ptr) :
    QUmlWriteStructuralFeatureAction(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlAddStructuralFeatureValueActionPrivate);
}

// OWNED ATTRIBUTES

/*!
    Gives the position at which to insert a new value or move an existing value in ordered structural features. The type of the pin is UnlimitedNatural, but the value cannot be zero. This pin is omitted for unordered structural features.
 */
QUmlInputPin *QUmlAddStructuralFeatureValueAction::insertAt() const
{
    // This is a read-write association end

    QM_D(const QUmlAddStructuralFeatureValueAction);
    return d->insertAt;
}

void QUmlAddStructuralFeatureValueAction::setInsertAt(QUmlInputPin *insertAt)
{
    // This is a read-write association end

    QM_D(QUmlAddStructuralFeatureValueAction);
    if (d->insertAt != insertAt) {
        d->insertAt = insertAt;
    }
}

/*!
    Specifies whether existing values of the structural feature of the object should be removed before adding the new value.
 */
bool QUmlAddStructuralFeatureValueAction::isReplaceAll() const
{
    // This is a read-write property

    QM_D(const QUmlAddStructuralFeatureValueAction);
    return d->isReplaceAll;
}

void QUmlAddStructuralFeatureValueAction::setReplaceAll(bool isReplaceAll)
{
    // This is a read-write property

    QM_D(QUmlAddStructuralFeatureValueAction);
    if (d->isReplaceAll != isReplaceAll) {
        d->isReplaceAll = isReplaceAll;
    }
}

QT_END_NAMESPACE

