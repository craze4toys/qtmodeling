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
#include "qumlinteractionconstraint.h"

#include "private/qumlinteractionconstraintobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlInteractionConstraint

    \inmodule QtUml

    \brief An interaction constraint is a Boolean expression that guards an operand in a combined fragment.
 */

/*!
    Creates a new QUmlInteractionConstraint. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlInteractionConstraint::QUmlInteractionConstraint(bool createQModelingObject) :
    QUmlConstraint(false),
    _maxint(0),
    _minint(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlInteractionConstraintObject(this));
}

/*!
    Destroys the QUmlInteractionConstraint.
 */
QUmlInteractionConstraint::~QUmlInteractionConstraint()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlInteractionConstraint.
*/
QModelingElement *QUmlInteractionConstraint::clone() const
{
    QUmlInteractionConstraint *c = new QUmlInteractionConstraint;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    if (specification())
        c->setSpecification(dynamic_cast<QUmlValueSpecification *>(specification()->clone()));
    if (maxint())
        c->setMaxint(dynamic_cast<QUmlValueSpecification *>(maxint()->clone()));
    if (minint())
        c->setMinint(dynamic_cast<QUmlValueSpecification *>(minint()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The maximum number of iterations of a loop

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
QUmlValueSpecification *QUmlInteractionConstraint::maxint() const
{
    // This is a read-write association end

    return _maxint;
}

/*!
    Adjusts maxint to \a maxint.
 */
void QUmlInteractionConstraint::setMaxint(QUmlValueSpecification *maxint)
{
    // This is a read-write association end

    if (_maxint != maxint) {
        // Adjust subsetted properties
        removeOwnedElement(_maxint);

        _maxint = maxint;
        if (maxint && maxint->asQModelingObject() && this->asQModelingObject())
            QObject::connect(maxint->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setMaxint()));
        maxint->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        if (maxint) {
            addOwnedElement(maxint);
        }
    }
}

/*!
    The minimum number of iterations of a loop

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
QUmlValueSpecification *QUmlInteractionConstraint::minint() const
{
    // This is a read-write association end

    return _minint;
}

/*!
    Adjusts minint to \a minint.
 */
void QUmlInteractionConstraint::setMinint(QUmlValueSpecification *minint)
{
    // This is a read-write association end

    if (_minint != minint) {
        // Adjust subsetted properties
        removeOwnedElement(_minint);

        _minint = minint;
        if (minint && minint->asQModelingObject() && this->asQModelingObject())
            QObject::connect(minint->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setMinint()));
        minint->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        if (minint) {
            addOwnedElement(minint);
        }
    }
}

QT_END_NAMESPACE

