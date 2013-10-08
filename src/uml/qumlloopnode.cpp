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
#include "qumlloopnode.h"

#include "private/qumlloopnodeobject_p.h"

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
#include <QtUml/QUmlElementImport>
#include <QtUml/QUmlExceptionHandler>
#include <QtUml/QUmlExecutableNode>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOutputPin>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlPackageableElement>
#include <QtUml/QUmlPackageImport>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>
#include <QtUml/QUmlVariable>

/*!
    \class QUmlLoopNode

    \inmodule QtUml

    \brief A loop node is a structured activity node that represents a loop with setup, test, and body sections.
 */
QUmlLoopNode::QUmlLoopNode(bool createQObject) :
    QUmlStructuredActivityNode(false),
    _decider(0),
    _isTestedFirst(false)
{
    if (createQObject)
        _qObject = new QUmlLoopNodeObject(this);
    setClassForProperty();
    setPropertyData();
}

QUmlLoopNode::~QUmlLoopNode()
{
    if (!deletingFromQObject) {
        if (_qObject)
            _qObject->setProperty("deletingFromModelingObject", true);
        delete _qObject;
    }
}

QModelingObject *QUmlLoopNode::clone() const
{
    QUmlLoopNode *c = new QUmlLoopNode;
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    foreach (QUmlDependency *element, clientDependencies())
        c->addClientDependency(dynamic_cast<QUmlDependency *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    foreach (QUmlInterruptibleActivityRegion *element, inInterruptibleRegions())
        c->addInInterruptibleRegion(dynamic_cast<QUmlInterruptibleActivityRegion *>(element->clone()));
    foreach (QUmlActivityPartition *element, inPartitions())
        c->addInPartition(dynamic_cast<QUmlActivityPartition *>(element->clone()));
    if (inStructuredNode())
        c->setInStructuredNode(dynamic_cast<QUmlStructuredActivityNode *>(inStructuredNode()->clone()));
    foreach (QUmlActivityEdge *element, incomings())
        c->addIncoming(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    foreach (QUmlActivityEdge *element, outgoings())
        c->addOutgoing(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    foreach (QUmlActivityNode *element, redefinedNodes())
        c->addRedefinedNode(dynamic_cast<QUmlActivityNode *>(element->clone()));
    foreach (QUmlExceptionHandler *element, handlers())
        c->addHandler(dynamic_cast<QUmlExceptionHandler *>(element->clone()));
    c->setLocallyReentrant(isLocallyReentrant());
    foreach (QUmlConstraint *element, localPostconditions())
        c->addLocalPostcondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlConstraint *element, localPreconditions())
        c->addLocalPrecondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlElementImport *element, elementImports())
        c->addElementImport(dynamic_cast<QUmlElementImport *>(element->clone()));
    foreach (QUmlConstraint *element, ownedRules())
        c->addOwnedRule(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlPackageImport *element, packageImports())
        c->addPackageImport(dynamic_cast<QUmlPackageImport *>(element->clone()));
    if (activity())
        c->setActivity(dynamic_cast<QUmlActivity *>(activity()->clone()));
    foreach (QUmlActivityEdge *element, edges())
        c->addEdge(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    c->setMustIsolate(mustIsolate());
    foreach (QUmlActivityNode *element, nodes())
        c->addNode(dynamic_cast<QUmlActivityNode *>(element->clone()));
    foreach (QUmlVariable *element, variables())
        c->addVariable(dynamic_cast<QUmlVariable *>(element->clone()));
    foreach (QUmlOutputPin *element, bodyOutputs())
        c->addBodyOutput(dynamic_cast<QUmlOutputPin *>(element->clone()));
    foreach (QUmlExecutableNode *element, bodyParts())
        c->addBodyPart(dynamic_cast<QUmlExecutableNode *>(element->clone()));
    if (decider())
        c->setDecider(dynamic_cast<QUmlOutputPin *>(decider()->clone()));
    c->setTestedFirst(isTestedFirst());
    foreach (QUmlOutputPin *element, loopVariables())
        c->addLoopVariable(dynamic_cast<QUmlOutputPin *>(element->clone()));
    foreach (QUmlInputPin *element, loopVariableInputs())
        c->addLoopVariableInput(dynamic_cast<QUmlInputPin *>(element->clone()));
    foreach (QUmlOutputPin *element, results())
        c->addResult(dynamic_cast<QUmlOutputPin *>(element->clone()));
    foreach (QUmlExecutableNode *element, setupParts())
        c->addSetupPart(dynamic_cast<QUmlExecutableNode *>(element->clone()));
    foreach (QUmlExecutableNode *element, tests())
        c->addTest(dynamic_cast<QUmlExecutableNode *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    A list of output pins within the body fragment the values of which are moved to the loop variable pins after completion of execution of the body, before the next iteration of the loop begins or before the loop exits.
 */
const QList<QUmlOutputPin *> QUmlLoopNode::bodyOutputs() const
{
    // This is a read-write association end

    return _bodyOutputs;
}

void QUmlLoopNode::addBodyOutput(QUmlOutputPin *bodyOutput)
{
    // This is a read-write association end

    if (!_bodyOutputs.contains(bodyOutput)) {
        _bodyOutputs.append(bodyOutput);
        if (bodyOutput && bodyOutput->asQObject() && this->asQObject())
            QObject::connect(bodyOutput->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeBodyOutput(QObject *)));
    }
}

void QUmlLoopNode::removeBodyOutput(QUmlOutputPin *bodyOutput)
{
    // This is a read-write association end

    if (_bodyOutputs.contains(bodyOutput)) {
        _bodyOutputs.removeAll(bodyOutput);
    }
}

/*!
    The set of nodes and edges that perform the repetitive computations of the loop. The body section is executed as long as the test section produces a true value.
 */
const QSet<QUmlExecutableNode *> QUmlLoopNode::bodyParts() const
{
    // This is a read-write association end

    return _bodyParts;
}

void QUmlLoopNode::addBodyPart(QUmlExecutableNode *bodyPart)
{
    // This is a read-write association end

    if (!_bodyParts.contains(bodyPart)) {
        _bodyParts.insert(bodyPart);
        if (bodyPart && bodyPart->asQObject() && this->asQObject())
            QObject::connect(bodyPart->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeBodyPart(QObject *)));
    }
}

void QUmlLoopNode::removeBodyPart(QUmlExecutableNode *bodyPart)
{
    // This is a read-write association end

    if (_bodyParts.contains(bodyPart)) {
        _bodyParts.remove(bodyPart);
    }
}

/*!
    An output pin within the test fragment the value of which is examined after execution of the test to determine whether to execute the loop body.
 */
QUmlOutputPin *QUmlLoopNode::decider() const
{
    // This is a read-write association end

    return _decider;
}

void QUmlLoopNode::setDecider(QUmlOutputPin *decider)
{
    // This is a read-write association end

    if (_decider != decider) {
        _decider = decider;
        if (decider && decider->asQObject() && this->asQObject())
            QObject::connect(decider->asQObject(), SIGNAL(destroyed()), this->asQObject(), SLOT(setDecider()));
    }
}

/*!
    If true, the test is performed before the first execution of the body. If false, the body is executed once before the test is performed.
 */
bool QUmlLoopNode::isTestedFirst() const
{
    // This is a read-write property

    return _isTestedFirst;
}

void QUmlLoopNode::setTestedFirst(bool isTestedFirst)
{
    // This is a read-write property

    if (_isTestedFirst != isTestedFirst) {
        _isTestedFirst = isTestedFirst;
        _modifiedResettableProperties << QStringLiteral("isTestedFirst");
    }
}

/*!
    A list of output pins that hold the values of the loop variables during an execution of the loop. When the test fails, the values are movied to the result pins of the loop.
 */
const QList<QUmlOutputPin *> QUmlLoopNode::loopVariables() const
{
    // This is a read-write association end

    return _loopVariables;
}

void QUmlLoopNode::addLoopVariable(QUmlOutputPin *loopVariable)
{
    // This is a read-write association end

    if (!_loopVariables.contains(loopVariable)) {
        _loopVariables.append(loopVariable);
        if (loopVariable && loopVariable->asQObject() && this->asQObject())
            QObject::connect(loopVariable->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeLoopVariable(QObject *)));
    }
}

void QUmlLoopNode::removeLoopVariable(QUmlOutputPin *loopVariable)
{
    // This is a read-write association end

    if (_loopVariables.contains(loopVariable)) {
        _loopVariables.removeAll(loopVariable);
    }
}

/*!
    A list of values that are moved into the loop variable pins before the first iteration of the loop.
 */
const QList<QUmlInputPin *> QUmlLoopNode::loopVariableInputs() const
{
    // This is a read-write association end

    return _loopVariableInputs;
}

void QUmlLoopNode::addLoopVariableInput(QUmlInputPin *loopVariableInput)
{
    // This is a read-write association end

    if (!_loopVariableInputs.contains(loopVariableInput)) {
        _loopVariableInputs.append(loopVariableInput);
        if (loopVariableInput && loopVariableInput->asQObject() && this->asQObject())
            QObject::connect(loopVariableInput->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeLoopVariableInput(QObject *)));
        loopVariableInput->asQObject()->setParent(this->asQObject());
    }
}

void QUmlLoopNode::removeLoopVariableInput(QUmlInputPin *loopVariableInput)
{
    // This is a read-write association end

    if (_loopVariableInputs.contains(loopVariableInput)) {
        _loopVariableInputs.removeAll(loopVariableInput);
        if (loopVariableInput->asQObject())
            loopVariableInput->asQObject()->setParent(0);
    }
}

/*!
    A list of output pins that constitute the data flow output of the entire loop.
 */
const QList<QUmlOutputPin *> QUmlLoopNode::results() const
{
    // This is a read-write association end

    return _results;
}

void QUmlLoopNode::addResult(QUmlOutputPin *result)
{
    // This is a read-write association end

    if (!_results.contains(result)) {
        _results.append(result);
        if (result && result->asQObject() && this->asQObject())
            QObject::connect(result->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeResult(QObject *)));
        result->asQObject()->setParent(this->asQObject());
    }
}

void QUmlLoopNode::removeResult(QUmlOutputPin *result)
{
    // This is a read-write association end

    if (_results.contains(result)) {
        _results.removeAll(result);
        if (result->asQObject())
            result->asQObject()->setParent(0);
    }
}

/*!
    The set of nodes and edges that initialize values or perform other setup computations for the loop.
 */
const QSet<QUmlExecutableNode *> QUmlLoopNode::setupParts() const
{
    // This is a read-write association end

    return _setupParts;
}

void QUmlLoopNode::addSetupPart(QUmlExecutableNode *setupPart)
{
    // This is a read-write association end

    if (!_setupParts.contains(setupPart)) {
        _setupParts.insert(setupPart);
        if (setupPart && setupPart->asQObject() && this->asQObject())
            QObject::connect(setupPart->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeSetupPart(QObject *)));
    }
}

void QUmlLoopNode::removeSetupPart(QUmlExecutableNode *setupPart)
{
    // This is a read-write association end

    if (_setupParts.contains(setupPart)) {
        _setupParts.remove(setupPart);
    }
}

/*!
    The set of nodes, edges, and designated value that compute a Boolean value to determine if another execution of the body will be performed.
 */
const QSet<QUmlExecutableNode *> QUmlLoopNode::tests() const
{
    // This is a read-write association end

    return _tests;
}

void QUmlLoopNode::addTest(QUmlExecutableNode *test)
{
    // This is a read-write association end

    if (!_tests.contains(test)) {
        _tests.insert(test);
        if (test && test->asQObject() && this->asQObject())
            QObject::connect(test->asQObject(), SIGNAL(destroyed(QObject*)), this->asQObject(), SLOT(removeTest(QObject *)));
    }
}

void QUmlLoopNode::removeTest(QUmlExecutableNode *test)
{
    // This is a read-write association end

    if (_tests.contains(test)) {
        _tests.remove(test);
    }
}

void QUmlLoopNode::setClassForProperty()
{
    _classForProperty[QStringLiteral("ownedComments")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("ownedElements")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("owner")] = QStringLiteral("QUmlElement");
    _classForProperty[QStringLiteral("clientDependencies")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("name")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("nameExpression")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("namespace_")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("qualifiedName")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("visibility")] = QStringLiteral("QUmlNamedElement");
    _classForProperty[QStringLiteral("isLeaf")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinedElements")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("redefinitionContexts")] = QStringLiteral("QUmlRedefinableElement");
    _classForProperty[QStringLiteral("inGroups")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("inInterruptibleRegions")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("inPartitions")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("inStructuredNode")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("incomings")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("outgoings")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("redefinedNodes")] = QStringLiteral("QUmlActivityNode");
    _classForProperty[QStringLiteral("handlers")] = QStringLiteral("QUmlExecutableNode");
    _classForProperty[QStringLiteral("context")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("inputs")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("isLocallyReentrant")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("localPostconditions")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("localPreconditions")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("outputs")] = QStringLiteral("QUmlAction");
    _classForProperty[QStringLiteral("elementImports")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("importedMembers")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("members")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("ownedMembers")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("ownedRules")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("packageImports")] = QStringLiteral("QUmlNamespace");
    _classForProperty[QStringLiteral("containedEdges")] = QStringLiteral("QUmlActivityGroup");
    _classForProperty[QStringLiteral("containedNodes")] = QStringLiteral("QUmlActivityGroup");
    _classForProperty[QStringLiteral("subgroups")] = QStringLiteral("QUmlActivityGroup");
    _classForProperty[QStringLiteral("superGroup")] = QStringLiteral("QUmlActivityGroup");
    _classForProperty[QStringLiteral("activity")] = QStringLiteral("QUmlStructuredActivityNode");
    _classForProperty[QStringLiteral("edges")] = QStringLiteral("QUmlStructuredActivityNode");
    _classForProperty[QStringLiteral("mustIsolate")] = QStringLiteral("QUmlStructuredActivityNode");
    _classForProperty[QStringLiteral("nodes")] = QStringLiteral("QUmlStructuredActivityNode");
    _classForProperty[QStringLiteral("variables")] = QStringLiteral("QUmlStructuredActivityNode");
    _classForProperty[QStringLiteral("bodyOutputs")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("bodyParts")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("decider")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("isTestedFirst")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("loopVariables")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("loopVariableInputs")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("results")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("setupParts")] = QStringLiteral("QUmlLoopNode");
    _classForProperty[QStringLiteral("tests")] = QStringLiteral("QUmlLoopNode");
}

void QUmlLoopNode::setPropertyData()
{
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::DocumentationRole] = QStringLiteral("A list of output pins within the body fragment the values of which are moved to the loop variable pins after completion of execution of the body, before the next iteration of the loop begins or before the loop exits.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyOutputs")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::DocumentationRole] = QStringLiteral("The set of nodes and edges that perform the repetitive computations of the loop. The body section is executed as long as the test section produces a true value.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("bodyParts")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::DocumentationRole] = QStringLiteral("An output pin within the test fragment the value of which is examined after execution of the test to determine whether to execute the loop body.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("decider")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::DocumentationRole] = QStringLiteral("If true, the test is performed before the first execution of the body. If false, the body is executed once before the test is performed.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("isTestedFirst")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::DocumentationRole] = QStringLiteral("A list of output pins that hold the values of the loop variables during an execution of the loop. When the test fails, the values are movied to the result pins of the loop.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariables")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::DocumentationRole] = QStringLiteral("A list of values that are moved into the loop variable pins before the first iteration of the loop.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("StructuredActivityNode-structuredNodeInput");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("loopVariableInputs")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::AggregationRole] = QStringLiteral("composite");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::DocumentationRole] = QStringLiteral("A list of output pins that constitute the data flow output of the entire loop.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("StructuredActivityNode-structuredNodeOutput");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("results")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::DocumentationRole] = QStringLiteral("The set of nodes and edges that initialize values or perform other setup computations for the loop.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("setupParts")][QtModeling::OppositeEndRole] = QStringLiteral("");

    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::AggregationRole] = QStringLiteral("none");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::PropertyClassRole] = QStringLiteral("QUmlLoopNode");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::IsDerivedRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::IsDerivedUnionRole] = false;
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::DocumentationRole] = QStringLiteral("The set of nodes, edges, and designated value that compute a Boolean value to determine if another execution of the body will be performed.");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::RedefinedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::SubsettedPropertiesRole] = QStringLiteral("");
    QModelingObject::propertyDataHash[QStringLiteral("QUmlLoopNode")][QStringLiteral("tests")][QtModeling::OppositeEndRole] = QStringLiteral("");

}

