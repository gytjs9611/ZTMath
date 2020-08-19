import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
    property bool boxChecked
    property string titleColor

    onTitleColorChanged: {
        checkTitle.color = titleColor
    }


    CheckBox {
        id: checkBox
        height: parent.height
        anchors{
            left : parent.left
            verticalCenter: parent.verticalCenter
        }
        onClicked: {
            if(!page.errorState){
                boxChecked = (checkState==Qt.Checked)
            }
            else{
                enabled = true
            }
        }
    }
    Text{
        id: checkTitle
        text:title
        font.pixelSize: parent.height
        font.bold: false
        font.family:"NanumBarunGothic"
        color: titleColor
        anchors{
            left:checkBox.right
            leftMargin: parent.width*0.08
            verticalCenter: parent.verticalCenter
        }
    }

}
