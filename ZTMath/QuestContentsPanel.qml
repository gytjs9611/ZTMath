import QtQuick 2.0

Rectangle {
    id: root
//    color:"lightgray"
    property int currentPage : page.currentPage
    property int leftStartId
    property int rightStartId

    onCurrentPageChanged: {
        leftStartId = (page.currentPage-1)*20+1
        rightStartId = (page.currentPage-1)*20+11

    }

    QuestionHalfPanel{
        id: leftPanel
//        color:"lightblue"
        isLeft: true
        width: parent.width*0.48
        height:parent.height
        startId:leftStartId
        anchors{
            left: root.left
            top:root.top
        }
    }

    Rectangle{
        z:3
        id: middleLine
        color:"#E1E1E1"
        width:root.width*0.001
        height: root.height*0.9
        anchors{
            left: root.left
            verticalCenter: root.verticalCenter
            leftMargin: root.width*0.48
        }
    }

    QuestionHalfPanel{
        id: rightPanel
//        color:"lightblue"
        isLeft: false
        width: parent.width*0.48
        height: parent.height
        startId:rightStartId
        anchors{
            right:root.right
            top: root.top
//            leftMargin: root.width*0
        }
    }

}
