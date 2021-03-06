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
#include "qumlcombinedfragment.h"

#include "private/qumlcombinedfragmentobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlGate>
#include <QtUml/QUmlGeneralOrdering>
#include <QtUml/QUmlInteraction>
#include <QtUml/QUmlInteractionOperand>
#include <QtUml/QUmlLifeline>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlStringExpression>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlCombinedFragment

    \inmodule QtUml

    \brief A combined fragment defines an expression of interaction fragments. A combined fragment is defined by an interaction operator and corresponding interaction operands. Through the use of combined fragments the user will be able to describe a number of traces in a compact and concise manner.
 */

/*!
    Creates a new QUmlCombinedFragment. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlCombinedFragment::QUmlCombinedFragment(bool createQModelingObject) :
    _interactionOperator(QtUml::InteractionOperatorKindSeq)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlCombinedFragmentObject(this));
}

/*!
    Destroys the QUmlCombinedFragment.
 */
QUmlCombinedFragment::~QUmlCombinedFragment()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlCombinedFragment.
*/
QModelingElement *QUmlCombinedFragment::clone() const
{
    QUmlCombinedFragment *c = new QUmlCombinedFragment;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlGeneralOrdering *element, generalOrderings())
        c->addGeneralOrdering(dynamic_cast<QUmlGeneralOrdering *>(element->clone()));
    foreach (QUmlGate *element, cfragmentGates())
        c->addCfragmentGate(dynamic_cast<QUmlGate *>(element->clone()));
    c->setInteractionOperator(interactionOperator());
    foreach (QUmlInteractionOperand *element, operands())
        c->addOperand(dynamic_cast<QUmlInteractionOperand *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies the gates that form the interface between this CombinedFragment and its surroundings

    \sa addCfragmentGate(), removeCfragmentGate()

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
const QSet<QUmlGate *> QUmlCombinedFragment::cfragmentGates() const
{
    // This is a read-write association end

    return _cfragmentGates;
}

/*!
    Adds \a cfragmentGate to cfragmentGates.

    \sa cfragmentGates(), removeCfragmentGate()
 */
void QUmlCombinedFragment::addCfragmentGate(QUmlGate *cfragmentGate)
{
    // This is a read-write association end

    if (!_cfragmentGates.contains(cfragmentGate)) {
        _cfragmentGates.insert(cfragmentGate);
        if (cfragmentGate && cfragmentGate->asQModelingObject() && this->asQModelingObject())
            QObject::connect(cfragmentGate->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeCfragmentGate(QObject *)));
        cfragmentGate->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedElement(cfragmentGate);
    }
}

/*!
    Removes \a cfragmentGate from cfragmentGates.

    \sa cfragmentGates(), addCfragmentGate()
 */
void QUmlCombinedFragment::removeCfragmentGate(QUmlGate *cfragmentGate)
{
    // This is a read-write association end

    if (_cfragmentGates.contains(cfragmentGate)) {
        _cfragmentGates.remove(cfragmentGate);
        if (cfragmentGate->asQModelingObject())
            cfragmentGate->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(cfragmentGate);
    }
}

/*!
    Specifies the operation which defines the semantics of this combination of InteractionFragments.
 */
QtUml::InteractionOperatorKind QUmlCombinedFragment::interactionOperator() const
{
    // This is a read-write property

    return _interactionOperator;
}

/*!
    Adjusts interactionOperator to \a interactionOperator.
 */
void QUmlCombinedFragment::setInteractionOperator(QtUml::InteractionOperatorKind interactionOperator)
{
    // This is a read-write property

    if (_interactionOperator != interactionOperator) {
        _interactionOperator = interactionOperator;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("interactionOperator");
    }
}

/*!
    The set of operands of the combined fragment.

    \sa addOperand(), removeOperand()

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
const QList<QUmlInteractionOperand *> QUmlCombinedFragment::operands() const
{
    // This is a read-write association end

    return _operands;
}

/*!
    Adds \a operand to operands.

    \sa operands(), removeOperand()
 */
void QUmlCombinedFragment::addOperand(QUmlInteractionOperand *operand)
{
    // This is a read-write association end

    if (!_operands.contains(operand)) {
        _operands.append(operand);
        if (operand && operand->asQModelingObject() && this->asQModelingObject())
            QObject::connect(operand->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeOperand(QObject *)));
        operand->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedElement(operand);
    }
}

/*!
    Removes \a operand from operands.

    \sa operands(), addOperand()
 */
void QUmlCombinedFragment::removeOperand(QUmlInteractionOperand *operand)
{
    // This is a read-write association end

    if (_operands.contains(operand)) {
        _operands.removeAll(operand);
        if (operand->asQModelingObject())
            operand->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(operand);
    }
}

QT_END_NAMESPACE

