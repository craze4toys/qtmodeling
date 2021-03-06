/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtMof module of the Qt Toolkit.
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
#include "qmoffeature.h"

#include <QtMof/QMofClass>
#include <QtMof/QMofClassifier>
#include <QtMof/QMofComment>
#include <QtMof/QMofElement>
#include <QtMof/QMofNamedElement>
#include <QtMof/QMofNamespace>

QT_BEGIN_NAMESPACE

/*!
    \class QMofFeature

    \inmodule QtMof

    \brief A feature declares a behavioral or structural characteristic of instances of classifiers.

    \b {QMofFeature is an abstract class.}
 */

/*!
    Creates a new QMofFeature.
*/
QMofFeature::QMofFeature() :
    _isStatic(false)
{
}

/*!
    Destroys the QMofFeature.
 */
QMofFeature::~QMofFeature()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QMofFeature.
*/
QModelingElement *QMofFeature::clone() const
{
    QMofFeature *c = new QMofFeature;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QMofComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QMofComment *>(element->clone()));
    c->setName(name());
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    c->setStatic(isStatic());
    return c;
}

// OWNED ATTRIBUTES

/*!
    The Classifiers that have this Feature as a feature.

    \b {This is a read-only derived union property.}

    \b {Subsetted property(ies):} .

    \b {Opposite property(ies):} QMofClassifier::features().
 */
const QSet<QMofClassifier *> QMofFeature::featuringClassifiers() const
{
    // This is a read-only derived union association end

    return _featuringClassifiers;
}

/*!
    Adds \a featuringClassifier to featuringClassifiers.

    \sa featuringClassifiers(), removeFeaturingClassifier()
 */
void QMofFeature::addFeaturingClassifier(QMofClassifier *featuringClassifier)
{
    // This is a read-only derived union association end

    if (!_featuringClassifiers.contains(featuringClassifier)) {
        _featuringClassifiers.insert(featuringClassifier);
        if (featuringClassifier && featuringClassifier->asQModelingObject() && this->asQModelingObject())
            QObject::connect(featuringClassifier->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeFeaturingClassifier(QObject *)));

        // Adjust opposite properties
        if (featuringClassifier) {
            featuringClassifier->addFeature(this);
        }
    }
}

/*!
    Removes \a featuringClassifier from featuringClassifiers.

    \sa featuringClassifiers(), addFeaturingClassifier()
 */
void QMofFeature::removeFeaturingClassifier(QMofClassifier *featuringClassifier)
{
    // This is a read-only derived union association end

    if (_featuringClassifiers.contains(featuringClassifier)) {
        _featuringClassifiers.remove(featuringClassifier);

        // Adjust opposite properties
        if (featuringClassifier) {
            featuringClassifier->removeFeature(this);
        }
    }
}

/*!
    Specifies whether this feature characterizes individual instances classified by the classifier (false) or the classifier itself (true).
 */
bool QMofFeature::isStatic() const
{
    // This is a read-write property

    return _isStatic;
}

/*!
    Adjusts isStatic to \a isStatic.
 */
void QMofFeature::setStatic(bool isStatic)
{
    // This is a read-write property

    if (_isStatic != isStatic) {
        _isStatic = isStatic;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("isStatic");
    }
}

QT_END_NAMESPACE

