import QtQuick 2.0
import QtQml.Models 2.2
Grid {
    signal sig_clicked(string str)
    property int btnWidth: 0
    property int btnHeight: 0

    columns: 3
    rows: 4
    spacing: 1
    Repeater {
        model: id_NumBtn_model
        delegate: Component {
            Rectangle {
                width: btnWidth
                height: btnHeight
                color: "#FFFFFF"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        sig_clicked(str)
                    }
                    onEntered: {
                        color = "#D9D9D9"
                    }
                    onExited: {
                        color = "#FFFFFF"
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
        id: id_NumBtn_model
        ListElement {str: "1"}
        ListElement {str: "2"}
        ListElement {str: "3"}
        ListElement {str: "4"}
        ListElement {str: "5"}
        ListElement {str: "6"}
        ListElement {str: "7"}
        ListElement {str: "8"}
        ListElement {str: "9"}
        ListElement {str: "."}
        ListElement {str: "0"}
        ListElement {str: "-"}
    }
}
