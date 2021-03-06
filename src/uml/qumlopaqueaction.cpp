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
#include "qumlopaqueaction.h"

#include "private/qumlopaqueactionobject_p.h"

#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlExceptionHandler>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOutputPin>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlOpaqueAction

    \inmodule QtUml

    \brief An action with implementation-specific semantics.
 */

/*!
    Creates a new QUmlOpaqueAction. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlOpaqueAction::QUmlOpaqueAction(bool createQModelingObject)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlOpaqueActionObject(this));
}

/*!
    Destroys the QUmlOpaqueAction.
 */
QUmlOpaqueAction::~QUmlOpaqueAction()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlOpaqueAction.
*/
QModelingElement *QUmlOpaqueAction::clone() const
{
    QUmlOpaqueAction *c = new QUmlOpaqueAction;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    foreach (QUmlExceptionHandler *element, handlers())
        c->addHandler(dynamic_cast<QUmlExceptionHandler *>(element->clone()));
    c->setLocallyReentrant(isLocallyReentrant());
    foreach (QUmlConstraint *element, localPostconditions())
        c->addLocalPostcondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlConstraint *element, localPreconditions())
        c->addLocalPrecondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QString element, bodies())
        c->addBody(element);
    foreach (QUmlInputPin *element, inputValues())
        c->addInputValue(dynamic_cast<QUmlInputPin *>(element->clone()));
    foreach (QString element, languages())
        c->addLanguage(element);
    foreach (QUmlOutputPin *element, outputValues())
        c->addOutputValue(dynamic_cast<QUmlOutputPin *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies the action in one or more languages.

    \sa addBody(), removeBody()
 */
const QList<QString> QUmlOpaqueAction::bodies() const
{
    // This is a read-write property

    return _bodies;
}

/*!
    Adds \a body to bodies.

    \sa bodies(), removeBody()
 */
void QUmlOpaqueAction::addBody(QString body)
{
    // This is a read-write property

    if (!_bodies.contains(body)) {
        _bodies.append(body);
    }
}

/*!
    Removes \a body from bodies.

    \sa bodies(), addBody()
 */
void QUmlOpaqueAction::removeBody(QString body)
{
    // This is a read-write property

    if (_bodies.contains(body)) {
        _bodies.removeAll(body);
    }
}

/*!
    Provides input to the action.

    \sa addInputValue(), removeInputValue()

    \b {Subsetted property(ies):} QUmlAction::inputs().
 */
const QSet<QUmlInputPin *> QUmlOpaqueAction::inputValues() const
{
    // This is a read-write association end

    return _inputValues;
}

/*!
    Adds \a inputValue to inputValues.

    \sa inputValues(), removeInputValue()
 */
void QUmlOpaqueAction::addInputValue(QUmlInputPin *inputValue)
{
    // This is a read-write association end

    if (!_inputValues.contains(inputValue)) {
        _inputValues.insert(inputValue);
        if (inputValue && inputValue->asQModelingObject() && this->asQModelingObject())
            QObject::connect(inputValue->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeInputValue(QObject *)));
        inputValue->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addInput(inputValue);
    }
}

/*!
    Removes \a inputValue from inputValues.

    \sa inputValues(), addInputValue()
 */
void QUmlOpaqueAction::removeInputValue(QUmlInputPin *inputValue)
{
    // This is a read-write association end

    if (_inputValues.contains(inputValue)) {
        _inputValues.remove(inputValue);
        if (inputValue->asQModelingObject())
            inputValue->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeInput(inputValue);
    }
}

/*!
    Languages the body strings use, in the same order as the body strings

    \sa addLanguage(), removeLanguage()
 */
const QList<QString> QUmlOpaqueAction::languages() const
{
    // This is a read-write property

    return _languages;
}

/*!
    Adds \a language to languages.

    \sa languages(), removeLanguage()
 */
void QUmlOpaqueAction::addLanguage(QString language)
{
    // This is a read-write property

    if (!_languages.contains(language)) {
        _languages.append(language);
    }
}

/*!
    Removes \a language from languages.

    \sa languages(), addLanguage()
 */
void QUmlOpaqueAction::removeLanguage(QString language)
{
    // This is a read-write property

    if (_languages.contains(language)) {
        _languages.removeAll(language);
    }
}

/*!
    Takes output from the action.

    \sa addOutputValue(), removeOutputValue()

    \b {Subsetted property(ies):} QUmlAction::outputs().
 */
const QSet<QUmlOutputPin *> QUmlOpaqueAction::outputValues() const
{
    // This is a read-write association end

    return _outputValues;
}

/*!
    Adds \a outputValue to outputValues.

    \sa outputValues(), removeOutputValue()
 */
void QUmlOpaqueAction::addOutputValue(QUmlOutputPin *outputValue)
{
    // This is a read-write association end

    if (!_outputValues.contains(outputValue)) {
        _outputValues.insert(outputValue);
        if (outputValue && outputValue->asQModelingObject() && this->asQModelingObject())
            QObject::connect(outputValue->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeOutputValue(QObject *)));
        outputValue->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOutput(outputValue);
    }
}

/*!
    Removes \a outputValue from outputValues.

    \sa outputValues(), addOutputValue()
 */
void QUmlOpaqueAction::removeOutputValue(QUmlOutputPin *outputValue)
{
    // This is a read-write association end

    if (_outputValues.contains(outputValue)) {
        _outputValues.remove(outputValue);
        if (outputValue->asQModelingObject())
            outputValue->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOutput(outputValue);
    }
}

QT_END_NAMESPACE

