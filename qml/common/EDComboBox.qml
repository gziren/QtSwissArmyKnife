import QtQuick
import QtQuick.Controls

ComboBox {
    id: root

    property string settingKey: ""
    property bool useValueRole: true
    property string tips: ""

    onActivated: {
        if (settingKey) {
            edSettings.edSetValue(settingKey, useValueRole ? currentValue : currentText)
        }
    }

    onEditTextChanged: {
        if (settingKey && editable) {
            //edSettings.edSetValue(settingKey, useValueRole ? currentValue : editText)
        }
    }

    onHoveredChanged: {
        if (tips !== "") {
            if (hovered) {
                var popupX = mapToItem(tipsPopup.parent, 0, 0).x
                var popupY = mapToItem(tipsPopup.parent, 0, 0).y
                tipsPopup.x = popupX - (tipsPopup.width - root.width)/2
                tipsPopup.y = popupY - tipsPopup.height

                tipsPopup.open()
            } else {
                tipsPopup.close()
            }
        }
    }
    Component.onCompleted: {
        updateSettings()
    }

    EDPopup {
        id: tipsPopup
        dim: false
        modal: false
        contentItem: EDLabel {
            text: tips
        }
    }

    function updateSettings() {
        if (settingKey) {
            var parameter = edSettings.edValue(settingKey)
            var ret = useValueRole ? root.indexOfValue(parameter) : root.find(parameter)
            if (ret !== -1) {
                root.currentIndex = ret
            }
        }
    }
}

