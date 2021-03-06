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
#include "qumlinteraction.h"

#include "private/qumlinteractionobject_p.h"

#include <QtUml/QUmlAction>
#include <QtUml/QUmlBehavioralFeature>
#include <QtUml/QUmlBehavioredClassifier>
#include <QtUml/QUmlClass>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlClassifierTemplateParameter>
#include <QtUml/QUmlCollaborationUse>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConnectableElement>
#include <QtUml/QUmlConnector>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlExtension>
#include <QtUml/QUmlFeature>
#include <QtUml/QUmlGate>
#include <QtUml/QUmlGeneralization>
#include <QtUml/QUmlGeneralizationSet>
#include <QtUml/QUmlGeneralOrdering>
#include <QtUml/QUmlInteractionOperand>
#include <QtUml/QUmlInterfaceRealization>
#include <QtUml/QUmlLifeline>
#include <QtUml/QUmlMessage>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOperation>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlParameter>
#include <QtUml/QUmlParameterableElement>
#include <QtUml/QUmlParameterSet>
#include <QtUml/QUmlPort>
#include <QtUml/QUmlProperty>
#include <QtUml/QUmlReception>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlRedefinableTemplateSignature>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlSubstitution>
#include <QtUml/QUmlTemplateBinding>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlTemplateSignature>
#include <QtUml/QUmlType>
#include <QtUml/QUmlUseCase>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlInteraction

    \inmodule QtUml

    \brief An interaction is a unit of behavior that focuses on the observable exchange of information between connectable elements.
 */

/*!
    Creates a new QUmlInteraction. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlInteraction::QUmlInteraction(bool createQModelingObject)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlInteractionObject(this));
}

/*!
    Destroys the QUmlInteraction.
 */
QUmlInteraction::~QUmlInteraction()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlInteraction.
*/
QModelingElement *QUmlInteraction::clone() const
{
    QUmlInteraction *c = new QUmlInteraction;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    foreach (QUmlElementImport *element, elementImports())
        c->addElementImport(dynamic_cast<QUmlElementImport *>(element->clone()));
    foreach (QUmlConstraint *element, ownedRules())
        c->addOwnedRule(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlPackageImport *element, packageImports())
        c->addPackageImport(dynamic_cast<QUmlPackageImport *>(element->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    foreach (QUmlTemplateBinding *element, templateBindings())
        c->addTemplateBinding(dynamic_cast<QUmlTemplateBinding *>(element->clone()));
    foreach (QUmlCollaborationUse *element, collaborationUses())
        c->addCollaborationUse(dynamic_cast<QUmlCollaborationUse *>(element->clone()));
    foreach (QUmlGeneralization *element, generalizations())
        c->addGeneralization(dynamic_cast<QUmlGeneralization *>(element->clone()));
    c->setFinalSpecialization(isFinalSpecialization());
    if (ownedTemplateSignature())
        c->setOwnedTemplateSignature(dynamic_cast<QUmlRedefinableTemplateSignature *>(ownedTemplateSignature()->clone()));
    foreach (QUmlUseCase *element, ownedUseCases())
        c->addOwnedUseCase(dynamic_cast<QUmlUseCase *>(element->clone()));
    foreach (QUmlSubstitution *element, substitutions())
        c->addSubstitution(dynamic_cast<QUmlSubstitution *>(element->clone()));
    foreach (QUmlConnector *element, ownedConnectors())
        c->addOwnedConnector(dynamic_cast<QUmlConnector *>(element->clone()));
    foreach (QUmlInterfaceRealization *element, interfaceRealizations())
        c->addInterfaceRealization(dynamic_cast<QUmlInterfaceRealization *>(element->clone()));
    foreach (QUmlBehavior *element, ownedBehaviors())
        c->addOwnedBehavior(dynamic_cast<QUmlBehavior *>(element->clone()));
    c->setAbstract(isAbstract());
    c->setActive(isActive());
    foreach (QUmlClassifier *element, nestedClassifiers())
        c->addNestedClassifier(dynamic_cast<QUmlClassifier *>(element->clone()));
    foreach (QUmlProperty *element, ownedAttributes())
        c->addOwnedAttribute(dynamic_cast<QUmlProperty *>(element->clone()));
    foreach (QUmlOperation *element, ownedOperations())
        c->addOwnedOperation(dynamic_cast<QUmlOperation *>(element->clone()));
    foreach (QUmlReception *element, ownedReceptions())
        c->addOwnedReception(dynamic_cast<QUmlReception *>(element->clone()));
    c->setReentrant(isReentrant());
    foreach (QUmlParameter *element, ownedParameters())
        c->addOwnedParameter(dynamic_cast<QUmlParameter *>(element->clone()));
    foreach (QUmlParameterSet *element, ownedParameterSets())
        c->addOwnedParameterSet(dynamic_cast<QUmlParameterSet *>(element->clone()));
    foreach (QUmlConstraint *element, postconditions())
        c->addPostcondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlConstraint *element, preconditions())
        c->addPrecondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlGeneralOrdering *element, generalOrderings())
        c->addGeneralOrdering(dynamic_cast<QUmlGeneralOrdering *>(element->clone()));
    foreach (QUmlAction *element, actions())
        c->addAction(dynamic_cast<QUmlAction *>(element->clone()));
    foreach (QUmlGate *element, formalGates())
        c->addFormalGate(dynamic_cast<QUmlGate *>(element->clone()));
    foreach (QUmlInteractionFragment *element, fragments())
        c->addFragment(dynamic_cast<QUmlInteractionFragment *>(element->clone()));
    foreach (QUmlLifeline *element, lifelines())
        c->addLifeline(dynamic_cast<QUmlLifeline *>(element->clone()));
    foreach (QUmlMessage *element, messages())
        c->addMessage(dynamic_cast<QUmlMessage *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Actions owned by the Interaction.

    \sa addAction(), removeAction()

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
const QSet<QUmlAction *> QUmlInteraction::actions() const
{
    // This is a read-write association end

    return _actions;
}

/*!
    Adds \a action to actions.

    \sa actions(), removeAction()
 */
void QUmlInteraction::addAction(QUmlAction *action)
{
    // This is a read-write association end

    if (!_actions.contains(action)) {
        _actions.insert(action);
        if (action && action->asQModelingObject() && this->asQModelingObject())
            QObject::connect(action->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeAction(QObject *)));
        action->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedElement(action);
    }
}

/*!
    Removes \a action from actions.

    \sa actions(), addAction()
 */
void QUmlInteraction::removeAction(QUmlAction *action)
{
    // This is a read-write association end

    if (_actions.contains(action)) {
        _actions.remove(action);
        if (action->asQModelingObject())
            action->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(action);
    }
}

/*!
    Specifies the gates that form the message interface between this Interaction and any InteractionUses which reference it.

    \sa addFormalGate(), removeFormalGate()

    \b {Subsetted property(ies):} QUmlNamespace::ownedMembers().
 */
const QSet<QUmlGate *> QUmlInteraction::formalGates() const
{
    // This is a read-write association end

    return _formalGates;
}

/*!
    Adds \a formalGate to formalGates.

    \sa formalGates(), removeFormalGate()
 */
void QUmlInteraction::addFormalGate(QUmlGate *formalGate)
{
    // This is a read-write association end

    if (!_formalGates.contains(formalGate)) {
        _formalGates.insert(formalGate);
        if (formalGate && formalGate->asQModelingObject() && this->asQModelingObject())
            QObject::connect(formalGate->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeFormalGate(QObject *)));
        formalGate->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedMember(formalGate);
    }
}

/*!
    Removes \a formalGate from formalGates.

    \sa formalGates(), addFormalGate()
 */
void QUmlInteraction::removeFormalGate(QUmlGate *formalGate)
{
    // This is a read-write association end

    if (_formalGates.contains(formalGate)) {
        _formalGates.remove(formalGate);
        if (formalGate->asQModelingObject())
            formalGate->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(formalGate);
    }
}

/*!
    The ordered set of fragments in the Interaction.

    \sa addFragment(), removeFragment()

    \b {Subsetted property(ies):} QUmlNamespace::ownedMembers().

    \b {Opposite property(ies):} QUmlInteractionFragment::enclosingInteraction().
 */
const QList<QUmlInteractionFragment *> QUmlInteraction::fragments() const
{
    // This is a read-write association end

    return _fragments;
}

/*!
    Adds \a fragment to fragments.

    \sa fragments(), removeFragment()
 */
void QUmlInteraction::addFragment(QUmlInteractionFragment *fragment)
{
    // This is a read-write association end

    if (!_fragments.contains(fragment)) {
        _fragments.append(fragment);
        if (fragment && fragment->asQModelingObject() && this->asQModelingObject())
            QObject::connect(fragment->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeFragment(QObject *)));
        fragment->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedMember(fragment);

        // Adjust opposite properties
        if (fragment) {
            fragment->setEnclosingInteraction(this);
        }
    }
}

/*!
    Removes \a fragment from fragments.

    \sa fragments(), addFragment()
 */
void QUmlInteraction::removeFragment(QUmlInteractionFragment *fragment)
{
    // This is a read-write association end

    if (_fragments.contains(fragment)) {
        _fragments.removeAll(fragment);
        if (fragment->asQModelingObject())
            fragment->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(fragment);

        // Adjust opposite properties
        if (fragment) {
            fragment->setEnclosingInteraction(0);
        }
    }
}

/*!
    Specifies the participants in this Interaction.

    \sa addLifeline(), removeLifeline()

    \b {Subsetted property(ies):} QUmlNamespace::ownedMembers().

    \b {Opposite property(ies):} QUmlLifeline::interaction().
 */
const QSet<QUmlLifeline *> QUmlInteraction::lifelines() const
{
    // This is a read-write association end

    return _lifelines;
}

/*!
    Adds \a lifeline to lifelines.

    \sa lifelines(), removeLifeline()
 */
void QUmlInteraction::addLifeline(QUmlLifeline *lifeline)
{
    // This is a read-write association end

    if (!_lifelines.contains(lifeline)) {
        _lifelines.insert(lifeline);
        if (lifeline && lifeline->asQModelingObject() && this->asQModelingObject())
            QObject::connect(lifeline->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeLifeline(QObject *)));
        lifeline->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedMember(lifeline);

        // Adjust opposite properties
        if (lifeline) {
            lifeline->setInteraction(this);
        }
    }
}

/*!
    Removes \a lifeline from lifelines.

    \sa lifelines(), addLifeline()
 */
void QUmlInteraction::removeLifeline(QUmlLifeline *lifeline)
{
    // This is a read-write association end

    if (_lifelines.contains(lifeline)) {
        _lifelines.remove(lifeline);
        if (lifeline->asQModelingObject())
            lifeline->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(lifeline);

        // Adjust opposite properties
        if (lifeline) {
            lifeline->setInteraction(0);
        }
    }
}

/*!
    The Messages contained in this Interaction.

    \sa addMessage(), removeMessage()

    \b {Subsetted property(ies):} QUmlNamespace::ownedMembers().

    \b {Opposite property(ies):} QUmlMessage::interaction().
 */
const QSet<QUmlMessage *> QUmlInteraction::messages() const
{
    // This is a read-write association end

    return _messages;
}

/*!
    Adds \a message to messages.

    \sa messages(), removeMessage()
 */
void QUmlInteraction::addMessage(QUmlMessage *message)
{
    // This is a read-write association end

    if (!_messages.contains(message)) {
        _messages.insert(message);
        if (message && message->asQModelingObject() && this->asQModelingObject())
            QObject::connect(message->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeMessage(QObject *)));
        message->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedMember(message);

        // Adjust opposite properties
        if (message) {
            message->setInteraction(this);
        }
    }
}

/*!
    Removes \a message from messages.

    \sa messages(), addMessage()
 */
void QUmlInteraction::removeMessage(QUmlMessage *message)
{
    // This is a read-write association end

    if (_messages.contains(message)) {
        _messages.remove(message);
        if (message->asQModelingObject())
            message->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(message);

        // Adjust opposite properties
        if (message) {
            message->setInteraction(0);
        }
    }
}

QT_END_NAMESPACE

