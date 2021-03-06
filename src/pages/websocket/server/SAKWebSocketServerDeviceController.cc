﻿/*
 * Copyright 2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project(https://www.qsak.pro). The project is an open source project. You can
 * get the source of the project from: "https://github.com/qsak/QtSwissArmyKnife"
 * or "https://gitee.com/qsak/QtSwissArmyKnife". Also, you can join in the QQ
 * group which number is 952218522 to have a communication.
 */
#include <QList>
#include <QDebug>
#include <QMetaEnum>
#include <QLineEdit>

#include "SAKGlobal.hh"
#include "SAKWebSocketServerDeviceController.hh"
#include "ui_SAKWebSocketServerDeviceController.h"
SAKWebSocketServerDeviceController::SAKWebSocketServerDeviceController(QWidget *parent)
    :QWidget (parent)
    ,mUi (new Ui::SAKWebSocketServerDeviceController)
{
    mUi->setupUi(this);

    mServerHostComboBox = mUi->serverhostComboBox;
    mServerPortLineEdit = mUi->serverPortLineEdit;
    mClientHostComboBox = mUi->clientHostComboBox;
    mSendingTypeComboBox = mUi->sendingTypeComboBox;
    SAKGlobal::initWebSocketSendingTypeComboBox(mSendingTypeComboBox);
    /// @brief 获取本机网络地址
    refresh();
}

SAKWebSocketServerDeviceController::~SAKWebSocketServerDeviceController()
{
    delete mUi;
}

QString SAKWebSocketServerDeviceController::serverHost()
{
    mUiMutex.lock();
    QString host = mServerHostComboBox->currentText();
    mUiMutex.unlock();
    return host;
}

quint16 SAKWebSocketServerDeviceController::serverPort()
{
    mUiMutex.lock();
    quint16 port = static_cast<quint16>(mServerPortLineEdit->text().toInt());
    mUiMutex.unlock();
    return port;
}

QString SAKWebSocketServerDeviceController::currentClientHost()
{
    mUiMutex.lock();
    QStringList host = mClientHostComboBox->currentText().split(":");
    QString address = host.first();
    mUiMutex.unlock();
    return address;
}

quint16 SAKWebSocketServerDeviceController::currentClientPort()
{
    mUiMutex.lock();
    QString port = mClientHostComboBox->currentText().split(":").last();
    quint16 portTemp = static_cast<quint16>(port.toInt());
    mUiMutex.unlock();
    return portTemp;
}

quint32 SAKWebSocketServerDeviceController::sendingType()
{
    mUiMutex.lock();
    quint32 ret = mSendingTypeComboBox->currentData().toInt();
    mUiMutex.unlock();
    return ret;
}

void SAKWebSocketServerDeviceController::refresh()
{
    SAKGlobal::initIpComboBox(mServerHostComboBox);
}

void SAKWebSocketServerDeviceController::setUiEnable(bool enable)
{
    mServerHostComboBox->setEnabled(enable);
    mServerPortLineEdit->setEnabled(enable);
}

void SAKWebSocketServerDeviceController::addClient(QString host, quint16 port, QWebSocket *socket)
{
    QString item = host.append(":");
    item.append(QString::number(port));

    mUiMutex.lock();
    for(int i = 0; i < mClientHostComboBox->count(); i++){
        if (mClientHostComboBox->itemText(i).compare(item) == 0){
            mUiMutex.unlock();
            return;
        }
    }

    mClientHostComboBox->addItem(item, QVariant::fromValue(socket));
    mUiMutex.unlock();
}

void SAKWebSocketServerDeviceController::removeClient(QWebSocket *socket)
{
    mUiMutex.lock();
    for(int i = 0; i < mClientHostComboBox->count(); i++){
        if (mClientHostComboBox->itemData(i).value<QWebSocket*>() == socket){
            mClientHostComboBox->removeItem(i);
            break;
        }
    }
    mUiMutex.unlock();
}

void SAKWebSocketServerDeviceController::clearClient()
{
    mUiMutex.lock();
    mClientHostComboBox->clear();
    mUiMutex.unlock();
}
