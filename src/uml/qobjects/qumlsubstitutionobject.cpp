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
#include "qumlsubstitutionobject_p.h"
#include "private/qmodelingobject_p.h"

#include <QtUml/QUmlSubstitution>
#include <QtUml/QUmlClassifier>
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

QT_BEGIN_NAMESPACE

QUmlSubstitutionObject::QUmlSubstitutionObject(QUmlSubstitution *qModelingElement)
{
    setProperty("modelingElement", QVariant::fromValue(static_cast<QModelingElement *>(qModelingElement)));
    setGroupProperties();
    setPropertyData();
}

QUmlSubstitutionObject::~QUmlSubstitutionObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingelementproperty_cast<QUmlSubstitution *>(this)->deletingFromQModelingObject = true;
        delete qmodelingelementproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlSubstitutionObject::ownedComments() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->ownedComments())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlSubstitutionObject::ownedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->ownedElements())
        set.insert(element->asQModelingObject());
    return set;
}

QObject *QUmlSubstitutionObject::owner() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->owner())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->owner()->asQModelingObject();
}

// OWNED ATTRIBUTES [ParameterableElement]

QObject *QUmlSubstitutionObject::owningTemplateParameter() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->owningTemplateParameter())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->owningTemplateParameter()->asQModelingObject();
}

QObject *QUmlSubstitutionObject::templateParameter() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->templateParameter())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->templateParameter()->asQModelingObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlSubstitutionObject::clientDependencies() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->clientDependencies())
        set.insert(element->asQModelingObject());
    return set;
}

QString QUmlSubstitutionObject::name() const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->name();
}

QObject *QUmlSubstitutionObject::nameExpression() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->nameExpression())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->nameExpression()->asQModelingObject();
}

QObject *QUmlSubstitutionObject::namespace_() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->namespace_())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->namespace_()->asQModelingObject();
}

QString QUmlSubstitutionObject::qualifiedName() const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->qualifiedName();
}

// OWNED ATTRIBUTES [PackageableElement]

QtUml::VisibilityKind QUmlSubstitutionObject::visibility() const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->visibility();
}

// OWNED ATTRIBUTES [Relationship]

const QSet<QObject *> QUmlSubstitutionObject::relatedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->relatedElements())
        set.insert(element->asQModelingObject());
    return set;
}

// OWNED ATTRIBUTES [DirectedRelationship]

const QSet<QObject *> QUmlSubstitutionObject::sources() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->sources())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlSubstitutionObject::targets() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->targets())
        set.insert(element->asQModelingObject());
    return set;
}

// OWNED ATTRIBUTES [Dependency]

const QSet<QObject *> QUmlSubstitutionObject::clients() const
{
    QSet<QObject *> set;
    foreach (QUmlNamedElement *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->clients())
        set.insert(element->asQModelingObject());
    return set;
}

const QSet<QObject *> QUmlSubstitutionObject::suppliers() const
{
    QSet<QObject *> set;
    foreach (QUmlNamedElement *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->suppliers())
        set.insert(element->asQModelingObject());
    return set;
}

// OWNED ATTRIBUTES [Abstraction]

QObject *QUmlSubstitutionObject::mapping() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->mapping())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->mapping()->asQModelingObject();
}

// OWNED ATTRIBUTES [Substitution]

QObject *QUmlSubstitutionObject::contract() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->contract())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->contract()->asQModelingObject();
}

QObject *QUmlSubstitutionObject::substitutingClassifier() const
{
    if (!qmodelingelementproperty_cast<QUmlSubstitution *>(this)->substitutingClassifier())
        return 0;
    else
        return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->substitutingClassifier()->asQModelingObject();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlSubstitutionObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->allOwnedElements())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlSubstitutionObject::mustBeOwned() const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->mustBeOwned();
}

// OPERATIONS [ParameterableElement]

bool QUmlSubstitutionObject::isCompatibleWith(QObject *p) const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->isCompatibleWith(qmodelingelementproperty_cast<QUmlParameterableElement *>(p));
}

bool QUmlSubstitutionObject::isTemplateParameter() const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->isTemplateParameter();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlSubstitutionObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->allNamespaces())
        set.append(element->asQModelingObject());
    return set;
}

QSet<QObject *> QUmlSubstitutionObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingelementproperty_cast<QUmlSubstitution *>(this)->allOwningPackages())
        set.insert(element->asQModelingObject());
    return set;
}

bool QUmlSubstitutionObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->isDistinguishableFrom(qmodelingelementproperty_cast<QUmlNamedElement *>(n), qmodelingelementproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlSubstitutionObject::separator() const
{
    return qmodelingelementproperty_cast<QUmlSubstitution *>(this)->separator();
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlSubstitutionObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlSubstitutionObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeOwnedComment(qmodelingelementproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlSubstitutionObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlSubstitutionObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeOwnedElement(qmodelingelementproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlSubstitutionObject::setOwner(QObject *owner)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setOwner(qmodelingelementproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [ParameterableElement]

void QUmlSubstitutionObject::setOwningTemplateParameter(QObject *owningTemplateParameter)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setOwningTemplateParameter(qmodelingelementproperty_cast<QUmlTemplateParameter *>(owningTemplateParameter));
}

void QUmlSubstitutionObject::setTemplateParameter(QObject *templateParameter)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setTemplateParameter(qmodelingelementproperty_cast<QUmlTemplateParameter *>(templateParameter));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlSubstitutionObject::addClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlSubstitutionObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeClientDependency(qmodelingelementproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlSubstitutionObject::setName(QString name)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setName(name);
}

void QUmlSubstitutionObject::setNameExpression(QObject *nameExpression)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setNameExpression(qmodelingelementproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlSubstitutionObject::setNamespace(QObject *namespace_)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setNamespace(qmodelingelementproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlSubstitutionObject::setQualifiedName(QString qualifiedName)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setQualifiedName(qualifiedName);
}
// SLOTS FOR OWNED ATTRIBUTES [PackageableElement]

void QUmlSubstitutionObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setVisibility(visibility);
}

void QUmlSubstitutionObject::unsetVisibility()
{
    Q_D(QModelingObject);
    d->modifiedResettableProperties.removeAll(QStringLiteral("visibility"));
}

// SLOTS FOR OWNED ATTRIBUTES [Relationship]

void QUmlSubstitutionObject::addRelatedElement(QObject *relatedElement)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addRelatedElement(qmodelingelementproperty_cast<QUmlElement *>(relatedElement));
}

void QUmlSubstitutionObject::removeRelatedElement(QObject *relatedElement)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeRelatedElement(qmodelingelementproperty_cast<QUmlElement *>(relatedElement));
}

// SLOTS FOR OWNED ATTRIBUTES [DirectedRelationship]

void QUmlSubstitutionObject::addSource(QObject *source)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addSource(qmodelingelementproperty_cast<QUmlElement *>(source));
}

void QUmlSubstitutionObject::removeSource(QObject *source)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeSource(qmodelingelementproperty_cast<QUmlElement *>(source));
}

void QUmlSubstitutionObject::addTarget(QObject *target)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addTarget(qmodelingelementproperty_cast<QUmlElement *>(target));
}

void QUmlSubstitutionObject::removeTarget(QObject *target)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeTarget(qmodelingelementproperty_cast<QUmlElement *>(target));
}

// SLOTS FOR OWNED ATTRIBUTES [Dependency]

void QUmlSubstitutionObject::addClient(QObject *client)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addClient(qmodelingelementproperty_cast<QUmlNamedElement *>(client));
}

void QUmlSubstitutionObject::removeClient(QObject *client)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeClient(qmodelingelementproperty_cast<QUmlNamedElement *>(client));
}

void QUmlSubstitutionObject::addSupplier(QObject *supplier)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->addSupplier(qmodelingelementproperty_cast<QUmlNamedElement *>(supplier));
}

void QUmlSubstitutionObject::removeSupplier(QObject *supplier)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->removeSupplier(qmodelingelementproperty_cast<QUmlNamedElement *>(supplier));
}

// SLOTS FOR OWNED ATTRIBUTES [Abstraction]

void QUmlSubstitutionObject::setMapping(QObject *mapping)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setMapping(qmodelingelementproperty_cast<QUmlOpaqueExpression *>(mapping));
}

// SLOTS FOR OWNED ATTRIBUTES [Substitution]

void QUmlSubstitutionObject::setContract(QObject *contract)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setContract(qmodelingelementproperty_cast<QUmlClassifier *>(contract));
}

void QUmlSubstitutionObject::setSubstitutingClassifier(QObject *substitutingClassifier)
{
    qmodelingelementproperty_cast<QUmlSubstitution *>(this)->setSubstitutingClassifier(qmodelingelementproperty_cast<QUmlClassifier *>(substitutingClassifier));
}


void QUmlSubstitutionObject::setGroupProperties()
{
    Q_D(QModelingObject);
    const QMetaObject *metaObject = this->metaObject();

    d->propertyGroups << QStringLiteral("QObject");
    d->groupProperties.insert(QStringLiteral("QObject"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("objectName"))));

    d->propertyGroups << QStringLiteral("QUmlElement");
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedComments"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedElements"))));
    d->groupProperties.insert(QStringLiteral("QUmlElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owner"))));

    d->propertyGroups << QStringLiteral("QUmlParameterableElement");
    d->groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owningTemplateParameter"))));
    d->groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateParameter"))));

    d->propertyGroups << QStringLiteral("QUmlNamedElement");
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clientDependencies"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("name"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("nameExpression"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("namespace_"))));
    d->groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("qualifiedName"))));

    d->propertyGroups << QStringLiteral("QUmlPackageableElement");
    d->groupProperties.insert(QStringLiteral("QUmlPackageableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));

    d->propertyGroups << QStringLiteral("QUmlRelationship");
    d->groupProperties.insert(QStringLiteral("QUmlRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("relatedElements"))));

    d->propertyGroups << QStringLiteral("QUmlDirectedRelationship");
    d->groupProperties.insert(QStringLiteral("QUmlDirectedRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("sources"))));
    d->groupProperties.insert(QStringLiteral("QUmlDirectedRelationship"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("targets"))));

    d->propertyGroups << QStringLiteral("QUmlDependency");
    d->groupProperties.insert(QStringLiteral("QUmlDependency"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("clients"))));
    d->groupProperties.insert(QStringLiteral("QUmlDependency"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("suppliers"))));

    d->propertyGroups << QStringLiteral("QUmlAbstraction");
    d->groupProperties.insert(QStringLiteral("QUmlAbstraction"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("mapping"))));

    d->propertyGroups << QStringLiteral("QUmlRealization");

    d->propertyGroups << QStringLiteral("QUmlSubstitution");
    d->groupProperties.insert(QStringLiteral("QUmlSubstitution"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("contract"))));
    d->groupProperties.insert(QStringLiteral("QUmlSubstitution"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("substitutingClassifier"))));
}

void QUmlSubstitutionObject::setPropertyData()
{
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, PropertyClassRole, QStringLiteral("QUmlSubstitution"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, DocumentationRole, QStringLiteral("The contract with which the substituting classifier complies."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, SubsettedPropertiesRole, QStringLiteral("Dependency-supplier"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, contract, OppositeEndRole, QStringLiteral(""));

    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, AggregationRole, QStringLiteral("none"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, PropertyClassRole, QStringLiteral("QUmlSubstitution"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, IsDerivedRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, IsDerivedUnionRole, false);
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, DocumentationRole, QStringLiteral("Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected."));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, RedefinedPropertiesRole, QStringLiteral(""));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, SubsettedPropertiesRole, QStringLiteral("Element-owner Dependency-client"));
    Q_DECLARE_METAPROPERTY_INFO(QUmlSubstitution, substitutingClassifier, OppositeEndRole, QStringLiteral("Classifier-substitution"));

}

QT_END_NAMESPACE

