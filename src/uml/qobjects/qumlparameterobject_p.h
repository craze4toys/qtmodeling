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
#ifndef QUMLPARAMETEROBJECT_H
#define QUMLPARAMETEROBJECT_H

#include <QtUml/QtUmlGlobal>

#include <QtModeling/QModelingObject>

#include <QtUml/QtUmlNamespace>

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

class QUmlParameter;
class QModelingObjectPrivate;
class Q_UML_EXPORT QUmlParameterObject : public QModelingObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QUmlParameterObject)
    Q_DECLARE_PRIVATE(QModelingObject)

    // Properties [Element]
    Q_PROPERTY(QSet<QObject *> ownedComments READ ownedComments NOTIFY ownedCommentsChanged)
    Q_PROPERTY(QSet<QObject *> ownedElements READ ownedElements NOTIFY ownedElementsChanged)
    Q_PROPERTY(QObject * owner READ owner NOTIFY ownerChanged)

    // Properties [MultiplicityElement]
    Q_PROPERTY(bool isOrdered READ isOrdered WRITE setOrdered NOTIFY isOrderedChanged RESET unsetOrdered)
    Q_PROPERTY(bool isUnique READ isUnique WRITE setUnique NOTIFY isUniqueChanged RESET unsetUnique)
    Q_PROPERTY(int lower READ lower WRITE setLower NOTIFY lowerChanged RESET unsetLower STORED false)
    Q_PROPERTY(QObject * lowerValue READ lowerValue WRITE setLowerValue NOTIFY lowerValueChanged)
    Q_PROPERTY(QString upper READ upper WRITE setUpper NOTIFY upperChanged RESET unsetUpper STORED false)
    Q_PROPERTY(QObject * upperValue READ upperValue WRITE setUpperValue NOTIFY upperValueChanged)

    // Properties [NamedElement]
    Q_PROPERTY(QSet<QObject *> clientDependencies READ clientDependencies NOTIFY clientDependenciesChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QObject * nameExpression READ nameExpression WRITE setNameExpression NOTIFY nameExpressionChanged)
    Q_PROPERTY(QObject * namespace_ READ namespace_ NOTIFY namespaceChanged)
    Q_PROPERTY(QString qualifiedName READ qualifiedName NOTIFY qualifiedNameChanged STORED false)
    Q_PROPERTY(QtUml::VisibilityKind visibility READ visibility WRITE setVisibility NOTIFY visibilityChanged)

    // Properties [TypedElement]
    Q_PROPERTY(QObject * type READ type WRITE setType NOTIFY typeChanged)

    // Properties [ParameterableElement]
    Q_PROPERTY(QObject * owningTemplateParameter READ owningTemplateParameter WRITE setOwningTemplateParameter NOTIFY owningTemplateParameterChanged)

    // Properties [ConnectableElement]
    Q_PROPERTY(QList<QObject *> ends READ ends NOTIFY endsChanged STORED false)
    Q_PROPERTY(QObject * templateParameter READ templateParameter WRITE setTemplateParameter NOTIFY templateParameterChanged)

    // Properties [Parameter]
    Q_PROPERTY(QString default_ READ default_ WRITE setDefault NOTIFY defaultChanged STORED false)
    Q_PROPERTY(QObject * defaultValue READ defaultValue WRITE setDefaultValue NOTIFY defaultValueChanged)
    Q_PROPERTY(QtUml::ParameterDirectionKind direction READ direction WRITE setDirection NOTIFY directionChanged RESET unsetDirection)
    Q_PROPERTY(QtUml::ParameterEffectKind effect READ effect WRITE setEffect NOTIFY effectChanged)
    Q_PROPERTY(bool isException READ isException WRITE setException NOTIFY isExceptionChanged RESET unsetException)
    Q_PROPERTY(bool isStream READ isStream WRITE setStream NOTIFY isStreamChanged RESET unsetStream)
    Q_PROPERTY(QObject * operation READ operation WRITE setOperation NOTIFY operationChanged)
    Q_PROPERTY(QSet<QObject *> parameterSets READ parameterSets NOTIFY parameterSetsChanged)

public:
    Q_INVOKABLE explicit QUmlParameterObject(QUmlParameter *modelingElement);

    // Owned attributes [Element]
    Q_INVOKABLE const QSet<QObject *> ownedComments() const;
    Q_INVOKABLE const QSet<QObject *> ownedElements() const;
    Q_INVOKABLE QObject *owner() const;

    // Owned attributes [MultiplicityElement]
    Q_INVOKABLE bool isOrdered() const;
    Q_INVOKABLE bool isUnique() const;
    Q_TODO Q_INVOKABLE int lower() const;
    Q_INVOKABLE QObject *lowerValue() const;
    Q_TODO Q_INVOKABLE QString upper() const;
    Q_INVOKABLE QObject *upperValue() const;

    // Owned attributes [NamedElement]
    Q_INVOKABLE const QSet<QObject *> clientDependencies() const;
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE QObject *nameExpression() const;
    Q_INVOKABLE QObject *namespace_() const;
    Q_INVOKABLE QString qualifiedName() const;
    Q_INVOKABLE QtUml::VisibilityKind visibility() const;

    // Owned attributes [TypedElement]
    Q_INVOKABLE QObject *type() const;

    // Owned attributes [ParameterableElement]
    Q_INVOKABLE QObject *owningTemplateParameter() const;

    // Owned attributes [ConnectableElement]
    Q_TODO Q_INVOKABLE const QList<QObject *> ends() const;
    Q_INVOKABLE QObject *templateParameter() const;

    // Owned attributes [Parameter]
    Q_TODO Q_INVOKABLE QString default_() const;
    Q_INVOKABLE QObject *defaultValue() const;
    Q_INVOKABLE QtUml::ParameterDirectionKind direction() const;
    Q_INVOKABLE QtUml::ParameterEffectKind effect() const;
    Q_INVOKABLE bool isException() const;
    Q_INVOKABLE bool isStream() const;
    Q_INVOKABLE QObject *operation() const;
    Q_INVOKABLE const QSet<QObject *> parameterSets() const;

    // Operations [Element]
    Q_INVOKABLE QSet<QObject *> allOwnedElements() const;
    Q_INVOKABLE bool mustBeOwned() const;

    // Operations [MultiplicityElement]
    Q_TODO Q_INVOKABLE bool compatibleWith(QObject *other) const;
    Q_TODO Q_INVOKABLE bool includesCardinality(int C) const;
    Q_TODO Q_INVOKABLE bool includesMultiplicity(QObject *M) const;
    Q_TODO Q_INVOKABLE bool is(int lowerbound, int upperbound) const;
    Q_TODO Q_INVOKABLE bool isMultivalued() const;
    Q_TODO Q_INVOKABLE int lowerBound() const;
    Q_TODO Q_INVOKABLE QString upperBoundOperation() const;

    // Operations [NamedElement]
    Q_INVOKABLE QList<QObject *> allNamespaces() const;
    Q_TODO Q_INVOKABLE QSet<QObject *> allOwningPackages() const;
    Q_TODO Q_INVOKABLE bool isDistinguishableFrom(QObject *n, QObject *ns) const;
    Q_INVOKABLE QString separator() const;

    // Operations [ParameterableElement]
    Q_TODO Q_INVOKABLE bool isCompatibleWith(QObject *p) const;
    Q_TODO Q_INVOKABLE bool isTemplateParameter() const;

public Q_SLOTS:

    // Slots for owned attributes [Element]
    void addOwnedComment(QObject *ownedComment);
    void removeOwnedComment(QObject *ownedComment);
    void Q_DECL_HIDDEN addOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN removeOwnedElement(QObject *ownedElement);
    void Q_DECL_HIDDEN setOwner(QObject *owner = 0);

    // Slots for owned attributes [MultiplicityElement]
    void setOrdered(bool isOrdered);
    void unsetOrdered();
    void setUnique(bool isUnique);
    void unsetUnique();
    void setLower(int lower);
    void unsetLower();
    void setLowerValue(QObject *lowerValue = 0);
    void setUpper(QString upper);
    void unsetUpper();
    void setUpperValue(QObject *upperValue = 0);

    // Slots for owned attributes [NamedElement]
    void addClientDependency(QObject *clientDependency);
    void removeClientDependency(QObject *clientDependency);
    void setName(QString name);
    void setNameExpression(QObject *nameExpression = 0);
    void Q_DECL_HIDDEN setNamespace(QObject *namespace_ = 0);
    void Q_DECL_HIDDEN setQualifiedName(QString qualifiedName);
    void setVisibility(QtUml::VisibilityKind visibility);

    // Slots for owned attributes [TypedElement]
    void setType(QObject *type = 0);

    // Slots for owned attributes [ParameterableElement]
    void setOwningTemplateParameter(QObject *owningTemplateParameter = 0);

    // Slots for owned attributes [ConnectableElement]
    void Q_DECL_HIDDEN addEnd(QObject *end);
    void Q_DECL_HIDDEN removeEnd(QObject *end);
    void setTemplateParameter(QObject *templateParameter = 0);

    // Slots for owned attributes [Parameter]
    void setDefault(QString default_);
    void setDefaultValue(QObject *defaultValue = 0);
    void setDirection(QtUml::ParameterDirectionKind direction);
    void unsetDirection();
    void setEffect(QtUml::ParameterEffectKind effect);
    void setException(bool isException);
    void unsetException();
    void setStream(bool isStream);
    void unsetStream();
    void setOperation(QObject *operation = 0);
    void addParameterSet(QObject *parameterSet);
    void removeParameterSet(QObject *parameterSet);

Q_SIGNALS:

    // Signals for owned attributes [Element]
    void ownedCommentsChanged(QSet<QObject *> ownedComments);
    void ownedElementsChanged(QSet<QObject *> ownedElements);
    void ownerChanged(QObject *owner);

    // Signals for owned attributes [MultiplicityElement]
    void isOrderedChanged(bool isOrdered);
    void isUniqueChanged(bool isUnique);
    void lowerChanged(int lower);
    void lowerValueChanged(QObject *lowerValue);
    void upperChanged(QString upper);
    void upperValueChanged(QObject *upperValue);

    // Signals for owned attributes [NamedElement]
    void clientDependenciesChanged(QSet<QObject *> clientDependencies);
    void nameChanged(QString name);
    void nameExpressionChanged(QObject *nameExpression);
    void namespaceChanged(QObject *namespace_);
    void qualifiedNameChanged(QString qualifiedName);
    void visibilityChanged(QtUml::VisibilityKind visibility);

    // Signals for owned attributes [TypedElement]
    void typeChanged(QObject *type);

    // Signals for owned attributes [ParameterableElement]
    void owningTemplateParameterChanged(QObject *owningTemplateParameter);

    // Signals for owned attributes [ConnectableElement]
    void endsChanged(QList<QObject *> ends);
    void templateParameterChanged(QObject *templateParameter);

    // Signals for owned attributes [Parameter]
    void defaultChanged(QString default_);
    void defaultValueChanged(QObject *defaultValue);
    void directionChanged(QtUml::ParameterDirectionKind direction);
    void effectChanged(QtUml::ParameterEffectKind effect);
    void isExceptionChanged(bool isException);
    void isStreamChanged(bool isStream);
    void operationChanged(QObject *operation);
    void parameterSetsChanged(QSet<QObject *> parameterSets);

protected:
    virtual void setGroupProperties();
    virtual void setPropertyData();
};

QT_END_NAMESPACE

#endif // QUMLPARAMETEROBJECT_H

