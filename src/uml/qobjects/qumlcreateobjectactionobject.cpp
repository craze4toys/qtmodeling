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
#include "qumlcreateobjectactionobject_p.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlCreateObjectAction>
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

QT_BEGIN_NAMESPACE

QUmlCreateObjectActionObject::QUmlCreateObjectActionObject(QUmlCreateObjectAction *qModelingElement)
{
    setProperty("modelingElement", QVariant::fromValue(static_cast<QModelingElement *>(qModelingElement)));
    setGroupProperties();
    setPropertyData();
}

QUmlCreateObjectActionObject::~QUmlCreateObjectActionObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->deletingFromQModelingObject = true;
        delete qmodelingelementproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlCreateObjectActionObject::ownedComments() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->ownedComments())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlCreateObjectActionObject::ownedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->ownedElements())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlCreateObjectActionObject::owner() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->owner())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->owner()->asQModelingObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlCreateObjectActionObject::clientDependencies() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->clientDependencies())
        set.insert(element->asQModelingObject());
    return set;
}

QString QUmlCreateObjectActionObject::name() const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->name();
}

QObject *QUmlCreateObjectActionObject::nameExpression() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->nameExpression())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->nameExpression()->asQModelingObject();
}

QObject *QUmlCreateObjectActionObject::namespace_() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->namespace_())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->namespace_()->asQModelingObject();
}

QString QUmlCreateObjectActionObject::qualifiedName() const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->qualifiedName();
}

QtUml::VisibilityKind QUmlCreateObjectActionObject::visibility() const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->visibility();
}

// OWNED ATTRIBUTES [RedefinableElement]

bool QUmlCreateObjectActionObject::isLeaf() const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->isLeaf();
}

const QSet<QObject *> QUmlCreateObjectActionObject::redefinedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlRedefinableElement *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->redefinedElements())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlCreateObjectActionObject::redefinitionContexts() const
{
    QSet<QObject *> set;
    foreach (QUmlClassifier *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->redefinitionContexts())
        set.insert(element->asQModelingObject());
    return set;
}

// OWNED ATTRIBUTES [ActivityNode]

QObject *QUmlCreateObjectActionObject::activity() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->activity())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->activity()->asQModelingObject();
}

const QSet<QObject *> QUmlCreateObjectActionObject::inGroups() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityGroup *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->inGroups())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlCreateObjectActionObject::inInterruptibleRegions() const
{
    QSet<QObject *> set;
    foreach (QUmlInterruptibleActivityRegion *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->inInterruptibleRegions())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlCreateObjectActionObject::inPartitions() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityPartition *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->inPartitions())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlCreateObjectActionObject::inStructuredNode() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->inStructuredNode())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->inStructuredNode()->asQModelingObject();
}

const QSet<QObject *> QUmlCreateObjectActionObject::incomings() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityEdge *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->incomings())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlCreateObjectActionObject::outgoings() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityEdge *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->outgoings())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlCreateObjectActionObject::redefinedNodes() const
{
    QSet<QObject *> set;
    foreach (QUmlActivityNode *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->redefinedNodes())
        set.insert(element->asQModelingObject());
    return set;
}

// OWNED ATTRIBUTES [ExecutableNode]

const QSet<QObject *> QUmlCreateObjectActionObject::handlers() const
{
    QSet<QObject *> set;
    foreach (QUmlExceptionHandler *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->handlers())
        set.insert(element->asQModelingObject());
    return set;
}

// OWNED ATTRIBUTES [Action]

QObject *QUmlCreateObjectActionObject::context() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->context())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->context()->asQModelingObject();
}

const QList<QObject *> QUmlCreateObjectActionObject::inputs() const
{
    QList<QObject *> list;
    foreach (QUmlInputPin *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->inputs())
        list.append(element->asQModelingObject());
    return list;
}

bool QUmlCreateObjectActionObject::isLocallyReentrant() const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->isLocallyReentrant();
}

const QSet<QObject *> QUmlCreateObjectActionObject::localPostconditions() const
{
    QSet<QObject *> set;
    foreach (QUmlConstraint *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->localPostconditions())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlCreateObjectActionObject::localPreconditions() const
{
    QSet<QObject *> set;
    foreach (QUmlConstraint *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->localPreconditions())
        set.insert(element->asQModelingObject());
    return set;
}

const QList<QObject *> QUmlCreateObjectActionObject::outputs() const
{
    QList<QObject *> list;
    foreach (QUmlOutputPin *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->outputs())
        list.append(element->asQModelingObject());
    return list;
}

// OWNED ATTRIBUTES [CreateObjectAction]

QObject *QUmlCreateObjectActionObject::classifier() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->classifier())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->classifier()->asQModelingObject();
}

QObject *QUmlCreateObjectActionObject::result() const
{
    if (!qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->result())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->result()->asQModelingObject();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlCreateObjectActionObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->allOwnedElements())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlCreateObjectActionObject::mustBeOwned() const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->mustBeOwned();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlCreateObjectActionObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->allNamespaces())
        set.append(element->asQModelingObject());
    return set;
}

QSet<QObject *> QUmlCreateObjectActionObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->allOwningPackages())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlCreateObjectActionObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->isDistinguishableFrom(qmodelingelementproperty_cast<QUmlNamedElement *>(n), qmodelingelementproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlCreateObjectActionObject::separator() const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->separator();
}

// OPERATIONS [RedefinableElement]

bool QUmlCreateObjectActionObject::isConsistentWith(QObject *redefinee) const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->isConsistentWith(qmodelingelementproperty_cast<QUmlRedefinableElement *>(redefinee));
}

bool QUmlCreateObjectActionObject::isRedefinitionContextValid(QObject *redefined) const
{
    return qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->isRedefinitionContextValid(qmodelingelementproperty_cast<QUmlRedefinableElement *>(redefined));
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlCreateObjectActionObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlCreateObjectActionObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlCreateObjectActionObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlCreateObjectActionObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlCreateObjectActionObject::setOwner(QObject *owner)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setOwner(qmodelingelementproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlCreateObjectActionObject::addClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlCreateObjectActionObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlCreateObjectActionObject::setName(QString name)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setName(name);
}

void QUmlCreateObjectActionObject::setNameExpression(QObject *nameExpression)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setNameExpression(qmodelingelementproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlCreateObjectActionObject::setNamespace(QObject *namespace_)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setNamespace(qmodelingelementproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlCreateObjectActionObject::setQualifiedName(QString qualifiedName)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setQualifiedName(qualifiedName);
}

void QUmlCreateObjectActionObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setVisibility(visibility);
}

// SLOTS FOR OWNED ATTRIBUTES [RedefinableElement]

void QUmlCreateObjectActionObject::setLeaf(bool isLeaf)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setLeaf(isLeaf);
}

void QUmlCreateObjectActionObject::unsetLeaf()
{
    Q_D(QModelingObject);
    d->modifiedResettableProperties.removeAll(QStringLiteral("leaf"));
}

void QUmlCreateObjectActionObject::addRedefinedElement(QObject *redefinedElement)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addRedefinedElement(qmodelingelementproperty_cast<QUmlRedefinableElement *>(redefinedElement));
}

void QUmlCreateObjectActionObject::removeRedefinedElement(QObject *redefinedElement)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeRedefinedElement(qmodelingelementproperty_cast<QUmlRedefinableElement *>(redefinedElement));
}

void QUmlCreateObjectActionObject::addRedefinitionContext(QObject *redefinitionContext)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addRedefinitionContext(qmodelingelementproperty_cast<QUmlClassifier *>(redefinitionContext));
}

void QUmlCreateObjectActionObject::removeRedefinitionContext(QObject *redefinitionContext)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeRedefinitionContext(qmodelingelementproperty_cast<QUmlClassifier *>(redefinitionContext));
}

// SLOTS FOR OWNED ATTRIBUTES [ActivityNode]

void QUmlCreateObjectActionObject::setActivity(QObject *activity)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setActivity(qmodelingelementproperty_cast<QUmlActivity *>(activity));
}

void QUmlCreateObjectActionObject::addInGroup(QObject *inGroup)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addInGroup(qmodelingelementproperty_cast<QUmlActivityGroup *>(inGroup));
}

void QUmlCreateObjectActionObject::removeInGroup(QObject *inGroup)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeInGroup(qmodelingelementproperty_cast<QUmlActivityGroup *>(inGroup));
}

void QUmlCreateObjectActionObject::addInInterruptibleRegion(QObject *inInterruptibleRegion)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addInInterruptibleRegion(qmodelingelementproperty_cast<QUmlInterruptibleActivityRegion *>(inInterruptibleRegion));
}

void QUmlCreateObjectActionObject::removeInInterruptibleRegion(QObject *inInterruptibleRegion)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeInInterruptibleRegion(qmodelingelementproperty_cast<QUmlInterruptibleActivityRegion *>(inInterruptibleRegion));
}

void QUmlCreateObjectActionObject::addInPartition(QObject *inPartition)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addInPartition(qmodelingelementproperty_cast<QUmlActivityPartition *>(inPartition));
}

void QUmlCreateObjectActionObject::removeInPartition(QObject *inPartition)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeInPartition(qmodelingelementproperty_cast<QUmlActivityPartition *>(inPartition));
}

void QUmlCreateObjectActionObject::setInStructuredNode(QObject *inStructuredNode)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setInStructuredNode(qmodelingelementproperty_cast<QUmlStructuredActivityNode *>(inStructuredNode));
}

void QUmlCreateObjectActionObject::addIncoming(QObject *incoming)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addIncoming(qmodelingelementproperty_cast<QUmlActivityEdge *>(incoming));
}

void QUmlCreateObjectActionObject::removeIncoming(QObject *incoming)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeIncoming(qmodelingelementproperty_cast<QUmlActivityEdge *>(incoming));
}

void QUmlCreateObjectActionObject::addOutgoing(QObject *outgoing)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addOutgoing(qmodelingelementproperty_cast<QUmlActivityEdge *>(outgoing));
}

void QUmlCreateObjectActionObject::removeOutgoing(QObject *outgoing)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeOutgoing(qmodelingelementproperty_cast<QUmlActivityEdge *>(outgoing));
}

void QUmlCreateObjectActionObject::addRedefinedNode(QObject *redefinedNode)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addRedefinedNode(qmodelingelementproperty_cast<QUmlActivityNode *>(redefinedNode));
}

void QUmlCreateObjectActionObject::removeRedefinedNode(QObject *redefinedNode)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeRedefinedNode(qmodelingelementproperty_cast<QUmlActivityNode *>(redefinedNode));
}

// SLOTS FOR OWNED ATTRIBUTES [ExecutableNode]

void QUmlCreateObjectActionObject::addHandler(QObject *handler)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addHandler(qmodelingelementproperty_cast<QUmlExceptionHandler *>(handler));
}

void QUmlCreateObjectActionObject::removeHandler(QObject *handler)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeHandler(qmodelingelementproperty_cast<QUmlExceptionHandler *>(handler));
}

// SLOTS FOR OWNED ATTRIBUTES [Action]

void QUmlCreateObjectActionObject::setContext(QObject *context)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setContext(qmodelingelementproperty_cast<QUmlClassifier *>(context));
}

void QUmlCreateObjectActionObject::addInput(QObject *input)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addInput(qmodelingelementproperty_cast<QUmlInputPin *>(input));
}

void QUmlCreateObjectActionObject::removeInput(QObject *input)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeInput(qmodelingelementproperty_cast<QUmlInputPin *>(input));
}

void QUmlCreateObjectActionObject::setLocallyReentrant(bool isLocallyReentrant)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setLocallyReentrant(isLocallyReentrant);
}

void QUmlCreateObjectActionObject::unsetLocallyReentrant()
{
    Q_D(QModelingObject);
    d->modifiedResettableProperties.removeAll(QStringLiteral("locallyReentrant"));
}

void QUmlCreateObjectActionObject::addLocalPostcondition(QObject *localPostcondition)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addLocalPostcondition(qmodelingelementproperty_cast<QUmlConstraint *>(localPostcondition));
}

void QUmlCreateObjectActionObject::removeLocalPostcondition(QObject *localPostcondition)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeLocalPostcondition(qmodelingelementproperty_cast<QUmlConstraint *>(localPostcondition));
}

void QUmlCreateObjectActionObject::addLocalPrecondition(QObject *localPrecondition)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addLocalPrecondition(qmodelingelementproperty_cast<QUmlConstraint *>(localPrecondition));
}

void QUmlCreateObjectActionObject::removeLocalPrecondition(QObject *localPrecondition)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeLocalPrecondition(qmodelingelementproperty_cast<QUmlConstraint *>(localPrecondition));
}

void QUmlCreateObjectActionObject::addOutput(QObject *output)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->addOutput(qmodelingelementproperty_cast<QUmlOutputPin *>(output));
}

void QUmlCreateObjectActionObject::removeOutput(QObject *output)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->removeOutput(qmodelingelementproperty_cast<QUmlOutputPin *>(output));
}

// SLOTS FOR OWNED ATTRIBUTES [CreateObjectAction]

void QUmlCreateObjectActionObject::setClassifier(QObject *classifier)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setClassifier(qmodelingelementproperty_cast<QUmlClassifier *>(classifier));
}

void QUmlCreateObjectActionObject::setResult(QObject *result)
{
    qmodelingelementproperty_cast<QUmlCreateObjectAction *>(this)->setResult(qmodelingelementproperty_cast<QUmlOutputPin *>(result));
}


void QUmlCreateObjectActionObject::setGroupProperties()
{
    Q_D(QModelingObject);
    const QMetaObject *metaObject = this->metaObject();

    d->propertyGroups << QStringLiteral("QObject");
    d->groupProperties.insert(QStringLiteral("QObject"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("objectName"))));

    d->propertyGroups << QStringLiteral("QUmlElement");
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));

    d->propertyGroups << QStringLiteral("QUmlNamedElement");
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clientDependencies"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("name"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nameExpression"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("namespace_"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiedName"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));

    d->propertyGroups << QStringLiteral("QUmlRedefinableElement");
    d->groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isLeaf"))));
    d->groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinedElements"))));
    d->groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinitionContexts"))));

    d->propertyGroups << QStringLiteral("QUmlActivityNode");
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("activity"))));
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("inGroups"))));
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("inInterruptibleRegions"))));
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("inPartitions"))));
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("inStructuredNode"))));
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("incomings"))));
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("outgoings"))));
    d->groupProperties.insert(QStringLiteral("QUmlActivityNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinedNodes"))));

    d->propertyGroups << QStringLiteral("QUmlExecutableNode");
    d->groupProperties.insert(QStringLiteral("QUmlExecutableNode"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("handlers"))));

    d->propertyGroups << QStringLiteral("QUmlAction");
    d->groupProperties.insert(QStringLiteral("QUmlAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("context"))));
    d->groupProperties.insert(QStringLiteral("QUmlAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("inputs"))));
    d->groupProperties.insert(QStringLiteral("QUmlAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isLocallyReentrant"))));
    d->groupProperties.insert(QStringLiteral("QUmlAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("localPostconditions"))));
    d->groupProperties.insert(QStringLiteral("QUmlAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("localPreconditions"))));
    d->groupProperties.insert(QStringLiteral("QUmlAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("outputs"))));

    d->propertyGroups << QStringLiteral("QUmlCreateObjectAction");
    d->groupProperties.insert(QStringLiteral("QUmlCreateObjectAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("classifier"))));
    d->groupProperties.insert(QStringLiteral("QUmlCreateObjectAction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("result"))));
}

void QUmlCreateObjectActionObject::setPropertyData()
{
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, PropertyClassRole, QStringLiteral("QUmlCreateObjectAction"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, DocumentationRole, QStringLiteral("Classifier to be instantiated."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, SubsettedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, classifier, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, AggregationRole, QStringLiteral("composite"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, PropertyClassRole, QStringLiteral("QUmlCreateObjectAction"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, DocumentationRole, QStringLiteral("Gives the output pin on which the result is put."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, SubsettedPropertiesRole, QStringLiteral("Action-output"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlCreateObjectAction, result, OppositeEndRole, QStringLiteral(""));

}

QT_END_NAMESPACE

