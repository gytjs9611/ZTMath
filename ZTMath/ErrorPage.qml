import QtQuick 2.0
import QtQuick.Controls 2.4


Rectangle{
    property string errorText
    property string explainText

    id:mainWindow
    width:parent.width*0.25
    height:this.width*0.5
    color:"#FFFFFF"
    radius:3
    anchors{
        centerIn:parent
    }
    Text{
        id: mainText
        width:parent.width
        text: errorText
        color:"black"
        font{
            family:"NanumBarunGothic"
            pixelSize: parent.height*0.15
        }
        horizontalAlignment: Text.AlignHCenter
        anchors{
            top : parent.top
            topMargin:parent.height*0.17

        }

    }
    Text{
        id: subText
        width:parent.width
        text: explainText
        color:"#6A6A6A"
        font{
            family:"NanumBarunGothic"
            pixelSize: parent.height*0.1
        }
        horizontalAlignment: Text.AlignHCenter
        anchors{
            top : mainText.bottom
            topMargin:parent.height*0.07

        }

    }
    Rectangle{
        id: line
        width:parent.width*0.98
        height:parent.height*0.008
        color:"#DFDFDF"
        anchors{
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: parent.height*0.3
        }
    }

    Button{
        property string buttonColor : "#1F7CFF"
        id:okButton
        width:parent.width*0.2
        height:parent.height*0.27
        background:Rectangle{
            color: "white"
        }
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: line.bottom
            topMargin: parent.height*0.01
        }
        Text{
            id: buttonText
            text:"OK"
            color: parent.buttonColor
            font{
                family:"NanumBarunGothic"
                pixelSize: parent.height*0.5
                bold: true
            }
            anchors{
                fill : parent
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

        }
        onPressedChanged: {
            if(pressed){
                buttonColor = "#145CFF"
            }
            else{
                buttonColor = "#1F7CFF"
            }
        }
        onClicked: {
            page.setErrorState(false)

        }

    }




}
