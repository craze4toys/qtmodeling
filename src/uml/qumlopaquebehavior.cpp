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
#include "qumlopaquebehavior.h"

#include "private/qumlopaquebehaviorobject_p.h"

#include <QtUml/QUmlBehavior>
#include <QtUml/QUmlBehavioralFeature>
#include <QtUml/QUmlBehavioredClassifier>
#include <QtUml/QUmlClass>
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
#include <QtUml/QUmlExtension>
#include <QtUml/QUmlFeature>
#include <QtUml/QUmlGeneralization>
#include <QtUml/QUmlGeneralizationSet>
#include <QtUml/QUmlInterfaceRealization>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOperation>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlParameter>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlParameterSet>
#include <QtUml/QUmlPort>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlReception>
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
    \class QUmlOpaqueBehavior

    \inmodule QtUml

    \brief An behavior with implementation-specific semantics.
 */
QUmlOpaqueBehavior::QUmlOpaqueBehavior(bool createQObject)
{
    if (createQObject)
        _qObject = new QUmlOpaqueBehaviorObject(this);
    setPropertyData();
}

QUmlOpaqueBehavior::~QUmlOpaqueBehavior()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlOpaqueBehavior::clone() const
{
    QUmlOpaqueBehavior *c = new QUmlOpaqueBehavior;
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
    foreach (QUmlConnector *element, ownedConnectors())
        c->addOwnedConnector(dynamic_cast<QUmlConnector *>(element->clone()));
    if (classifierBehavior())
        c->setClassifierBehavior(dynamic_cast<QUmlBehavior *>(classifierBehavior()->clone()));
    foreach (QUmlInterfaceRealization *element, interfaceRealizations())
        c->addInterfaceRealization(dynamic_cast<QUmlInterfaceRealization *>(element->clone()));
    foreach (QUmlBehavior *element, ownedBehaviors())
        c->addOwnedBehavior(dynamic_cast<QUmlBehavior *>(element->clone()));
    c->setAbstract(isAbstract());
    c->setActive(isActive());
    foreach (QUmlClassifier *element, nestedClassifiers())
        c->addNestedClassifier(dynamic_cast<QUmlClassifier *>(element->clone()));
    foreach (QUmlProperty *element, ownedAttributes())
        c->addOwnedAttribute(dynamic_cast<QUmlProperty *>(element->clone()));
    foreach (QUmlOperation *element, ownedOperations())
        c->addOwnedOperation(dynamic_cast<QUmlOperation *>(element->clone()));
    foreach (QUmlReception *element, ownedReceptions())
        c->addOwnedReception(dynamic_cast<QUmlReception *>(element->clone()));
    c->setReentrant(isReentrant());
    foreach (QUmlParameter *element, ownedParameters())
        c->addOwnedParameter(dynamic_cast<QUmlParameter *>(element->clone()));
    foreach (QUmlParameterSet *element, ownedParameterSets())
        c->addOwnedParameterSet(dynamic_cast<QUmlParameterSet *>(element->clone()));
    foreach (QUmlConstraint *element, postconditions())
        c->addPostcondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlConstraint *element, preconditions())
        c->addPrecondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlBehavior *element, redefinedBehaviors())
        c->addRedefinedBehavior(dynamic_cast<QUmlBehavior *>(element->clone()));
    if (specification())
        c->setSpecification(dynamic_cast<QUmlBehavioralFeature *>(specification()->clone()));
    foreach (QString element, bodies())
        c->addBody(element);
    foreach (QString element, languages())
        c->addLanguage(element);
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies the behavior in one or more languages.
 */
const QList<QString> QUmlOpaqueBehavior::bodies() const
{
    // This is a read-write property

    return _bodies;
}

void QUmlOpaqueBehavior::addBody(QString body)
{
    // This is a read-write property

    if (!_bodies.contains(body)) {
        _bodies.append(body);
    }
}

void QUmlOpaqueBehavior::removeBody(QString body)
{
    // This is a read-write property

    if (_bodies.contains(body)) {
        _bodies.removeAll(body);
    }
}

/*!
    Languages the body strings use in the same order as the body strings.
 */
const QList<QString> QUmlOpaqueBehavior::languages() const
{
    // This is a read-write property

    return _languages;
}

void QUmlOpaqueBehavior::addLanguage(QString language)
{
    // This is a read-write property

    if (!_languages.contains(language)) {
        _languages.append(language);
    }
}

void QUmlOpaqueBehavior::removeLanguage(QString language)
{
    // This is a read-write property

    if (_languages.contains(language)) {
        _languages.removeAll(language);
    }
}

void QUmlOpaqueBehavior::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlOpaqueBehavior");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::DocumentationRole] = QStringLiteral("Specifies the behavior in one or more languages.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("body")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlOpaqueBehavior");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::DocumentationRole] = QStringLiteral("Languages the body strings use in the same order as the body strings.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlOpaqueBehavior")][QStringLiteral("language")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

void QUmlOpaqueBehavior::setClassForProperty()
{
    _classForProperty[QStringLiteral("ownedComments")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("ownedElements")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("owner")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("clientDependencies")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("name")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("nameExpression")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("namespace_")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("qualifiedName")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("elementImports")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("importedMembers")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("members")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("ownedMembers")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("ownedRules")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("packageImports")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("owningTemplateParameter")] = QStringLiteral("QUmlParameterableElement");
    _classForProperty[QStringLiteral("visibility")] = QStringLiteral("QUmlPackageableElement");
    _classForProperty[QStringLiteral("package")] = QStringLiteral("QUmlType");
    _classForProperty[QStringLiteral("isLeaf")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinedElements")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinitionContexts")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("templateBindings")] = QStringLiteral("QUmlTemplateableElement");
    _classForProperty[QStringLiteral("attributes")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("collaborationUses")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("features")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("generalizations")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("inheritedMembers")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("isFinalSpecialization")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("ownedTemplateSignature")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("ownedUseCases")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("powertypeExtents")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("redefinedClassifiers")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("representation")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("substitutions")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("templateParameter")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("useCases")] = QStringLiteral("QUmlClassifier");
    _classForProperty[QStringLiteral("ownedConnectors")] = QStringLiteral("QUmlStructuredClassifier");
    _classForProperty[QStringLiteral("parts")] = QStringLiteral("QUmlStructuredClassifier");
    _classForProperty[QStringLiteral("roles")] = QStringLiteral("QUmlStructuredClassifier");
    _classForProperty[QStringLiteral("ownedPorts")] = QStringLiteral("QUmlEncapsulatedClassifier");
    _classForProperty[QStringLiteral("classifierBehavior")] = QStringLiteral("QUmlBehavioredClassifier");
    _classForProperty[QStringLiteral("interfaceRealizations")] = QStringLiteral("QUmlBehavioredClassifier");
    _classForProperty[QStringLiteral("ownedBehaviors")] = QStringLiteral("QUmlBehavioredClassifier");
    _classForProperty[QStringLiteral("extensions")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("isAbstract")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("isActive")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("nestedClassifiers")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("ownedAttributes")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("ownedOperations")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("ownedReceptions")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("superClasses")] = QStringLiteral("QUmlClass");
    _classForProperty[QStringLiteral("context")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("isReentrant")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("ownedParameters")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("ownedParameterSets")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("postconditions")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("preconditions")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("redefinedBehaviors")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("specification")] = QStringLiteral("QUmlBehavior");
    _classForProperty[QStringLiteral("bodies")] = QStringLiteral("QUmlOpaqueBehavior");
    _classForProperty[QStringLiteral("languages")] = QStringLiteral("QUmlOpaqueBehavior");
}

