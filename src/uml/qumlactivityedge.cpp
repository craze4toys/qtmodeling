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
#include "qumlactivityedge.h"

#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>
#include <QtUml/QUmlValueSpecification>

/*!
    \class QUmlActivityEdge

    \inmodule QtUml

    \brief Activity edges can be contained in interruptible regions.An activity edge is an abstract class for directed connections between two activity nodes.
 */
QUmlActivityEdge::QUmlActivityEdge() :
    _activity(0),
    _guard(0),
    _inStructuredNode(0),
    _interrupts(0),
    _source(0),
    _target(0),
    _weight(0)
{
    setClassForProperty();
    setPropertyData();
}

QUmlActivityEdge::~QUmlActivityEdge()
{
}

QModelingObject *QUmlActivityEdge::clone() const
{
    QUmlActivityEdge *c = new QUmlActivityEdge;
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
    if (guard())
        c->setGuard(dynamic_cast<QUmlValueSpecification *>(guard()->clone()));
    foreach (QUmlActivityPartition *element, inPartitions())
        c->addInPartition(dynamic_cast<QUmlActivityPartition *>(element->clone()));
    if (inStructuredNode())
        c->setInStructuredNode(dynamic_cast<QUmlStructuredActivityNode *>(inStructuredNode()->clone()));
    if (interrupts())
        c->setInterrupts(dynamic_cast<QUmlInterruptibleActivityRegion *>(interrupts()->clone()));
    foreach (QUmlActivityEdge *element, redefinedEdges())
        c->addRedefinedEdge(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    if (source())
        c->setSource(dynamic_cast<QUmlActivityNode *>(source()->clone()));
    if (target())
        c->setTarget(dynamic_cast<QUmlActivityNode *>(target()->clone()));
    if (weight())
        c->setWeight(dynamic_cast<QUmlValueSpecification *>(weight()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Activity containing the edge.
 */
QUmlActivity *QUmlActivityEdge::activity() const
{
    // This is a read-write association end

    return _activity;
}

void QUmlActivityEdge::setActivity(QUmlActivity *activity)
{
    // This is a read-write association end

    if (_activity != activity) {
        // Adjust subsetted properties

        _activity = activity;
        if (activity && activity->asQObject() && this->asQObject())
            QObject::connect(activity->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setActivity()));

        // Adjust subsetted properties
        setOwner(activity);
    }
}

/*!
    Specification evaluated at runtime to determine if the edge can be traversed.
 */
QUmlValueSpecification *QUmlActivityEdge::guard() const
{
    // This is a read-write association end

    return _guard;
}

void QUmlActivityEdge::setGuard(QUmlValueSpecification *guard)
{
    // This is a read-write association end

    if (_guard != guard) {
        // Adjust subsetted properties
        removeOwnedElement(_guard);

        _guard = guard;
        if (guard && guard->asQObject() && this->asQObject())
            QObject::connect(guard->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setGuard()));
        guard->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (guard) {
            addOwnedElement(guard);
        }
    }
}

/*!
    Groups containing the edge.
 */
const QSet<QUmlActivityGroup *> QUmlActivityEdge::inGroups() const
{
    // This is a read-only derived union association end

    return _inGroups;
}

void QUmlActivityEdge::addInGroup(QUmlActivityGroup *inGroup)
{
    // This is a read-only derived union association end

    if (!_inGroups.contains(inGroup)) {
        _inGroups.insert(inGroup);
        if (inGroup && inGroup->asQObject() && this->asQObject())
            QObject::connect(inGroup->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeInGroup(QObject *)));

        // Adjust opposite properties
        if (inGroup) {
            inGroup->addContainedEdge(this);
        }
    }
}

void QUmlActivityEdge::removeInGroup(QUmlActivityGroup *inGroup)
{
    // This is a read-only derived union association end

    if (_inGroups.contains(inGroup)) {
        _inGroups.remove(inGroup);

        // Adjust opposite properties
        if (inGroup) {
            inGroup->removeContainedEdge(this);
        }
    }
}

/*!
    Partitions containing the edge.
 */
const QSet<QUmlActivityPartition *> QUmlActivityEdge::inPartitions() const
{
    // This is a read-write association end

    return _inPartitions;
}

void QUmlActivityEdge::addInPartition(QUmlActivityPartition *inPartition)
{
    // This is a read-write association end

    if (!_inPartitions.contains(inPartition)) {
        _inPartitions.insert(inPartition);
        if (inPartition && inPartition->asQObject() && this->asQObject())
            QObject::connect(inPartition->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeInPartition(QObject *)));

        // Adjust subsetted properties
        addInGroup(inPartition);

        // Adjust opposite properties
        if (inPartition) {
            inPartition->addEdge(this);
        }
    }
}

void QUmlActivityEdge::removeInPartition(QUmlActivityPartition *inPartition)
{
    // This is a read-write association end

    if (_inPartitions.contains(inPartition)) {
        _inPartitions.remove(inPartition);

        // Adjust subsetted properties
        removeInGroup(inPartition);

        // Adjust opposite properties
        if (inPartition) {
            inPartition->removeEdge(this);
        }
    }
}

/*!
    Structured activity node containing the edge.
 */
QUmlStructuredActivityNode *QUmlActivityEdge::inStructuredNode() const
{
    // This is a read-write association end

    return _inStructuredNode;
}

void QUmlActivityEdge::setInStructuredNode(QUmlStructuredActivityNode *inStructuredNode)
{
    // This is a read-write association end

    if (_inStructuredNode != inStructuredNode) {
        // Adjust subsetted properties
        removeInGroup(_inStructuredNode);

        _inStructuredNode = inStructuredNode;
        if (inStructuredNode && inStructuredNode->asQObject() && this->asQObject())
            QObject::connect(inStructuredNode->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setInStructuredNode()));

        // Adjust subsetted properties
        if (inStructuredNode) {
            addInGroup(inStructuredNode);
        }
        setOwner(inStructuredNode);
    }
}

/*!
    Region that the edge can interrupt.
 */
QUmlInterruptibleActivityRegion *QUmlActivityEdge::interrupts() const
{
    // This is a read-write association end

    return _interrupts;
}

void QUmlActivityEdge::setInterrupts(QUmlInterruptibleActivityRegion *interrupts)
{
    // This is a read-write association end

    if (_interrupts != interrupts) {
        _interrupts = interrupts;
        if (interrupts && interrupts->asQObject() && this->asQObject())
            QObject::connect(interrupts->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setInterrupts()));
    }
}

/*!
    Inherited edges replaced by this edge in a specialization of the activity.
 */
const QSet<QUmlActivityEdge *> QUmlActivityEdge::redefinedEdges() const
{
    // This is a read-write association end

    return _redefinedEdges;
}

void QUmlActivityEdge::addRedefinedEdge(QUmlActivityEdge *redefinedEdge)
{
    // This is a read-write association end

    if (!_redefinedEdges.contains(redefinedEdge)) {
        _redefinedEdges.insert(redefinedEdge);
        if (redefinedEdge && redefinedEdge->asQObject() && this->asQObject())
            QObject::connect(redefinedEdge->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRedefinedEdge(QObject *)));

        // Adjust subsetted properties
        addRedefinedElement(redefinedEdge);
    }
}

void QUmlActivityEdge::removeRedefinedEdge(QUmlActivityEdge *redefinedEdge)
{
    // This is a read-write association end

    if (_redefinedEdges.contains(redefinedEdge)) {
        _redefinedEdges.remove(redefinedEdge);

        // Adjust subsetted properties
        removeRedefinedElement(redefinedEdge);
    }
}

/*!
    Node from which tokens are taken when they traverse the edge.
 */
QUmlActivityNode *QUmlActivityEdge::source() const
{
    // This is a read-write association end

    return _source;
}

void QUmlActivityEdge::setSource(QUmlActivityNode *source)
{
    // This is a read-write association end

    if (_source != source) {
        _source = source;
        if (source && source->asQObject() && this->asQObject())
            QObject::connect(source->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setSource()));
    }
}

/*!
    Node to which tokens are put when they traverse the edge.
 */
QUmlActivityNode *QUmlActivityEdge::target() const
{
    // This is a read-write association end

    return _target;
}

void QUmlActivityEdge::setTarget(QUmlActivityNode *target)
{
    // This is a read-write association end

    if (_target != target) {
        _target = target;
        if (target && target->asQObject() && this->asQObject())
            QObject::connect(target->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setTarget()));
    }
}

/*!
    The minimum number of tokens that must traverse the edge at the same time.
 */
QUmlValueSpecification *QUmlActivityEdge::weight() const
{
    // This is a read-write association end

    return _weight;
}

void QUmlActivityEdge::setWeight(QUmlValueSpecification *weight)
{
    // This is a read-write association end

    if (_weight != weight) {
        // Adjust subsetted properties
        removeOwnedElement(_weight);

        _weight = weight;
        if (weight && weight->asQObject() && this->asQObject())
            QObject::connect(weight->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setWeight()));
        weight->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (weight) {
            addOwnedElement(weight);
        }
    }
}

void QUmlActivityEdge::setClassForProperty()
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
    _classForProperty[QStringLiteral("activity")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("guard")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("inGroups")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("inPartitions")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("inStructuredNode")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("interrupts")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("redefinedEdges")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("source")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("target")] = QStringLiteral("QUmlActivityEdge");
    _classForProperty[QStringLiteral("weight")] = QStringLiteral("QUmlActivityEdge");
}

void QUmlActivityEdge::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::DocumentationRole] = QStringLiteral("Activity containing the edge.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-owner");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("activity")][QtModeling::OppositeEndRole] = QStringLiteral("Activity-edge");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::DocumentationRole] = QStringLiteral("Specification evaluated at runtime to determine if the edge can be traversed.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("guard")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::IsDerivedUnionRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::DocumentationRole] = QStringLiteral("Groups containing the edge.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inGroups")][QtModeling::OppositeEndRole] = QStringLiteral("ActivityGroup-containedEdge");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::DocumentationRole] = QStringLiteral("Partitions containing the edge.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("ActivityEdge-inGroup");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inPartitions")][QtModeling::OppositeEndRole] = QStringLiteral("ActivityPartition-edge");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::DocumentationRole] = QStringLiteral("Structured activity node containing the edge.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("ActivityEdge-inGroup Element-owner");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("inStructuredNode")][QtModeling::OppositeEndRole] = QStringLiteral("StructuredActivityNode-edge");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::DocumentationRole] = QStringLiteral("Region that the edge can interrupt.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("interrupts")][QtModeling::OppositeEndRole] = QStringLiteral("InterruptibleActivityRegion-interruptingEdge");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::DocumentationRole] = QStringLiteral("Inherited edges replaced by this edge in a specialization of the activity.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("RedefinableElement-redefinedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("redefinedEdges")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::DocumentationRole] = QStringLiteral("Node from which tokens are taken when they traverse the edge.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("source")][QtModeling::OppositeEndRole] = QStringLiteral("ActivityNode-outgoing");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::DocumentationRole] = QStringLiteral("Node to which tokens are put when they traverse the edge.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("target")][QtModeling::OppositeEndRole] = QStringLiteral("ActivityNode-incoming");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlActivityEdge");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::DocumentationRole] = QStringLiteral("The minimum number of tokens that must traverse the edge at the same time.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlActivityEdge")][QStringLiteral("weight")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

