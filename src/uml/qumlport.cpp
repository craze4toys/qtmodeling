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
#include "qumlport.h"

#include "private/qumlportobject_p.h"

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
#include <QtUml/QUmlProtocolStateMachine>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlType>
#include <QtUml/QUmlValueSpecification>

/*!
    \class QUmlPort

    \inmodule QtUml

    \brief A port has an associated protocol state machine.A port is a property of a classifier that specifies a distinct interaction point between that classifier and its environment or between the (behavior of the) classifier and its internal parts. Ports are connected to properties of the classifier by connectors through which requests can be made to invoke the behavioral features of a classifier. A Port may specify the services a classifier provides (offers) to its environment as well as the services that a classifier expects (requires) of its environment.
 */
QUmlPort::QUmlPort(bool createQObject) :
    QUmlProperty(false),
    _isBehavior(false),
    _isConjugated(false),
    _isService(true),
    _protocol(0)
{
    if (createQObject)
        _qObject = new QUmlPortObject(this);
    setClassForProperty();
    setPropertyData();
}

QUmlPort::~QUmlPort()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlPort::clone() const
{
    QUmlPort *c = new QUmlPort;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    if (type())
        c->setType(dynamic_cast<QUmlType *>(type()->clone()));
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
    c->setBehavior(isBehavior());
    c->setConjugated(isConjugated());
    c->setService(isService());
    if (protocol())
        c->setProtocol(dynamic_cast<QUmlProtocolStateMachine *>(protocol()->clone()));
    foreach (QUmlPort *element, redefinedPorts())
        c->addRedefinedPort(dynamic_cast<QUmlPort *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies whether requests arriving at this port are sent to the classifier behavior of this classifier. Such ports are referred to as behavior port. Any invocation of a behavioral feature targeted at a behavior port will be handled by the instance of the owning classifier itself, rather than by any instances that this classifier may contain.
 */
bool QUmlPort::isBehavior() const
{
    // This is a read-write property

    return _isBehavior;
}

void QUmlPort::setBehavior(bool isBehavior)
{
    // This is a read-write property

    if (_isBehavior != isBehavior) {
        _isBehavior = isBehavior;
        _modifiedResettableProperties << QStringLiteral("isBehavior");
    }
}

/*!
    Specifies the way that the provided and required interfaces are derived from the Port’s Type. The default value is false.
 */
bool QUmlPort::isConjugated() const
{
    // This is a read-write property

    return _isConjugated;
}

void QUmlPort::setConjugated(bool isConjugated)
{
    // This is a read-write property

    if (_isConjugated != isConjugated) {
        _isConjugated = isConjugated;
        _modifiedResettableProperties << QStringLiteral("isConjugated");
    }
}

/*!
    If true indicates that this port is used to provide the published functionality of a classifier; if false, this port is used to implement the classifier but is not part of the essential externally-visible functionality of the classifier and can, therefore, be altered or deleted along with the internal implementation of the classifier and other properties that are considered part of its implementation.
 */
bool QUmlPort::isService() const
{
    // This is a read-write property

    return _isService;
}

void QUmlPort::setService(bool isService)
{
    // This is a read-write property

    if (_isService != isService) {
        _isService = isService;
        _modifiedResettableProperties << QStringLiteral("isService");
    }
}

/*!
    References an optional protocol state machine which describes valid interactions at this interaction point.
 */
QUmlProtocolStateMachine *QUmlPort::protocol() const
{
    // This is a read-write association end

    return _protocol;
}

void QUmlPort::setProtocol(QUmlProtocolStateMachine *protocol)
{
    // This is a read-write association end

    if (_protocol != protocol) {
        _protocol = protocol;
        if (protocol && protocol->asQObject() && this->asQObject())
            QObject::connect(protocol->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setProtocol()));
    }
}

/*!
    References the interfaces specifying the set of operations and receptions that the classifier offers to its environment via this port, and which it will handle either directly or by forwarding it to a part of its internal structure. This association is derived according to the value of isConjugated. If isConjugated is false, provided is derived as the union of the sets of interfaces realized by the type of the port and its supertypes, or directly from the type of the port if the port is typed by an interface. If isConjugated is true, it is derived as the union of the sets of interfaces used by the type of the port and its supertypes.
 */
const QSet<QUmlInterface *> QUmlPort::provided() const
{
    // This is a read-only derived association end

    qWarning("UmlPort::provided(): to be implemented (this is a derived association end)");

    return QSet<QUmlInterface *>();
}

void QUmlPort::addProvided(QUmlInterface *provided)
{
    // This is a read-only derived association end

    qWarning("UmlPort::addProvided(): to be implemented (this is a derived association end)");
    Q_UNUSED(provided);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void QUmlPort::removeProvided(QUmlInterface *provided)
{
    // This is a read-only derived association end

    qWarning("UmlPort::removeProvided(): to be implemented (this is a derived association end)");
    Q_UNUSED(provided);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    A port may be redefined when its containing classifier is specialized. The redefining port may have additional interfaces to those that are associated with the redefined port or it may replace an interface by one of its subtypes.
 */
const QSet<QUmlPort *> QUmlPort::redefinedPorts() const
{
    // This is a read-write association end

    return _redefinedPorts;
}

void QUmlPort::addRedefinedPort(QUmlPort *redefinedPort)
{
    // This is a read-write association end

    if (!_redefinedPorts.contains(redefinedPort)) {
        _redefinedPorts.insert(redefinedPort);
        if (redefinedPort && redefinedPort->asQObject() && this->asQObject())
            QObject::connect(redefinedPort->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRedefinedPort(QObject *)));

        // Adjust subsetted properties
        addRedefinedProperty(redefinedPort);
    }
}

void QUmlPort::removeRedefinedPort(QUmlPort *redefinedPort)
{
    // This is a read-write association end

    if (_redefinedPorts.contains(redefinedPort)) {
        _redefinedPorts.remove(redefinedPort);

        // Adjust subsetted properties
        removeRedefinedProperty(redefinedPort);
    }
}

/*!
    References the interfaces specifying the set of operations and receptions that the classifier expects its environment to handle via this port. This association is derived according to the value of isConjugated. If isConjugated is false, required is derived as the union of the sets of interfaces used by the type of the port and its supertypes. If isConjugated is true, it is derived as the union of the sets of interfaces realized by the type of the port and its supertypes, or directly from the type of the port if the port is typed by an interface.
 */
const QSet<QUmlInterface *> QUmlPort::required() const
{
    // This is a read-only derived association end

    qWarning("UmlPort::required(): to be implemented (this is a derived association end)");

    return QSet<QUmlInterface *>();
}

void QUmlPort::addRequired(QUmlInterface *required)
{
    // This is a read-only derived association end

    qWarning("UmlPort::addRequired(): to be implemented (this is a derived association end)");
    Q_UNUSED(required);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void QUmlPort::removeRequired(QUmlInterface *required)
{
    // This is a read-only derived association end

    qWarning("UmlPort::removeRequired(): to be implemented (this is a derived association end)");
    Q_UNUSED(required);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

void QUmlPort::setClassForProperty()
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
    _classForProperty[QStringLiteral("type")] = QStringLiteral("QUmlTypedElement");
    _classForProperty[QStringLiteral("isOrdered")] = QStringLiteral("QUmlMultiplicityElement");
    _classForProperty[QStringLiteral("isUnique")] = QStringLiteral("QUmlMultiplicityElement");
    _classForProperty[QStringLiteral("lower")] = QStringLiteral("QUmlMultiplicityElement");
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
    _classForProperty[QStringLiteral("isBehavior")] = QStringLiteral("QUmlPort");
    _classForProperty[QStringLiteral("isConjugated")] = QStringLiteral("QUmlPort");
    _classForProperty[QStringLiteral("isService")] = QStringLiteral("QUmlPort");
    _classForProperty[QStringLiteral("protocol")] = QStringLiteral("QUmlPort");
    _classForProperty[QStringLiteral("provided")] = QStringLiteral("QUmlPort");
    _classForProperty[QStringLiteral("redefinedPorts")] = QStringLiteral("QUmlPort");
    _classForProperty[QStringLiteral("required")] = QStringLiteral("QUmlPort");
}

void QUmlPort::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlPort");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::DocumentationRole] = QStringLiteral("Specifies whether requests arriving at this port are sent to the classifier behavior of this classifier. Such ports are referred to as behavior port. Any invocation of a behavioral feature targeted at a behavior port will be handled by the instance of the owning classifier itself, rather than by any instances that this classifier may contain.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isBehavior")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlPort");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::DocumentationRole] = QStringLiteral("Specifies the way that the provided and required interfaces are derived from the Port’s Type. The default value is false.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isConjugated")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlPort");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::DocumentationRole] = QStringLiteral("If true indicates that this port is used to provide the published functionality of a classifier; if false, this port is used to implement the classifier but is not part of the essential externally-visible functionality of the classifier and can, therefore, be altered or deleted along with the internal implementation of the classifier and other properties that are considered part of its implementation.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("isService")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlPort");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::DocumentationRole] = QStringLiteral("References an optional protocol state machine which describes valid interactions at this interaction point.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("protocol")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlPort");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::DocumentationRole] = QStringLiteral("References the interfaces specifying the set of operations and receptions that the classifier offers to its environment via this port, and which it will handle either directly or by forwarding it to a part of its internal structure. This association is derived according to the value of isConjugated. If isConjugated is false, provided is derived as the union of the sets of interfaces realized by the type of the port and its supertypes, or directly from the type of the port if the port is typed by an interface. If isConjugated is true, it is derived as the union of the sets of interfaces used by the type of the port and its supertypes.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("provided")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlPort");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::DocumentationRole] = QStringLiteral("A port may be redefined when its containing classifier is specialized. The redefining port may have additional interfaces to those that are associated with the redefined port or it may replace an interface by one of its subtypes.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Property-redefinedProperty");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("redefinedPorts")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlPort");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::DocumentationRole] = QStringLiteral("References the interfaces specifying the set of operations and receptions that the classifier expects its environment to handle via this port. This association is derived according to the value of isConjugated. If isConjugated is false, required is derived as the union of the sets of interfaces used by the type of the port and its supertypes. If isConjugated is true, it is derived as the union of the sets of interfaces realized by the type of the port and its supertypes, or directly from the type of the port if the port is typed by an interface.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlPort")][QStringLiteral("required")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

