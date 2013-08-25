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
#include "qumlbehavior.h"
#include "qumlbehavior_p.h"

#include <QtUml/QUmlBehavioralFeature>
#include <QtUml/QUmlBehavioredClassifier>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlParameter>
#include <QtUml/QUmlParameterSet>

QT_BEGIN_NAMESPACE

QUmlBehaviorPrivate::QUmlBehaviorPrivate() :
    isReentrant(true),
    specification(0)
{
}

/*!
    \class QUmlBehavior

    \inmodule QtUml

    \brief Behavior is a specification of how its context classifier changes state over time. This specification may be either a definition of possible behavior execution or emergent behavior, or a selective illustration of an interesting subset of possible executions. The latter form is typically used for capturing examples, such as a trace of a particular execution.A behavior owns zero or more parameter sets.
 */

QUmlBehavior::QUmlBehavior(bool create_d_ptr) :
    QUmlClass(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlBehaviorPrivate);
}

// OWNED ATTRIBUTES

/*!
    The classifier that is the context for the execution of the behavior. If the behavior is owned by a BehavioredClassifier, that classifier is the context. Otherwise, the context is the first BehavioredClassifier reached by following the chain of owner relationships. For example, following this algorithm, the context of an entry action in a state machine is the classifier that owns the state machine. The features of the context classifier as well as the elements visible to the context classifier are visible to the behavior.
 */
QUmlBehavioredClassifier *QUmlBehavior::context() const
{
    // This is a read-only derived association end

    qWarning("QUmlBehavior::context(): to be implemented (this is a derived association end)");

    return 0;
}

/*!
    Tells whether the behavior can be invoked while it is still executing from a previous invocation.
 */
bool QUmlBehavior::isReentrant() const
{
    // This is a read-write property

    QM_D(const QUmlBehavior);
    return d->isReentrant;
}

void QUmlBehavior::setReentrant(bool isReentrant)
{
    // This is a read-write property

    QM_D(QUmlBehavior);
    if (d->isReentrant != isReentrant) {
        d->isReentrant = isReentrant;
    }
}

/*!
    References a list of parameters to the behavior which describes the order and type of arguments that can be given when the behavior is invoked and of the values which will be returned when the behavior completes its execution.
 */
QList<QUmlParameter *> QUmlBehavior::ownedParameter() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavior);
    return d->ownedParameter;
}

void QUmlBehavior::addOwnedParameter(QUmlParameter *ownedParameter)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (!d->ownedParameter.contains(ownedParameter)) {
        d->ownedParameter.append(ownedParameter);
    }
}

void QUmlBehavior::removeOwnedParameter(QUmlParameter *ownedParameter)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (d->ownedParameter.contains(ownedParameter)) {
        d->ownedParameter.removeAll(ownedParameter);
    }
}

/*!
    The ParameterSets owned by this Behavior.
 */
QSet<QUmlParameterSet *> QUmlBehavior::ownedParameterSet() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavior);
    return d->ownedParameterSet;
}

void QUmlBehavior::addOwnedParameterSet(QUmlParameterSet *ownedParameterSet)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (!d->ownedParameterSet.contains(ownedParameterSet)) {
        d->ownedParameterSet.insert(ownedParameterSet);
    }
}

void QUmlBehavior::removeOwnedParameterSet(QUmlParameterSet *ownedParameterSet)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (d->ownedParameterSet.contains(ownedParameterSet)) {
        d->ownedParameterSet.remove(ownedParameterSet);
    }
}

/*!
    An optional set of Constraints specifying what is fulfilled after the execution of the behavior is completed, if its precondition was fulfilled before its invocation.
 */
QSet<QUmlConstraint *> QUmlBehavior::postcondition() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavior);
    return d->postcondition;
}

void QUmlBehavior::addPostcondition(QUmlConstraint *postcondition)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (!d->postcondition.contains(postcondition)) {
        d->postcondition.insert(postcondition);
    }
}

void QUmlBehavior::removePostcondition(QUmlConstraint *postcondition)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (d->postcondition.contains(postcondition)) {
        d->postcondition.remove(postcondition);
    }
}

/*!
    An optional set of Constraints specifying what must be fulfilled when the behavior is invoked.
 */
QSet<QUmlConstraint *> QUmlBehavior::precondition() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavior);
    return d->precondition;
}

void QUmlBehavior::addPrecondition(QUmlConstraint *precondition)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (!d->precondition.contains(precondition)) {
        d->precondition.insert(precondition);
    }
}

void QUmlBehavior::removePrecondition(QUmlConstraint *precondition)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (d->precondition.contains(precondition)) {
        d->precondition.remove(precondition);
    }
}

/*!
    References a behavior that this behavior redefines. A subtype of Behavior may redefine any other subtype of Behavior. If the behavior implements a behavioral feature, it replaces the redefined behavior. If the behavior is a classifier behavior, it extends the redefined behavior.
 */
QSet<QUmlBehavior *> QUmlBehavior::redefinedBehavior() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavior);
    return d->redefinedBehavior;
}

void QUmlBehavior::addRedefinedBehavior(QUmlBehavior *redefinedBehavior)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (!d->redefinedBehavior.contains(redefinedBehavior)) {
        d->redefinedBehavior.insert(redefinedBehavior);
    }
}

void QUmlBehavior::removeRedefinedBehavior(QUmlBehavior *redefinedBehavior)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (d->redefinedBehavior.contains(redefinedBehavior)) {
        d->redefinedBehavior.remove(redefinedBehavior);
    }
}

/*!
    Designates a behavioral feature that the behavior implements. The behavioral feature must be owned by the classifier that owns the behavior or be inherited by it. The parameters of the behavioral feature and the implementing behavior must match. A behavior does not need to have a specification, in which case it either is the classifer behavior of a BehavioredClassifier or it can only be invoked by another behavior of the classifier.
 */
QUmlBehavioralFeature *QUmlBehavior::specification() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavior);
    return d->specification;
}

void QUmlBehavior::setSpecification(QUmlBehavioralFeature *specification)
{
    // This is a read-write association end

    QM_D(QUmlBehavior);
    if (d->specification != specification) {
        d->specification = specification;
    }
}

QT_END_NAMESPACE

