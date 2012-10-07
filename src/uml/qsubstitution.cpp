/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qsubstitution.h"

#include <QtUml/QClassifier>

QT_BEGIN_NAMESPACE_QTUML

class QSubstitutionPrivate
{
public:
    explicit QSubstitutionPrivate();
    virtual ~QSubstitutionPrivate();

    QClassifier *contract;
    QClassifier *substitutingClassifier;
};

QSubstitutionPrivate::QSubstitutionPrivate() :
    contract(0),
    substitutingClassifier(0)
{
}

QSubstitutionPrivate::~QSubstitutionPrivate()
{
}

/*!
    \class QSubstitution

    \inmodule QtUml

    \brief A substitution is a relationship between two classifiers signifies that the substituting classifier complies with the contract specified by the contract classifier. This implies that instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
 */

QSubstitution::QSubstitution(QObject *parent)
    : QRealization(parent), d_ptr(new QSubstitutionPrivate)
{
}

QSubstitution::~QSubstitution()
{
    delete d_ptr;
}

/*!
    The contract with which the substituting classifier complies.
 */
QClassifier *QSubstitution::contract() const
{
    return d_ptr->contract;
}

void QSubstitution::setContract(const QClassifier *contract)
{
    d_ptr->contract = const_cast<QClassifier *>(contract);
}

/*!
    Instances of the substituting classifier are runtime substitutable where instances of the contract classifier are expected.
 */
QClassifier *QSubstitution::substitutingClassifier() const
{
    return d_ptr->substitutingClassifier;
}

void QSubstitution::setSubstitutingClassifier(const QClassifier *substitutingClassifier)
{
    d_ptr->substitutingClassifier = const_cast<QClassifier *>(substitutingClassifier);
}

#include "moc_qsubstitution.cpp"

QT_END_NAMESPACE_QTUML

