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
#include "qumllinkenddestructiondataobject_p.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlLinkEndDestructionData>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlQualifierValue>

QT_BEGIN_NAMESPACE

QUmlLinkEndDestructionDataObject::QUmlLinkEndDestructionDataObject(QUmlLinkEndDestructionData *modelingElement)
{
    setProperty("modelingElement", QVariant::fromValue(static_cast<QModelingElement *>(modelingElement)));
    setGroupProperties();
    setPropertyData();
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlLinkEndDestructionDataObject::ownedComments() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->ownedComments())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlLinkEndDestructionDataObject::ownedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->ownedElements())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlLinkEndDestructionDataObject::owner() const
{
    if (!qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->owner())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->owner()->asQModelingObject();
}

// OWNED ATTRIBUTES [LinkEndData]

QObject *QUmlLinkEndDestructionDataObject::end() const
{
    if (!qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->end())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->end()->asQModelingObject();
}

const QSet<QObject *> QUmlLinkEndDestructionDataObject::qualifiers() const
{
    QSet<QObject *> set;
    foreach (QUmlQualifierValue *element, qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->qualifiers())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlLinkEndDestructionDataObject::value() const
{
    if (!qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->value())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->value()->asQModelingObject();
}

// OWNED ATTRIBUTES [LinkEndDestructionData]

QObject *QUmlLinkEndDestructionDataObject::destroyAt() const
{
    if (!qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->destroyAt())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->destroyAt()->asQModelingObject();
}

bool QUmlLinkEndDestructionDataObject::isDestroyDuplicates() const
{
    return qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->isDestroyDuplicates();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlLinkEndDestructionDataObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->allOwnedElements())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlLinkEndDestructionDataObject::mustBeOwned() const
{
    return qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->mustBeOwned();
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlLinkEndDestructionDataObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->addOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
    emit ownedCommentsChanged(this->ownedComments());
}

void QUmlLinkEndDestructionDataObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->removeOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
    emit ownedCommentsChanged(this->ownedComments());
}

void QUmlLinkEndDestructionDataObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->addOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
    emit ownedElementsChanged(this->ownedElements());
}

void QUmlLinkEndDestructionDataObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->removeOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
    emit ownedElementsChanged(this->ownedElements());
}

void QUmlLinkEndDestructionDataObject::setOwner(QObject *owner)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->setOwner(qmodelingelementproperty_cast<QUmlElement *>(owner));
    emit ownerChanged(this->owner());
}

// SLOTS FOR OWNED ATTRIBUTES [LinkEndData]

void QUmlLinkEndDestructionDataObject::setEnd(QObject *end)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->setEnd(qmodelingelementproperty_cast<QUmlProperty *>(end));
    emit endChanged(this->end());
}

void QUmlLinkEndDestructionDataObject::addQualifier(QObject *qualifier)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->addQualifier(qmodelingelementproperty_cast<QUmlQualifierValue *>(qualifier));
    emit qualifiersChanged(this->qualifiers());
}

void QUmlLinkEndDestructionDataObject::removeQualifier(QObject *qualifier)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->removeQualifier(qmodelingelementproperty_cast<QUmlQualifierValue *>(qualifier));
    emit qualifiersChanged(this->qualifiers());
}

void QUmlLinkEndDestructionDataObject::setValue(QObject *value)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->setValue(qmodelingelementproperty_cast<QUmlInputPin *>(value));
    emit valueChanged(this->value());
}

// SLOTS FOR OWNED ATTRIBUTES [LinkEndDestructionData]

void QUmlLinkEndDestructionDataObject::setDestroyAt(QObject *destroyAt)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->setDestroyAt(qmodelingelementproperty_cast<QUmlInputPin *>(destroyAt));
    emit destroyAtChanged(this->destroyAt());
}

void QUmlLinkEndDestructionDataObject::setDestroyDuplicates(bool isDestroyDuplicates)
{
    qmodelingelementproperty_cast<QUmlLinkEndDestructionData *>(this)->setDestroyDuplicates(isDestroyDuplicates);
    emit isDestroyDuplicatesChanged(this->isDestroyDuplicates());
}

void QUmlLinkEndDestructionDataObject::unsetDestroyDuplicates()
{
    Q_D(QModelingObject);
    setDestroyDuplicates(false);
    d->modifiedResettableProperties.removeAll(QStringLiteral("isDestroyDuplicates"));
}


void QUmlLinkEndDestructionDataObject::setGroupProperties()
{
    Q_D(QModelingObject);
    const QMetaObject *metaObject = this->metaObject();

    d->propertyGroups << QStringLiteral("QObject");
    d->groupProperties.insert(QStringLiteral("QObject"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("objectName"))));

    d->propertyGroups << QStringLiteral("QUmlElement");
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));

    d->propertyGroups << QStringLiteral("QUmlLinkEndData");
    d->groupProperties.insert(QStringLiteral("QUmlLinkEndData"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("end"))));
    d->groupProperties.insert(QStringLiteral("QUmlLinkEndData"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiers"))));
    d->groupProperties.insert(QStringLiteral("QUmlLinkEndData"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("value"))));

    d->propertyGroups << QStringLiteral("QUmlLinkEndDestructionData");
    d->groupProperties.insert(QStringLiteral("QUmlLinkEndDestructionData"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("destroyAt"))));
    d->groupProperties.insert(QStringLiteral("QUmlLinkEndDestructionData"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isDestroyDuplicates"))));
}

void QUmlLinkEndDestructionDataObject::setPropertyData()
{
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, AggregationRole, QStringLiteral("composite"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, PropertyClassRole, QStringLiteral("QUmlElement"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, PropertyTypeRole, QStringLiteral("QSet<QUmlComment *>"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, DocumentationRole, QStringLiteral("The Comments owned by this element."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, SubsettedPropertiesRole, QStringLiteral("Element-ownedElement"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedComments, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, AggregationRole, QStringLiteral("composite"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, PropertyClassRole, QStringLiteral("QUmlElement"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, PropertyTypeRole, QStringLiteral("QSet<QUmlElement *>"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, IsDerivedRole, true);
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, IsDerivedUnionRole, true);
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, DocumentationRole, QStringLiteral("The Elements owned by this element."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, SubsettedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, ownedElements, OppositeEndRole, QStringLiteral("Element-owner"));

    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, PropertyClassRole, QStringLiteral("QUmlElement"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, PropertyTypeRole, QStringLiteral("QUmlElement *"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, IsDerivedRole, true);
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, IsDerivedUnionRole, true);
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, DocumentationRole, QStringLiteral("The Element that owns this element."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, SubsettedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlElement, owner, OppositeEndRole, QStringLiteral("Element-ownedElement"));

    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, PropertyClassRole, QStringLiteral("QUmlLinkEndData"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, PropertyTypeRole, QStringLiteral("QUmlProperty *"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, DocumentationRole, QStringLiteral("Association end for which this link-end data specifies values."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, SubsettedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, end, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, AggregationRole, QStringLiteral("composite"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, PropertyClassRole, QStringLiteral("QUmlLinkEndData"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, PropertyTypeRole, QStringLiteral("QSet<QUmlQualifierValue *>"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, DocumentationRole, QStringLiteral("List of qualifier values"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, SubsettedPropertiesRole, QStringLiteral("Element-ownedElement"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, qualifiers, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, PropertyClassRole, QStringLiteral("QUmlLinkEndData"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, PropertyTypeRole, QStringLiteral("QUmlInputPin *"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, DocumentationRole, QStringLiteral("Input pin that provides the specified object for the given end. This pin is omitted if the link-end data specifies an 'open' end for reading."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, SubsettedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndData, value, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, PropertyClassRole, QStringLiteral("QUmlLinkEndDestructionData"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, PropertyTypeRole, QStringLiteral("QUmlInputPin *"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, DocumentationRole, QStringLiteral("Specifies the position of an existing link to be destroyed in ordered nonunique association ends. The type of the pin is UnlimitedNatural, but the value cannot be zero or unlimited."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, SubsettedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, destroyAt, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, PropertyClassRole, QStringLiteral("QUmlLinkEndDestructionData"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, PropertyTypeRole, QStringLiteral("bool"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, DocumentationRole, QStringLiteral("Specifies whether to destroy duplicates of the value in nonunique association ends."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, SubsettedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlLinkEndDestructionData, isDestroyDuplicates, OppositeEndRole, QStringLiteral(""));

}

QT_END_NAMESPACE

