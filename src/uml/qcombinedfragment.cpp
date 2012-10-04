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

#include "qcombinedfragment.h"
//#include "qcombinedfragment_p.h"

QT_BEGIN_NAMESPACE_QTUML

/*!
    \class QCombinedFragment

    \inmodule QtUml

    \brief A combined fragment defines an expression of interaction fragments. A combined fragment is defined by an interaction operator and corresponding interaction operands. Through the use of combined fragments the user will be able to describe a number of traces in a compact and concise manner.
 */

QCombinedFragment::QCombinedFragment(QObject *parent)
    : QObject(parent)
{
}

QCombinedFragment::~QCombinedFragment()
{
}

/*!
    Specifies the operation which defines the semantics of this combination of InteractionFragments.
 */
QtUml::InteractionOperatorKind QCombinedFragment::interactionOperator() const
{
}

void QCombinedFragment::setInteractionOperator(QtUml::InteractionOperatorKind interactionOperator)
{
}

/*!
    Specifies the gates that form the interface between this CombinedFragment and its surroundings
 */
const QSet<QGate *> *QCombinedFragment::cfragmentGates() const
{
}

void QCombinedFragment::addCfragmentGate(const QGate *cfragmentGate)
{
}

void QCombinedFragment::removeCfragmentGate(const QGate *cfragmentGate)
{
}

/*!
    The set of operands of the combined fragment.
 */
const QList<QInteractionOperand *> *QCombinedFragment::operands() const
{
}

void QCombinedFragment::addOperand(const QInteractionOperand *operand)
{
}

void QCombinedFragment::removeOperand(const QInteractionOperand *operand)
{
}

#include "moc_qcombinedfragment.cpp"

QT_END_NAMESPACE_QTUML

