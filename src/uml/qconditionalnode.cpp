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

#include "qconditionalnode.h"
#include "qconditionalnode_p.h"

#include <QtUml/QClause>
#include <QtUml/QOutputPin>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

namespace QtUml
{

QConditionalNodePrivate::QConditionalNodePrivate() :
    isAssured(false),
    isDeterminate(false)
{
}

QConditionalNodePrivate::~QConditionalNodePrivate()
{
}

/*!
    \class QConditionalNode

    \inmodule QtUml

    \brief A conditional node is a structured activity node that represents an exclusive choice among some number of alternatives.
 */

QConditionalNode::QConditionalNode(QWrappedObject *wrapper, QWrappedObject *parent) :
    QStructuredActivityNode(*new QConditionalNodePrivate, wrapper, parent)
{
    setPropertyData();
}

QConditionalNode::QConditionalNode(QConditionalNodePrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QStructuredActivityNode(dd, wrapper, parent)
{
    setPropertyData();
}

QConditionalNode::~QConditionalNode()
{
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM QConditionalNode
// ---------------------------------------------------------------

/*!
    If true, the modeler asserts that at least one test will succeed.
 */
bool QConditionalNode::isAssured() const
{
    // This is a read-write attribute

    Q_D(const QConditionalNode);
    return d->isAssured;
}

void QConditionalNode::setAssured(bool isAssured)
{
    // This is a read-write attribute

    Q_D(QConditionalNode);
    if (d->isAssured != isAssured) {
        d->isAssured = isAssured;
    }
    d->modifiedResettableProperties << QString::fromLatin1("isAssured");
}

void QConditionalNode::unsetAssured()
{
    setAssured(false);
    Q_D(QConditionalNode);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("isAssured"));
}

/*!
    If true, the modeler asserts that at most one test will succeed.
 */
bool QConditionalNode::isDeterminate() const
{
    // This is a read-write attribute

    Q_D(const QConditionalNode);
    return d->isDeterminate;
}

void QConditionalNode::setDeterminate(bool isDeterminate)
{
    // This is a read-write attribute

    Q_D(QConditionalNode);
    if (d->isDeterminate != isDeterminate) {
        d->isDeterminate = isDeterminate;
    }
    d->modifiedResettableProperties << QString::fromLatin1("isDeterminate");
}

void QConditionalNode::unsetDeterminate()
{
    setDeterminate(false);
    Q_D(QConditionalNode);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("isDeterminate"));
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QConditionalNode
// ---------------------------------------------------------------

/*!
    Set of clauses composing the conditional.
 */
QSet<QClause *> QConditionalNode::clauses() const
{
    // This is a read-write association end

    Q_D(const QConditionalNode);
    return d->clauses;
}

void QConditionalNode::addClause(QClause *clause)
{
    // This is a read-write association end

    Q_D(QConditionalNode);
    if (!d->clauses.contains(clause)) {
        d->clauses.insert(clause);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->addOwnedElement(qwrappedobject_cast<QElement *>(clause));
    }
}

void QConditionalNode::removeClause(QClause *clause)
{
    // This is a read-write association end

    Q_D(QConditionalNode);
    if (d->clauses.contains(clause)) {
        d->clauses.remove(clause);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QElementPrivate *>(d))->removeOwnedElement(qwrappedobject_cast<QElement *>(clause));
    }
}

/*!
    A list of output pins that constitute the data flow outputs of the conditional.
 */
QList<QOutputPin *> QConditionalNode::results() const
{
    // This is a read-write association end

    Q_D(const QConditionalNode);
    return d->results;
}

void QConditionalNode::addResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QConditionalNode);
    if (!d->results.contains(result)) {
        d->results.append(result);
        qTopLevelWrapper(result)->setParent(qTopLevelWrapper(this));

        // Adjust redefined property(ies)
        (qwrappedobject_cast<QStructuredActivityNode *>(this))->addStructuredNodeOutput(qwrappedobject_cast<QOutputPin *>(result));
    }
}

void QConditionalNode::removeResult(QOutputPin *result)
{
    // This is a read-write association end

    Q_D(QConditionalNode);
    if (d->results.contains(result)) {
        d->results.removeAll(result);
        qTopLevelWrapper(result)->setParent(0);

        // Adjust redefined property(ies)
        (qwrappedobject_cast<QStructuredActivityNode *>(this))->removeStructuredNodeOutput(qwrappedobject_cast<QOutputPin *>(result));
    }
}

void QConditionalNode::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isAssured")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isAssured")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isAssured")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("If true, the modeler asserts that at least one test will succeed.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isAssured")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isAssured")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isAssured")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isDeterminate")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isDeterminate")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isDeterminate")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("If true, the modeler asserts that at most one test will succeed.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isDeterminate")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isDeterminate")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("isDeterminate")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("clauses")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("clauses")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("clauses")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("Set of clauses composing the conditional.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("clauses")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("clauses")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QElement::ownedElements");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("clauses")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("results")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("results")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("results")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("A list of output pins that constitute the data flow outputs of the conditional.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("results")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("QStructuredActivityNode::structuredNodeOutputs");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("results")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QConditionalNode")][QString::fromLatin1("results")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QStructuredActivityNode::setPropertyData();
}

}

QT_END_NAMESPACE

#include "moc_qconditionalnode.cpp"

