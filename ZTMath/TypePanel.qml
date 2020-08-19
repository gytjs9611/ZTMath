import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: root
    color:"white"
    property int textSize : this.height*0.2



    Text{
        id:type
        width:parent.width*0.14
        text:"연산타입"
        horizontalAlignment: Text.AlignHCenter
        font{
            pixelSize: textSize
            family:"NanumBarunGothic"
            bold: true
        }
        anchors{
            left:parent.left
            bottom:parent.bottom
        }
    }

    Text{
        id: level
        text:"자릿수"
        width:parent.width*0.48
        horizontalAlignment: Text.AlignHCenter
        font{
            pixelSize: textSize
            family:"NanumBarunGothic"
            bold: true
        }
        anchors{
            left:type.right
            bottom:parent.bottom
        }
    }
    Text{
        id:num
        width:parent.width*0.31
        text:"문제수"
        horizontalAlignment: Text.AlignHCenter
        font{
            pixelSize: textSize
            family:"NanumBarunGothic"
            bold: true
        }
        anchors{
            left:level.right
            bottom:parent.bottom
        }
    }
}
