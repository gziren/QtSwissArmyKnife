/******************************************************************************
 * Copyright 2023 Qsaker(qsaker@foxmail.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 *****************************************************************************/
#include <QLineEdit>
#include <QFileDialog>

#include "SAKStorerTool.hh"
#include "SAKStorerToolUi.hh"
#include "ui_SAKStorerToolUi.h"

SAKStorerToolUi::SAKStorerToolUi(QWidget *parent)
    : SAKBaseToolUi{parent}
    , ui(new Ui::SAKStorerToolUi)
{
    ui->setupUi(this);
    connect(ui->pushButtonSelectFile, &QPushButton::clicked,
            this, &SAKStorerToolUi::onPushButtonSelectFileClicked);
}

SAKStorerToolUi::~SAKStorerToolUi()
{
    delete ui;
}

void SAKStorerToolUi::onBaseToolUiInitialized(SAKBaseTool *tool,
                             const QString &settingsGroup)
{
    ui->checkBoxEnable->setGroupKey(settingsGroup, "enable");
    ui->checkBoxDate->setGroupKey(settingsGroup, "date");
    ui->checkBoxTime->setGroupKey(settingsGroup, "time");
    ui->checkBoxMs->setGroupKey(settingsGroup, "ms");
    ui->checkBoxRx->setGroupKey(settingsGroup, "rx");
    ui->checkBoxTx->setGroupKey(settingsGroup, "tx");
    ui->comboBoxFormat->setGroupKey(settingsGroup, "format");
    ui->lineEditStorerPath->setGroupKey(settingsGroup, "path");

    if (!tool) {
        qCWarning((*mLoggingCategory)) << "The tool value is nullptr!";
        return;
    }

    SAKStorerTool *cookedTool = qobject_cast<SAKStorerTool*>(tool);
    if (!cookedTool) {
        qCWarning((*mLoggingCategory)) << "The cookedTool value is nullptr!";
        return;
    }

    cookedTool->setEnable(ui->checkBoxEnable->isChecked());
    cookedTool->setSaveTx(ui->checkBoxTx->isChecked());
    cookedTool->setSaveRx(ui->checkBoxRx->isChecked());
    cookedTool->setSaveDate(ui->checkBoxDate->isChecked());
    cookedTool->setSaveTime(ui->checkBoxTime->isChecked());
    cookedTool->setSaveMs(ui->checkBoxMs->isChecked());
    cookedTool->setSaveFormat(ui->comboBoxFormat->currentData().toInt());
    cookedTool->setFileName(ui->lineEditStorerPath->text());

    connect(ui->checkBoxEnable, &QCheckBox::clicked, this, [=](){
        cookedTool->setEnable(ui->checkBoxEnable->isChecked());
    });
    connect(ui->checkBoxRx, &QCheckBox::clicked, this, [=](){
        cookedTool->setSaveRx(ui->checkBoxDate->isChecked());
    });
    connect(ui->checkBoxTx, &QCheckBox::clicked, this, [=](){
        cookedTool->setSaveTx(ui->checkBoxDate->isChecked());
    });
    connect(ui->checkBoxDate, &QCheckBox::clicked, this, [=](){
        cookedTool->setSaveDate(ui->checkBoxDate->isChecked());
    });
    connect(ui->checkBoxDate, &QCheckBox::clicked, this, [=](){
        cookedTool->setSaveTime(ui->checkBoxTime->isChecked());
    });
    connect(ui->checkBoxMs, &QCheckBox::clicked, this, [=](){
        cookedTool->setSaveMs(ui->checkBoxMs->isChecked());
    });
    connect(ui->comboBoxFormat,
            static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            this, [=](){
        int format = ui->comboBoxFormat->currentData().toInt();
        cookedTool->setSaveFormat(format);
    });
    connect(ui->lineEditStorerPath, &SAKLineEdit::textChanged, this, [=](){
        cookedTool->setFileName(ui->lineEditStorerPath->text());
    });
}

void SAKStorerToolUi::onPushButtonSelectFileClicked()
{
    auto str = QFileDialog::getSaveFileName(this, tr("Save file"),
                                            ".", tr("txt (*.txt); all (*)"));
    if (!str.isEmpty()) {
        ui->lineEditStorerPath->setText(str);
    }
}
