/***************************************************************************************************
 * Copyright 2023 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include "sakbasetoolui.h"

class xToolsCommunicationTool;
class SAKCommunicationToolUi : public SAKBaseToolUi
{
    Q_OBJECT
public:
    explicit SAKCommunicationToolUi(QWidget *parent = nullptr);
    virtual void onIsWorkingChanged(bool isWorking) override;
};
