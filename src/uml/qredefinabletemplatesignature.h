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
#ifndef QTUML_QREDEFINABLETEMPLATESIGNATURE_H
#define QTUML_QREDEFINABLETEMPLATESIGNATURE_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtWrappedObjects/QWrappedObject>
#include <QtUml/QTemplateSignature>
#include <QtUml/QRedefinableElement>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QtUml
{

QT_MODULE(QtUml)

// Forward decls for function parameters
class QClassifier;
class QTemplateParameter;

class QRedefinableTemplateSignaturePrivate;

class Q_UML_EXPORT QRedefinableTemplateSignature : public QWrappedObject
{
    Q_OBJECT

    Q_PROPERTY(QSet<QtUml::QElement *> ownedElements READ ownedElements)
    Q_PROPERTY(QtUml::QElement * owner READ owner)
    Q_PROPERTY(QSet<QtUml::QComment *> ownedComments READ ownedComments)

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QtUmlNS::VisibilityKind visibility READ visibility WRITE setVisibility)
    Q_PROPERTY(QString qualifiedName READ qualifiedName STORED false)
    Q_PROPERTY(QtUml::QStringExpression * nameExpression READ nameExpression WRITE setNameExpression)
    Q_PROPERTY(QtUml::QNamespace * namespace_ READ namespace_)
    Q_PROPERTY(QSet<QtUml::QDependency *> clientDependencies READ clientDependencies)

    Q_PROPERTY(bool isLeaf READ isLeaf WRITE setLeaf RESET unsetLeaf)
    Q_PROPERTY(QSet<QtUml::QRedefinableElement *> redefinedElements READ redefinedElements)
    Q_PROPERTY(QSet<QtUml::QClassifier *> redefinitionContexts READ redefinitionContexts)

    Q_PROPERTY(QSet<QtUml::QTemplateParameter *> inheritedParameters READ inheritedParameters STORED false)
    Q_PROPERTY(QtUml::QClassifier * classifier READ classifier WRITE setClassifier)
    Q_PROPERTY(QSet<QtUml::QRedefinableTemplateSignature *> extendedSignatures READ extendedSignatures)

    Q_DISABLE_COPY(QRedefinableTemplateSignature)
    Q_DECLARE_PRIVATE(QRedefinableTemplateSignature)

public:
    Q_INVOKABLE explicit QRedefinableTemplateSignature(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QRedefinableTemplateSignature();

    // Association ends from aggregated QElement
    Q_INVOKABLE QSet<QElement *> ownedElements() const;
    Q_INVOKABLE QElement *owner() const;
    Q_INVOKABLE QSet<QComment *> ownedComments() const;
    Q_INVOKABLE void addOwnedComment(QComment *ownedComment);
    Q_INVOKABLE void removeOwnedComment(QComment *ownedComment);

    // Attributes from aggregated QNamedElement
    Q_INVOKABLE QString name() const;
    Q_INVOKABLE void setName(QString name);
    Q_INVOKABLE QtUmlNS::VisibilityKind visibility() const;
    Q_INVOKABLE void setVisibility(QtUmlNS::VisibilityKind visibility);
    Q_INVOKABLE QString qualifiedName() const;

    // Association ends from aggregated QNamedElement
    Q_INVOKABLE QStringExpression *nameExpression() const;
    Q_INVOKABLE void setNameExpression(QStringExpression *nameExpression);
    Q_INVOKABLE QNamespace *namespace_() const;
    Q_INVOKABLE QSet<QDependency *> clientDependencies() const;
    Q_INVOKABLE void addClientDependency(QDependency *clientDependency);
    Q_INVOKABLE void removeClientDependency(QDependency *clientDependency);

    // Attributes from aggregated QRedefinableElement
    Q_INVOKABLE bool isLeaf() const;
    Q_INVOKABLE void setLeaf(bool isLeaf);
    Q_INVOKABLE void unsetLeaf();

    // Association ends from aggregated QRedefinableElement
    Q_INVOKABLE QSet<QRedefinableElement *> redefinedElements() const;
    Q_INVOKABLE QSet<QClassifier *> redefinitionContexts() const;

    // Association ends from QRedefinableTemplateSignature
    Q_INVOKABLE QSet<QTemplateParameter *> inheritedParameters() const;
    Q_INVOKABLE QClassifier *classifier() const;
    Q_INVOKABLE void setClassifier(QClassifier *classifier);
    Q_INVOKABLE QSet<QRedefinableTemplateSignature *> extendedSignatures() const;
    Q_INVOKABLE void addExtendedSignature(QRedefinableTemplateSignature *extendedSignature);
    Q_INVOKABLE void removeExtendedSignature(QRedefinableTemplateSignature *extendedSignature);

    // Operations
    Q_INVOKABLE bool isConsistentWith(const QRedefinableElement *redefinee) const;

    virtual void setPropertyData();

protected:
    explicit QRedefinableTemplateSignature(QRedefinableTemplateSignaturePrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);

private:
    QTemplateSignature *_wrappedTemplateSignature;
    QRedefinableElement *_wrappedRedefinableElement;
};

}

QT_END_NAMESPACE

QT_END_HEADER

#endif // QTUML_QREDEFINABLETEMPLATESIGNATURE_H

