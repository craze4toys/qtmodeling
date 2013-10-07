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
#include "qumlreplyaction.h"

#include "private/qumlreplyactionobject_p.h"

#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlExceptionHandler>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOutputPin>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>
#include <QtUml/QUmlTrigger>

/*!
    \class QUmlReplyAction

    \inmodule QtUml

    \brief A reply action is an action that accepts a set of return values and a value containing return information produced by a previous accept call action. The reply action returns the values to the caller of the previous call, completing execution of the call.
 */
QUmlReplyAction::QUmlReplyAction(bool createQObject) :
    _replyToCall(0),
    _returnInformation(0)
{
    if (createQObject)
        _qObject = new QUmlReplyActionObject(this);
    setPropertyData();
}

QUmlReplyAction::~QUmlReplyAction()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlReplyAction::clone() const
{
    QUmlReplyAction *c = new QUmlReplyAction;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    if (activity())
        c->setActivity(dynamic_cast<QUmlActivity *>(activity()->clone()));
    foreach (QUmlInterruptibleActivityRegion *element, inInterruptibleRegions())
        c->addInInterruptibleRegion(dynamic_cast<QUmlInterruptibleActivityRegion *>(element->clone()));
    foreach (QUmlActivityPartition *element, inPartitions())
        c->addInPartition(dynamic_cast<QUmlActivityPartition *>(element->clone()));
    if (inStructuredNode())
        c->setInStructuredNode(dynamic_cast<QUmlStructuredActivityNode *>(inStructuredNode()->clone()));
    foreach (QUmlActivityEdge *element, incomings())
        c->addIncoming(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    foreach (QUmlActivityEdge *element, outgoings())
        c->addOutgoing(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    foreach (QUmlActivityNode *element, redefinedNodes())
        c->addRedefinedNode(dynamic_cast<QUmlActivityNode *>(element->clone()));
    foreach (QUmlExceptionHandler *element, handlers())
        c->addHandler(dynamic_cast<QUmlExceptionHandler *>(element->clone()));
    c->setLocallyReentrant(isLocallyReentrant());
    foreach (QUmlConstraint *element, localPostconditions())
        c->addLocalPostcondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlConstraint *element, localPreconditions())
        c->addLocalPrecondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    if (replyToCall())
        c->setReplyToCall(dynamic_cast<QUmlTrigger *>(replyToCall()->clone()));
    foreach (QUmlInputPin *element, replyValues())
        c->addReplyValue(dynamic_cast<QUmlInputPin *>(element->clone()));
    if (returnInformation())
        c->setReturnInformation(dynamic_cast<QUmlInputPin *>(returnInformation()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The trigger specifying the operation whose call is being replied to.
 */
QUmlTrigger *QUmlReplyAction::replyToCall() const
{
    // This is a read-write association end

    return _replyToCall;
}

void QUmlReplyAction::setReplyToCall(QUmlTrigger *replyToCall)
{
    // This is a read-write association end

    if (_replyToCall != replyToCall) {
        _replyToCall = replyToCall;
        if (replyToCall && replyToCall->asQObject() && this->asQObject())
            QObject::connect(replyToCall->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setReplyToCall()));
    }
}

/*!
    A list of pins containing the reply values of the operation. These values are returned to the caller.
 */
const QSet<QUmlInputPin *> QUmlReplyAction::replyValues() const
{
    // This is a read-write association end

    return _replyValues;
}

void QUmlReplyAction::addReplyValue(QUmlInputPin *replyValue)
{
    // This is a read-write association end

    if (!_replyValues.contains(replyValue)) {
        _replyValues.insert(replyValue);
        if (replyValue && replyValue->asQObject() && this->asQObject())
            QObject::connect(replyValue->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeReplyValue(QObject *)));
        replyValue->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addInput(replyValue);
    }
}

void QUmlReplyAction::removeReplyValue(QUmlInputPin *replyValue)
{
    // This is a read-write association end

    if (_replyValues.contains(replyValue)) {
        _replyValues.remove(replyValue);
        if (replyValue->asQObject())
            replyValue->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeInput(replyValue);
    }
}

/*!
    A pin containing the return information value produced by an earlier AcceptCallAction.
 */
QUmlInputPin *QUmlReplyAction::returnInformation() const
{
    // This is a read-write association end

    return _returnInformation;
}

void QUmlReplyAction::setReturnInformation(QUmlInputPin *returnInformation)
{
    // This is a read-write association end

    if (_returnInformation != returnInformation) {
        // Adjust subsetted properties
        removeInput(_returnInformation);

        _returnInformation = returnInformation;
        if (returnInformation && returnInformation->asQObject() && this->asQObject())
            QObject::connect(returnInformation->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setReturnInformation()));
        returnInformation->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (returnInformation) {
            addInput(returnInformation);
        }
    }
}

void QUmlReplyAction::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlReplyAction");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::DocumentationRole] = QStringLiteral("The trigger specifying the operation whose call is being replied to.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyToCall")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlReplyAction");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::DocumentationRole] = QStringLiteral("A list of pins containing the reply values of the operation. These values are returned to the caller.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Action-input");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("replyValue")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlReplyAction");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::DocumentationRole] = QStringLiteral("A pin containing the return information value produced by an earlier AcceptCallAction.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Action-input");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlReplyAction")][QStringLiteral("returnInformation")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

void QUmlReplyAction::setClassForProperty()
{
    _classForProperty[QStringLiteral("ownedComments")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("ownedElements")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("owner")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("clientDependencies")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("name")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("nameExpression")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("namespace_")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("qualifiedName")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("visibility")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("isLeaf")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinedElements")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinitionContexts")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("activity")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("inGroups")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("inInterruptibleRegions")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("inPartitions")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("inStructuredNode")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("incomings")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("outgoings")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("redefinedNodes")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("handlers")] = QStringLiteral("QUmlExecutableNode");
    _classForProperty[QStringLiteral("context")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("inputs")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("isLocallyReentrant")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("localPostconditions")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("localPreconditions")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("outputs")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("replyToCall")] = QStringLiteral("QUmlReplyAction");
    _classForProperty[QStringLiteral("replyValues")] = QStringLiteral("QUmlReplyAction");
    _classForProperty[QStringLiteral("returnInformation")] = QStringLiteral("QUmlReplyAction");
}

