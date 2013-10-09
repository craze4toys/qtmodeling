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
#include "qumlprofile.h"

#include "private/qumlprofileobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlPackageMerge>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlProfileApplication>
#include <QtUml/QUmlStereotype>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateBinding>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlTemplateSignature>
#include <QtUml/QUmlType>

/*!
    \class QUmlProfile

    \inmodule QtUml

    \brief A profile defines limited extensions to a reference metamodel with the purpose of adapting the metamodel to a specific platform or domain.
 */
QUmlProfile::QUmlProfile(bool createQObject) :
    QUmlPackage(false)
{
    if (createQObject)
        _qObject = new QUmlProfileObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlProfile::~QUmlProfile()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlProfile::clone() const
{
    QUmlProfile *c = new QUmlProfile;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    foreach (QUmlElementImport *element, elementImports())
        c->addElementImport(dynamic_cast<QUmlElementImport *>(element->clone()));
    foreach (QUmlConstraint *element, ownedRules())
        c->addOwnedRule(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlPackageImport *element, packageImports())
        c->addPackageImport(dynamic_cast<QUmlPackageImport *>(element->clone()));
    if (owningTemplateParameter())
        c->setOwningTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(owningTemplateParameter()->clone()));
    if (templateParameter())
        c->setTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(templateParameter()->clone()));
    c->setVisibility(visibility());
    if (ownedTemplateSignature())
        c->setOwnedTemplateSignature(dynamic_cast<QUmlTemplateSignature *>(ownedTemplateSignature()->clone()));
    foreach (QUmlTemplateBinding *element, templateBindings())
        c->addTemplateBinding(dynamic_cast<QUmlTemplateBinding *>(element->clone()));
    c->setURI(URI());
    if (nestingPackage())
        c->setNestingPackage(dynamic_cast<QUmlPackage *>(nestingPackage()->clone()));
    foreach (QUmlPackageMerge *element, packageMerges())
        c->addPackageMerge(dynamic_cast<QUmlPackageMerge *>(element->clone()));
    foreach (QUmlPackageableElement *element, packagedElements())
        c->addPackagedElement(dynamic_cast<QUmlPackageableElement *>(element->clone()));
    foreach (QUmlProfileApplication *element, profileApplications())
        c->addProfileApplication(dynamic_cast<QUmlProfileApplication *>(element->clone()));
    foreach (QUmlElementImport *element, metaclassReferences())
        c->addMetaclassReference(dynamic_cast<QUmlElementImport *>(element->clone()));
    foreach (QUmlPackageImport *element, metamodelReferences())
        c->addMetamodelReference(dynamic_cast<QUmlPackageImport *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    References a metaclass that may be extended.
 */
const QSet<QUmlElementImport *> QUmlProfile::metaclassReferences() const
{
    // This is a read-write association end

    return _metaclassReferences;
}

void QUmlProfile::addMetaclassReference(QUmlElementImport *metaclassReference)
{
    // This is a read-write association end

    if (!_metaclassReferences.contains(metaclassReference)) {
        _metaclassReferences.insert(metaclassReference);
        if (metaclassReference && metaclassReference->asQObject() && this->asQObject())
            QObject::connect(metaclassReference->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeMetaclassReference(QObject *)));
        metaclassReference->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addElementImport(metaclassReference);
    }
}

void QUmlProfile::removeMetaclassReference(QUmlElementImport *metaclassReference)
{
    // This is a read-write association end

    if (_metaclassReferences.contains(metaclassReference)) {
        _metaclassReferences.remove(metaclassReference);
        if (metaclassReference->asQObject())
            metaclassReference->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeElementImport(metaclassReference);
    }
}

/*!
    References a package containing (directly or indirectly) metaclasses that may be extended.
 */
const QSet<QUmlPackageImport *> QUmlProfile::metamodelReferences() const
{
    // This is a read-write association end

    return _metamodelReferences;
}

void QUmlProfile::addMetamodelReference(QUmlPackageImport *metamodelReference)
{
    // This is a read-write association end

    if (!_metamodelReferences.contains(metamodelReference)) {
        _metamodelReferences.insert(metamodelReference);
        if (metamodelReference && metamodelReference->asQObject() && this->asQObject())
            QObject::connect(metamodelReference->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeMetamodelReference(QObject *)));
        metamodelReference->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addPackageImport(metamodelReference);
    }
}

void QUmlProfile::removeMetamodelReference(QUmlPackageImport *metamodelReference)
{
    // This is a read-write association end

    if (_metamodelReferences.contains(metamodelReference)) {
        _metamodelReferences.remove(metamodelReference);
        if (metamodelReference->asQObject())
            metamodelReference->asQObject()->setParent(0);

        // Adjust subsetted properties
        removePackageImport(metamodelReference);
    }
}

void QUmlProfile::setGroupProperties()
{
    const QMetaObject *metaObject = _qObject->metaObject();

    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    _groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clientDependencies"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("name"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nameExpression"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("namespace_"))));
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiedName"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("elementImports"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("importedMembers"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("members"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedMembers"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedRules"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("packageImports"))));
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owningTemplateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlPackageableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));
    _groupProperties.insert(QStringLiteral("QUmlTemplateableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedTemplateSignature"))));
    _groupProperties.insert(QStringLiteral("QUmlTemplateableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateBindings"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("URI"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nestedPackages"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nestingPackage"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedStereotypes"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedTypes"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("packageMerges"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("packagedElements"))));
    _groupProperties.insert(QStringLiteral("QUmlPackage"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("profileApplications"))));
    _groupProperties.insert(QStringLiteral("QUmlProfile"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("metaclassReferences"))));
    _groupProperties.insert(QStringLiteral("QUmlProfile"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("metamodelReferences"))));
}

void QUmlProfile::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlProfile");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::DocumentationRole] = QStringLiteral("References a metaclass that may be extended.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Namespace-elementImport");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metaclassReferences")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlProfile");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::DocumentationRole] = QStringLiteral("References a package containing (directly or indirectly) metaclasses that may be extended.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Namespace-packageImport");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlProfile")][QStringLiteral("metamodelReferences")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

