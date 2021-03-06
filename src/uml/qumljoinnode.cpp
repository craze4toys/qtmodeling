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
#include "qumljoinnode.h"

#include "private/qumljoinnodeobject_p.h"

#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>
#include <QtUml/QUmlValueSpecification>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlJoinNode

    \inmodule QtUml

    \brief A join node is a control node that synchronizes multiple flows.Join nodes have a Boolean value specification using the names of the incoming edges to specify the conditions under which the join will emit a token.
 */

/*!
    Creates a new QUmlJoinNode. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlJoinNode::QUmlJoinNode(bool createQModelingObject) :
    _isCombineDuplicate(true),
    _joinSpec(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlJoinNodeObject(this));
}

/*!
    Destroys the QUmlJoinNode.
 */
QUmlJoinNode::~QUmlJoinNode()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlJoinNode.
*/
QModelingElement *QUmlJoinNode::clone() const
{
    QUmlJoinNode *c = new QUmlJoinNode;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    c->setCombineDuplicate(isCombineDuplicate());
    if (joinSpec())
        c->setJoinSpec(dynamic_cast<QUmlValueSpecification *>(joinSpec()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Tells whether tokens having objects with the same identity are combined into one by the join.
 */
bool QUmlJoinNode::isCombineDuplicate() const
{
    // This is a read-write property

    return _isCombineDuplicate;
}

/*!
    Adjusts isCombineDuplicate to \a isCombineDuplicate.
 */
void QUmlJoinNode::setCombineDuplicate(bool isCombineDuplicate)
{
    // This is a read-write property

    if (_isCombineDuplicate != isCombineDuplicate) {
        _isCombineDuplicate = isCombineDuplicate;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("isCombineDuplicate");
    }
}

/*!
    A specification giving the conditions under which the join with emit a token. Default is 'and'.

    \b {Subsetted property(ies):} QUmlElement::ownedElements().
 */
QUmlValueSpecification *QUmlJoinNode::joinSpec() const
{
    // This is a read-write association end

    return _joinSpec;
}

/*!
    Adjusts joinSpec to \a joinSpec.
 */
void QUmlJoinNode::setJoinSpec(QUmlValueSpecification *joinSpec)
{
    // This is a read-write association end

    if (_joinSpec != joinSpec) {
        // Adjust subsetted properties
        removeOwnedElement(_joinSpec);

        _joinSpec = joinSpec;
        if (joinSpec && joinSpec->asQModelingObject() && this->asQModelingObject())
            QObject::connect(joinSpec->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setJoinSpec()));
        joinSpec->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        if (joinSpec) {
            addOwnedElement(joinSpec);
        }
    }
}

QT_END_NAMESPACE

