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

#include "qregion.h"
#include "qregion_p.h"

#include <QtUml/QVertex>
#include <QtUml/QTransition>
#include <QtUml/QStateMachine>
#include <QtUml/QClassifier>
#include <QtUml/QState>

#include <QtWrappedObjects/QtWrappedObjectsNamespace>

QT_BEGIN_NAMESPACE

namespace QtUml
{

QRegionPrivate::QRegionPrivate() :
    extendedRegion(0),
    stateMachine(0),
    state(0)
{
}

QRegionPrivate::~QRegionPrivate()
{
}

/*!
    \class QRegion

    \inmodule QtUml

    \brief A region is an orthogonal part of either a composite state or a state machine. It contains states and transitions.
 */

QRegion::QRegion(QWrappedObject *wrapper, QWrappedObject *parent) :
    QWrappedObject(*new QRegionPrivate, wrapper, parent),
    _wrappedRedefinableElement(new QRedefinableElement(this)),
    _wrappedNamespace(new QNamespace(this))
{
    setPropertyData();
}

QRegion::QRegion(QRegionPrivate &dd, QWrappedObject *wrapper, QWrappedObject *parent) :
    QWrappedObject(dd, wrapper, parent),
    _wrappedRedefinableElement(new QRedefinableElement(this)),
    _wrappedNamespace(new QNamespace(this))
{
    setPropertyData();
}

QRegion::~QRegion()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
QSet<QElement *> QRegion::ownedElements() const
{
    return (qwrappedobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QRegion::owner() const
{
    return (qwrappedobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
QSet<QComment *> QRegion::ownedComments() const
{
    return (qwrappedobject_cast<const QElement *>(this))->ownedComments();
}

void QRegion::addOwnedComment(QComment *ownedComment)
{
    (qwrappedobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QRegion::removeOwnedComment(QComment *ownedComment)
{
    (qwrappedobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The name of the NamedElement.
 */
QString QRegion::name() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->name();
}

void QRegion::setName(QString name)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setName(name);
}

/*!
    Determines where the NamedElement appears within different Namespaces within the overall model, and its accessibility.
 */
QtUmlNS::VisibilityKind QRegion::visibility() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->visibility();
}

void QRegion::setVisibility(QtUmlNS::VisibilityKind visibility)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setVisibility(visibility);
}

/*!
    A name which allows the NamedElement to be identified within a hierarchy of nested Namespaces. It is constructed from the names of the containing namespaces starting at the root of the hierarchy and ending with the name of the NamedElement itself.
 */
QString QRegion::qualifiedName() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->qualifiedName();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamedElement
// ---------------------------------------------------------------

/*!
    The string expression used to define the name of this named element.
 */
QStringExpression *QRegion::nameExpression() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->nameExpression();
}

void QRegion::setNameExpression(QStringExpression *nameExpression)
{
    (qwrappedobject_cast<QNamedElement *>(this))->setNameExpression(nameExpression);
}

/*!
    Specifies the namespace that owns the NamedElement.
 */
QNamespace *QRegion::namespace_() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->namespace_();
}

/*!
    Indicates the dependencies that reference the client.
 */
QSet<QDependency *> QRegion::clientDependencies() const
{
    return (qwrappedobject_cast<const QNamedElement *>(this))->clientDependencies();
}

void QRegion::addClientDependency(QDependency *clientDependency)
{
    (qwrappedobject_cast<QNamedElement *>(this))->addClientDependency(clientDependency);
}

void QRegion::removeClientDependency(QDependency *clientDependency)
{
    (qwrappedobject_cast<QNamedElement *>(this))->removeClientDependency(clientDependency);
}

// ---------------------------------------------------------------
// ATTRIBUTES FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    Indicates whether it is possible to further redefine a RedefinableElement. If the value is true, then it is not possible to further redefine the RedefinableElement. Note that this property is preserved through package merge operations; that is, the capability to redefine a RedefinableElement (i.e., isLeaf=false) must be preserved in the resulting RedefinableElement of a package merge operation where a RedefinableElement with isLeaf=false is merged with a matching RedefinableElement with isLeaf=true: the resulting RedefinableElement will have isLeaf=false. Default value is false.
 */
bool QRegion::isLeaf() const
{
    return (qwrappedobject_cast<const QRedefinableElement *>(this))->isLeaf();
}

void QRegion::setLeaf(bool isLeaf)
{
    (qwrappedobject_cast<QRedefinableElement *>(this))->setLeaf(isLeaf);
}

void QRegion::unsetLeaf()
{
    setLeaf(false);
    Q_D(QRegion);
    d->modifiedResettableProperties.removeAll(QString::fromLatin1("isLeaf"));
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QRedefinableElement
// ---------------------------------------------------------------

/*!
    The redefinable element that is being redefined by this element.
 */
QSet<QRedefinableElement *> QRegion::redefinedElements() const
{
    return (qwrappedobject_cast<const QRedefinableElement *>(this))->redefinedElements();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QNamespace
// ---------------------------------------------------------------

/*!
    References the PackageImports owned by the Namespace.
 */
QSet<QPackageImport *> QRegion::packageImports() const
{
    return (qwrappedobject_cast<const QNamespace *>(this))->packageImports();
}

void QRegion::addPackageImport(QPackageImport *packageImport)
{
    (qwrappedobject_cast<QNamespace *>(this))->addPackageImport(packageImport);
}

void QRegion::removePackageImport(QPackageImport *packageImport)
{
    (qwrappedobject_cast<QNamespace *>(this))->removePackageImport(packageImport);
}

/*!
    A collection of NamedElements identifiable within the Namespace, either by being owned or by being introduced by importing or inheritance.
 */
QSet<QNamedElement *> QRegion::members() const
{
    return (qwrappedobject_cast<const QNamespace *>(this))->members();
}

/*!
    References the PackageableElements that are members of this Namespace as a result of either PackageImports or ElementImports.
 */
QSet<QPackageableElement *> QRegion::importedMembers() const
{
    return (qwrappedobject_cast<const QNamespace *>(this))->importedMembers();
}

/*!
    References the ElementImports owned by the Namespace.
 */
QSet<QElementImport *> QRegion::elementImports() const
{
    return (qwrappedobject_cast<const QNamespace *>(this))->elementImports();
}

void QRegion::addElementImport(QElementImport *elementImport)
{
    (qwrappedobject_cast<QNamespace *>(this))->addElementImport(elementImport);
}

void QRegion::removeElementImport(QElementImport *elementImport)
{
    (qwrappedobject_cast<QNamespace *>(this))->removeElementImport(elementImport);
}

/*!
    Specifies a set of Constraints owned by this Namespace.
 */
QSet<QConstraint *> QRegion::ownedRules() const
{
    return (qwrappedobject_cast<const QNamespace *>(this))->ownedRules();
}

void QRegion::addOwnedRule(QConstraint *ownedRule)
{
    (qwrappedobject_cast<QNamespace *>(this))->addOwnedRule(ownedRule);
}

void QRegion::removeOwnedRule(QConstraint *ownedRule)
{
    (qwrappedobject_cast<QNamespace *>(this))->removeOwnedRule(ownedRule);
}

/*!
    A collection of NamedElements owned by the Namespace.
 */
QSet<QNamedElement *> QRegion::ownedMembers() const
{
    return (qwrappedobject_cast<const QNamespace *>(this))->ownedMembers();
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QRegion
// ---------------------------------------------------------------

/*!
    The region of which this region is an extension.
 */
QRegion *QRegion::extendedRegion() const
{
    // This is a read-write association end

    Q_D(const QRegion);
    return d->extendedRegion;
}

void QRegion::setExtendedRegion(QRegion *extendedRegion)
{
    // This is a read-write association end

    Q_D(QRegion);
    if (d->extendedRegion != extendedRegion) {
        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QRedefinableElementPrivate *>(d))->removeRedefinedElement(qwrappedobject_cast<QRedefinableElement *>(d->extendedRegion));

        d->extendedRegion = extendedRegion;

        // Adjust subsetted property(ies)
        if (extendedRegion) {
            (qwrappedobject_cast<QRedefinableElementPrivate *>(d))->addRedefinedElement(qwrappedobject_cast<QRedefinableElement *>(extendedRegion));
        }
    }
}

/*!
    The set of transitions owned by the region.
 */
QSet<QTransition *> QRegion::transitions() const
{
    // This is a read-write association end

    Q_D(const QRegion);
    return d->transitions;
}

void QRegion::addTransition(QTransition *transition)
{
    // This is a read-write association end

    Q_D(QRegion);
    if (!d->transitions.contains(transition)) {
        d->transitions.insert(transition);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qwrappedobject_cast<QNamedElement *>(transition));

        // Adjust opposite property
        transition->setContainer(this);
    }
}

void QRegion::removeTransition(QTransition *transition)
{
    // This is a read-write association end

    Q_D(QRegion);
    if (d->transitions.contains(transition)) {
        d->transitions.remove(transition);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qwrappedobject_cast<QNamedElement *>(transition));

        // Adjust opposite property
        transition->setContainer(0);
    }
}

/*!
    The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.
 */
QStateMachine *QRegion::stateMachine() const
{
    // This is a read-write association end

    Q_D(const QRegion);
    return d->stateMachine;
}

void QRegion::setStateMachine(QStateMachine *stateMachine)
{
    // This is a read-write association end

    Q_D(QRegion);
    if (d->stateMachine != stateMachine) {
        // Adjust opposite property
        if (d->stateMachine)
            d->stateMachine->removeRegion(this);

        d->stateMachine = stateMachine;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamedElementPrivate *>(d))->setNamespace_(qwrappedobject_cast<QNamespace *>(stateMachine));

        // Adjust opposite property
        if (stateMachine)
            stateMachine->addRegion(this);
    }
}

/*!
    The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.
 */
QState *QRegion::state() const
{
    // This is a read-write association end

    Q_D(const QRegion);
    return d->state;
}

void QRegion::setState(QState *state)
{
    // This is a read-write association end

    Q_D(QRegion);
    if (d->state != state) {
        // Adjust opposite property
        if (d->state)
            d->state->removeRegion(this);

        d->state = state;

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamedElementPrivate *>(d))->setNamespace_(qwrappedobject_cast<QNamespace *>(state));

        // Adjust opposite property
        if (state)
            state->addRegion(this);
    }
}

/*!
    References the classifier in which context this element may be redefined.
 */
QClassifier *QRegion::redefinitionContext() const
{
    // This is a read-only derived association end

    qWarning("QRegion::redefinitionContext: to be implemented (this is a derived associationend)");

    return 0; // change here to your derived return
}

/*!
    The set of vertices that are owned by this region.
 */
QSet<QVertex *> QRegion::subvertices() const
{
    // This is a read-write association end

    Q_D(const QRegion);
    return d->subvertices;
}

void QRegion::addSubvertex(QVertex *subvertex)
{
    // This is a read-write association end

    Q_D(QRegion);
    if (!d->subvertices.contains(subvertex)) {
        d->subvertices.insert(subvertex);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamespacePrivate *>(d))->addOwnedMember(qwrappedobject_cast<QNamedElement *>(subvertex));

        // Adjust opposite property
        subvertex->setContainer(this);
    }
}

void QRegion::removeSubvertex(QVertex *subvertex)
{
    // This is a read-write association end

    Q_D(QRegion);
    if (d->subvertices.contains(subvertex)) {
        d->subvertices.remove(subvertex);

        // Adjust subsetted property(ies)
        (qwrappedobject_cast<QNamespacePrivate *>(d))->removeOwnedMember(qwrappedobject_cast<QNamedElement *>(subvertex));

        // Adjust opposite property
        subvertex->setContainer(0);
    }
}

/*!
    The operation belongsToPSM () checks if the region belongs to a protocol state machine
 */
bool QRegion::belongsToPSM() const
{
    qWarning("QRegion::belongsToPSM: operation to be implemented");

    return bool(); // change here to your derived return
}

/*!
    The operation containingStateMachine() returns the sate machine in which this Region is defined
 */
QStateMachine *QRegion::containingStateMachine() const
{
    qWarning("QRegion::containingStateMachine: operation to be implemented");

    return 0; // change here to your derived return
}

/*!
    The query isConsistentWith() specifies that a redefining region is consistent with a redefined region provided that the redefining region is an extension of the redefined region, i.e. it adds vertices and transitions and it redefines states and transitions of the redefined region.
 */
bool QRegion::isConsistentWith(const QRedefinableElement *redefinee) const
{
    qWarning("QRegion::isConsistentWith: operation to be implemented");
    Q_UNUSED(redefinee);

    return bool(); // change here to your derived return
}

/*!
    The query isRedefinitionContextValid() specifies whether the redefinition contexts of a region are properly related to the redefinition contexts of the specified region to allow this element to redefine the other. The containing statemachine/state of a redefining region must redefine the containing statemachine/state of the redefined region.
 */
bool QRegion::isRedefinitionContextValid(const QRegion *redefined) const
{
    qWarning("QRegion::isRedefinitionContextValid: operation to be implemented");
    Q_UNUSED(redefined);

    return bool(); // change here to your derived return
}

void QRegion::setPropertyData()
{
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("extendedRegion")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("extendedRegion")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("extendedRegion")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The region of which this region is an extension.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("extendedRegion")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("extendedRegion")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QRedefinableElement::redefinedElements");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("extendedRegion")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("transitions")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("transitions")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("transitions")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The set of transitions owned by the region.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("transitions")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("transitions")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QNamespace::ownedMembers");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("transitions")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QTransition::container");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("stateMachine")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("stateMachine")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("stateMachine")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The StateMachine that owns the Region. If a Region is owned by a StateMachine, then it cannot also be owned by a State.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("stateMachine")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("stateMachine")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QNamedElement::namespace");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("stateMachine")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QStateMachine::region");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("state")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("state")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("state")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The State that owns the Region. If a Region is owned by a State, then it cannot also be owned by a StateMachine.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("state")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("state")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QNamedElement::namespace");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("state")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QState::region");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("redefinitionContext")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("none");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("redefinitionContext")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("redefinitionContext")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("References the classifier in which context this element may be redefined.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("redefinitionContext")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("QRedefinableElement::redefinitionContexts");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("redefinitionContext")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("redefinitionContext")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("");

    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("subvertices")][QtWrappedObjects::AggregationRole] = QString::fromLatin1("composite");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("subvertices")][QtWrappedObjects::IsDerivedUnionRole] = false;
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("subvertices")][QtWrappedObjects::DocumentationRole] = QString::fromLatin1("The set of vertices that are owned by this region.");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("subvertices")][QtWrappedObjects::RedefinedPropertiesRole] = QString::fromLatin1("");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("subvertices")][QtWrappedObjects::SubsettedPropertiesRole] = QString::fromLatin1("QNamespace::ownedMembers");
    QWrappedObject::propertyDataHash[QString::fromLatin1("QtUml::QRegion")][QString::fromLatin1("subvertices")][QtWrappedObjects::OppositeEndRole] = QString::fromLatin1("QVertex::container");

    QWrappedObject::setPropertyData();
}

}

QT_END_NAMESPACE

#include "moc_qregion.cpp"

