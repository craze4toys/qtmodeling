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
#include "qumlactionexecutionspecification.h"

#include "private/qumlactionexecutionspecificationobject_p.h"

#include <QtUml/QUmlAction>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlGeneralOrdering>
#include <QtUml/QUmlInteraction>
#include <QtUml/QUmlInteractionOperand>
#include <QtUml/QUmlLifeline>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOccurrenceSpecification>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlStringExpression>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlActionExecutionSpecification

    \inmodule QtUml

    \brief An action execution specification is a kind of execution specification representing the execution of an action.
 */

/*!
    Creates a new QUmlActionExecutionSpecification. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlActionExecutionSpecification::QUmlActionExecutionSpecification(bool createQModelingObject) :
    _action(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlActionExecutionSpecificationObject(this));
}

/*!
    Destroys the QUmlActionExecutionSpecification.
 */
QUmlActionExecutionSpecification::~QUmlActionExecutionSpecification()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlActionExecutionSpecification.
*/
QModelingElement *QUmlActionExecutionSpecification::clone() const
{
    QUmlActionExecutionSpecification *c = new QUmlActionExecutionSpecification;
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
    return c;
}

// OWNED ATTRIBUTES

/*!
    Action whose execution is occurring.
 */
QUmlAction *QUmlActionExecutionSpecification::action() const
{
    // This is a read-write association end

    return _action;
}

/*!
    Adjusts action to \a action.
 */
void QUmlActionExecutionSpecification::setAction(QUmlAction *action)
{
    // This is a read-write association end

    if (_action != action) {
        _action = action;
        if (action && action->asQModelingObject() && this->asQModelingObject())
            QObject::connect(action->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setAction()));
    }
}

QT_END_NAMESPACE

