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
#ifndef QTUML_QACTION_H
#define QTUML_QACTION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QExecutableNode>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QActionPrivate;
class QOutputPin;
class QConstraint;
class QClassifier;
class QInputPin;

class Q_UML_EXPORT QAction : public QExecutableNode
{
    Q_DISABLE_COPY(QAction)
    Q_DECLARE_PRIVATE(QAction)

public:
    virtual ~QAction();

    // Attributes
    bool isLocallyReentrant() const;
    void setLocallyReentrant(bool isLocallyReentrant);

    // Association-ends
    QClassifier *context() const;
    const QList<QInputPin *> *inputs() const;
    const QSet<QConstraint *> *localPostconditions() const;
    void addLocalPostcondition(const QConstraint *localPostcondition);
    void removeLocalPostcondition(const QConstraint *localPostcondition);
    const QSet<QConstraint *> *localPreconditions() const;
    void addLocalPrecondition(const QConstraint *localPrecondition);
    void removeLocalPrecondition(const QConstraint *localPrecondition);
    const QList<QOutputPin *> *outputs() const;

protected:
    // Synchronization functions for read-only subsetted properties
    void addInput(const QInputPin *input);
    void removeInput(const QInputPin *input);
    void addOutput(const QOutputPin *output);
    void removeOutput(const QOutputPin *output);

protected:
    explicit QAction();

private:
    QActionPrivate *d_ptr;
};

QT_END_NAMESPACE_QTUML

QT_END_HEADER

#endif // QTUML_QACTION_H
