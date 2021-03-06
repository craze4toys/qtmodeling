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
#include "qumlextensionend.h"

#include "private/qumlextensionendobject_p.h"

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
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStereotype>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlType>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlExtensionEnd

    \inmodule QtUml

    \brief An extension end is used to tie an extension to a stereotype when extending a metaclass.The default multiplicity of an extension end is 0..1.
 */

/*!
    Creates a new QUmlExtensionEnd. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlExtensionEnd::QUmlExtensionEnd(bool createQModelingObject) :
    QUmlProperty(false),
    _type(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlExtensionEndObject(this));
}

/*!
    Destroys the QUmlExtensionEnd.
 */
QUmlExtensionEnd::~QUmlExtensionEnd()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlExtensionEnd.
*/
QModelingElement *QUmlExtensionEnd::clone() const
{
    QUmlExtensionEnd *c = new QUmlExtensionEnd;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setOrdered(isOrdered());
    c->setUnique(isUnique());
    if (lowerValue())
        c->setLowerValue(dynamic_cast<QUmlValueSpecification *>(lowerValue()->clone()));
    if (upperValue())
        c->setUpperValue(dynamic_cast<QUmlValueSpecification *>(upperValue()->clone()));
    c->setLeaf(isLeaf());
    c->setStatic(isStatic());
    foreach (QUmlDeployment *element, deployments())
        c->addDeployment(dynamic_cast<QUmlDeployment *>(element->clone()));
    c->setAggregation(aggregation());
    if (defaultValue())
        c->setDefaultValue(dynamic_cast<QUmlValueSpecification *>(defaultValue()->clone()));
    c->setDerived(isDerived());
    c->setDerivedUnion(isDerivedUnion());
    c->setID(isID());
    c->setReadOnly(isReadOnly());
    foreach (QUmlProperty *element, qualifiers())
        c->addQualifier(dynamic_cast<QUmlProperty *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    This redefinition changes the default multiplicity of association ends, since model elements are usually extended by 0 or 1 instance of the extension stereotype.

    \b {This is a derived property.}

    \b {Redefined property(ies):} QUmlMultiplicityElement::lower().
 */
int QUmlExtensionEnd::lower() const
{
    // This is a read-write derived property

    qWarning("QUmlExtensionEnd::lower(): to be implemented (this is a derived property)");

    return int();
}

/*!
    Adjusts lower to \a lower.
 */
void QUmlExtensionEnd::setLower(int lower)
{
    // This is a read-write derived property

    qWarning("QUmlExtensionEnd::setLower(): to be implemented (this is a derived property)");
    Q_UNUSED(lower);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>

        // Adjust redefined properties
        QUmlMultiplicityElement::setLower(lower);
    }
}

/*!
    References the type of the ExtensionEnd. Note that this association restricts the possible types of an ExtensionEnd to only be Stereotypes.

    \b {Redefined property(ies):} QUmlTypedElement::type().
 */
QUmlStereotype *QUmlExtensionEnd::type() const
{
    // This is a read-write association end

    return _type;
}

/*!
    Adjusts type to \a type.
 */
void QUmlExtensionEnd::setType(QUmlStereotype *type)
{
    // This is a read-write association end

    if (_type != type) {
        _type = type;
        if (type && type->asQModelingObject() && this->asQModelingObject())
            QObject::connect(type->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setType()));

        // Adjust redefined properties
        QUmlTypedElement::setType(type);
    }
}

// OPERATIONS

/*!
    The query lowerBound() returns the lower bound of the multiplicity as an Integer. This is a redefinition of the default lower bound, which normally, for MultiplicityElements, evaluates to 1 if empty.
 */
int QUmlExtensionEnd::lowerBound() const
{
    qWarning("QUmlExtensionEnd::lowerBound(): to be implemented (operation)");

    return int ();
}

QT_END_NAMESPACE

