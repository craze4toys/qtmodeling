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
#include "qumlelement.h"

#include <QtUml/QUmlComment>

/*!
    \class QUmlElement

    \inmodule QtUml

    \brief An element is a constituent of a model. As such, it has the capability of owning other elements.
 */
QUmlElement::QUmlElement() :
    _owner(0)
{
    setClassForProperty();
    setPropertyData();
}

QUmlElement::~QUmlElement()
{
}

QModelingObject *QUmlElement::clone() const
{
    QUmlElement *c = new QUmlElement;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The Comments owned by this element.
 */
const QSet<QUmlComment *> QUmlElement::ownedComments() const
{
    // This is a read-write association end

    return _ownedComments;
}

void QUmlElement::addOwnedComment(QUmlComment *ownedComment)
{
    // This is a read-write association end

    if (!_ownedComments.contains(ownedComment)) {
        _ownedComments.insert(ownedComment);
        if (ownedComment && ownedComment->asQObject() && this->asQObject())
            QObject::connect(ownedComment->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeOwnedComment(QObject *)));
        ownedComment->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addOwnedElement(ownedComment);
    }
}

void QUmlElement::removeOwnedComment(QUmlComment *ownedComment)
{
    // This is a read-write association end

    if (_ownedComments.contains(ownedComment)) {
        _ownedComments.remove(ownedComment);
        if (ownedComment->asQObject())
            ownedComment->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(ownedComment);
    }
}

/*!
    The Elements owned by this element.
 */
const QSet<QUmlElement *> QUmlElement::ownedElements() const
{
    // This is a read-only derived union association end

    return _ownedElements;
}

void QUmlElement::addOwnedElement(QUmlElement *ownedElement)
{
    // This is a read-only derived union association end

    if (!_ownedElements.contains(ownedElement)) {
        _ownedElements.insert(ownedElement);
        if (ownedElement && ownedElement->asQObject() && this->asQObject())
            QObject::connect(ownedElement->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeOwnedElement(QObject *)));
        ownedElement->asQObject()->setParent(this->asQObject());
    }
}

void QUmlElement::removeOwnedElement(QUmlElement *ownedElement)
{
    // This is a read-only derived union association end

    if (_ownedElements.contains(ownedElement)) {
        _ownedElements.remove(ownedElement);
        if (ownedElement->asQObject())
            ownedElement->asQObject()->setParent(0);
    }
}

/*!
    The Element that owns this element.
 */
QUmlElement *QUmlElement::owner() const
{
    // This is a read-only derived union association end

    return _owner;
}

void QUmlElement::setOwner(QUmlElement *owner)
{
    // This is a read-only derived union association end

    if (_owner != owner) {
        _owner = owner;
        if (owner && owner->asQObject() && this->asQObject())
            QObject::connect(owner->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setOwner()));
    }
}

// OPERATIONS

/*!
    The query allOwnedElements() gives all of the direct and indirect owned elements of an element.
 */
QSet<QUmlElement *> QUmlElement::allOwnedElements() const
{
    QSet<QUmlElement *> allOwnedElements_;
    allOwnedElements(allOwnedElements_);
    return allOwnedElements_;
}

/*!
    The query mustBeOwned() indicates whether elements of this type must have an owner. Subclasses of Element that do not require an owner must override this operation.
 */
bool QUmlElement::mustBeOwned() const
{
    return true;
}

void QUmlElement::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::DocumentationRole] = QStringLiteral("The Comments owned by this element.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedComments")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::IsDerivedUnionRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::DocumentationRole] = QStringLiteral("The Elements owned by this element.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("ownedElements")][QtModeling::OppositeEndRole] = QStringLiteral("Element-owner");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::IsDerivedUnionRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::DocumentationRole] = QStringLiteral("The Element that owns this element.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlElement")][QStringLiteral("owner")][QtModeling::OppositeEndRole] = QStringLiteral("Element-ownedElement");

}

void QUmlElement::setClassForProperty()
{
    _classForProperty[QStringLiteral("ownedComments")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("ownedElements")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("owner")] = QStringLiteral("QUmlElement");
}

void QUmlElement::allOwnedElements(QSet<QUmlElement *> &allOwnedElements_) const
{
    allOwnedElements_.unite(_ownedElements);
    foreach (QUmlElement *element, _ownedElements)
        element->allOwnedElements(allOwnedElements_);
}

