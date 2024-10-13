﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of eTools project.
 *
 * eTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "ChartsUi.h"
#include "ui_ChartsUi.h"

#include <QChartView>
#include <QCheckBox>
#include <QMenu>
#include <QPointF>
#include <QPushButton>
#include <QTimer>
#include <QWidgetAction>

#include "ChartsUiSettings.h"
#include "IO/IO/DataVisualization/2D/Charts.h"

namespace xTools {

ChartsUi::ChartsUi(QWidget *parent)
    : AbstractIOUi(parent)
    , ui(new Ui::ChartsUi)
{
    ui->setupUi(this);
    ui->widgetChartView->setContentsMargins(0, 0, 0, 0);

    m_settings = new ChartsUiSettings();
    m_settingsMenu = new QMenu(this);
    QWidgetAction *action = new QWidgetAction(m_settingsMenu);
    action->setDefaultWidget(m_settings);
    m_settingsMenu->addAction(action);
}

ChartsUi::~ChartsUi()
{
    m_settings->deleteLater();
    delete ui;
}

QVariantMap ChartsUi::save() const
{
    QVariantMap data;
    return data;
}

void ChartsUi::load(const QVariantMap &parameters)
{
    Q_UNUSED(parameters);
}

void ChartsUi::setupIO(AbstractIO *io)
{
    AbstractIOUi::setupIO(io);

    auto *charts = qobject_cast<Charts *>(io);
    if (!charts) {
        return;
    }

    int type = Qt::AutoConnection | Qt::UniqueConnection;
    auto cookedType = static_cast<Qt::ConnectionType>(type);
    connect(charts, &Charts::newValues, this, &ChartsUi::onNewValues, cookedType);
    connect(charts, &Charts::newPoints, this, &ChartsUi::onNewPoints, cookedType);
}

QMenu *ChartsUi::settingsMenu() const
{
    return m_settingsMenu;
}

void ChartsUi::onNewValues(const QList<double> &values)
{
    // Do something with values
}

void ChartsUi::onNewPoints(const QList<QPointF> &points)
{
    // Do something with points
}

} // namespace xTools