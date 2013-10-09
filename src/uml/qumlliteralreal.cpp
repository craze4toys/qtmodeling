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
#include "qumlliteralreal.h"

#include "private/qumlliteralrealobject_p.h"

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

/*!
    \class QUmlLiteralReal

    \inmodule QtUml

    \brief A literal real is a specification of a real value.
 */
QUmlLiteralReal::QUmlLiteralReal(bool createQObject)
{
    if (createQObject)
        _qObject = new QUmlLiteralRealObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlLiteralReal::~QUmlLiteralReal()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlLiteralReal::clone() const
{
    QUmlLiteralReal *c = new QUmlLiteralReal;
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
    c->setValue(value());
    return c;
}

// OWNED ATTRIBUTES

double QUmlLiteralReal::value() const
{
    // This is a read-write property

    return _value;
}

void QUmlLiteralReal::setValue(double value)
{
    // This is a read-write property

    if (_value != value) {
        _value = value;
    }
}

// OPERATIONS

/*!
    The query isComputable() is redefined to be true.
 */
bool QUmlLiteralReal::isComputable() const
{
    qWarning("UmlLiteralReal::isComputable(): to be implemented (operation)");

    return bool ();
}

/*!
    The query realValue() gives the value.
 */
double QUmlLiteralReal::realValue() const
{
    qWarning("UmlLiteralReal::realValue(): to be implemented (operation)");

    return double ();
}

void QUmlLiteralReal::setGroupProperties()
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
    _groupProperties.insert(QStringLiteral("QUmlLiteralReal"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("value"))));
}

void QUmlLiteralReal::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLiteralReal");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::DocumentationRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLiteralReal")][QStringLiteral("value")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

