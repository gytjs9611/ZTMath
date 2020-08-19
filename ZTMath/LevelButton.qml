import QtQuick 2.0
import QtQuick.Controls 2.4


Button{
    property int selectedIndex : operation.level
    property string buttonColor : "#656565"
    property string buttonPressedColor : "#484848"
    property string buttonText
    property string buttonTextColor : "white"
    property int textSize : this.height*0.5
    property int radiusValue : this.width*0.4
    property string colorState


    id: buttonItem
    text:buttonText
    contentItem:Text{
        text:parent.text
        anchors.fill: parent
        font{
            pixelSize:textSize
            family:"NanumBarunGothic"
            bold:true
        }
        color: buttonTextColor
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

    }

    background: Rectangle {
        id: buttonSetting
        radius: radiusValue
        color: buttonColor
    }


}
