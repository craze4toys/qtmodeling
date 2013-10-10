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
#include "qumldurationinterval.h"

#include "private/qumldurationintervalobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlDuration>
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
    \class QUmlDurationInterval

    \inmodule QtUml

    \brief A duration interval defines the range between two durations.
 */
QUmlDurationInterval::QUmlDurationInterval(bool createQModelingObject) :
    QUmlInterval(false),
    _max(0),
    _min(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlDurationIntervalObject(this));
}

QUmlDurationInterval::~QUmlDurationInterval()
{
    if (!deletingFromQModelingObject) {
        if (_qModelingObject)
            _qModelingObject->setProperty("deletingFromModelingObject", true);
        delete _qModelingObject;
    }
}

QModelingElement *QUmlDurationInterval::clone() const
{
    QUmlDurationInterval *c = new QUmlDurationInterval;
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
        c->setMax(dynamic_cast<QUmlDuration *>(max()->clone()));
    if (min())
        c->setMin(dynamic_cast<QUmlDuration *>(min()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Refers to the Duration denoting the maximum value of the range.
 */
QUmlDuration *QUmlDurationInterval::max() const
{
    // This is a read-write association end

    return _max;
}

void QUmlDurationInterval::setMax(QUmlDuration *max)
{
    // This is a read-write association end

    if (_max != max) {
        _max = max;
        if (max && max->asQModelingObject() && this->asQModelingObject())
            QObject::connect(max->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setMax()));
    }
}

/*!
    Refers to the Duration denoting the minimum value of the range.
 */
QUmlDuration *QUmlDurationInterval::min() const
{
    // This is a read-write association end

    return _min;
}

void QUmlDurationInterval::setMin(QUmlDuration *min)
{
    // This is a read-write association end

    if (_min != min) {
        _min = min;
        if (min && min->asQModelingObject() && this->asQModelingObject())
            QObject::connect(min->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setMin()));
    }
}

