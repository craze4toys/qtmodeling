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
#include "qumlinterval.h"

#include "private/qumlintervalobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlType>
#include <QtUml/QUmlValueSpecification>

/*!
    \class QUmlInterval

    \inmodule QtUml

    \brief An interval defines the range between two value specifications.
 */
QUmlInterval::QUmlInterval(bool createQObject) :
    _max(0),
    _min(0)
{
    if (createQObject)
        _qObject = new QUmlIntervalObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlInterval::~QUmlInterval()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlInterval::clone() const
{
    QUmlInterval *c = new QUmlInterval;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    if (type())
        c->setType(dynamic_cast<QUmlType *>(type()->clone()));
    if (owningTemplateParameter())
        c->setOwningTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(owningTemplateParameter()->clone()));
    if (templateParameter())
        c->setTemplateParameter(dynamic_cast<QUmlTemplateParameter *>(templateParameter()->clone()));
    c->setVisibility(visibility());
    if (max())
        c->setMax(dynamic_cast<QUmlValueSpecification *>(max()->clone()));
    if (min())
        c->setMin(dynamic_cast<QUmlValueSpecification *>(min()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Refers to the ValueSpecification denoting the maximum value of the range.
 */
QUmlValueSpecification *QUmlInterval::max() const
{
    // This is a read-write association end

    return _max;
}

void QUmlInterval::setMax(QUmlValueSpecification *max)
{
    // This is a read-write association end

    if (_max != max) {
        _max = max;
        if (max && max->asQObject() && this->asQObject())
            QObject::connect(max->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setMax()));
    }
}

/*!
    Refers to the ValueSpecification denoting the minimum value of the range.
 */
QUmlValueSpecification *QUmlInterval::min() const
{
    // This is a read-write association end

    return _min;
}

void QUmlInterval::setMin(QUmlValueSpecification *min)
{
    // This is a read-write association end

    if (_min != min) {
        _min = min;
        if (min && min->asQObject() && this->asQObject())
            QObject::connect(min->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setMin()));
    }
}

void QUmlInterval::setGroupProperties()
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
    _groupProperties.insert(QStringLiteral("QUmlTypedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("type"))));
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("owningTemplateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlParameterableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("templateParameter"))));
    _groupProperties.insert(QStringLiteral("QUmlPackageableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));
    _groupProperties.insert(QStringLiteral("QUmlInterval"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("max"))));
    _groupProperties.insert(QStringLiteral("QUmlInterval"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("min"))));
}

void QUmlInterval::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInterval");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::DocumentationRole] = QStringLiteral("Refers to the ValueSpecification denoting the maximum value of the range.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("max")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlInterval");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::DocumentationRole] = QStringLiteral("Refers to the ValueSpecification denoting the minimum value of the range.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlInterval")][QStringLiteral("min")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

