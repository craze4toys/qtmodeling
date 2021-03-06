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
#include "qumlmanifestation.h"

#include "private/qumlmanifestationobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOpaqueExpression>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTemplateParameter>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlManifestation

    \inmodule QtUml

    \brief A manifestation is the concrete physical rendering of one or more model elements by an artifact.
 */

/*!
    Creates a new QUmlManifestation. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlManifestation::QUmlManifestation(bool createQModelingObject) :
    QUmlAbstraction(false),
    _utilizedElement(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlManifestationObject(this));
}

/*!
    Destroys the QUmlManifestation.
 */
QUmlManifestation::~QUmlManifestation()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlManifestation.
*/
QModelingElement *QUmlManifestation::clone() const
{
    QUmlManifestation *c = new QUmlManifestation;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    if (mapping())
        c->setMapping(dynamic_cast<QUmlOpaqueExpression *>(mapping()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The model element that is utilized in the manifestation in an Artifact.

    \b {Subsetted property(ies):} QUmlDependency::suppliers().
 */
QUmlPackageableElement *QUmlManifestation::utilizedElement() const
{
    // This is a read-write association end

    return _utilizedElement;
}

/*!
    Adjusts utilizedElement to \a utilizedElement.
 */
void QUmlManifestation::setUtilizedElement(QUmlPackageableElement *utilizedElement)
{
    // This is a read-write association end

    if (_utilizedElement != utilizedElement) {
        // Adjust subsetted properties
        removeSupplier(_utilizedElement);

        _utilizedElement = utilizedElement;
        if (utilizedElement && utilizedElement->asQModelingObject() && this->asQModelingObject())
            QObject::connect(utilizedElement->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setUtilizedElement()));

        // Adjust subsetted properties
        if (utilizedElement) {
            addSupplier(utilizedElement);
        }
    }
}

QT_END_NAMESPACE

