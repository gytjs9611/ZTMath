import QtQuick 2.0
import QtQuick.Controls 2.4

Rectangle {
    Banner{
//        color:"lightblue"
        id: bannerPanel
        mainText:"문제풀기"
        subTextVisible:false
        width: parent.width*0.7
        height: parent.height

    }
    Button{
        property string buttonColor : "#3E3E3E"
        id:okButton
        width:parent.width*0.4
        height:bannerPanel.height*0.9
        background:Rectangle{
            color: "white"
        }
        anchors{
            bottom: bannerPanel.bottom
            left: bannerPanel.right
            leftMargin: parent.width*0.1
        }
        Text{
            id: buttonText
            text:"|  HOME"
            color: parent.buttonColor
            font{
                family:"NanumBarunGothic"
                pixelSize: parent.height*0.5
                bold: true
            }
            anchors{
                bottom:parent.bottom
            }
            horizontalAlignment: Text.AlignHCenter

        }
        onPressedChanged: {
            if(!page.errorState){
                if(pressed){
                    buttonColor = "#202020"
                }
                else{
                    buttonColor = "#3E3E3E"
                }
            }
        }
        onClicked: {
            if(!page.errorState){
                page.setCurrentPage(0)
            }

        }

    }


}
