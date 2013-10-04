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
#include "qumlopaqueexpressionobject_p.h"

#include <QtUml/QUmlOpaqueExpression>
#include <QtUml/QUmlBehavior>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlParameter>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlType>

QT_BEGIN_NAMESPACE

QUmlOpaqueExpressionObject::QUmlOpaqueExpressionObject(QUmlOpaqueExpression *qModelingObject)
{
    setProperty("modelingObject", QVariant::fromValue(qModelingObject));
}

QUmlOpaqueExpressionObject::~QUmlOpaqueExpressionObject()
{
    if (!property("deletingFromModelingObject").isValid()) {
        qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->deletingFromQObject = true;
        delete qmodelingobjectproperty_cast<QUmlComment *>(this);
    }
}

// OWNED ATTRIBUTES [Element]

const QSet<QObject *> QUmlOpaqueExpressionObject::ownedComment() const
{
    QSet<QObject *> set;
    foreach (QUmlComment *element, qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->ownedComment())
        set.insert(element->asQObject());
    return set;
}

const QSet<QObject *> QUmlOpaqueExpressionObject::ownedElement() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->ownedElement())
        set.insert(element->asQObject());
    return set;
}

QObject *QUmlOpaqueExpressionObject::owner() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->owner())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->owner()->asQObject();
}

// OWNED ATTRIBUTES [NamedElement]

const QSet<QObject *> QUmlOpaqueExpressionObject::clientDependency() const
{
    QSet<QObject *> set;
    foreach (QUmlDependency *element, qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->clientDependency())
        set.insert(element->asQObject());
    return set;
}

QString QUmlOpaqueExpressionObject::name() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->name();
}

QObject *QUmlOpaqueExpressionObject::nameExpression() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->nameExpression())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->nameExpression()->asQObject();
}

QObject *QUmlOpaqueExpressionObject::namespace_() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->namespace_())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->namespace_()->asQObject();
}

QString QUmlOpaqueExpressionObject::qualifiedName() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->qualifiedName();
}
// OWNED ATTRIBUTES [TypedElement]

QObject *QUmlOpaqueExpressionObject::type() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->type())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->type()->asQObject();
}

// OWNED ATTRIBUTES [ParameterableElement]

QObject *QUmlOpaqueExpressionObject::owningTemplateParameter() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->owningTemplateParameter())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->owningTemplateParameter()->asQObject();
}

QObject *QUmlOpaqueExpressionObject::templateParameter() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->templateParameter())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->templateParameter()->asQObject();
}

// OWNED ATTRIBUTES [PackageableElement]

QtUml::VisibilityKind QUmlOpaqueExpressionObject::visibility() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->visibility();
}

// OWNED ATTRIBUTES [OpaqueExpression]

QObject *QUmlOpaqueExpressionObject::behavior() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->behavior())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->behavior()->asQObject();
}

const QList<QString> QUmlOpaqueExpressionObject::body() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->body();
}

const QList<QString> QUmlOpaqueExpressionObject::language() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->language();
}

QObject *QUmlOpaqueExpressionObject::result() const
{
    if (!qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->result())
        return 0;
    else
        return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->result()->asQObject();
}

// OPERATIONS [Element]

QSet<QObject *> QUmlOpaqueExpressionObject::allOwnedElements() const
{
    QSet<QObject *> set;
    foreach (QUmlElement *element, qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->allOwnedElements())
        set.insert(element->asQObject());
    return set;
}

bool QUmlOpaqueExpressionObject::mustBeOwned() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->mustBeOwned();
}

// OPERATIONS [NamedElement]

QList<QObject *> QUmlOpaqueExpressionObject::allNamespaces() const
{
    QList<QObject *> set;
    foreach (QUmlNamespace *element, qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->allNamespaces())
        set.append(element->asQObject());
    return set;
}

QSet<QObject *> QUmlOpaqueExpressionObject::allOwningPackages() const
{
    QSet<QObject *> set;
    foreach (QUmlPackage *element, qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->allOwningPackages())
        set.insert(element->asQObject());
    return set;
}

bool QUmlOpaqueExpressionObject::isDistinguishableFrom(QObject *n, QObject *ns) const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isDistinguishableFrom(qmodelingobjectproperty_cast<QUmlNamedElement *>(n), qmodelingobjectproperty_cast<QUmlNamespace *>(ns));
}

QString QUmlOpaqueExpressionObject::separator() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->separator();
}

// OPERATIONS [ParameterableElement]

bool QUmlOpaqueExpressionObject::isTemplateParameter() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isTemplateParameter();
}

// OPERATIONS [ValueSpecification]

bool QUmlOpaqueExpressionObject::booleanValue() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->booleanValue();
}

int QUmlOpaqueExpressionObject::integerValue() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->integerValue();
}

bool QUmlOpaqueExpressionObject::isCompatibleWith(QObject *p) const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isCompatibleWith(qmodelingobjectproperty_cast<QUmlParameterableElement *>(p));
}

bool QUmlOpaqueExpressionObject::isComputable() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isComputable();
}

bool QUmlOpaqueExpressionObject::isNull() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isNull();
}

double QUmlOpaqueExpressionObject::realValue() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->realValue();
}

QString QUmlOpaqueExpressionObject::stringValue() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->stringValue();
}

int QUmlOpaqueExpressionObject::unlimitedValue() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->unlimitedValue();
}

// OPERATIONS [OpaqueExpression]

bool QUmlOpaqueExpressionObject::isIntegral() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isIntegral();
}

bool QUmlOpaqueExpressionObject::isNonNegative() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isNonNegative();
}

bool QUmlOpaqueExpressionObject::isPositive() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->isPositive();
}

int QUmlOpaqueExpressionObject::value() const
{
    return qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->value();
}

// SLOTS FOR OWNED ATTRIBUTES [Element]

void QUmlOpaqueExpressionObject::addOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->addOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlOpaqueExpressionObject::removeOwnedComment(QObject *ownedComment)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->removeOwnedComment(qmodelingobjectproperty_cast<QUmlComment *>(ownedComment));
}

void QUmlOpaqueExpressionObject::addOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->addOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlOpaqueExpressionObject::removeOwnedElement(QObject *ownedElement)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->removeOwnedElement(qmodelingobjectproperty_cast<QUmlElement *>(ownedElement));
}

void QUmlOpaqueExpressionObject::setOwner(QObject *owner)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setOwner(qmodelingobjectproperty_cast<QUmlElement *>(owner));
}

// SLOTS FOR OWNED ATTRIBUTES [NamedElement]

void QUmlOpaqueExpressionObject::addClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->addClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlOpaqueExpressionObject::removeClientDependency(QObject *clientDependency)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->removeClientDependency(qmodelingobjectproperty_cast<QUmlDependency *>(clientDependency));
}

void QUmlOpaqueExpressionObject::setName(QString name)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setName(name);
}

void QUmlOpaqueExpressionObject::setNameExpression(QObject *nameExpression)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setNameExpression(qmodelingobjectproperty_cast<QUmlStringExpression *>(nameExpression));
}

void QUmlOpaqueExpressionObject::setNamespace(QObject *namespace_)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setNamespace(qmodelingobjectproperty_cast<QUmlNamespace *>(namespace_));
}

void QUmlOpaqueExpressionObject::setQualifiedName(QString qualifiedName)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setQualifiedName(qualifiedName);
}
// SLOTS FOR OWNED ATTRIBUTES [TypedElement]

void QUmlOpaqueExpressionObject::setType(QObject *type)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setType(qmodelingobjectproperty_cast<QUmlType *>(type));
}

// SLOTS FOR OWNED ATTRIBUTES [ParameterableElement]

void QUmlOpaqueExpressionObject::setOwningTemplateParameter(QObject *owningTemplateParameter)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setOwningTemplateParameter(qmodelingobjectproperty_cast<QUmlTemplateParameter *>(owningTemplateParameter));
}

void QUmlOpaqueExpressionObject::setTemplateParameter(QObject *templateParameter)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setTemplateParameter(qmodelingobjectproperty_cast<QUmlTemplateParameter *>(templateParameter));
}

// SLOTS FOR OWNED ATTRIBUTES [PackageableElement]

void QUmlOpaqueExpressionObject::setVisibility(QtUml::VisibilityKind visibility)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setVisibility(visibility);
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->modifiedResettableProperties() << QStringLiteral("visibility");
}

void QUmlOpaqueExpressionObject::unsetVisibility()
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->modifiedResettableProperties().removeAll(QStringLiteral("visibility"));
}

// SLOTS FOR OWNED ATTRIBUTES [OpaqueExpression]

void QUmlOpaqueExpressionObject::setBehavior(QObject *behavior)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setBehavior(qmodelingobjectproperty_cast<QUmlBehavior *>(behavior));
}

void QUmlOpaqueExpressionObject::addBody(QString  body)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->addBody(body);
}

void QUmlOpaqueExpressionObject::removeBody(QString  body)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->removeBody(body);
}

void QUmlOpaqueExpressionObject::addLanguage(QString  language)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->addLanguage(language);
}

void QUmlOpaqueExpressionObject::removeLanguage(QString  language)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->removeLanguage(language);
}

void QUmlOpaqueExpressionObject::setResult(QObject *result)
{
    qmodelingobjectproperty_cast<QUmlOpaqueExpression *>(this)->setResult(qmodelingobjectproperty_cast<QUmlParameter *>(result));
}

QT_END_NAMESPACE

