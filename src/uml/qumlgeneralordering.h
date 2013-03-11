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
** rights. These rights are described in the Nokia  LGPL Exception
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
#ifndef QUMLGENERALORDERING_H
#define QUMLGENERALORDERING_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QUmlNamedElement>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

// Forward decls for function parameters
class QUmlOccurrenceSpecification;

class QUmlGeneralOrderingPrivate;

class Q_UML_EXPORT QUmlGeneralOrdering : public QUmlNamedElement
{
    Q_OBJECT
    Q_CLASSINFO("MetaModelPrefix", "QUml")

    Q_PROPERTY(QUmlOccurrenceSpecification * before READ before WRITE setBefore)
    Q_PROPERTY(QUmlOccurrenceSpecification * after READ after WRITE setAfter)

    Q_DISABLE_COPY(QUmlGeneralOrdering)
    Q_DECLARE_PRIVATE(QUmlGeneralOrdering)

public:
    Q_INVOKABLE explicit QUmlGeneralOrdering(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QUmlGeneralOrdering();

    // Association ends from QUmlGeneralOrdering
    Q_INVOKABLE QUmlOccurrenceSpecification *before() const;
    Q_INVOKABLE void setBefore(QUmlOccurrenceSpecification *before);
    Q_INVOKABLE QUmlOccurrenceSpecification *after() const;
    Q_INVOKABLE void setAfter(QUmlOccurrenceSpecification *after);

    virtual void setPropertyData();

protected:
    explicit QUmlGeneralOrdering(QUmlGeneralOrderingPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLGENERALORDERING_H
