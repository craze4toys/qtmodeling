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
#ifndef QUMLBEHAVIORALFEATURE_H
#define QUMLBEHAVIORALFEATURE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtWrappedObjects/QWrappedObject>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlFeature>

// QtUml includes
#include <QtUml/QtUmlNamespace>

// Qt includes
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

// Forward decls for function parameters
class QUmlType;
class QUmlNamedElement;
class QUmlParameterSet;
class QUmlBehavior;
class QUmlParameter;

class QUmlBehavioralFeaturePrivate;

class Q_UML_EXPORT QUmlBehavioralFeature : public QWrappedObject
{
    Q_OBJECT
    Q_CLASSINFO("MetaModelPrefix", "QUml")

    Q_PROPERTY(QSet<QUmlElement *> ownedElements READ ownedElements)
    Q_PROPERTY(QUmlElement * owner READ owner)
    Q_PROPERTY(QSet<QUmlComment *> ownedComments READ ownedComments)

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)
    Q_PROPERTY(QUmlStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QUmlNamespace * namespace_ READ namespace_)
    Q_PROPERTY(QSet<QUmlDependency *> clientDependencies READ clientDependencies)

    Q_PROPERTY(QSet<QUmlPackageImport *> packageImports READ packageImports)
    Q_PROPERTY(QSet<QUmlNamedElement *> members READ members)
    Q_PROPERTY(QSet<QUmlPackageableElement *> importedMembers READ importedMembers STORED false)
    Q_PROPERTY(QSet<QUmlElementImport *> elementImports READ elementImports)
    Q_PROPERTY(QSet<QUmlConstraint *> ownedRules READ ownedRules)
    Q_PROPERTY(QSet<QUmlNamedElement *> ownedMembers READ ownedMembers)

    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf RESET unsetLeaf)
    Q_PROPERTY(QSet<QUmlRedefinableElement *> redefinedElements READ redefinedElements)
    Q_PROPERTY(QSet<QUmlClassifier *> redefinitionContexts READ redefinitionContexts)

    Q_PROPERTY(bool isStatic READ isStatic WRITE setStatic RESET unsetStatic)
    Q_PROPERTY(QSet<QUmlClassifier *> featuringClassifiers READ featuringClassifiers)

    Q_PROPERTY(QtUml::CallConcurrencyKind concurrency READ concurrency WRITE setConcurrency RESET unsetConcurrency)
    Q_PROPERTY(bool isAbstract READ isAbstract WRITE setAbstract RESET unsetAbstract)
    Q_PROPERTY(QSet<QUmlType *> raisedExceptions READ raisedExceptions)
    Q_PROPERTY(QList<QUmlParameter *> ownedParameters READ ownedParameters)
    Q_PROPERTY(QSet<QUmlParameterSet *> ownedParameterSets READ ownedParameterSets)
    Q_PROPERTY(QSet<QUmlBehavior *> methods READ methods)

    Q_DISABLE_COPY(QUmlBehavioralFeature)
    Q_DECLARE_PRIVATE(QUmlBehavioralFeature)

public:
    Q_INVOKABLE explicit QUmlBehavioralFeature(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QUmlBehavioralFeature();

    // Association ends from aggregated QUmlElement
    Q_INVOKABLE QSet<QUmlElement *> ownedElements() const;
    Q_INVOKABLE QUmlElement *owner() const;
    Q_INVOKABLE QSet<QUmlComment *> ownedComments() const;
    Q_INVOKABLE void addOwnedComment(QUmlComment *ownedComment);
    Q_INVOKABLE void removeOwnedComment(QUmlComment *ownedComment);

    // Attributes from aggregated QUmlNamedElement
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE void setName(QString name);
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;
    Q_INVOKABLE void setVisibility(QtUml::VisibilityKind visibility);
    Q_INVOKABLE QString qualifiedName() const;

    // Association ends from aggregated QUmlNamedElement
    Q_INVOKABLE QUmlStringExpression *nameExpression() const;
    Q_INVOKABLE void setNameExpression(QUmlStringExpression *nameExpression);
    Q_INVOKABLE QUmlNamespace *namespace_() const;
    Q_INVOKABLE QSet<QUmlDependency *> clientDependencies() const;
    Q_INVOKABLE void addClientDependency(QUmlDependency *clientDependency);
    Q_INVOKABLE void removeClientDependency(QUmlDependency *clientDependency);

    // Association ends from aggregated QUmlNamespace
    Q_INVOKABLE QSet<QUmlPackageImport *> packageImports() const;
    Q_INVOKABLE void addPackageImport(QUmlPackageImport *packageImport);
    Q_INVOKABLE void removePackageImport(QUmlPackageImport *packageImport);
    Q_INVOKABLE QSet<QUmlNamedElement *> members() const;
    Q_INVOKABLE QSet<QUmlPackageableElement *> importedMembers() const;
    Q_INVOKABLE QSet<QUmlElementImport *> elementImports() const;
    Q_INVOKABLE void addElementImport(QUmlElementImport *elementImport);
    Q_INVOKABLE void removeElementImport(QUmlElementImport *elementImport);
    Q_INVOKABLE QSet<QUmlConstraint *> ownedRules() const;
    Q_INVOKABLE void addOwnedRule(QUmlConstraint *ownedRule);
    Q_INVOKABLE void removeOwnedRule(QUmlConstraint *ownedRule);
    Q_INVOKABLE QSet<QUmlNamedElement *> ownedMembers() const;

    // Attributes from aggregated QUmlRedefinableElement
    Q_INVOKABLE bool isLeaf() const;
    Q_INVOKABLE void setLeaf(bool isLeaf);
    Q_INVOKABLE void unsetLeaf();

    // Association ends from aggregated QUmlRedefinableElement
    Q_INVOKABLE QSet<QUmlRedefinableElement *> redefinedElements() const;
    Q_INVOKABLE QSet<QUmlClassifier *> redefinitionContexts() const;

    // Attributes from aggregated QUmlFeature
    Q_INVOKABLE bool isStatic() const;
    Q_INVOKABLE void setStatic(bool isStatic);
    Q_INVOKABLE void unsetStatic();

    // Association ends from aggregated QUmlFeature
    Q_INVOKABLE QSet<QUmlClassifier *> featuringClassifiers() const;

    // Attributes from QUmlBehavioralFeature
    Q_INVOKABLE QtUml::CallConcurrencyKind concurrency() const;
    Q_INVOKABLE void setConcurrency(QtUml::CallConcurrencyKind concurrency);
    Q_INVOKABLE void unsetConcurrency();
    Q_INVOKABLE bool isAbstract() const;
    Q_INVOKABLE void setAbstract(bool isAbstract);
    Q_INVOKABLE void unsetAbstract();

    // Association ends from QUmlBehavioralFeature
    Q_INVOKABLE QSet<QUmlType *> raisedExceptions() const;
    Q_INVOKABLE void addRaisedException(QUmlType *raisedException);
    Q_INVOKABLE void removeRaisedException(QUmlType *raisedException);
    Q_INVOKABLE QList<QUmlParameter *> ownedParameters() const;
    Q_INVOKABLE void addOwnedParameter(QUmlParameter *ownedParameter);
    Q_INVOKABLE void removeOwnedParameter(QUmlParameter *ownedParameter);
    Q_INVOKABLE QSet<QUmlParameterSet *> ownedParameterSets() const;
    Q_INVOKABLE void addOwnedParameterSet(QUmlParameterSet *ownedParameterSet);
    Q_INVOKABLE void removeOwnedParameterSet(QUmlParameterSet *ownedParameterSet);
    Q_INVOKABLE QSet<QUmlBehavior *> methods() const;
    Q_INVOKABLE void addMethod(QUmlBehavior *method);
    Q_INVOKABLE void removeMethod(QUmlBehavior *method);

    // Operations
    Q_INVOKABLE bool isDistinguishableFrom(const QUmlNamedElement *n, const QUmlNamespace *ns) const;

    virtual void setPropertyData();

protected:
    explicit QUmlBehavioralFeature(QUmlBehavioralFeaturePrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);

private:
    QUmlNamespace *_wrappedUmlNamespace;
    QUmlFeature *_wrappedUmlFeature;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLBEHAVIORALFEATURE_H
