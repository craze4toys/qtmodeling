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
#include "qumlconsiderignorefragment.h"
#include "qumlconsiderignorefragment_p.h"

#include <QtUml/QUmlNamedElement>

QT_BEGIN_NAMESPACE

QUmlConsiderIgnoreFragmentPrivate::QUmlConsiderIgnoreFragmentPrivate()
{
}

/*!
    \class QUmlConsiderIgnoreFragment

    \inmodule QtUml

    \brief A consider ignore fragment is a kind of combined fragment that is used for the consider and ignore cases, which require lists of pertinent messages to be specified.
 */

QUmlConsiderIgnoreFragment::QUmlConsiderIgnoreFragment(bool create_d_ptr) :
    QUmlCombinedFragment(false)
{
    if (create_d_ptr)
        set_d_ptr(new QUmlConsiderIgnoreFragmentPrivate);
}

// OWNED ATTRIBUTES

/*!
    The set of messages that apply to this fragment
 */
QSet<QUmlNamedElement *> QUmlConsiderIgnoreFragment::message() const
{
    // This is a read-write association end

    QM_D(const QUmlConsiderIgnoreFragment);
    return d->message;
}

void QUmlConsiderIgnoreFragment::addMessage(QUmlNamedElement *message)
{
    // This is a read-write association end

    QM_D(QUmlConsiderIgnoreFragment);
    if (!d->message.contains(message)) {
        d->message.insert(message);
    }
}

void QUmlConsiderIgnoreFragment::removeMessage(QUmlNamedElement *message)
{
    // This is a read-write association end

    QM_D(QUmlConsiderIgnoreFragment);
    if (d->message.contains(message)) {
        d->message.remove(message);
    }
}

QT_END_NAMESPACE

