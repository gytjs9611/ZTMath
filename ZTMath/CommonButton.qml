import QtQuick 2.0
import QtQuick.Controls 2.4


Button{
    property string buttonColor : "#2254FD"
    property string buttonPressedColor : "#254DD4"
    property string buttonText
    property string buttonTextColor : "white"
    property int textSize : this.height*0.5
    property int radiusValue : 5

    signal commonButtonClicked

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

    onPressedChanged:{
        if(!page.errorState){
            if(pressed){
                buttonSetting.color= buttonPressedColor
            }
            else{
                buttonSetting.color= buttonColor
            }
        }
    }
    onClicked: {
        commonButtonClicked()
    }



}
