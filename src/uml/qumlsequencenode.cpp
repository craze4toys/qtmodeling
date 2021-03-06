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
#include "qumlsequencenode.h"

#include "private/qumlsequencenodeobject_p.h"

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
#include <QtUml/QUmlVariable>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlSequenceNode

    \inmodule QtUml

    \brief A sequence node is a structured activity node that executes its actions in order.
 */

/*!
    Creates a new QUmlSequenceNode. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlSequenceNode::QUmlSequenceNode(bool createQModelingObject) :
    QUmlStructuredActivityNode(false)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlSequenceNodeObject(this));
}

/*!
    Destroys the QUmlSequenceNode.
 */
QUmlSequenceNode::~QUmlSequenceNode()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlSequenceNode.
*/
QModelingElement *QUmlSequenceNode::clone() const
{
    QUmlSequenceNode *c = new QUmlSequenceNode;
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
    foreach (QUmlElementImport *element, elementImports())
        c->addElementImport(dynamic_cast<QUmlElementImport *>(element->clone()));
    foreach (QUmlConstraint *element, ownedRules())
        c->addOwnedRule(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlPackageImport *element, packageImports())
        c->addPackageImport(dynamic_cast<QUmlPackageImport *>(element->clone()));
    foreach (QUmlActivityEdge *element, edges())
        c->addEdge(dynamic_cast<QUmlActivityEdge *>(element->clone()));
    c->setMustIsolate(mustIsolate());
    foreach (QUmlInputPin *element, structuredNodeInputs())
        c->addStructuredNodeInput(dynamic_cast<QUmlInputPin *>(element->clone()));
    foreach (QUmlOutputPin *element, structuredNodeOutputs())
        c->addStructuredNodeOutput(dynamic_cast<QUmlOutputPin *>(element->clone()));
    foreach (QUmlVariable *element, variables())
        c->addVariable(dynamic_cast<QUmlVariable *>(element->clone()));
    foreach (QUmlExecutableNode *element, executableNodes())
        c->addExecutableNode(dynamic_cast<QUmlExecutableNode *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    An ordered set of executable nodes.

    \sa addExecutableNode(), removeExecutableNode()

    \b {Redefined property(ies):} QUmlStructuredActivityNode::nodes().
 */
const QList<QUmlExecutableNode *> QUmlSequenceNode::executableNodes() const
{
    // This is a read-write association end

    return _executableNodes;
}

/*!
    Adds \a executableNode to executableNodes.

    \sa executableNodes(), removeExecutableNode()
 */
void QUmlSequenceNode::addExecutableNode(QUmlExecutableNode *executableNode)
{
    // This is a read-write association end

    if (!_executableNodes.contains(executableNode)) {
        _executableNodes.append(executableNode);
        if (executableNode && executableNode->asQModelingObject() && this->asQModelingObject())
            QObject::connect(executableNode->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeExecutableNode(QObject *)));
        executableNode->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust redefined properties
        QUmlStructuredActivityNode::addNode(executableNode);
    }
}

/*!
    Removes \a executableNode from executableNodes.

    \sa executableNodes(), addExecutableNode()
 */
void QUmlSequenceNode::removeExecutableNode(QUmlExecutableNode *executableNode)
{
    // This is a read-write association end

    if (_executableNodes.contains(executableNode)) {
        _executableNodes.removeAll(executableNode);
        if (executableNode->asQModelingObject())
            executableNode->asQModelingObject()->setParent(0);

        // Adjust redefined properties
        QUmlStructuredActivityNode::removeNode(executableNode);
    }
}

QT_END_NAMESPACE

