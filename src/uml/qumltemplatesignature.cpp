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
#include "qumltemplatesignature.h"
#include "qumltemplatesignature_p.h"

#include <QtUml/QUmlTemplateableElement>
#include <QtUml/QUmlTemplateParameter>

QT_BEGIN_NAMESPACE

QUmlTemplateSignaturePrivate::QUmlTemplateSignaturePrivate() :
    template_(0)
{
}

/*!
    \class QUmlTemplateSignature

    \inmodule QtUml

    \brief A template signature bundles the set of formal template parameters for a templated element.
 */

QUmlTemplateSignature::QUmlTemplateSignature(bool create_d_ptr) :
    QUmlElement(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlTemplateSignaturePrivate);
}

// OWNED ATTRIBUTES

/*!
    The formal template parameters that are owned by this template signature.
 */
QList<QUmlTemplateParameter *> QUmlTemplateSignature::ownedParameter() const
{
    // This is a read-write association end

    QM_D(const QUmlTemplateSignature);
    return d->ownedParameter;
}

void QUmlTemplateSignature::addOwnedParameter(QUmlTemplateParameter *ownedParameter)
{
    // This is a read-write association end

    QM_D(QUmlTemplateSignature);
    if (!d->ownedParameter.contains(ownedParameter)) {
        d->ownedParameter.append(ownedParameter);
    }
}

void QUmlTemplateSignature::removeOwnedParameter(QUmlTemplateParameter *ownedParameter)
{
    // This is a read-write association end

    QM_D(QUmlTemplateSignature);
    if (d->ownedParameter.contains(ownedParameter)) {
        d->ownedParameter.removeAll(ownedParameter);
    }
}

/*!
    The ordered set of all formal template parameters for this template signature.
 */
QList<QUmlTemplateParameter *> QUmlTemplateSignature::parameter() const
{
    // This is a read-write association end

    QM_D(const QUmlTemplateSignature);
    return d->parameter;
}

void QUmlTemplateSignature::addParameter(QUmlTemplateParameter *parameter)
{
    // This is a read-write association end

    QM_D(QUmlTemplateSignature);
    if (!d->parameter.contains(parameter)) {
        d->parameter.append(parameter);
    }
}

void QUmlTemplateSignature::removeParameter(QUmlTemplateParameter *parameter)
{
    // This is a read-write association end

    QM_D(QUmlTemplateSignature);
    if (d->parameter.contains(parameter)) {
        d->parameter.removeAll(parameter);
    }
}

/*!
    The element that owns this template signature.
 */
QUmlTemplateableElement *QUmlTemplateSignature::template_() const
{
    // This is a read-write association end

    QM_D(const QUmlTemplateSignature);
    return d->template_;
}

void QUmlTemplateSignature::setTemplate(QUmlTemplateableElement *template_)
{
    // This is a read-write association end

    QM_D(QUmlTemplateSignature);
    if (d->template_ != template_) {
        d->template_ = template_;
    }
}

QT_END_NAMESPACE

