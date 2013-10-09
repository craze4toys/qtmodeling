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
#include "qumlstructuredclassifier.h"

#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlClassifierTemplateParameter>
#include <QtUml/QUmlCollaborationUse>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConnectableElement>
#include <QtUml/QUmlConnector>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlFeature>
#include <QtUml/QUmlGeneralization>
#include <QtUml/QUmlGeneralizationSet>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlRedefinableTemplateSignature>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlSubstitution>
#include <QtUml/QUmlTemplateBinding>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlTemplateSignature>
#include <QtUml/QUmlType>
#include <QtUml/QUmlUseCase>

/*!
    \class QUmlStructuredClassifier

    \inmodule QtUml

    \brief A structured classifier is an abstract metaclass that represents any classifier whose behavior can be fully or partly described by the collaboration of owned or referenced instances.
 */
QUmlStructuredClassifier::QUmlStructuredClassifier()
{
    setGroupProperties();
    setPropertyData();
}

QUmlStructuredClassifier::~QUmlStructuredClassifier()
{
}

QModelingObject *QUmlStructuredClassifier::clone() const
{
    QUmlStructuredClassifier *c = new QUmlStructuredClassifier;
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
    c->setVisibility(visibility());
    if (package())
        c->setPackage(dynamic_cast<QUmlPackage *>(package()->clone()));
    c->setLeaf(isLeaf());
    foreach (QUmlTemplateBinding *element, templateBindings())
        c->addTemplateBinding(dynamic_cast<QUmlTemplateBinding *>(element->clone()));
    foreach (QUmlCollaborationUse *element, collaborationUses())
        c->addCollaborationUse(dynamic_cast<QUmlCollaborationUse *>(element->clone()));
    foreach (QUmlGeneralization *element, generalizations())
        c->addGeneralization(dynamic_cast<QUmlGeneralization *>(element->clone()));
    c->setAbstract(isAbstract());
    c->setFinalSpecialization(isFinalSpecialization());
    if (ownedTemplateSignature())
        c->setOwnedTemplateSignature(dynamic_cast<QUmlRedefinableTemplateSignature *>(ownedTemplateSignature()->clone()));
    foreach (QUmlUseCase *element, ownedUseCases())
        c->addOwnedUseCase(dynamic_cast<QUmlUseCase *>(element->clone()));
    foreach (QUmlGeneralizationSet *element, powertypeExtents())
        c->addPowertypeExtent(dynamic_cast<QUmlGeneralizationSet *>(element->clone()));
    foreach (QUmlClassifier *element, redefinedClassifiers())
        c->addRedefinedClassifier(dynamic_cast<QUmlClassifier *>(element->clone()));
    if (representation())
        c->setRepresentation(dynamic_cast<QUmlCollaborationUse *>(representation()->clone()));
    foreach (QUmlSubstitution *element, substitutions())
        c->addSubstitution(dynamic_cast<QUmlSubstitution *>(element->clone()));
    if (templateParameter())
        c->setTemplateParameter(dynamic_cast<QUmlClassifierTemplateParameter *>(templateParameter()->clone()));
    foreach (QUmlUseCase *element, useCases())
        c->addUseCase(dynamic_cast<QUmlUseCase *>(element->clone()));
    foreach (QUmlProperty *element, ownedAttributes())
        c->addOwnedAttribute(dynamic_cast<QUmlProperty *>(element->clone()));
    foreach (QUmlConnector *element, ownedConnectors())
        c->addOwnedConnector(dynamic_cast<QUmlConnector *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    References the properties owned by the classifier.
 */
const QList<QUmlProperty *> QUmlStructuredClassifier::ownedAttributes() const
{
    // This is a read-write association end

    return _ownedAttributes;
}

void QUmlStructuredClassifier::addOwnedAttribute(QUmlProperty *ownedAttribute)
{
    // This is a read-write association end

    if (!_ownedAttributes.contains(ownedAttribute)) {
        _ownedAttributes.append(ownedAttribute);
        if (ownedAttribute && ownedAttribute->asQObject() && this->asQObject())
            QObject::connect(ownedAttribute->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeOwnedAttribute(QObject *)));
        ownedAttribute->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addAttribute(ownedAttribute);
        addOwnedMember(ownedAttribute);
        addRole(ownedAttribute);
    }
}

void QUmlStructuredClassifier::removeOwnedAttribute(QUmlProperty *ownedAttribute)
{
    // This is a read-write association end

    if (_ownedAttributes.contains(ownedAttribute)) {
        _ownedAttributes.removeAll(ownedAttribute);
        if (ownedAttribute->asQObject())
            ownedAttribute->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeAttribute(ownedAttribute);
        removeOwnedMember(ownedAttribute);
        removeRole(ownedAttribute);
    }
}

/*!
    References the connectors owned by the classifier.
 */
const QSet<QUmlConnector *> QUmlStructuredClassifier::ownedConnectors() const
{
    // This is a read-write association end

    return _ownedConnectors;
}

void QUmlStructuredClassifier::addOwnedConnector(QUmlConnector *ownedConnector)
{
    // This is a read-write association end

    if (!_ownedConnectors.contains(ownedConnector)) {
        _ownedConnectors.insert(ownedConnector);
        if (ownedConnector && ownedConnector->asQObject() && this->asQObject())
            QObject::connect(ownedConnector->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeOwnedConnector(QObject *)));
        ownedConnector->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addFeature(ownedConnector);
        addOwnedMember(ownedConnector);
    }
}

void QUmlStructuredClassifier::removeOwnedConnector(QUmlConnector *ownedConnector)
{
    // This is a read-write association end

    if (_ownedConnectors.contains(ownedConnector)) {
        _ownedConnectors.remove(ownedConnector);
        if (ownedConnector->asQObject())
            ownedConnector->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeFeature(ownedConnector);
        removeOwnedMember(ownedConnector);
    }
}

/*!
    References the properties specifying instances that the classifier owns by composition. This association is derived, selecting those owned properties where isComposite is true.
 */
const QSet<QUmlProperty *> QUmlStructuredClassifier::parts() const
{
    // This is a read-only derived association end

    qWarning("UmlStructuredClassifier::parts(): to be implemented (this is a derived association end)");

    return QSet<QUmlProperty *>();
}

void QUmlStructuredClassifier::addPart(QUmlProperty *part)
{
    // This is a read-only derived association end

    qWarning("UmlStructuredClassifier::addPart(): to be implemented (this is a derived association end)");
    Q_UNUSED(part);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void QUmlStructuredClassifier::removePart(QUmlProperty *part)
{
    // This is a read-only derived association end

    qWarning("UmlStructuredClassifier::removePart(): to be implemented (this is a derived association end)");
    Q_UNUSED(part);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    References the roles that instances may play in this classifier.
 */
const QSet<QUmlConnectableElement *> QUmlStructuredClassifier::roles() const
{
    // This is a read-only derived union association end

    return _roles;
}

void QUmlStructuredClassifier::addRole(QUmlConnectableElement *role)
{
    // This is a read-only derived union association end

    if (!_roles.contains(role)) {
        _roles.insert(role);
        if (role && role->asQObject() && this->asQObject())
            QObject::connect(role->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRole(QObject *)));

        // Adjust subsetted properties
        addMember(role);
    }
}

void QUmlStructuredClassifier::removeRole(QUmlConnectableElement *role)
{
    // This is a read-only derived union association end

    if (_roles.contains(role)) {
        _roles.remove(role);

        // Adjust subsetted properties
        removeMember(role);
    }
}

void QUmlStructuredClassifier::setGroupProperties()
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
    _groupProperties.insert(QStringLiteral("QUmlPackageableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));
    _groupProperties.insert(QStringLiteral("QUmlType"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("package"))));
    _groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isLeaf"))));
    _groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinedElements"))));
    _groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinitionContexts"))));
    _groupProperties.insert(QStringLiteral("QUmlTemplateableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateBindings"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("attributes"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("collaborationUses"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("features"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("generals"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("generalizations"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("inheritedMembers"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isAbstract"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isFinalSpecialization"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedTemplateSignature"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedUseCases"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("powertypeExtents"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinedClassifiers"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("representation"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("substitutions"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("useCases"))));
    _groupProperties.insert(QStringLiteral("QUmlStructuredClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedAttributes"))));
    _groupProperties.insert(QStringLiteral("QUmlStructuredClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedConnectors"))));
    _groupProperties.insert(QStringLiteral("QUmlStructuredClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("parts"))));
    _groupProperties.insert(QStringLiteral("QUmlStructuredClassifier"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("roles"))));
}

void QUmlStructuredClassifier::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlStructuredClassifier");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::DocumentationRole] = QStringLiteral("References the properties owned by the classifier.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Classifier-attribute Namespace-ownedMember StructuredClassifier-role");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedAttributes")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlStructuredClassifier");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::DocumentationRole] = QStringLiteral("References the connectors owned by the classifier.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Classifier-feature A_redefinitionContext_redefinableElement-redefinableElement Namespace-ownedMember");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("ownedConnectors")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlStructuredClassifier");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::DocumentationRole] = QStringLiteral("References the properties specifying instances that the classifier owns by composition. This association is derived, selecting those owned properties where isComposite is true.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("parts")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlStructuredClassifier");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::IsDerivedUnionRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::DocumentationRole] = QStringLiteral("References the roles that instances may play in this classifier.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Namespace-member");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlStructuredClassifier")][QStringLiteral("roles")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

