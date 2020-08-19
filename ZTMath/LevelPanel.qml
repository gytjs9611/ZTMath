import QtQuick 2.0
import QtQuick.Controls 2.4

Rectangle {
    id: root
    Text{
        id: title
        width: parent.width*0.25
        height: parent.height
        text: "난이도"
        font{
            pixelSize: root.height*0.4
            family: "NanumBarunGothic"
            bold: true
        }
        anchors{
            left: parent.left
            leftMargin: parent.width* 0.05
        }
        verticalAlignment: Text.AlignVCenter
    }
    Rectangle{
        id: line
        width: parent.width*0.45
        height: parent.height*0.2
        color: "lightgray"
        anchors{
            left:high.horizontalCenter
            verticalCenter: high.verticalCenter
        }
    }

    property string normalColor : "#656565"
    property string pressedColor : "#2C2E31"

    LevelButton{
        property int selectedIndex : operation.level

        id: high
        width: parent.width*0.12
        height: this.width
        text: "상"
        textSize:this.height*0.5
        radiusValue: this.width*0.4

        buttonPressedColor: pressedColor
        anchors{
            left: title.right
            leftMargin: parent.width*0.05
            verticalCenter: title.verticalCenter
        }

        onClicked: {
            operation.setLevel(0)
            plus.setLevel(0)
            minus.setLevel(0)
            mult.setLevel(0)
            div.setLevel(0)
            console.log("0 clicked")
        }
        onSelectedIndexChanged: {
            if(selectedIndex!=0){
                buttonColor = normalColor
                colorState = normalColor
            }
            else{
                buttonColor = pressedColor
                colorState = pressedColor
            }
        }

    }
    LevelButton {
        property int selectedIndex : operation.level

        id: mid
        width: parent.width*0.12
        height: this.width
        text: "중"
        textSize:this.height*0.5
        radiusValue: this.width*0.4

        buttonPressedColor: normalColor

        anchors{
            left: high.right
            leftMargin: parent.width*0.1
            verticalCenter: title.verticalCenter
        }

        onClicked: {
            operation.setLevel(1)
            plus.setLevel(1)
            minus.setLevel(1)
            mult.setLevel(1)
            div.setLevel(1)
            console.log("1 clicked")
        }
        onSelectedIndexChanged: {
            if(selectedIndex!=1){
                buttonColor = normalColor
                colorState = normalColor
            }
            else{
                buttonColor = pressedColor
                colorState = pressedColor
            }
        }

    }
    LevelButton{
        property int selectedIndex : operation.level

        id: low
        width: parent.width*0.12
        height: this.width
        text: "하"
        textSize:this.height*0.5
        radiusValue: this.width*0.4

        buttonPressedColor: normalColor
        anchors{
            left: mid.right
            leftMargin: parent.width*0.1
            verticalCenter: title.verticalCenter
        }


        onClicked: {
            operation.setLevel(2)
            plus.setLevel(2)
            minus.setLevel(2)
            mult.setLevel(2)
            div.setLevel(2)
            console.log("2 clicked")
        }
        onSelectedIndexChanged: {
            if(selectedIndex!=2){
                buttonColor = normalColor
                colorState = normalColor
            }
            else{
                buttonColor = pressedColor
                colorState = pressedColor
            }
        }

    }
}
