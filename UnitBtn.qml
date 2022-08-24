import QtQuick 2.0
import QtQml.Models 2.2
Grid {
    signal sig_clicked(string unit)
    property int btnWidth: 0
    property int btnHeight: 0

    columns: 1
    spacing: 1
    Repeater {
        model: id_unitBtn_model
        delegate: Component {
            Rectangle {
                width: btnWidth
                height: btnHeight
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        sig_clicked(str)
                    }
                }
                Text {
                    id: id_unitStr
                    text: str
                    anchors.centerIn: parent
                }
            }
        }
    }

    ListModel {
        id: id_unitBtn_model
        ListElement {str: "V"}
        ListElement {str: "W"}
        ListElement {str: "dBm"}
        ListElement {str: "dBV"}
        ListElement {str: "dBw"}
    }
}
