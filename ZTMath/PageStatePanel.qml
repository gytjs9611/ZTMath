import QtQuick 2.0

Rectangle {
    property int current : page.currentPage
    property int total : page.totalPage
    property int pageTextSize : this.height*0.5

    Text{
        width: parent.width*0.25
        height: parent.height*0.8
        id:pageState
        text:current + "   /   " + total
        font{
            family:"NanumBarunGothic"
            pixelSize: pageTextSize
            bold: true
        }
        anchors{
            bottom:parent.bottom
            right:leftButton.left
            rightMargin:parent.width*0.05
        }
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight

    }
    CommonButton{
        id: leftButton
        width: parent.width*0.25
        height:parent.height*0.8
        buttonText : "<  이전 페이지"
        anchors{
            bottom:parent.bottom
            right:rightButton.left
            rightMargin: parent.width*0.01

        }
        onCommonButtonClicked: {
            if(!page.errorState){
                if(current==1){
                    page.setErrorMainMsg("경고!");
                    page.setErrorSubMsg("첫 페이지입니다.");
                    page.setErrorState(true)
                }
                else{
                    page.setCurrentPage(current-1)
                }
            }

        }

    }
    CommonButton{
        id: rightButton
        width: parent.width*0.25
        height:parent.height*0.8
        buttonText : "다음 페이지  >"
        anchors{
            bottom:parent.bottom
            right:answerButton.left
            rightMargin:parent.width*0.02
        }
        onCommonButtonClicked: {
            if(!page.errorState){
                if(current==page.totalPage){
                    page.setErrorMainMsg("경고!");
                    page.setErrorSubMsg("마지막 페이지입니다.");
                    page.setErrorState(true)
                }
                else if(!page.errorState){
                    page.setCurrentPage(current+1)
                }
            }
        }

    }
    CommonButton{
        id: answerButton
        width: parent.width*0.25
        height:parent.height*0.8
        buttonText : "정답보기"
        buttonColor: "#333333"
        buttonPressedColor: "#262626"
        anchors{
            bottom:parent.bottom
            right:parent.right
            leftMargin:parent.width*0.01
        }
        onCommonButtonClicked: {
            if(!page.errorState){
                page.setAnswerMode(true)
                page.setAnswerCurrentPage(1)
            }

        }

    }
}
