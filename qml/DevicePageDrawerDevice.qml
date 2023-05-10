import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import ED.EasyDebug
import "./common/"

EDPane {
    id: root
    property alias txMasker: maskerGroupBox.txMasker
    property alias rxMasker: maskerGroupBox.rxMasker
    property alias analyzer: analyzerGroupBox.analyzer
    ScrollView {
        anchors.fill: parent
        ColumnLayout {
            width: root.width
            DevicePageDrawerDeviceMasker {
                id: maskerGroupBox
                Layout.fillWidth: true
            }
            DevicePageDrawerDeviceAnalyzer {
                id: analyzerGroupBox
                Layout.fillWidth: true
            }
        }
    }

}
