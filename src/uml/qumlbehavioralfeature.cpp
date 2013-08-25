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
#include "qumlbehavioralfeature.h"
#include "qumlbehavioralfeature_p.h"

#include <QtUml/QUmlBehavior>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlParameter>
#include <QtUml/QUmlParameterSet>
#include <QtUml/QUmlType>

QT_BEGIN_NAMESPACE

QUmlBehavioralFeaturePrivate::QUmlBehavioralFeaturePrivate() :
    concurrency(QtUml::CallConcurrencySequential),
    isAbstract(false)
{
}

/*!
    \class QUmlBehavioralFeature

    \inmodule QtUml

    \brief A behavioral feature is a feature of a classifier that specifies an aspect of the behavior of its instances.A behavioral feature is implemented (realized) by a behavior. A behavioral feature specifies that a classifier will respond to a designated request by invoking its implementing method.A behavioral feature owns zero or more parameter sets.
 */

QUmlBehavioralFeature::QUmlBehavioralFeature(bool create_d_ptr) :
    QUmlNamespace(false),
    QUmlFeature(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlBehavioralFeaturePrivate);
}

// OWNED ATTRIBUTES

/*!
    Specifies the semantics of concurrent calls to the same passive instance (i.e., an instance originating from a class with isActive being false). Active instances control access to their own behavioral features.
 */
QtUml::CallConcurrencyKind QUmlBehavioralFeature::concurrency() const
{
    // This is a read-write property

    QM_D(const QUmlBehavioralFeature);
    return d->concurrency;
}

void QUmlBehavioralFeature::setConcurrency(QtUml::CallConcurrencyKind concurrency)
{
    // This is a read-write property

    QM_D(QUmlBehavioralFeature);
    if (d->concurrency != concurrency) {
        d->concurrency = concurrency;
    }
}

/*!
    If true, then the behavioral feature does not have an implementation, and one must be supplied by a more specific element. If false, the behavioral feature must have an implementation in the classifier or one must be inherited from a more general element.
 */
bool QUmlBehavioralFeature::isAbstract() const
{
    // This is a read-write property

    QM_D(const QUmlBehavioralFeature);
    return d->isAbstract;
}

void QUmlBehavioralFeature::setAbstract(bool isAbstract)
{
    // This is a read-write property

    QM_D(QUmlBehavioralFeature);
    if (d->isAbstract != isAbstract) {
        d->isAbstract = isAbstract;
    }
}

/*!
    A behavioral description that implements the behavioral feature. There may be at most one behavior for a particular pairing of a classifier (as owner of the behavior) and a behavioral feature (as specification of the behavior).
 */
QSet<QUmlBehavior *> QUmlBehavioralFeature::method() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavioralFeature);
    return d->method;
}

void QUmlBehavioralFeature::addMethod(QUmlBehavior *method)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (!d->method.contains(method)) {
        d->method.insert(method);
    }
}

void QUmlBehavioralFeature::removeMethod(QUmlBehavior *method)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (d->method.contains(method)) {
        d->method.remove(method);
    }
}

/*!
    Specifies the ordered set of formal parameters of this BehavioralFeature.
 */
QList<QUmlParameter *> QUmlBehavioralFeature::ownedParameter() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavioralFeature);
    return d->ownedParameter;
}

void QUmlBehavioralFeature::addOwnedParameter(QUmlParameter *ownedParameter)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (!d->ownedParameter.contains(ownedParameter)) {
        d->ownedParameter.append(ownedParameter);
    }
}

void QUmlBehavioralFeature::removeOwnedParameter(QUmlParameter *ownedParameter)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (d->ownedParameter.contains(ownedParameter)) {
        d->ownedParameter.removeAll(ownedParameter);
    }
}

/*!
    The ParameterSets owned by this BehavioralFeature.
 */
QSet<QUmlParameterSet *> QUmlBehavioralFeature::ownedParameterSet() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavioralFeature);
    return d->ownedParameterSet;
}

void QUmlBehavioralFeature::addOwnedParameterSet(QUmlParameterSet *ownedParameterSet)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (!d->ownedParameterSet.contains(ownedParameterSet)) {
        d->ownedParameterSet.insert(ownedParameterSet);
    }
}

void QUmlBehavioralFeature::removeOwnedParameterSet(QUmlParameterSet *ownedParameterSet)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (d->ownedParameterSet.contains(ownedParameterSet)) {
        d->ownedParameterSet.remove(ownedParameterSet);
    }
}

/*!
    References the Types representing exceptions that may be raised during an invocation of this feature.
 */
QSet<QUmlType *> QUmlBehavioralFeature::raisedException() const
{
    // This is a read-write association end

    QM_D(const QUmlBehavioralFeature);
    return d->raisedException;
}

void QUmlBehavioralFeature::addRaisedException(QUmlType *raisedException)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (!d->raisedException.contains(raisedException)) {
        d->raisedException.insert(raisedException);
    }
}

void QUmlBehavioralFeature::removeRaisedException(QUmlType *raisedException)
{
    // This is a read-write association end

    QM_D(QUmlBehavioralFeature);
    if (d->raisedException.contains(raisedException)) {
        d->raisedException.remove(raisedException);
    }
}

// OPERATIONS

/*!
    The query isDistinguishableFrom() determines whether two BehavioralFeatures may coexist in the same Namespace. It specifies that they have to have different signatures.
 */
bool QUmlBehavioralFeature::isDistinguishableFrom(QUmlNamedElement *n, QUmlNamespace *ns) const
{
    Q_UNUSED(n);
    Q_UNUSED(ns);
    return bool ();
}

QT_END_NAMESPACE

