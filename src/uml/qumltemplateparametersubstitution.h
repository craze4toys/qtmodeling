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
#ifndef QUMLTEMPLATEPARAMETERSUBSTITUTION_H
#define QUMLTEMPLATEPARAMETERSUBSTITUTION_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QUmlElement>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtUml)

// Forward decls for function parameters
class QUmlParameterableElement;
class QUmlTemplateParameter;
class QUmlTemplateBinding;

class QUmlTemplateParameterSubstitutionPrivate;

class Q_UML_EXPORT QUmlTemplateParameterSubstitution : public QUmlElement
{
    Q_OBJECT
    Q_CLASSINFO("MetaModelPrefix", "QUml")

    Q_PROPERTY(QUmlParameterableElement * ownedActual READ ownedActual WRITE setOwnedActual)
    Q_PROPERTY(QUmlTemplateParameter * formal READ formal WRITE setFormal)
    Q_PROPERTY(QUmlParameterableElement * actual READ actual WRITE setActual)
    Q_PROPERTY(QUmlTemplateBinding * templateBinding READ templateBinding WRITE setTemplateBinding)

    Q_DISABLE_COPY(QUmlTemplateParameterSubstitution)
    Q_DECLARE_PRIVATE(QUmlTemplateParameterSubstitution)

public:
    Q_INVOKABLE explicit QUmlTemplateParameterSubstitution(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QUmlTemplateParameterSubstitution();

    // Association ends from QUmlTemplateParameterSubstitution
    Q_INVOKABLE QUmlParameterableElement *ownedActual() const;
    Q_INVOKABLE void setOwnedActual(QUmlParameterableElement *ownedActual);
    Q_INVOKABLE QUmlTemplateParameter *formal() const;
    Q_INVOKABLE void setFormal(QUmlTemplateParameter *formal);
    Q_INVOKABLE QUmlParameterableElement *actual() const;
    Q_INVOKABLE void setActual(QUmlParameterableElement *actual);
    Q_INVOKABLE QUmlTemplateBinding *templateBinding() const;
    Q_INVOKABLE void setTemplateBinding(QUmlTemplateBinding *templateBinding);

    virtual void setPropertyData();

protected:
    explicit QUmlTemplateParameterSubstitution(QUmlTemplateParameterSubstitutionPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QUMLTEMPLATEPARAMETERSUBSTITUTION_H
