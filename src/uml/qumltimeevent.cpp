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
#include "qumltimeevent.h"

#include "private/qumltimeeventobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlTimeExpression>

/*!
    \class QUmlTimeEvent

    \inmodule QtUml

    \brief A time event can be defined relative to entering the current state of the executing state machine.A time event specifies a point in time. At the specified time, the event occurs.
 */
QUmlTimeEvent::QUmlTimeEvent(bool createQObject) :
    _isRelative(false),
    _when(0)
{
    if (createQObject)
        _qObject = new QUmlTimeEventObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlTimeEvent::~QUmlTimeEvent()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlTimeEvent::clone() const
{
    QUmlTimeEvent *c = new QUmlTimeEvent;
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
    c->setRelative(isRelative());
    if (when())
        c->setWhen(dynamic_cast<QUmlTimeExpression *>(when()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies whether it is relative or absolute time.
 */
bool QUmlTimeEvent::isRelative() const
{
    // This is a read-write property

    return _isRelative;
}

void QUmlTimeEvent::setRelative(bool isRelative)
{
    // This is a read-write property

    if (_isRelative != isRelative) {
        _isRelative = isRelative;
        _modifiedResettableProperties << QStringLiteral("isRelative");
    }
}

/*!
    Specifies the corresponding time deadline.
 */
QUmlTimeExpression *QUmlTimeEvent::when() const
{
    // This is a read-write association end

    return _when;
}

void QUmlTimeEvent::setWhen(QUmlTimeExpression *when)
{
    // This is a read-write association end

    if (_when != when) {
        // Adjust subsetted properties
        removeOwnedElement(_when);

        _when = when;
        if (when && when->asQObject() && this->asQObject())
            QObject::connect(when->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setWhen()));
        when->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (when) {
            addOwnedElement(when);
        }
    }
}

void QUmlTimeEvent::setGroupProperties()
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
    _groupProperties.insert(QStringLiteral("QUmlTimeEvent"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isRelative"))));
    _groupProperties.insert(QStringLiteral("QUmlTimeEvent"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("when"))));
}

void QUmlTimeEvent::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlTimeEvent");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::DocumentationRole] = QStringLiteral("Specifies whether it is relative or absolute time.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("isRelative")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlTimeEvent");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::DocumentationRole] = QStringLiteral("Specifies the corresponding time deadline.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlTimeEvent")][QStringLiteral("when")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

