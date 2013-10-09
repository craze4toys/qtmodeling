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
#include "qumldeploymentspecification.h"

#include "private/qumldeploymentspecificationobject_p.h"

#include <QtUml/QUmlArtifact>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlClassifierTemplateParameter>
#include <QtUml/QUmlCollaborationUse>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlDeployment>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlFeature>
#include <QtUml/QUmlGeneralization>
#include <QtUml/QUmlGeneralizationSet>
#include <QtUml/QUmlManifestation>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOperation>
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
    \class QUmlDeploymentSpecification

    \inmodule QtUml

    \brief A deployment specification specifies a set of properties that determine execution parameters of a component artifact that is deployed on a node. A deployment specification can be aimed at a specific type of container. An artifact that reifies or implements deployment specification properties is a deployment descriptor.
 */
QUmlDeploymentSpecification::QUmlDeploymentSpecification(bool createQObject) :
    QUmlArtifact(false),
    _deployment(0)
{
    if (createQObject)
        _qObject = new QUmlDeploymentSpecificationObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlDeploymentSpecification::~QUmlDeploymentSpecification()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlDeploymentSpecification::clone() const
{
    QUmlDeploymentSpecification *c = new QUmlDeploymentSpecification;
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
    c->setFileName(fileName());
    foreach (QUmlManifestation *element, manifestations())
        c->addManifestation(dynamic_cast<QUmlManifestation *>(element->clone()));
    foreach (QUmlArtifact *element, nestedArtifacts())
        c->addNestedArtifact(dynamic_cast<QUmlArtifact *>(element->clone()));
    foreach (QUmlProperty *element, ownedAttributes())
        c->addOwnedAttribute(dynamic_cast<QUmlProperty *>(element->clone()));
    foreach (QUmlOperation *element, ownedOperations())
        c->addOwnedOperation(dynamic_cast<QUmlOperation *>(element->clone()));
    if (deployment())
        c->setDeployment(dynamic_cast<QUmlDeployment *>(deployment()->clone()));
    c->setDeploymentLocation(deploymentLocation());
    c->setExecutionLocation(executionLocation());
    return c;
}

// OWNED ATTRIBUTES

/*!
    The deployment with which the DeploymentSpecification is associated.
 */
QUmlDeployment *QUmlDeploymentSpecification::deployment() const
{
    // This is a read-write association end

    return _deployment;
}

void QUmlDeploymentSpecification::setDeployment(QUmlDeployment *deployment)
{
    // This is a read-write association end

    if (_deployment != deployment) {
        // Adjust subsetted properties

        _deployment = deployment;
        if (deployment && deployment->asQObject() && this->asQObject())
            QObject::connect(deployment->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setDeployment()));

        // Adjust subsetted properties
        setOwner(deployment);
    }
}

/*!
    The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address'.
 */
QString QUmlDeploymentSpecification::deploymentLocation() const
{
    // This is a read-write property

    return _deploymentLocation;
}

void QUmlDeploymentSpecification::setDeploymentLocation(QString deploymentLocation)
{
    // This is a read-write property

    if (_deploymentLocation != deploymentLocation) {
        _deploymentLocation = deploymentLocation;
    }
}

/*!
    The location where a component Artifact executes. This may be a local or remote location.
 */
QString QUmlDeploymentSpecification::executionLocation() const
{
    // This is a read-write property

    return _executionLocation;
}

void QUmlDeploymentSpecification::setExecutionLocation(QString executionLocation)
{
    // This is a read-write property

    if (_executionLocation != executionLocation) {
        _executionLocation = executionLocation;
    }
}

void QUmlDeploymentSpecification::setGroupProperties()
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
    _groupProperties.insert(QStringLiteral("QUmlArtifact"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("fileName"))));
    _groupProperties.insert(QStringLiteral("QUmlArtifact"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("manifestations"))));
    _groupProperties.insert(QStringLiteral("QUmlArtifact"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nestedArtifacts"))));
    _groupProperties.insert(QStringLiteral("QUmlArtifact"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedAttributes"))));
    _groupProperties.insert(QStringLiteral("QUmlArtifact"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedOperations"))));
    _groupProperties.insert(QStringLiteral("QUmlDeploymentSpecification"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("deployment"))));
    _groupProperties.insert(QStringLiteral("QUmlDeploymentSpecification"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("deploymentLocation"))));
    _groupProperties.insert(QStringLiteral("QUmlDeploymentSpecification"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("executionLocation"))));
}

void QUmlDeploymentSpecification::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlDeploymentSpecification");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::DocumentationRole] = QStringLiteral("The deployment with which the DeploymentSpecification is associated.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-owner");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deployment")][QtModeling::OppositeEndRole] = QStringLiteral("Deployment-configuration");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlDeploymentSpecification");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::DocumentationRole] = QStringLiteral("The location where an Artifact is deployed onto a Node. This is typically a 'directory' or 'memory address'.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("deploymentLocation")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlDeploymentSpecification");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::DocumentationRole] = QStringLiteral("The location where a component Artifact executes. This may be a local or remote location.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDeploymentSpecification")][QStringLiteral("executionLocation")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

