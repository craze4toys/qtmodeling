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
#include "qumlcomponentrealization.h"

#include "private/qumlcomponentrealizationobject_p.h"

#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlComponent>
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
    \class QUmlComponentRealization

    \inmodule QtUml

    \brief The realization concept is specialized to (optionally) define the classifiers that realize the contract offered by a component in terms of its provided and required interfaces. The component forms an abstraction from these various classifiers.
 */
QUmlComponentRealization::QUmlComponentRealization(bool createQObject) :
    QUmlRealization(false),
    _abstraction(0)
{
    if (createQObject)
        _qObject = new QUmlComponentRealizationObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlComponentRealization::~QUmlComponentRealization()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlComponentRealization::clone() const
{
    QUmlComponentRealization *c = new QUmlComponentRealization;
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
    if (abstraction())
        c->setAbstraction(dynamic_cast<QUmlComponent *>(abstraction()->clone()));
    foreach (QUmlClassifier *element, realizingClassifiers())
        c->addRealizingClassifier(dynamic_cast<QUmlClassifier *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The Component that owns this ComponentRealization and which is implemented by its realizing classifiers.
 */
QUmlComponent *QUmlComponentRealization::abstraction() const
{
    // This is a read-write association end

    return _abstraction;
}

void QUmlComponentRealization::setAbstraction(QUmlComponent *abstraction)
{
    // This is a read-write association end

    if (_abstraction != abstraction) {
        // Adjust subsetted properties
        removeSupplier(_abstraction);

        _abstraction = abstraction;
        if (abstraction && abstraction->asQObject() && this->asQObject())
            QObject::connect(abstraction->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setAbstraction()));

        // Adjust subsetted properties
        if (abstraction) {
            addSupplier(abstraction);
        }
        setOwner(abstraction);
    }
}

/*!
    The classifiers that are involved in the implementation of the Component that owns this Realization.
 */
const QSet<QUmlClassifier *> QUmlComponentRealization::realizingClassifiers() const
{
    // This is a read-write association end

    return _realizingClassifiers;
}

void QUmlComponentRealization::addRealizingClassifier(QUmlClassifier *realizingClassifier)
{
    // This is a read-write association end

    if (!_realizingClassifiers.contains(realizingClassifier)) {
        _realizingClassifiers.insert(realizingClassifier);
        if (realizingClassifier && realizingClassifier->asQObject() && this->asQObject())
            QObject::connect(realizingClassifier->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRealizingClassifier(QObject *)));

        // Adjust subsetted properties
        addClient(realizingClassifier);
    }
}

void QUmlComponentRealization::removeRealizingClassifier(QUmlClassifier *realizingClassifier)
{
    // This is a read-write association end

    if (_realizingClassifiers.contains(realizingClassifier)) {
        _realizingClassifiers.remove(realizingClassifier);

        // Adjust subsetted properties
        removeClient(realizingClassifier);
    }
}

void QUmlComponentRealization::setGroupProperties()
{
    const QMetaObject *metaObject = _qObject->metaObject();

    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owningTemplateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clientDependencies"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("name"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nameExpression"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("namespace_"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiedName"))));
    _groupProperties.insert(QStringLiteral("QUmlPackageableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));
    _groupProperties.insert(QStringLiteral("QUmlRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("relatedElements"))));
    _groupProperties.insert(QStringLiteral("QUmlDirectedRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("sources"))));
    _groupProperties.insert(QStringLiteral("QUmlDirectedRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("targets"))));
    _groupProperties.insert(QStringLiteral("QUmlDependency"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clients"))));
    _groupProperties.insert(QStringLiteral("QUmlDependency"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("suppliers"))));
    _groupProperties.insert(QStringLiteral("QUmlAbstraction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("mapping"))));
    _groupProperties.insert(QStringLiteral("QUmlComponentRealization"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("abstraction"))));
    _groupProperties.insert(QStringLiteral("QUmlComponentRealization"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("realizingClassifiers"))));
}

void QUmlComponentRealization::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlComponentRealization");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::DocumentationRole] = QStringLiteral("The Component that owns this ComponentRealization and which is implemented by its realizing classifiers.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Dependency-supplier Element-owner");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("abstraction")][QtModeling::OppositeEndRole] = QStringLiteral("Component-realization");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlComponentRealization");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::DocumentationRole] = QStringLiteral("The classifiers that are involved in the implementation of the Component that owns this Realization.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Dependency-client");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlComponentRealization")][QStringLiteral("realizingClassifiers")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

