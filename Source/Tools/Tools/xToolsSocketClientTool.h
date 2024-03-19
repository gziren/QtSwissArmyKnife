/***************************************************************************************************
 * Copyright 2023-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include "xToolsCommunicationTool.h"

class xToolsSocketClientTool : public xToolsCommunicationTool
{
    Q_OBJECT
    // clang-format off
    Q_PROPERTY(QString clientIp READ clientIp WRITE setClientIp NOTIFY clientIpChanged)
    Q_PROPERTY(int clientPort READ clientPort WRITE setClientPort NOTIFY clientPortChanged)
    Q_PROPERTY(bool specifyClientIpPort READ specifyClientIpPort WRITE setSpecifyClientIpPort NOTIFY specifyClientIpPortChanged)
    Q_PROPERTY(QString serverIp READ serverIp WRITE setServerIp NOTIFY serverIpChanged)
    Q_PROPERTY(int serverPort READ serverPort WRITE setServerPort NOTIFY serverPortChanged)
    Q_PROPERTY(QString bindingIpPort READ bindingIpPort NOTIFY bindingIpPortChanged)
    // Just for web socket client.
    Q_PROPERTY(int messageType READ messageType WRITE setMessageType NOTIFY messageTypeChanged)
    // clang-format on
public:
    explicit xToolsSocketClientTool(QObject *parent = nullptr);

public:
    QString clientIp();
    void setClientIp(const QString &ip);
    int clientPort();
    void setClientPort(int port);
    bool specifyClientIpPort();
    void setSpecifyClientIpPort(bool specified);
    QString serverIp();
    void setServerIp(const QString &ip);
    int serverPort();
    void setServerPort(int port);
    QString bindingIpPort();
    int messageType();
    void setMessageType(int type);

protected:
    QString m_clientIp;
    int m_clientPort;
    bool m_specifyClientIpPort;
    QString m_serverIp;
    int m_serverPort;
    QString m_bindingIpPort;
    std::atomic_int8_t m_messageType;

signals:
    void clientIpChanged();
    void clientPortChanged();
    void specifyClientIpPortChanged();
    void serverIpChanged();
    void serverPortChanged();
    void bindingIpPortChanged();
    void messageTypeChanged();
};
