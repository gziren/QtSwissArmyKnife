#-------------------------------------------------
#
# Project created by QtCreator 2018-07-06T22:57:33
#
#-------------------------------------------------

QT += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

contains(CONFIG, debug, debug|release){
    TARGET = QtSwissArmyKnifed
}else{
    TARGET = QtSwissArmyKnife
}

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, unTabPage the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

# 子项目
#include(SAKHID.pri)
#include(SAKUSB.pri)
#include(SAKSCTP.pri)
include(SAKSetup.pri)
include(SAKTools.pri)
include(SAKCommon.pri)
include(SAKCharts.pri)
include(SAKModules.pri)
#include(SAKBluetooth.pri)
include(SAKWebSocket.pri)
include(SAKSerialPort.pri)

exists(private/SAKPrivate.pri){
    include(private/SAKPrivate.pri)
}

QSAK_APP_NAME        = "QtSwissArmyKnife"
QSAK_ORG_NAME        = "Qter"
QSAK_ORG_DOMAIN      = "IT"
QSAK_APP_DESCRIPTION = "Qt Swiss Army Knife"
QSAK_APP_COPYRIGHT   = "Copyright 2018-2020 Qter(qsaker@qq.com). All rights reserved."

win32 {
    QMAKE_TARGET_COMPANY        = "$${QSAK_ORG_NAME}"
    QMAKE_TARGET_DESCRIPTION    = "$${QSAK_APP_DESCRIPTION}"
    QMAKE_TARGET_COPYRIGHT      = "$${QSAK_APP_COPYRIGHT}"
    QMAKE_TARGET_PRODUCT        = "$${QSAK_APP_NAME}"
    QMAKE_TARGET_VERSION        = "$${SAK_VERSION}"
}

#--------------------------------------------------------------------------------------------
#编译目录配置
UI_DIR      = $$OUT_PWD/ui
MOC_DIR     = $$OUT_PWD/moc
RCC_DIR     = $$OUT_PWD/res
OBJECTS_DIR = $$OUT_PWD/obj

#--------------------------------------------------------------------------------------------
#Windows配置
win32 {
    RC_ICONS = Windows.ico
    msvc:{
        QMAKE_CXXFLAGS += -execution-charset:utf-8
    }
}

#--------------------------------------------------------------------------------------------
#国际化文件
TRANSLATIONS  += \
    translations/sak/SAK_en.ts \
    translations/sak/SAK_zh_CN.ts \
    translations/sak/SAK_zh_TW.ts

RESOURCES += \
    SAKResources.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}

INCLUDEPATH += \
    src \
    src/moreinfo \
    src/common \
    src/pages \
    src/pages/page \
    src/pages/page/device \
    src/pages/page/input \
    src/pages/page/other \
    src/pages/page/other/autoresponse \
    src/pages/page/other/highlight \
    src/pages/page/other/more \
    src/pages/page/other/more/generator \
    src/pages/page/other/more/protocol \
    src/pages/page/other/readwrite \
    src/pages/page/other/timing \
    src/pages/page/other/transmission \
    src/pages/page/output \
    src/pages/page/output/save \
    src/pages/page/statistics \
    src/pages/tcp/client \
    src/pages/tcp/server \
    src/pages/udp \
    src/qrcode \
    src/startui \
    src/singleton \
    src/update

FORMS += \
    src/SAKMainWindow.ui \
    src/moreinfo/SAKMoreInformation.ui \
    src/pages/page/SAKDebugPage.ui \
    src/pages/page/input/SAKInputCrcSettingsDialog.ui \
    src/pages/page/input/SAKInputDataItem.ui \
    src/pages/page/input/SAKInputDataItemManager.ui \
    src/pages/page/other/autoresponse/SAKAutoResponseItemWidget.ui \
    src/pages/page/other/autoresponse/SAKAutoResponseSettingsWidget.ui \
    src/pages/page/other/highlight/SAKHighlightSettingsWidget.ui \
    src/pages/page/other/more/SAKMoreSettingsWidget.ui \
    src/pages/page/other/more/generator/SAKWaveformGeneratorWidget.ui \
    src/pages/page/other/more/protocol/SAKProtocolAnalyzerWidget.ui \
    src/pages/page/other/readwrite/SAKReadWriteSettingsWidget.ui \
    src/pages/page/other/timing/SAKTimingSendingItemWidget.ui \
    src/pages/page/other/timing/SAKTimingSendingSettingsWidget.ui \
    src/pages/page/other/transmission/SAKSerialPortTransmissionItemWidget.ui \
    src/pages/page/other/transmission/SAKTcpTransmissionItemWidget.ui \
    src/pages/page/other/transmission/SAKTransmissionPage.ui \
    src/pages/page/other/transmission/SAKTransmissionSettings.ui \
    src/pages/page/other/transmission/SAKUdpTransmissionItemWidget.ui \
    src/pages/page/output/save/SAKSaveOutputDataSettings.ui \
    src/pages/tcp/client/SAKTcpClientDeviceController.ui \
    src/pages/tcp/server/SAKTcpServerDeviceController.ui \
    src/pages/udp/SAKUdpAdvanceSettingWidget.ui \
    src/pages/udp/SAKUdpDeviceController.ui \
    src/pages/udp/SAKUdpMulticastEditingDialog.ui \
    src/qrcode/SAKQRCodeDialog.ui \
    src/singleton/SAKSingletonErrorDialog.ui \
    src/update/SAKDownloadItemWidget.ui \
    src/update/SAKUpdateManager.ui

HEADERS += \
    src/SAK.hh \
    src/SAKApplication.hh \
    src/SAKGlobal.hh \
    src/SAKMainWindow.hh \
    src/SAKSettings.hh \
    src/SAKSqlDatabase.hh \
    src/common/SAKInterface.hh \
    src/moreinfo/SAKMoreInformation.hh \
    src/pages/page/SAKDebugPage.hh \
    src/pages/page/SAKDebugPageDatabaseInterface.hh \
    src/pages/page/device/SAKDevice.hh \
    src/pages/page/input/SAKDebugPageInputManager.hh \
    src/pages/page/input/SAKInputCrcSettingsDialog.hh \
    src/pages/page/input/SAKInputDataFactory.hh \
    src/pages/page/input/SAKInputDataItem.hh \
    src/pages/page/input/SAKInputDataItemManager.hh \
    src/pages/page/other/SAKOtherSettingsManager.hh \
    src/pages/page/other/autoresponse/SAKAutoResponseItemWidget.hh \
    src/pages/page/other/autoresponse/SAKAutoResponseSettingsWidget.hh \
    src/pages/page/other/highlight/SAKHighlightSettings.hh \
    src/pages/page/other/highlight/SAKHighlightSettingsWidget.hh \
    src/pages/page/other/more/SAKMoreSettingsWidget.hh \
    src/pages/page/other/more/generator/SAKWaveformGeneratorWidget.hh \
    src/pages/page/other/more/protocol/SAKProtocolAnalyzer.hh \
    src/pages/page/other/more/protocol/SAKProtocolAnalyzerWidget.hh \
    src/pages/page/other/readwrite/SAKReadWriteSettingsWidget.hh \
    src/pages/page/other/timing/SAKTimingSendingItemWidget.hh \
    src/pages/page/other/timing/SAKTimingSendingSettingsWidget.hh \
    src/pages/page/other/transmission/SAKBaseTransmissionItemWidget.hh \
    src/pages/page/other/transmission/SAKSerialPortTransmissionItemWidget.hh \
    src/pages/page/other/transmission/SAKTcpTransmissionItemWidget.hh \
    src/pages/page/other/transmission/SAKTransmissionItemDelegate.hh \
    src/pages/page/other/transmission/SAKTransmissionPage.hh \
    src/pages/page/other/transmission/SAKTransmissionSettings.hh \
    src/pages/page/other/transmission/SAKUdpTransmissionItemWidget.hh \
    src/pages/page/output/SAKDebugPageOutputManager.hh \
    src/pages/page/output/SAKOutputDataFactory.hh \
    src/pages/page/output/save/SAKSaveOutputDataSettings.hh \
    src/pages/page/output/save/SAKSaveOutputDataThread.hh \
    src/pages/page/statistics/SAKStatisticsManager.hh \
    src/common/SAKCRCInterface.hh \
    src/common/SAKDataStruct.hh \
    src/pages/tcp/client/SAKTcpClientDebugPage.hh \
    src/pages/tcp/client/SAKTcpClientDevice.hh \
    src/pages/tcp/client/SAKTcpClientDeviceController.hh \
    src/pages/tcp/server/SAKTcpServerDebugPage.hh \
    src/pages/tcp/server/SAKTcpServerDevice.hh \
    src/pages/tcp/server/SAKTcpServerDeviceController.hh \
    src/pages/udp/SAKUdpAdvanceSettingWidget.hh \
    src/pages/udp/SAKUdpDebugPage.hh \
    src/pages/udp/SAKUdpDevice.hh \
    src/pages/udp/SAKUdpDeviceController.hh \
    src/pages/udp/SAKUdpMulticastEditingDialog.hh \
    src/qrcode/SAKQRCodeDialog.hh \
    src/qrcode/SAKQRCodeWidget.hh \
    src/singleton/SAKSingletonController.hh \
    src/singleton/SAKSingletonErrorDialog.hh \
    src/startui/SAKSplashScreen.hh \
    src/update/SAKDownloadItemWidget.hh \
    src/update/SAKUpdateManager.hh

SOURCES += \
    src/SAK.cc \
    src/SAKApplication.cc \
    src/SAKGlobal.cc \
    src/SAKMainWindow.cc \
    src/SAKSettings.cc \
    src/SAKSqlDatabase.cc \
    src/common/SAKInterface.cc \
    src/moreinfo/SAKMoreInformation.cc \
    src/pages/page/SAKDebugPage.cc \
    src/pages/page/SAKDebugPageDatabaseInterface.cc \
    src/pages/page/device/SAKDevice.cc \
    src/pages/page/input/SAKDebugPageInputManager.cc \
    src/pages/page/input/SAKInputCrcSettingsDialog.cc \
    src/pages/page/input/SAKInputDataFactory.cc \
    src/pages/page/input/SAKInputDataItem.cc \
    src/pages/page/input/SAKInputDataItemManager.cc \
    src/pages/page/other/SAKOtherSettingsManager.cc \
    src/pages/page/other/autoresponse/SAKAutoResponseItemWidget.cc \
    src/pages/page/other/autoresponse/SAKAutoResponseSettingsWidget.cc \
    src/pages/page/other/highlight/SAKHighlightSettings.cc \
    src/pages/page/other/highlight/SAKHighlightSettingsWidget.cc \
    src/pages/page/other/more/SAKMoreSettingsWidget.cc \
    src/pages/page/other/more/generator/SAKWaveformGeneratorWidget.cc \
    src/pages/page/other/more/protocol/SAKProtocolAnalyzer.cc \
    src/pages/page/other/more/protocol/SAKProtocolAnalyzerWidget.cc \
    src/pages/page/other/readwrite/SAKReadWriteSettingsWidget.cc \
    src/pages/page/other/timing/SAKTimingSendingItemWidget.cc \
    src/pages/page/other/timing/SAKTimingSendingSettingsWidget.cc \
    src/pages/page/other/transmission/SAKBaseTransmissionItemWidget.cc \
    src/pages/page/other/transmission/SAKSerialPortTransmissionItemWidget.cc \
    src/pages/page/other/transmission/SAKTcpTransmissionItemWidget.cc \
    src/pages/page/other/transmission/SAKTransmissionItemDelegate.cc \
    src/pages/page/other/transmission/SAKTransmissionPage.cc \
    src/pages/page/other/transmission/SAKTransmissionSettings.cc \
    src/pages/page/other/transmission/SAKUdpTransmissionItemWidget.cc \
    src/pages/page/output/SAKDebugPageOutputManager.cc \
    src/pages/page/output/SAKOutputDataFactory.cc \
    src/pages/page/output/save/SAKSaveOutputDataSettings.cc \
    src/pages/page/output/save/SAKSaveOutputDataThread.cc \
    src/pages/page/statistics/SAKStatisticsManager.cc \
    src/common/SAKCRCInterface.cc \
    src/common/SAKDataStruct.cc \
    src/main.cc \
    src/pages/tcp/client/SAKTcpClientDebugPage.cc \
    src/pages/tcp/client/SAKTcpClientDevice.cc \
    src/pages/tcp/client/SAKTcpClientDeviceController.cc \
    src/pages/tcp/server/SAKTcpServerDebugPage.cc \
    src/pages/tcp/server/SAKTcpServerDevice.cc \
    src/pages/tcp/server/SAKTcpServerDeviceController.cc \
    src/pages/udp/SAKUdpAdvanceSettingWidget.cc \
    src/pages/udp/SAKUdpDebugPage.cc \
    src/pages/udp/SAKUdpDevice.cc \
    src/pages/udp/SAKUdpDeviceController.cc \
    src/pages/udp/SAKUdpMulticastEditingDialog.cc \
    src/qrcode/SAKQRCodeDialog.cc \
    src/qrcode/SAKQRCodeWidget.cc \
    src/singleton/SAKSingletonController.cc \
    src/singleton/SAKSingletonErrorDialog.cc \
    src/startui/SAKSplashScreen.cc \
    src/update/SAKDownloadItemWidget.cc \
    src/update/SAKUpdateManager.cc
