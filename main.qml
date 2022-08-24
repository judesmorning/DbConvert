import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import DB.ConvertTool 1.0

Window {
    id: window
    width: 440
    height: 455
    visible: true
    title: qsTr("Db Convert")
    color: "#E6E6E6"

    /****************内部实现****************/
    /*结果显示*/
    Rectangle {
        height: 100
        color: "#E6E6E6"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        TextEdit {
            id: id_text
            anchors.fill: parent
            font.pixelSize: 20
            readOnly: true
        }
    }

    /*数字按键*/
    Rectangle {
        id: id_numRoot
        x: 5
        y: 175
        width: 294
        height: 270
        color: Qt.rgba(0,0,0,0)

        NumBtn {
            anchors.fill: parent
            anchors.margins: 1
            btnWidth: id_numRoot.width/columns-1
            btnHeight: id_numRoot.height/rows-0.5
            onSig_clicked: {
                if(-1 !== id_text.text.indexOf("\n"))//已计算过一次
                {
                    id_text.clear();
                }
                id_text.text = id_text.text + str;
            }
        }
     }

    /*单位按键*/
    Rectangle {
        id: id_unitRoot
        x: 305
        y: 178
        width: 130
        height: 275
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 5
        anchors.bottomMargin: 5
        color: Qt.rgba(0,0,0,0)

        //类型
        ConvertBtn {
            id: id_convertBtn
            width: id_unitRoot.width
            height: 50
        }

        //清除按钮
        Button {
            id: id_clearBtn
            text: "清除"
            width: id_convertBtn.width
            height: id_convertBtn.height
            anchors.top: id_convertBtn.bottom
            anchors.topMargin: 3
            onClicked: {
                id_text.clear();
            }
        }

        //计算按钮
        Button {
            text: "计算"
            width: id_convertBtn.width
            height: id_convertBtn.height
            anchors.top: id_clearBtn.bottom
            anchors.topMargin: 3
            onClicked: {
                id_text.text = id_convertTool.calc(id_text.text, id_convertBtn.currentIndex);
            }
        }
    }

    /*计算工具*/
    ConvertTool {
        id: id_convertTool
    }

}


