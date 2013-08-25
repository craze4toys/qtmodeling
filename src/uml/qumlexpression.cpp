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
#include "qumlexpression.h"
#include "qumlexpression_p.h"

QT_BEGIN_NAMESPACE

QUmlExpressionPrivate::QUmlExpressionPrivate()
{
}

/*!
    \class QUmlExpression

    \inmodule QtUml

    \brief An expression is a structured tree of symbols that denotes a (possibly empty) set of values when evaluated in a context.An expression represents a node in an expression tree, which may be non-terminal or terminal. It defines a symbol, and has a possibly empty sequence of operands which are value specifications.
 */

QUmlExpression::QUmlExpression(bool create_d_ptr) :
    QUmlValueSpecification(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlExpressionPrivate);
}

// OWNED ATTRIBUTES

/*!
    Specifies a sequence of operands.
 */
QList<QUmlValueSpecification *> QUmlExpression::operand() const
{
    // This is a read-write association end

    QM_D(const QUmlExpression);
    return d->operand;
}

void QUmlExpression::addOperand(QUmlValueSpecification *operand)
{
    // This is a read-write association end

    QM_D(QUmlExpression);
    if (!d->operand.contains(operand)) {
        d->operand.append(operand);
    }
}

void QUmlExpression::removeOperand(QUmlValueSpecification *operand)
{
    // This is a read-write association end

    QM_D(QUmlExpression);
    if (d->operand.contains(operand)) {
        d->operand.removeAll(operand);
    }
}

/*!
    The symbol associated with the node in the expression tree.
 */
QString QUmlExpression::symbol() const
{
    // This is a read-write property

    QM_D(const QUmlExpression);
    return d->symbol;
}

void QUmlExpression::setSymbol(QString symbol)
{
    // This is a read-write property

    QM_D(QUmlExpression);
    if (d->symbol != symbol) {
        d->symbol = symbol;
    }
}

QT_END_NAMESPACE

