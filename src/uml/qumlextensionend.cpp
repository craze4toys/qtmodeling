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
#include "qumlextensionend.h"

#include "private/qumlextensionendobject_p.h"

#include <QtUml/QUmlAssociation>
#include <QtUml/QUmlClass>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConnectableElementTemplateParameter>
#include <QtUml/QUmlConnectorEnd>
#include <QtUml/QUmlDataType>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlDeployment>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInterface>
#include <QtUml/QUmlMultiplicityElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStereotype>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlType>
#include <QtUml/QUmlValueSpecification>

/*!
    \class QUmlExtensionEnd

    \inmodule QtUml

    \brief An extension end is used to tie an extension to a stereotype when extending a metaclass.The default multiplicity of an extension end is 0..1.
 */
QUmlExtensionEnd::QUmlExtensionEnd(bool createQObject) :
    QUmlProperty(false),
    _type(0)
{
    if (createQObject)
        _qObject = new QUmlExtensionEndObject(this);
    setClassForProperty();
    setPropertyData();
}

QUmlExtensionEnd::~QUmlExtensionEnd()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlExtensionEnd::clone() const
{
    QUmlExtensionEnd *c = new QUmlExtensionEnd;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setOrdered(isOrdered());
    c->setUnique(isUnique());
    if (lowerValue())
        c->setLowerValue(dynamic_cast<QUmlValueSpecification *>(lowerValue()->clone()));
    if (upperValue())
        c->setUpperValue(dynamic_cast<QUmlValueSpecification *>(upperValue()->clone()));
    c->setLeaf(isLeaf());
    c->setStatic(isStatic());
    if (owningTemplateParameter())
        c->setOwningTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(owningTemplateParameter()->clone()));
    if (templateParameter())
        c->setTemplateParameter(dynamic_cast<QUmlConnectableElementTemplateParameter *>(templateParameter()->clone()));
    foreach (QUmlDeployment *element, deployments())
        c->addDeployment(dynamic_cast<QUmlDeployment *>(element->clone()));
    c->setAggregation(aggregation());
    if (association())
        c->setAssociation(dynamic_cast<QUmlAssociation *>(association()->clone()));
    if (associationEnd())
        c->setAssociationEnd(dynamic_cast<QUmlProperty *>(associationEnd()->clone()));
    if (class_())
        c->setClass(dynamic_cast<QUmlClass *>(class_()->clone()));
    if (datatype())
        c->setDatatype(dynamic_cast<QUmlDataType *>(datatype()->clone()));
    if (defaultValue())
        c->setDefaultValue(dynamic_cast<QUmlValueSpecification *>(defaultValue()->clone()));
    if (interface_())
        c->setInterface(dynamic_cast<QUmlInterface *>(interface_()->clone()));
    c->setDerived(isDerived());
    c->setDerivedUnion(isDerivedUnion());
    c->setID(isID());
    c->setReadOnly(isReadOnly());
    if (owningAssociation())
        c->setOwningAssociation(dynamic_cast<QUmlAssociation *>(owningAssociation()->clone()));
    foreach (QUmlProperty *element, qualifiers())
        c->addQualifier(dynamic_cast<QUmlProperty *>(element->clone()));
    foreach (QUmlProperty *element, redefinedProperties())
        c->addRedefinedProperty(dynamic_cast<QUmlProperty *>(element->clone()));
    foreach (QUmlProperty *element, subsettedProperties())
        c->addSubsettedProperty(dynamic_cast<QUmlProperty *>(element->clone()));
    if (type())
        c->setType(dynamic_cast<QUmlStereotype *>(type()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    This redefinition changes the default multiplicity of association ends, since model elements are usually extended by 0 or 1 instance of the extension stereotype.
 */
int QUmlExtensionEnd::lower() const
{
    // This is a read-write derived property

    qWarning("UmlExtensionEnd::lower(): to be implemented (this is a derived property)");

    return int();
}

void QUmlExtensionEnd::setLower(int lower)
{
    // This is a read-write derived property

    qWarning("UmlExtensionEnd::setLower(): to be implemented (this is a derived property)");
    Q_UNUSED(lower);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    References the type of the ExtensionEnd. Note that this association restricts the possible types of an ExtensionEnd to only be Stereotypes.
 */
QUmlStereotype *QUmlExtensionEnd::type() const
{
    // This is a read-write association end

    return _type;
}

void QUmlExtensionEnd::setType(QUmlStereotype *type)
{
    // This is a read-write association end

    if (_type != type) {
        _type = type;
        if (type && type->asQObject() && this->asQObject())
            QObject::connect(type->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setType()));
    }
}

// OPERATIONS

/*!
    The query lowerBound() returns the lower bound of the multiplicity as an Integer. This is a redefinition of the default lower bound, which normally, for MultiplicityElements, evaluates to 1 if empty.
 */
int QUmlExtensionEnd::lowerBound() const
{
    qWarning("UmlExtensionEnd::lowerBound(): to be implemented (operation)");

    return int ();
}

void QUmlExtensionEnd::setClassForProperty()
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
    _classForProperty[QStringLiteral("isOrdered")] = QStringLiteral("QUmlMultiplicityElement");
    _classForProperty[QStringLiteral("isUnique")] = QStringLiteral("QUmlMultiplicityElement");
    _classForProperty[QStringLiteral("lowerValue")] = QStringLiteral("QUmlMultiplicityElement");
    _classForProperty[QStringLiteral("upper")] = QStringLiteral("QUmlMultiplicityElement");
    _classForProperty[QStringLiteral("upperValue")] = QStringLiteral("QUmlMultiplicityElement");
    _classForProperty[QStringLiteral("isLeaf")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinedElements")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinitionContexts")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("featuringClassifiers")] = QStringLiteral("QUmlFeature");
    _classForProperty[QStringLiteral("isStatic")] = QStringLiteral("QUmlFeature");
    _classForProperty[QStringLiteral("owningTemplateParameter")] = QStringLiteral("QUmlParameterableElement");
    _classForProperty[QStringLiteral("ends")] = QStringLiteral("QUmlConnectableElement");
    _classForProperty[QStringLiteral("templateParameter")] = QStringLiteral("QUmlConnectableElement");
    _classForProperty[QStringLiteral("deployedElements")] = QStringLiteral("QUmlDeploymentTarget");
    _classForProperty[QStringLiteral("deployments")] = QStringLiteral("QUmlDeploymentTarget");
    _classForProperty[QStringLiteral("aggregation")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("association")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("associationEnd")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("class_")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("datatype")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("default_")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("defaultValue")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("interface_")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("isComposite")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("isDerived")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("isDerivedUnion")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("isID")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("isReadOnly")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("opposite")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("owningAssociation")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("qualifiers")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("redefinedProperties")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("subsettedProperties")] = QStringLiteral("QUmlProperty");
    _classForProperty[QStringLiteral("lower")] = QStringLiteral("QUmlExtensionEnd");
    _classForProperty[QStringLiteral("type")] = QStringLiteral("QUmlExtensionEnd");
}

void QUmlExtensionEnd::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlExtensionEnd");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::DocumentationRole] = QStringLiteral("This redefinition changes the default multiplicity of association ends, since model elements are usually extended by 0 or 1 instance of the extension stereotype.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("MultiplicityElement-lower");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("lower")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlExtensionEnd");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::DocumentationRole] = QStringLiteral("References the type of the ExtensionEnd. Note that this association restricts the possible types of an ExtensionEnd to only be Stereotypes.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("TypedElement-type");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlExtensionEnd")][QStringLiteral("type")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

