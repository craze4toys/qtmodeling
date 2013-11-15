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
#include "designspaceexplorerplugin.h"

#include <duseinterfaces/iuicontroller.h>

#include <QtQuick/QQuickView>

#include <QtWidgets/QAction>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

#include <QtCore/QFileInfo>

#include <QtModeling/QXmiReader>
#include <QtModeling/QModelingElement>

#include "newdusedesigndialog.h"

DesignSpaceExplorerPlugin::DesignSpaceExplorerPlugin(QObject *parent) :
    DuSE::IPlugin(parent),
    _currentDesignSpaceLocationQuickView(new QQuickView),
    _metricsQuickView(new QQuickView),
    _designSpaceExplorer(new QTableWidget),
    _newDuseDesignDialog(new NewDuseDesignDialog)
{
}

DesignSpaceExplorerPlugin::~DesignSpaceExplorerPlugin()
{
    delete _newDuseDesignDialog;
}

bool DesignSpaceExplorerPlugin::initialize(DuSE::ICore *core)
{
    _currentDesignSpaceLocationQuickView->setSource(QUrl("qrc:/designspaceexplorer/currentdesignspacelocation.qml"));
    _currentDesignSpaceLocationQuickView->setResizeMode(QQuickView::SizeRootObjectToView);

    core->uiController()->addCentralWidgetTab(QWidget::createWindowContainer(_currentDesignSpaceLocationQuickView), "Current Design Space Location");

    _metricsQuickView->setSource(QUrl("qrc:/designspaceexplorer/qualitymetrics/qualitymetrics.qml"));
    _metricsQuickView->setResizeMode(QQuickView::SizeRootObjectToView);

    core->uiController()->addDockWidget(Qt::LeftDockWidgetArea, tr("Quality Metrics"), QWidget::createWindowContainer(_metricsQuickView));

    _designSpaceExplorer->setAlternatingRowColors(true);
    _designSpaceExplorer->horizontalHeader()->setStretchLastSection(true);
    _designSpaceExplorer->verticalHeader()->setVisible(false);
    _designSpaceExplorer->setColumnCount(3);
    _designSpaceExplorer->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Design Dimension")));
    _designSpaceExplorer->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Dimension Instance Target")));
    _designSpaceExplorer->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Variation Point")));
    _designSpaceExplorer->resizeColumnToContents(0);
    _designSpaceExplorer->resizeColumnToContents(1);
    _designSpaceExplorer->resizeColumnToContents(2);

    core->uiController()->addDockWidget(Qt::RightDockWidgetArea, "Design Space Explorer", _designSpaceExplorer);

    QString iconThemeName;

    QAction *_actionFileNewDuseDesign = new QAction(0);
    _actionFileNewDuseDesign->setText(QApplication::translate("MainWindow", "New &DuSE Design ...", 0));
    _actionFileNewDuseDesign->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
    _actionFileNewDuseDesign->setObjectName(QStringLiteral("actionFileNewDuseDesign"));
    QIcon icon8;
    iconThemeName = QStringLiteral("document-new");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon8 = QIcon::fromTheme(iconThemeName);
    } else {
        icon8.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }
    _actionFileNewDuseDesign->setIcon(icon8);
    connect(_actionFileNewDuseDesign, &QAction::triggered, this, &DesignSpaceExplorerPlugin::newDuseDesign);
    core->uiController()->addAction(_actionFileNewDuseDesign, "menu_File");

    QAction *_actionFileOpenDuseDesign = new QAction(0);
    _actionFileOpenDuseDesign->setText(QApplication::translate("MainWindow", "Open DuSE Design ...", 0));
    _actionFileOpenDuseDesign->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0));
    _actionFileOpenDuseDesign->setObjectName(QStringLiteral("actionFileOpenDuseDesign"));
    QIcon icon9;
    iconThemeName = QStringLiteral("document-open");
    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon9 = QIcon::fromTheme(iconThemeName);
    } else {
        icon9.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }
    _actionFileOpenDuseDesign->setIcon(icon9);
    connect(_actionFileOpenDuseDesign, &QAction::triggered, this, &DesignSpaceExplorerPlugin::openDuseDesign);
    core->uiController()->addAction(_actionFileOpenDuseDesign, "menu_File");

    return true;
}

void DesignSpaceExplorerPlugin::newDuseDesign()
{
    do {
        if (_newDuseDesignDialog->exec() == QDialog::Accepted) {
            if (_newDuseDesignDialog->_inputModelFileName.isEmpty() || _newDuseDesignDialog->_duseInstanceModelFileName.isEmpty()) {
                QMessageBox::critical(0, tr("Create new DuSE design"), tr("You should select an input model and a DuSE instance model !"));
            }
            else {
//                setCursor(Qt::WaitCursor);

                QFile file(_newDuseDesignDialog->_duseInstanceModelFileName);
                if (!file.open(QFile::ReadOnly | QFile::Text)) {
                    QMessageBox::critical(0, tr("Create new DuSE design"), tr("Cannot read DuSE instance file !"));
//                    setCursor(Qt::ArrowCursor);
                    return;
                }
                QXmiReader reader;
                QList<QModelingElement *> modelingObjectList = reader.readFile(&file);
                if (QString::fromLatin1(modelingObjectList.first()->asQModelingObject()->metaObject()->className()) != QString::fromLatin1("QDuseDesignSpace")) {
                    QMessageBox::critical(0, tr("Create new DuSE design"), QString::fromLatin1("%1 is not a valid DuSE instance !").arg(QFileInfo(file).fileName()));
//                    setCursor(Qt::ArrowCursor);
                    return;
                }

//                _currentFileName = _newDuseDesign->_inputModelFileName;
//                foreach (QWrappedObject *object, _inputModel)
//                    delete object;
//                _inputModel = loadXmi(_currentFileName);

//                addToView(_inputModel[0]);

//                QScriptValue value = _engine.evaluate("function checkProfile() \
//                                                       { \
//                                                           var length = input[0].profileApplications.length; \
//                                                           for (var i = 0; i < length; ++i) \
//                                                               if (input[0].profileApplications[0].appliedProfile.name == '" + modelingObjectList.first()->asQModelingObject()->objectName() + "Profile') \
//                                                                   return true; \
//                                                           return false; \
//                                                       } \
//                                                       checkProfile();");
//                if (!value.toBool()) {
//                    QMessageBox::critical(this, tr("Create new DuSE design"), QString::fromLatin1("Input model does not contain the required %1Profile profile application !").arg(modelingObjectList.first()->asQModelingObject()->objectName()));
//                    setCursor(Qt::ArrowCursor);
//                    return;
//                }

                //modelingObjectList.first()->setQmlContextProperties(_metricsQuickView->engine()->rootContext());

//                _engine.globalObject().setProperty("designspace", _engine.newQObject(modelingObjectList.at(0)->asQModelingObject()));
//                _engine.evaluate("var dimensionsLength = designspace.designDimensions.length; \
//                                 for (var dimensionCounter = 0; dimensionCounter < dimensionsLength; ++dimensionCounter) { \
//                                     if (designspace.designDimensions[dimensionCounter].instanceSelectionRule) { \
//                                         var selected = eval(designspace.designDimensions[dimensionCounter].instanceSelectionRule); \
//                                         var selectedLength = selected.length; \
//                                         for (var selectedCounter = 0; selectedCounter < selectedLength; ++selectedCounter) { \
//                                             var dimensionInstance = new QDuseDesignDimensionInstance(); \
//                                             dimensionInstance.objectName = selected[selectedCounter].name; \
//                                             designspace.designDimensions[dimensionCounter].addDesignDimensionInstance(dimensionInstance); \
//                                         } \
//                                     } \
//                                 }");


//                evaluateQualityMetrics();
//                populateDesignSpaceView(modelingObjectList.at(0));

//                setCursor(Qt::ArrowCursor);
            }
        }
        else
            return;
    } while (_newDuseDesignDialog->_inputModelFileName.isEmpty() || _newDuseDesignDialog->_duseInstanceModelFileName.isEmpty());
}

void DesignSpaceExplorerPlugin::openDuseDesign()
{
}

