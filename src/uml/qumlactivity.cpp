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
#include "qumlactivity.h"

#include "private/qumlactivityobject_p.h"

#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
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
#include <QtUml/QUmlGeneralization>
#include <QtUml/QUmlGeneralizationSet>
#include <QtUml/QUmlInterfaceRealization>
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
#include <QtUml/QUmlStructuredActivityNode>
#include <QtUml/QUmlSubstitution>
#include <QtUml/QUmlTemplateBinding>
#include <QtUml/QUmlTemplateParameter>
#include <QtUml/QUmlTemplateSignature>
#include <QtUml/QUmlType>
#include <QtUml/QUmlUseCase>
#include <QtUml/QUmlVariable>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlActivity

    \inmodule QtUml

    \brief An activity is the specification of parameterized behavior as the coordinated sequencing of subordinate units whose individual elements are actions.
 */

/*!
    Creates a new QUmlActivity. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlActivity::QUmlActivity(bool createQModelingObject) :
    _isReadOnly(false),
    _isSingleExecution(false)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlActivityObject(this));
}

/*!
    Destroys the QUmlActivity.
 */
QUmlActivity::~QUmlActivity()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlActivity.
*/
QModelingElement *QUmlActivity::clone() const
{
    QUmlActivity *c = new QUmlActivity;
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
    foreach (QUmlActivityEdge *element, edges())
        c->addEdge(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    foreach (QUmlActivityGroup *element, groups())
        c->addGroup(dynamic_cast<QUmlActivityGroup *>(element->clone()));
    c->setReadOnly(isReadOnly());
    c->setSingleExecution(isSingleExecution());
    foreach (QUmlActivityNode *element, nodes())
        c->addNode(dynamic_cast<QUmlActivityNode *>(element->clone()));
    foreach (QUmlStructuredActivityNode *element, structuredNodes())
        c->addStructuredNode(dynamic_cast<QUmlStructuredActivityNode *>(element->clone()));
    foreach (QUmlVariable *element, variables())
        c->addVariable(dynamic_cast<QUmlVariable *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Edges expressing flow between nodes of the activity.

    \sa addEdge(), removeEdge()

    \b {Subsetted property(ies):} QUmlElement::ownedElements().

    \b {Opposite property(ies):} QUmlActivityEdge::activity().
 */
const QSet<QUmlActivityEdge *> QUmlActivity::edges() const
{
    // This is a read-write association end

    return _edges;
}

/*!
    Adds \a edge to edges.

    \sa edges(), removeEdge()
 */
void QUmlActivity::addEdge(QUmlActivityEdge *edge)
{
    // This is a read-write association end

    if (!_edges.contains(edge)) {
        _edges.insert(edge);
        if (edge && edge->asQModelingObject() && this->asQModelingObject())
            QObject::connect(edge->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeEdge(QObject *)));
        edge->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedElement(edge);

        // Adjust opposite properties
        if (edge) {
            edge->setActivity(this);
        }
    }
}

/*!
    Removes \a edge from edges.

    \sa edges(), addEdge()
 */
void QUmlActivity::removeEdge(QUmlActivityEdge *edge)
{
    // This is a read-write association end

    if (_edges.contains(edge)) {
        _edges.remove(edge);
        if (edge->asQModelingObject())
            edge->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(edge);

        // Adjust opposite properties
        if (edge) {
            edge->setActivity(0);
        }
    }
}

/*!
    Top-level groups in the activity.

    \sa addGroup(), removeGroup()

    \b {Subsetted property(ies):} QUmlElement::ownedElements().

    \b {Opposite property(ies):} QUmlActivityGroup::inActivity().
 */
const QSet<QUmlActivityGroup *> QUmlActivity::groups() const
{
    // This is a read-write association end

    return _groups;
}

/*!
    Adds \a group to groups.

    \sa groups(), removeGroup()
 */
void QUmlActivity::addGroup(QUmlActivityGroup *group)
{
    // This is a read-write association end

    if (!_groups.contains(group)) {
        _groups.insert(group);
        if (group && group->asQModelingObject() && this->asQModelingObject())
            QObject::connect(group->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeGroup(QObject *)));
        group->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedElement(group);

        // Adjust opposite properties
        if (group) {
            group->setInActivity(this);
        }
    }
}

/*!
    Removes \a group from groups.

    \sa groups(), addGroup()
 */
void QUmlActivity::removeGroup(QUmlActivityGroup *group)
{
    // This is a read-write association end

    if (_groups.contains(group)) {
        _groups.remove(group);
        if (group->asQModelingObject())
            group->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(group);

        // Adjust opposite properties
        if (group) {
            group->setInActivity(0);
        }
    }
}

/*!
    If true, this activity must not make any changes to variables outside the activity or to objects. (This is an assertion, not an executable property. It may be used by an execution engine to optimize model execution. If the assertion is violated by the action, then the model is ill-formed.) The default is false (an activity may make nonlocal changes).
 */
bool QUmlActivity::isReadOnly() const
{
    // This is a read-write property

    return _isReadOnly;
}

/*!
    Adjusts isReadOnly to \a isReadOnly.
 */
void QUmlActivity::setReadOnly(bool isReadOnly)
{
    // This is a read-write property

    if (_isReadOnly != isReadOnly) {
        _isReadOnly = isReadOnly;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("isReadOnly");
    }
}

/*!
    If true, all invocations of the activity are handled by the same execution.
 */
bool QUmlActivity::isSingleExecution() const
{
    // This is a read-write property

    return _isSingleExecution;
}

/*!
    Adjusts isSingleExecution to \a isSingleExecution.
 */
void QUmlActivity::setSingleExecution(bool isSingleExecution)
{
    // This is a read-write property

    if (_isSingleExecution != isSingleExecution) {
        _isSingleExecution = isSingleExecution;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("isSingleExecution");
    }
}

/*!
    Nodes coordinated by the activity.

    \sa addNode(), removeNode()

    \b {Subsetted property(ies):} QUmlElement::ownedElements().

    \b {Opposite property(ies):} QUmlActivityNode::activity().
 */
const QSet<QUmlActivityNode *> QUmlActivity::nodes() const
{
    // This is a read-write association end

    return _nodes;
}

/*!
    Adds \a node to nodes.

    \sa nodes(), removeNode()
 */
void QUmlActivity::addNode(QUmlActivityNode *node)
{
    // This is a read-write association end

    if (!_nodes.contains(node)) {
        _nodes.insert(node);
        if (node && node->asQModelingObject() && this->asQModelingObject())
            QObject::connect(node->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeNode(QObject *)));
        node->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedElement(node);

        // Adjust opposite properties
        if (node) {
            node->setActivity(this);
        }
    }
}

/*!
    Removes \a node from nodes.

    \sa nodes(), addNode()
 */
void QUmlActivity::removeNode(QUmlActivityNode *node)
{
    // This is a read-write association end

    if (_nodes.contains(node)) {
        _nodes.remove(node);
        if (node->asQModelingObject())
            node->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedElement(node);

        // Adjust opposite properties
        if (node) {
            node->setActivity(0);
        }
    }
}

/*!
    Top-level partitions in the activity.

    \sa addPartition(), removePartition()

    \b {Subsetted property(ies):} QUmlActivity::groups().
 */
const QSet<QUmlActivityPartition *> QUmlActivity::partitions() const
{
    // This is a read-write association end

    return _partitions;
}

/*!
    Adds \a partition to partitions.

    \sa partitions(), removePartition()
 */
void QUmlActivity::addPartition(QUmlActivityPartition *partition)
{
    // This is a read-write association end

    if (!_partitions.contains(partition)) {
        _partitions.insert(partition);
        if (partition && partition->asQModelingObject() && this->asQModelingObject())
            QObject::connect(partition->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removePartition(QObject *)));

        // Adjust subsetted properties
        addGroup(partition);
    }
}

/*!
    Removes \a partition from partitions.

    \sa partitions(), addPartition()
 */
void QUmlActivity::removePartition(QUmlActivityPartition *partition)
{
    // This is a read-write association end

    if (_partitions.contains(partition)) {
        _partitions.remove(partition);

        // Adjust subsetted properties
        removeGroup(partition);
    }
}

/*!
    Top-level structured nodes in the activity.

    \sa addStructuredNode(), removeStructuredNode()

    \b {Subsetted property(ies):} QUmlActivity::groups(), QUmlActivity::nodes().

    \b {Opposite property(ies):} QUmlStructuredActivityNode::activity().
 */
const QSet<QUmlStructuredActivityNode *> QUmlActivity::structuredNodes() const
{
    // This is a read-write association end

    return _structuredNodes;
}

/*!
    Adds \a structuredNode to structuredNodes.

    \sa structuredNodes(), removeStructuredNode()
 */
void QUmlActivity::addStructuredNode(QUmlStructuredActivityNode *structuredNode)
{
    // This is a read-write association end

    if (!_structuredNodes.contains(structuredNode)) {
        _structuredNodes.insert(structuredNode);
        if (structuredNode && structuredNode->asQModelingObject() && this->asQModelingObject())
            QObject::connect(structuredNode->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeStructuredNode(QObject *)));
        structuredNode->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addGroup(structuredNode);
        addNode(structuredNode);

        // Adjust opposite properties
        if (structuredNode) {
            structuredNode->setActivity(this);
        }
    }
}

/*!
    Removes \a structuredNode from structuredNodes.

    \sa structuredNodes(), addStructuredNode()
 */
void QUmlActivity::removeStructuredNode(QUmlStructuredActivityNode *structuredNode)
{
    // This is a read-write association end

    if (_structuredNodes.contains(structuredNode)) {
        _structuredNodes.remove(structuredNode);
        if (structuredNode->asQModelingObject())
            structuredNode->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeGroup(structuredNode);
        removeNode(structuredNode);

        // Adjust opposite properties
        if (structuredNode) {
            structuredNode->setActivity(0);
        }
    }
}

/*!
    Top-level variables in the activity.

    \sa addVariable(), removeVariable()

    \b {Subsetted property(ies):} QUmlNamespace::ownedMembers().

    \b {Opposite property(ies):} QUmlVariable::activityScope().
 */
const QSet<QUmlVariable *> QUmlActivity::variables() const
{
    // This is a read-write association end

    return _variables;
}

/*!
    Adds \a variable to variables.

    \sa variables(), removeVariable()
 */
void QUmlActivity::addVariable(QUmlVariable *variable)
{
    // This is a read-write association end

    if (!_variables.contains(variable)) {
        _variables.insert(variable);
        if (variable && variable->asQModelingObject() && this->asQModelingObject())
            QObject::connect(variable->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeVariable(QObject *)));
        variable->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        addOwnedMember(variable);

        // Adjust opposite properties
        if (variable) {
            variable->setActivityScope(this);
        }
    }
}

/*!
    Removes \a variable from variables.

    \sa variables(), addVariable()
 */
void QUmlActivity::removeVariable(QUmlVariable *variable)
{
    // This is a read-write association end

    if (_variables.contains(variable)) {
        _variables.remove(variable);
        if (variable->asQModelingObject())
            variable->asQModelingObject()->setParent(0);

        // Adjust subsetted properties
        removeOwnedMember(variable);

        // Adjust opposite properties
        if (variable) {
            variable->setActivityScope(0);
        }
    }
}

QT_END_NAMESPACE

