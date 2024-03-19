/***************************************************************************************************
 * Copyright 2023 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include "xToolsSocketClientTransmitterTool.h"

class xToolsWebSocketTransmitterTool : public xToolsSocketClientTransmitterTool
{
    Q_OBJECT
public:
    explicit xToolsWebSocketTransmitterTool(QObject *parent = nullptr);
    virtual xToolsCommunicationTool *createTool() override;
};
