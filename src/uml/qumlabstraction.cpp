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
#include "qumlabstraction.h"

#include "private/qumlabstractionobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOpaqueExpression>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>

/*!
    \class QUmlAbstraction

    \inmodule QtUml

    \brief An abstraction is a relationship that relates two elements or sets of elements that represent the same concept at different levels of abstraction or from different viewpoints.
 */
QUmlAbstraction::QUmlAbstraction(bool createQObject) :
    QUmlDependency(false),
    _mapping(0)
{
    if (createQObject)
        _qObject = new QUmlAbstractionObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlAbstraction::~QUmlAbstraction()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlAbstraction::clone() const
{
    QUmlAbstraction *c = new QUmlAbstraction;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    if (owningTemplateParameter())
        c->setOwningTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(owningTemplateParameter()->clone()));
    if (templateParameter())
        c->setTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(templateParameter()->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlNamedElement *element, clients())
        c->addClient(dynamic_cast<QUmlNamedElement *>(element->clone()));
    foreach (QUmlNamedElement *element, suppliers())
        c->addSupplier(dynamic_cast<QUmlNamedElement *>(element->clone()));
    if (mapping())
        c->setMapping(dynamic_cast<QUmlOpaqueExpression *>(mapping()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    An composition of an Expression that states the abstraction relationship between the supplier and the client. In some cases, such as Derivation, it is usually formal and unidirectional; in other cases, such as Trace, it is usually informal and bidirectional. The mapping expression is optional and may be omitted if the precise relationship between the elements is not specified.
 */
QUmlOpaqueExpression *QUmlAbstraction::mapping() const
{
    // This is a read-write association end

    return _mapping;
}

void QUmlAbstraction::setMapping(QUmlOpaqueExpression *mapping)
{
    // This is a read-write association end

    if (_mapping != mapping) {
        // Adjust subsetted properties
        removeOwnedElement(_mapping);

        _mapping = mapping;
        if (mapping && mapping->asQObject() && this->asQObject())
            QObject::connect(mapping->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setMapping()));
        mapping->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (mapping) {
            addOwnedElement(mapping);
        }
    }
}

void QUmlAbstraction::setGroupProperties()
{
    const QMetaObject *metaObject = _qObject->metaObject();

    _propertyGroups << QStringLiteral("QObject");
    _groupProperties.insert(QStringLiteral("QObject"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("objectName"))));

    _propertyGroups << QStringLiteral("QUmlElement");
    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));

    _propertyGroups << QStringLiteral("QUmlParameterableElement");
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owningTemplateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateParameter"))));

    _propertyGroups << QStringLiteral("QUmlNamedElement");
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clientDependencies"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("name"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nameExpression"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("namespace_"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiedName"))));

    _propertyGroups << QStringLiteral("QUmlPackageableElement");
    _groupProperties.insert(QStringLiteral("QUmlPackageableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));

    _propertyGroups << QStringLiteral("QUmlRelationship");
    _groupProperties.insert(QStringLiteral("QUmlRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("relatedElements"))));

    _propertyGroups << QStringLiteral("QUmlDirectedRelationship");
    _groupProperties.insert(QStringLiteral("QUmlDirectedRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("sources"))));
    _groupProperties.insert(QStringLiteral("QUmlDirectedRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("targets"))));

    _propertyGroups << QStringLiteral("QUmlDependency");
    _groupProperties.insert(QStringLiteral("QUmlDependency"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clients"))));
    _groupProperties.insert(QStringLiteral("QUmlDependency"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("suppliers"))));

    _propertyGroups << QStringLiteral("QUmlAbstraction");
    _groupProperties.insert(QStringLiteral("QUmlAbstraction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("mapping"))));
}

void QUmlAbstraction::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlAbstraction");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::DocumentationRole] = QStringLiteral("An composition of an Expression that states the abstraction relationship between the supplier and the client. In some cases, such as Derivation, it is usually formal and unidirectional; in other cases, such as Trace, it is usually informal and bidirectional. The mapping expression is optional and may be omitted if the precise relationship between the elements is not specified.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlAbstraction")][QStringLiteral("mapping")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

