import QtQuick 2.0

Rectangle {
    property int startId : 1+(page.answerCurrentPage-1)*20
    property int currentPage : page.answerCurrentPage

    onCurrentPageChanged: {
        startId = 1+(page.answerCurrentPage-1)*20
    }

    id : root
    color: "white"
    radius:5
    anchors{
        centerIn: parent
    }
    MouseArea{
        anchors.fill : parent
        onWheel: {
            if(wheel.angleDelta.y>0){
                if(page.answerCurrentPage!=1){
                    page.setAnswerCurrentPage(page.answerCurrentPage-1)
                }
            }
            else{
                if(page.answerCurrentPage!=page.answerTotalPage){
                    page.setAnswerCurrentPage(page.answerCurrentPage+1)
                }
            }
        }
    }

    Banner{
//        color:"lightblue"
        id: bannerPanel
        mainText:"정답확인"
//        subText: " "+page.answerCurrentPage+" / "+page.answerTotalPage
        subTextBold: true
        mainTextSize: parent.width*0.035
        z: 1
        width: parent.width*0.15
        height: parent.height*0.07
        anchors{
            top: parent.top
            left: parent.left
            topMargin: parent.height*0.06
            leftMargin: parent.height*0.17
        }
        subTextVisible: false
    }
    Text{
        text:" "+page.answerCurrentPage+" / "+page.answerTotalPage
        font{
            bold:true
            pixelSize: parent.width*0.018
            family: "NanumBarunGothic"
        }

        z:1
        width:parent.width*0.05
        height:this.width/3
        anchors{
            top: bannerPanel.top
            left: bannerPanel.right
            topMargin: parent.height*0.043
        }
        horizontalAlignment: Text.AlignRight
    }

    CommonButton{
        id: closeButton
        width: parent.width*0.032
        height: this.width
        text: "x"
        textSize: width*0.8
        radiusValue: width*0.2
        buttonColor: "#C41B1B"
        buttonPressedColor: "#911414"
        anchors{
            top : parent.top
            right: parent.right
            topMargin: parent.width*0.01
            rightMargin: parent.width*0.01
        }
        onClicked: {
            page.setAnswerMode(false)
        }
    }

    Rectangle{
        property int columnWidth : this.width/4
        property int itemHeight : this.height/5

//        z: 3
//        color: "lightgray"
        id: answerPanel
        width: parent.width*0.8
        height: parent.height*0.8
        anchors{
            top: closeButton.bottom
            left: parent.left
//            horizontalCenter: root.horizontalCenter
            leftMargin: parent.width*0.095
            topMargin: parent.height*0.07
        }

        Column{
            id: first
            width: parent.columnWidth
            height: parent.height
            anchors{
                left:parent.left
                top: parent.top
            }
            Repeater{
                model: {
                    if(startId>operation.num){
                        0
                    }
                    else{
                        5
                    }
                }

                QuestionItem{
                    id: answer1
                    width: first.width
                    height: answerPanel.itemHeight
                    questionId: startId+index

                }
            }
        }

        Column{
            id: second
            width: parent.columnWidth
            height: parent.height
            anchors{
                left:first.right
                top: parent.top
            }
            Repeater{
                model: {
                    if(startId+5>operation.num){
                        0
                    }
                    else{
                        5
                    }
                }

                QuestionItem{
                    id: answer2
                    width: second.width
                    height: answerPanel.itemHeight
                    questionId: startId+index+5
                }
            }
        }

        Column{
            id: third
            width: parent.columnWidth
            height: parent.height
            anchors{
                left:second.right
                top: parent.top
                leftMargin: parent.width*0.1
            }
            Repeater{
                model: {
                    if(startId+10>operation.num){
                        0
                    }
                    else{
                        5
                    }
                }

                QuestionItem{
                    id: answer3
                    width: third.width
                    height: answerPanel.itemHeight
                    questionId: startId+index+10
                }
            }
        }

        Column{
            id: fourth
            width: parent.columnWidth
            height: parent.height
            anchors{
                left:third.right
                top: parent.top
            }
            Repeater{
                model: {
                    if(startId+15>operation.num){
                        0
                    }
                    else{
                        5
                    }
                }

                QuestionItem{
                    id: answer4
                    width: fourth.width
                    height: answerPanel.itemHeight
                    questionId: startId+index+15
                }
            }
        }


    }






}
