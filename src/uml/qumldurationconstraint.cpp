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
#include "qumldurationconstraint.h"

#include "private/qumldurationconstraintobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlDurationInterval>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInterval>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlValueSpecification>

/*!
    \class QUmlDurationConstraint

    \inmodule QtUml

    \brief A duration constraint is a constraint that refers to a duration interval.
 */
QUmlDurationConstraint::QUmlDurationConstraint(bool createQObject) :
    QUmlIntervalConstraint(false),
    _specification(0)
{
    if (createQObject)
        _qObject = new QUmlDurationConstraintObject(this);
    setPropertyData();
}

QUmlDurationConstraint::~QUmlDurationConstraint()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlDurationConstraint::clone() const
{
    QUmlDurationConstraint *c = new QUmlDurationConstraint;
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
    foreach (QUmlElement *element, constrainedElements())
        c->addConstrainedElement(dynamic_cast<QUmlElement *>(element->clone()));
    if (context())
        c->setContext(dynamic_cast<QUmlNamespace *>(context()->clone()));
    c->setFirstEvent(firstEvent());
    if (specification())
        c->setSpecification(dynamic_cast<QUmlDurationInterval *>(specification()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The value of firstEvent[i] is related to constrainedElement[i] (where i is 1 or 2). If firstEvent[i] is true, then the corresponding observation event is the first time instant the execution enters constrainedElement[i]. If firstEvent[i] is false, then the corresponding observation event is the last time instant the execution is within constrainedElement[i]. Default value is true applied when constrainedElement[i] refers an element that represents only one time instant.
 */
bool QUmlDurationConstraint::firstEvent() const
{
    // This is a read-write property

    return _firstEvent;
}

void QUmlDurationConstraint::setFirstEvent(bool firstEvent)
{
    // This is a read-write property

    if (_firstEvent != firstEvent) {
        _firstEvent = firstEvent;
    }
}

/*!
    The interval constraining the duration.
 */
QUmlDurationInterval *QUmlDurationConstraint::specification() const
{
    // This is a read-write association end

    return _specification;
}

void QUmlDurationConstraint::setSpecification(QUmlDurationInterval *specification)
{
    // This is a read-write association end

    if (_specification != specification) {
        _specification = specification;
        if (specification && specification->asQObject() && this->asQObject())
            QObject::connect(specification->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setSpecification()));
        specification->asQObject()->setParent(this->asQObject());
    }
}

void QUmlDurationConstraint::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlDurationConstraint");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::DocumentationRole] = QStringLiteral("The value of firstEvent[i] is related to constrainedElement[i] (where i is 1 or 2). If firstEvent[i] is true, then the corresponding observation event is the first time instant the execution enters constrainedElement[i]. If firstEvent[i] is false, then the corresponding observation event is the last time instant the execution is within constrainedElement[i]. Default value is true applied when constrainedElement[i] refers an element that represents only one time instant.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("firstEvent")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlDurationConstraint");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::DocumentationRole] = QStringLiteral("The interval constraining the duration.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("IntervalConstraint-specification");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlDurationConstraint")][QStringLiteral("specification")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

void QUmlDurationConstraint::setClassForProperty()
{
    _classForProperty[QStringLiteral("ownedComments")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("ownedElements")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("owner")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("owningTemplateParameter")] = QStringLiteral("QUmlParameterableElement");
    _classForProperty[QStringLiteral("templateParameter")] = QStringLiteral("QUmlParameterableElement");
    _classForProperty[QStringLiteral("clientDependencies")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("name")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("nameExpression")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("namespace_")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("qualifiedName")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("visibility")] = QStringLiteral("QUmlPackageableElement");
    _classForProperty[QStringLiteral("constrainedElements")] = QStringLiteral("QUmlConstraint");
    _classForProperty[QStringLiteral("context")] = QStringLiteral("QUmlConstraint");
    _classForProperty[QStringLiteral("firstEvent")] = QStringLiteral("QUmlDurationConstraint");
    _classForProperty[QStringLiteral("specification")] = QStringLiteral("QUmlDurationConstraint");
}

