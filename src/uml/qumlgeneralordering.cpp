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
#include "qumlgeneralordering.h"

#include "private/qumlgeneralorderingobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOccurrenceSpecification>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlStringExpression>

/*!
    \class QUmlGeneralOrdering

    \inmodule QtUml

    \brief A general ordering represents a binary relation between two occurrence specifications, to describe that one occurrence specification must occur before the other in a valid trace. This mechanism provides the ability to define partial orders of occurrence cpecifications that may otherwise not have a specified order.
 */
QUmlGeneralOrdering::QUmlGeneralOrdering(bool createQModelingObject) :
    _after(0),
    _before(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlGeneralOrderingObject(this));
}

QUmlGeneralOrdering::~QUmlGeneralOrdering()
{
    if (!deletingFromQModelingObject) {
        if (_qModelingObject)
            _qModelingObject->setProperty("deletingFromModelingObject", true);
        delete _qModelingObject;
    }
}

QModelingElement *QUmlGeneralOrdering::clone() const
{
    QUmlGeneralOrdering *c = new QUmlGeneralOrdering;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    if (after())
        c->setAfter(dynamic_cast<QUmlOccurrenceSpecification *>(after()->clone()));
    if (before())
        c->setBefore(dynamic_cast<QUmlOccurrenceSpecification *>(before()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The OccurrenceSpecification referenced comes after the OccurrenceSpecification referenced by before.
 */
QUmlOccurrenceSpecification *QUmlGeneralOrdering::after() const
{
    // This is a read-write association end

    return _after;
}

void QUmlGeneralOrdering::setAfter(QUmlOccurrenceSpecification *after)
{
    // This is a read-write association end

    if (_after != after) {
        _after = after;
        if (after && after->asQModelingObject() && this->asQModelingObject())
            QObject::connect(after->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setAfter()));
    }
}

/*!
    The OccurrenceSpecification referenced comes before the OccurrenceSpecification referenced by after.
 */
QUmlOccurrenceSpecification *QUmlGeneralOrdering::before() const
{
    // This is a read-write association end

    return _before;
}

void QUmlGeneralOrdering::setBefore(QUmlOccurrenceSpecification *before)
{
    // This is a read-write association end

    if (_before != before) {
        _before = before;
        if (before && before->asQModelingObject() && this->asQModelingObject())
            QObject::connect(before->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setBefore()));
    }
}

