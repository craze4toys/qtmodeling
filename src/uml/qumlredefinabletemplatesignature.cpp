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
#include "qumlredefinabletemplatesignature.h"
#include "qumlredefinabletemplatesignature_p.h"

#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlTemplateParameter>

QT_BEGIN_NAMESPACE

QUmlRedefinableTemplateSignaturePrivate::QUmlRedefinableTemplateSignaturePrivate() :
    classifier(0)
{
}

/*!
    \class QUmlRedefinableTemplateSignature

    \inmodule QtUml

    \brief A redefinable template signature supports the addition of formal template parameters in a specialization of a template classifier.
 */

QUmlRedefinableTemplateSignature::QUmlRedefinableTemplateSignature(bool create_d_ptr) :
    QUmlTemplateSignature(false),
    QUmlRedefinableElement(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlRedefinableTemplateSignaturePrivate);
}

// OWNED ATTRIBUTES

/*!
    The classifier that owns this template signature.
 */
QUmlClassifier *QUmlRedefinableTemplateSignature::classifier() const
{
    // This is a read-write association end

    QM_D(const QUmlRedefinableTemplateSignature);
    return d->classifier;
}

void QUmlRedefinableTemplateSignature::setClassifier(QUmlClassifier *classifier)
{
    // This is a read-write association end

    QM_D(QUmlRedefinableTemplateSignature);
    if (d->classifier != classifier) {
        d->classifier = classifier;
    }
}

/*!
    The template signature that is extended by this template signature.
 */
QSet<QUmlRedefinableTemplateSignature *> QUmlRedefinableTemplateSignature::extendedSignature() const
{
    // This is a read-write association end

    QM_D(const QUmlRedefinableTemplateSignature);
    return d->extendedSignature;
}

void QUmlRedefinableTemplateSignature::addExtendedSignature(QUmlRedefinableTemplateSignature *extendedSignature)
{
    // This is a read-write association end

    QM_D(QUmlRedefinableTemplateSignature);
    if (!d->extendedSignature.contains(extendedSignature)) {
        d->extendedSignature.insert(extendedSignature);
    }
}

void QUmlRedefinableTemplateSignature::removeExtendedSignature(QUmlRedefinableTemplateSignature *extendedSignature)
{
    // This is a read-write association end

    QM_D(QUmlRedefinableTemplateSignature);
    if (d->extendedSignature.contains(extendedSignature)) {
        d->extendedSignature.remove(extendedSignature);
    }
}

/*!
    The formal template parameters of the extendedSignature.
 */
QSet<QUmlTemplateParameter *> QUmlRedefinableTemplateSignature::inheritedParameter() const
{
    // This is a read-only derived association end

    qWarning("QUmlRedefinableTemplateSignature::inheritedParameter(): to be implemented (this is a derived association end)");

    return QSet<QUmlTemplateParameter *>();
}

// OPERATIONS

/*!
    The query isConsistentWith() specifies, for any two RedefinableTemplateSignatures in a context in which redefinition is possible, whether redefinition would be logically consistent. A redefining template signature is always consistent with a redefined template signature, since redefinition only adds new formal parameters.
 */
bool QUmlRedefinableTemplateSignature::isConsistentWith(QUmlRedefinableElement *redefinee) const
{
    Q_UNUSED(redefinee);
    return bool ();
}

QT_END_NAMESPACE

