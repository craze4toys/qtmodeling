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

#include "qconnector.h"
//#include "qconnector_p.h"

QT_BEGIN_NAMESPACE_QTUML

/*!
    \class QConnector

    \inmodule QtUml

    \brief A delegation connector is a connector that links the external contract of a component (as specified by its ports) to the realization of that behavior. It represents the forwarding of events (operation requests and events): a signal that arrives at a port that has a delegation connector to one or more parts or ports on parts will be passed on to those targets for handling. An assembly connector is a connector between two or more parts or ports on parts that defines that one or more parts provide the services that other parts use.Specifies a link that enables communication between two or more instances. This link may be an instance of an association, or it may represent the possibility of the instances being able to communicate because their identities are known by virtue of being passed in as parameters, held in variables or slots, or because the communicating instances are the same instance. The link may be realized by something as simple as a pointer or by something as complex as a network connection. In contrast to associations, which specify links between any instance of the associated classifiers, connectors specify links between instances playing the connected parts only.
 */

QConnector::QConnector(QObject *parent)
    : QObject(parent)
{
}

QConnector::~QConnector()
{
}

/*!
    The set of Behaviors that specify the valid interaction patterns across the connector.
 */
const QSet<QBehavior *> *QConnector::contracts() const
{
}

void QConnector::addContract(const QBehavior *contract)
{
}

void QConnector::removeContract(const QBehavior *contract)
{
}

/*!
    A connector consists of at least two connector ends, each representing the participation of instances of the classifiers typing the connectable elements attached to this end. The set of connector ends is ordered.
 */
const QList<QConnectorEnd *> *QConnector::ends() const
{
}

void QConnector::addEnd(const QConnectorEnd *end)
{
}

void QConnector::removeEnd(const QConnectorEnd *end)
{
}

/*!
    A connector may be redefined when its containing classifier is specialized. The redefining connector may have a type that specializes the type of the redefined connector. The types of the connector ends of the redefining connector may specialize the types of the connector ends of the redefined connector. The properties of the connector ends of the redefining connector may be replaced.
 */
const QSet<QConnector *> *QConnector::redefinedConnectors() const
{
}

void QConnector::addRedefinedConnector(const QConnector *redefinedConnector)
{
}

void QConnector::removeRedefinedConnector(const QConnector *redefinedConnector)
{
}

/*!
    An optional association that specifies the link corresponding to this connector.
 */
QAssociation *QConnector::type() const
{
}

void QConnector::setType(const QAssociation *type)
{
}

/*!
    Missing derivation for Connector::/kind : ConnectorKind
 */
QtUml::ConnectorKind QConnector::kind() const
{
}

#include "moc_qconnector.cpp"

QT_END_NAMESPACE_QTUML

