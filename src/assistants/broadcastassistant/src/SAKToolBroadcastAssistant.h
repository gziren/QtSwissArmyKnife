﻿/******************************************************************************
 * Copyright 2023 Qsaker(qsaker@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of QtSwissArmyKnife
 * project(https://github.com/qsaker/QtSwissArmyKnife).
 *
 * QtSwissArmyKnife is licensed according to the terms in the file LICENCE in
 * the root of the source code directory.
 *****************************************************************************/
#ifndef SAKTOOLBROADCASTASSISTANT_H
#define SAKTOOLBROADCASTASSISTANT_H

#include <QWidget>
#include "SAKToolBroadcastThread.h"

namespace Ui {
class SAKBroadcastAssistant;
}

class SAKToolBroadcastAssistant : public QWidget {
  Q_OBJECT
 public:
  Q_INVOKABLE SAKToolBroadcastAssistant(QWidget* parent = Q_NULLPTR);
  ~SAKToolBroadcastAssistant();

 private:
  Ui::SAKBroadcastAssistant* ui;
  SAKToolBroadcastThread* mBroadcastThread;

 private:
  void initUi();
  void initUiBroadcastAddress();
  void initUiBroadcastInterval();
  void updateUiState(bool started);
  QByteArray packetData();

  void onBroadcastPushButtonClicked();
};

#endif  // SAKTOOLBROADCASTASSISTANT_H
