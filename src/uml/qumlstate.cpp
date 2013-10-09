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
#include "qumlstate.h"

#include "private/qumlstateobject_p.h"

#include <QtUml/QUmlBehavior>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConnectionPointReference>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlPseudostate>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlRegion>
#include <QtUml/QUmlStateMachine>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlTransition>
#include <QtUml/QUmlTrigger>

/*!
    \class QUmlState

    \inmodule QtUml

    \brief A state models a situation during which some (usually implicit) invariant condition holds.The states of protocol state machines are exposed to the users of their context classifiers. A protocol state represents an exposed stable situation of its context classifier: when an instance of the classifier is not processing any operation, users of this instance can always know its state configuration.
 */
QUmlState::QUmlState(bool createQObject) :
    _doActivity(0),
    _entry(0),
    _exit(0),
    _redefinedState(0),
    _stateInvariant(0),
    _submachine(0)
{
    if (createQObject)
        _qObject = new QUmlStateObject(this);
    setGroupProperties();
    setPropertyData();
}

QUmlState::~QUmlState()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlState::clone() const
{
    QUmlState *c = new QUmlState;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlElementImport *element, elementImports())
        c->addElementImport(dynamic_cast<QUmlElementImport *>(element->clone()));
    foreach (QUmlConstraint *element, ownedRules())
        c->addOwnedRule(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlPackageImport *element, packageImports())
        c->addPackageImport(dynamic_cast<QUmlPackageImport *>(element->clone()));
    c->setLeaf(isLeaf());
    if (container())
        c->setContainer(dynamic_cast<QUmlRegion *>(container()->clone()));
    foreach (QUmlConnectionPointReference *element, connections())
        c->addConnection(dynamic_cast<QUmlConnectionPointReference *>(element->clone()));
    foreach (QUmlPseudostate *element, connectionPoints())
        c->addConnectionPoint(dynamic_cast<QUmlPseudostate *>(element->clone()));
    foreach (QUmlTrigger *element, deferrableTriggers())
        c->addDeferrableTrigger(dynamic_cast<QUmlTrigger *>(element->clone()));
    if (doActivity())
        c->setDoActivity(dynamic_cast<QUmlBehavior *>(doActivity()->clone()));
    if (entry())
        c->setEntry(dynamic_cast<QUmlBehavior *>(entry()->clone()));
    if (exit())
        c->setExit(dynamic_cast<QUmlBehavior *>(exit()->clone()));
    if (redefinedState())
        c->setRedefinedState(dynamic_cast<QUmlState *>(redefinedState()->clone()));
    foreach (QUmlRegion *element, regions())
        c->addRegion(dynamic_cast<QUmlRegion *>(element->clone()));
    if (stateInvariant())
        c->setStateInvariant(dynamic_cast<QUmlConstraint *>(stateInvariant()->clone()));
    if (submachine())
        c->setSubmachine(dynamic_cast<QUmlStateMachine *>(submachine()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The entry and exit connection points used in conjunction with this (submachine) state, i.e. as targets and sources, respectively, in the region with the submachine state. A connection point reference references the corresponding definition of a connection point pseudostate in the statemachine referenced by the submachinestate.
 */
const QSet<QUmlConnectionPointReference *> QUmlState::connections() const
{
    // This is a read-write association end

    return _connections;
}

void QUmlState::addConnection(QUmlConnectionPointReference *connection)
{
    // This is a read-write association end

    if (!_connections.contains(connection)) {
        _connections.insert(connection);
        if (connection && connection->asQObject() && this->asQObject())
            QObject::connect(connection->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeConnection(QObject *)));
        connection->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addOwnedMember(connection);

        // Adjust opposite properties
        if (connection) {
            connection->setState(this);
        }
    }
}

void QUmlState::removeConnection(QUmlConnectionPointReference *connection)
{
    // This is a read-write association end

    if (_connections.contains(connection)) {
        _connections.remove(connection);
        if (connection->asQObject())
            connection->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(connection);

        // Adjust opposite properties
        if (connection) {
            connection->setState(0);
        }
    }
}

/*!
    The entry and exit pseudostates of a composite state. These can only be entry or exit Pseudostates, and they must have different names. They can only be defined for composite states.
 */
const QSet<QUmlPseudostate *> QUmlState::connectionPoints() const
{
    // This is a read-write association end

    return _connectionPoints;
}

void QUmlState::addConnectionPoint(QUmlPseudostate *connectionPoint)
{
    // This is a read-write association end

    if (!_connectionPoints.contains(connectionPoint)) {
        _connectionPoints.insert(connectionPoint);
        if (connectionPoint && connectionPoint->asQObject() && this->asQObject())
            QObject::connect(connectionPoint->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeConnectionPoint(QObject *)));
        connectionPoint->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addOwnedMember(connectionPoint);

        // Adjust opposite properties
        if (connectionPoint) {
            connectionPoint->setState(this);
        }
    }
}

void QUmlState::removeConnectionPoint(QUmlPseudostate *connectionPoint)
{
    // This is a read-write association end

    if (_connectionPoints.contains(connectionPoint)) {
        _connectionPoints.remove(connectionPoint);
        if (connectionPoint->asQObject())
            connectionPoint->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(connectionPoint);

        // Adjust opposite properties
        if (connectionPoint) {
            connectionPoint->setState(0);
        }
    }
}

/*!
    A list of triggers that are candidates to be retained by the state machine if they trigger no transitions out of the state (not consumed). A deferred trigger is retained until the state machine reaches a state configuration where it is no longer deferred.
 */
const QSet<QUmlTrigger *> QUmlState::deferrableTriggers() const
{
    // This is a read-write association end

    return _deferrableTriggers;
}

void QUmlState::addDeferrableTrigger(QUmlTrigger *deferrableTrigger)
{
    // This is a read-write association end

    if (!_deferrableTriggers.contains(deferrableTrigger)) {
        _deferrableTriggers.insert(deferrableTrigger);
        if (deferrableTrigger && deferrableTrigger->asQObject() && this->asQObject())
            QObject::connect(deferrableTrigger->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeDeferrableTrigger(QObject *)));
        deferrableTrigger->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addOwnedElement(deferrableTrigger);
    }
}

void QUmlState::removeDeferrableTrigger(QUmlTrigger *deferrableTrigger)
{
    // This is a read-write association end

    if (_deferrableTriggers.contains(deferrableTrigger)) {
        _deferrableTriggers.remove(deferrableTrigger);
        if (deferrableTrigger->asQObject())
            deferrableTrigger->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(deferrableTrigger);
    }
}

/*!
    An optional behavior that is executed while being in the state. The execution starts when this state is entered, and stops either by itself, or when the state is exited, whichever comes first.
 */
QUmlBehavior *QUmlState::doActivity() const
{
    // This is a read-write association end

    return _doActivity;
}

void QUmlState::setDoActivity(QUmlBehavior *doActivity)
{
    // This is a read-write association end

    if (_doActivity != doActivity) {
        // Adjust subsetted properties
        removeOwnedElement(_doActivity);

        _doActivity = doActivity;
        if (doActivity && doActivity->asQObject() && this->asQObject())
            QObject::connect(doActivity->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setDoActivity()));
        doActivity->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (doActivity) {
            addOwnedElement(doActivity);
        }
    }
}

/*!
    An optional behavior that is executed whenever this state is entered regardless of the transition taken to reach the state. If defined, entry actions are always executed to completion prior to any internal behavior or transitions performed within the state.
 */
QUmlBehavior *QUmlState::entry() const
{
    // This is a read-write association end

    return _entry;
}

void QUmlState::setEntry(QUmlBehavior *entry)
{
    // This is a read-write association end

    if (_entry != entry) {
        // Adjust subsetted properties
        removeOwnedElement(_entry);

        _entry = entry;
        if (entry && entry->asQObject() && this->asQObject())
            QObject::connect(entry->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setEntry()));
        entry->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (entry) {
            addOwnedElement(entry);
        }
    }
}

/*!
    An optional behavior that is executed whenever this state is exited regardless of which transition was taken out of the state. If defined, exit actions are always executed to completion only after all internal activities and transition actions have completed execution.
 */
QUmlBehavior *QUmlState::exit() const
{
    // This is a read-write association end

    return _exit;
}

void QUmlState::setExit(QUmlBehavior *exit)
{
    // This is a read-write association end

    if (_exit != exit) {
        // Adjust subsetted properties
        removeOwnedElement(_exit);

        _exit = exit;
        if (exit && exit->asQObject() && this->asQObject())
            QObject::connect(exit->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setExit()));
        exit->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (exit) {
            addOwnedElement(exit);
        }
    }
}

/*!
    A state with isComposite=true is said to be a composite state. A composite state is a state that contains at least one region.
 */
bool QUmlState::isComposite() const
{
    // This is a read-only derived property

    qWarning("UmlState::isComposite(): to be implemented (this is a derived property)");

    return bool();
}

void QUmlState::setComposite(bool isComposite)
{
    // This is a read-only derived property

    qWarning("UmlState::setComposite(): to be implemented (this is a derived property)");
    Q_UNUSED(isComposite);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    A state with isOrthogonal=true is said to be an orthogonal composite state. An orthogonal composite state contains two or more regions.
 */
bool QUmlState::isOrthogonal() const
{
    // This is a read-only derived property

    qWarning("UmlState::isOrthogonal(): to be implemented (this is a derived property)");

    return bool();
}

void QUmlState::setOrthogonal(bool isOrthogonal)
{
    // This is a read-only derived property

    qWarning("UmlState::setOrthogonal(): to be implemented (this is a derived property)");
    Q_UNUSED(isOrthogonal);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    A state with isSimple=true is said to be a simple state. A simple state does not have any regions and it does not refer to any submachine state machine.
 */
bool QUmlState::isSimple() const
{
    // This is a read-only derived property

    qWarning("UmlState::isSimple(): to be implemented (this is a derived property)");

    return bool();
}

void QUmlState::setSimple(bool isSimple)
{
    // This is a read-only derived property

    qWarning("UmlState::setSimple(): to be implemented (this is a derived property)");
    Q_UNUSED(isSimple);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    A state with isSubmachineState=true is said to be a submachine state. Such a state refers to a state machine (submachine).
 */
bool QUmlState::isSubmachineState() const
{
    // This is a read-only derived property

    qWarning("UmlState::isSubmachineState(): to be implemented (this is a derived property)");

    return bool();
}

void QUmlState::setSubmachineState(bool isSubmachineState)
{
    // This is a read-only derived property

    qWarning("UmlState::setSubmachineState(): to be implemented (this is a derived property)");
    Q_UNUSED(isSubmachineState);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    The state of which this state is a redefinition.
 */
QUmlState *QUmlState::redefinedState() const
{
    // This is a read-write association end

    return _redefinedState;
}

void QUmlState::setRedefinedState(QUmlState *redefinedState)
{
    // This is a read-write association end

    if (_redefinedState != redefinedState) {
        // Adjust subsetted properties
        removeRedefinedElement(_redefinedState);

        _redefinedState = redefinedState;
        if (redefinedState && redefinedState->asQObject() && this->asQObject())
            QObject::connect(redefinedState->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setRedefinedState()));

        // Adjust subsetted properties
        if (redefinedState) {
            addRedefinedElement(redefinedState);
        }
    }
}

/*!
    References the classifier in which context this element may be redefined.
 */
QUmlClassifier *QUmlState::redefinitionContext() const
{
    // This is a read-only derived association end

    qWarning("UmlState::redefinitionContext(): to be implemented (this is a derived association end)");

    return 0;
}

void QUmlState::setRedefinitionContext(QUmlClassifier *redefinitionContext)
{
    // This is a read-only derived association end

    qWarning("UmlState::setRedefinitionContext(): to be implemented (this is a derived association end)");
    Q_UNUSED(redefinitionContext);

    if (false /* <derivedexclusion-criteria> */) {
        // <derived-code>
    }
}

/*!
    The regions owned directly by the state.
 */
const QSet<QUmlRegion *> QUmlState::regions() const
{
    // This is a read-write association end

    return _regions;
}

void QUmlState::addRegion(QUmlRegion *region)
{
    // This is a read-write association end

    if (!_regions.contains(region)) {
        _regions.insert(region);
        if (region && region->asQObject() && this->asQObject())
            QObject::connect(region->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeRegion(QObject *)));
        region->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        addOwnedMember(region);

        // Adjust opposite properties
        if (region) {
            region->setState(this);
        }
    }
}

void QUmlState::removeRegion(QUmlRegion *region)
{
    // This is a read-write association end

    if (_regions.contains(region)) {
        _regions.remove(region);
        if (region->asQObject())
            region->asQObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(region);

        // Adjust opposite properties
        if (region) {
            region->setState(0);
        }
    }
}

/*!
    Specifies conditions that are always true when this state is the current state. In protocol state machines, state invariants are additional conditions to the preconditions of the outgoing transitions, and to the postcondition of the incoming transitions.
 */
QUmlConstraint *QUmlState::stateInvariant() const
{
    // This is a read-write association end

    return _stateInvariant;
}

void QUmlState::setStateInvariant(QUmlConstraint *stateInvariant)
{
    // This is a read-write association end

    if (_stateInvariant != stateInvariant) {
        // Adjust subsetted properties
        removeOwnedRule(_stateInvariant);

        _stateInvariant = stateInvariant;
        if (stateInvariant && stateInvariant->asQObject() && this->asQObject())
            QObject::connect(stateInvariant->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setStateInvariant()));
        stateInvariant->asQObject()->setParent(this->asQObject());

        // Adjust subsetted properties
        if (stateInvariant) {
            addOwnedRule(stateInvariant);
        }
    }
}

/*!
    The state machine that is to be inserted in place of the (submachine) state.
 */
QUmlStateMachine *QUmlState::submachine() const
{
    // This is a read-write association end

    return _submachine;
}

void QUmlState::setSubmachine(QUmlStateMachine *submachine)
{
    // This is a read-write association end

    if (_submachine != submachine) {
        _submachine = submachine;
        if (submachine && submachine->asQObject() && this->asQObject())
            QObject::connect(submachine->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setSubmachine()));
    }
}

// OPERATIONS

/*!
    The query containingStateMachine() returns the state machine that contains the state either directly or transitively.
 */
QUmlStateMachine *QUmlState::containingStateMachine() const
{
    qWarning("UmlState::containingStateMachine(): to be implemented (operation)");

    return 0;
}

/*!
    The query isConsistentWith() specifies that a redefining state is consistent with a redefined state provided that the redefining state is an extension of the redefined state: A simple state can be redefined (extended) to become a composite state (by adding a region) and a composite state can be redefined (extended) by adding regions and by adding vertices, states, and transitions to inherited regions. All states may add or replace entry, exit, and 'doActivity' actions.
 */
bool QUmlState::isConsistentWith(QUmlRedefinableElement *redefinee) const
{
    qWarning("UmlState::isConsistentWith(): to be implemented (operation)");

    Q_UNUSED(redefinee);
    return bool ();
}

/*!
    The query isRedefinitionContextValid() specifies whether the redefinition contexts of a state are properly related to the redefinition contexts of the specified state to allow this element to redefine the other. The containing region of a redefining state must redefine the containing region of the redefined state.
 */
bool QUmlState::isRedefinitionContextValid(QUmlState *redefined) const
{
    qWarning("UmlState::isRedefinitionContextValid(): to be implemented (operation)");

    Q_UNUSED(redefined);
    return bool ();
}

void QUmlState::setGroupProperties()
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
    _groupProperties.insert(QStringLiteral("QUmlNamedElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("visibility"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("elementImports"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("importedMembers"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("members"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedMembers"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("ownedRules"))));
    _groupProperties.insert(QStringLiteral("QUmlNamespace"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("packageImports"))));
    _groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isLeaf"))));
    _groupProperties.insert(QStringLiteral("QUmlRedefinableElement"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinedElements"))));
    _groupProperties.insert(QStringLiteral("QUmlVertex"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("container"))));
    _groupProperties.insert(QStringLiteral("QUmlVertex"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("incomings"))));
    _groupProperties.insert(QStringLiteral("QUmlVertex"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("outgoings"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("connections"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("connectionPoints"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("deferrableTriggers"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("doActivity"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("entry"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("exit"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isComposite"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isOrthogonal"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isSimple"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("isSubmachineState"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinedState"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("redefinitionContext"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("regions"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("stateInvariant"))));
    _groupProperties.insert(QStringLiteral("QUmlState"), new QMetaProperty(metaObject->property(metaObject->indexOfProperty("submachine"))));
}

void QUmlState::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::DocumentationRole] = QStringLiteral("The entry and exit connection points used in conjunction with this (submachine) state, i.e. as targets and sources, respectively, in the region with the submachine state. A connection point reference references the corresponding definition of a connection point pseudostate in the statemachine referenced by the submachinestate.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Namespace-ownedMember");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connections")][QtModeling::OppositeEndRole] = QStringLiteral("ConnectionPointReference-state");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::DocumentationRole] = QStringLiteral("The entry and exit pseudostates of a composite state. These can only be entry or exit Pseudostates, and they must have different names. They can only be defined for composite states.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Namespace-ownedMember");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("connectionPoints")][QtModeling::OppositeEndRole] = QStringLiteral("Pseudostate-state");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::DocumentationRole] = QStringLiteral("A list of triggers that are candidates to be retained by the state machine if they trigger no transitions out of the state (not consumed). A deferred trigger is retained until the state machine reaches a state configuration where it is no longer deferred.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("deferrableTriggers")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::DocumentationRole] = QStringLiteral("An optional behavior that is executed while being in the state. The execution starts when this state is entered, and stops either by itself, or when the state is exited, whichever comes first.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("doActivity")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::DocumentationRole] = QStringLiteral("An optional behavior that is executed whenever this state is entered regardless of the transition taken to reach the state. If defined, entry actions are always executed to completion prior to any internal behavior or transitions performed within the state.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("entry")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::DocumentationRole] = QStringLiteral("An optional behavior that is executed whenever this state is exited regardless of which transition was taken out of the state. If defined, exit actions are always executed to completion only after all internal activities and transition actions have completed execution.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Element-ownedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("exit")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::DocumentationRole] = QStringLiteral("A state with isComposite=true is said to be a composite state. A composite state is a state that contains at least one region.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isComposite")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::DocumentationRole] = QStringLiteral("A state with isOrthogonal=true is said to be an orthogonal composite state. An orthogonal composite state contains two or more regions.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isOrthogonal")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::DocumentationRole] = QStringLiteral("A state with isSimple=true is said to be a simple state. A simple state does not have any regions and it does not refer to any submachine state machine.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSimple")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::DocumentationRole] = QStringLiteral("A state with isSubmachineState=true is said to be a submachine state. Such a state refers to a state machine (submachine).");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("isSubmachineState")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::DocumentationRole] = QStringLiteral("The state of which this state is a redefinition.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("RedefinableElement-redefinedElement");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinedState")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::IsDerivedRole] = true;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::DocumentationRole] = QStringLiteral("References the classifier in which context this element may be redefined.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("RedefinableElement-redefinitionContext");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("redefinitionContext")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::DocumentationRole] = QStringLiteral("The regions owned directly by the state.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Namespace-ownedMember");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("regions")][QtModeling::OppositeEndRole] = QStringLiteral("Region-state");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::DocumentationRole] = QStringLiteral("Specifies conditions that are always true when this state is the current state. In protocol state machines, state invariants are additional conditions to the preconditions of the outgoing transitions, and to the postcondition of the incoming transitions.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("Namespace-ownedRule");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("stateInvariant")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlState");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::DocumentationRole] = QStringLiteral("The state machine that is to be inserted in place of the (submachine) state.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlState")][QStringLiteral("submachine")][QtModeling::OppositeEndRole] = QStringLiteral("StateMachine-submachineState");

}

