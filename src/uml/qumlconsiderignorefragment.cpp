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
#include "qumlconsiderignorefragment.h"

#include "private/qumlconsiderignorefragmentobject_p.h"

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

/*!
    \class QUmlConsiderIgnoreFragment

    \inmodule QtUml

    \brief A consider ignore fragment is a kind of combined fragment that is used for the consider and ignore cases, which require lists of pertinent messages to be specified.
 */
QUmlConsiderIgnoreFragment::QUmlConsiderIgnoreFragment(bool createQObject) :
    QUmlCombinedFragment(false)
{
    if (createQObject)
        _qObject = new QUmlConsiderIgnoreFragmentObject(this);
    setClassForProperty();
    setPropertyData();
}

QUmlConsiderIgnoreFragment::~QUmlConsiderIgnoreFragment()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlConsiderIgnoreFragment::clone() const
{
    QUmlConsiderIgnoreFragment *c = new QUmlConsiderIgnoreFragment;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlLifeline *element, covered())
        c->addCovered(dynamic_cast<QUmlLifeline *>(element->clone()));
    if (enclosingInteraction())
        c->setEnclosingInteraction(dynamic_cast<QUmlInteraction *>(enclosingInteraction()->clone()));
    if (enclosingOperand())
        c->setEnclosingOperand(dynamic_cast<QUmlInteractionOperand *>(enclosingOperand()->clone()));
    foreach (QUmlGeneralOrdering *element, generalOrderings())
        c->addGeneralOrdering(dynamic_cast<QUmlGeneralOrdering *>(element->clone()));
    foreach (QUmlGate *element, cfragmentGates())
        c->addCfragmentGate(dynamic_cast<QUmlGate *>(element->clone()));
    c->setInteractionOperator(interactionOperator());
    foreach (QUmlInteractionOperand *element, operands())
        c->addOperand(dynamic_cast<QUmlInteractionOperand *>(element->clone()));
    foreach (QUmlNamedElement *element, messages())
        c->addMessage(dynamic_cast<QUmlNamedElement *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The set of messages that apply to this fragment
 */
const QSet<QUmlNamedElement *> QUmlConsiderIgnoreFragment::messages() const
{
    // This is a read-write association end

    return _messages;
}

void QUmlConsiderIgnoreFragment::addMessage(QUmlNamedElement *message)
{
    // This is a read-write association end

    if (!_messages.contains(message)) {
        _messages.insert(message);
        if (message && message->asQObject() && this->asQObject())
            QObject::connect(message->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeMessage(QObject *)));
    }
}

void QUmlConsiderIgnoreFragment::removeMessage(QUmlNamedElement *message)
{
    // This is a read-write association end

    if (_messages.contains(message)) {
        _messages.remove(message);
    }
}

void QUmlConsiderIgnoreFragment::setClassForProperty()
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
    _classForProperty[QStringLiteral("covered")] = QStringLiteral("QUmlInteractionFragment");
    _classForProperty[QStringLiteral("enclosingInteraction")] = QStringLiteral("QUmlInteractionFragment");
    _classForProperty[QStringLiteral("enclosingOperand")] = QStringLiteral("QUmlInteractionFragment");
    _classForProperty[QStringLiteral("generalOrderings")] = QStringLiteral("QUmlInteractionFragment");
    _classForProperty[QStringLiteral("cfragmentGates")] = QStringLiteral("QUmlCombinedFragment");
    _classForProperty[QStringLiteral("interactionOperator")] = QStringLiteral("QUmlCombinedFragment");
    _classForProperty[QStringLiteral("operands")] = QStringLiteral("QUmlCombinedFragment");
    _classForProperty[QStringLiteral("messages")] = QStringLiteral("QUmlConsiderIgnoreFragment");
}

void QUmlConsiderIgnoreFragment::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlConsiderIgnoreFragment");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::DocumentationRole] = QStringLiteral("The set of messages that apply to this fragment");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlConsiderIgnoreFragment")][QStringLiteral("messages")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

