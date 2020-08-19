import QtQuick 2.0

Item {
    Banner{
//        color:"lightblue"
        id: bannerPanel
        mainText:"짭탄수학"
        subText:": 골룸족장의 뇌깨우기 프로젝트"
        width: parent.width*0.5
        height: parent.height*0.07
        anchors{
            top: parent.top
            left: parent.left
            topMargin: parent.height*0.1
            leftMargin: parent.height*0.08
        }
        subTextVisible: true
    }

    SelectPanel{
        id: selectPanel
//        color:"lightgray"
        width:parent.width*0.7
        height:parent.height*0.65
        anchors{
            top: bannerPanel.bottom
            left: bannerPanel.left
//            topMargin:parent.height*0.01
            leftMargin: parent.width*0.01
        }
    }

    LevelPanel{
//        color: "#ECECEC"
        radius: 5
        id: levelPanel
        width: parent.width*0.2
        height: selectPanel.commonHeight/2
        anchors{
            bottom: optionPanel.top
            left: selectPanel.right
            bottomMargin: parent.height*0.03
            leftMargin: parent.width*0.01
        }
    }



    OptionPanel {
        id: optionPanel
        color:"#ECECEC"
        radius: 5
        width: parent.width*0.2
        height: selectPanel.height*0.5
        anchors{
            top: selectPanel.top
            left: selectPanel.right
            topMargin: parent.width*0.1
            leftMargin: parent.width*0.01
        }
    }


    ButtonPanel{
        width: optionPanel.width
        height: this.width/6
        anchors{
            left: optionPanel.left
            bottom: selectPanel.bottom
            bottomMargin: parent.height*0.04
        }
    }

}
