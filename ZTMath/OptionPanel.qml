import QtQuick 2.0
import QtQuick.Controls 2.4


Rectangle{
    width:parent.width
    height:parent.height

    Text{
        id: optionTitle
        width:parent.width
        text:"  +  추가옵션"
        font{
            pixelSize:parent.height*0.08
            family:"NanumBarunGothic"
            bold: true
        }
        anchors{
            top: parent.top
            left: parent.left
            topMargin: parent.height*0.1
            leftMargin: parent.width*0.1
        }
    }

    CheckBox{
        id: inputModeCheckBox
        text:" 입력모드로 풀기"
        font{
            pixelSize: parent.height*0.08
            family:"NanumBarunGothic"
            bold: false
        }
        anchors{
            top: optionTitle.bottom
            left: optionTitle.left
            topMargin : parent.height*0.06
        }
    }

    CheckBox{
        id: randModeCheckBox
        text:" 문제 순서 랜덤"
        font{
            pixelSize: parent.height*0.08
            family:"NanumBarunGothic"
            bold: false
        }
        anchors{
            top: inputModeCheckBox.bottom
            left: optionTitle.left
            topMargin : parent.height*0.07
        }
    }

    CheckBox{
        id: tempCheckBox
        text:" 골룸 골룸 모드"
        font{
            pixelSize: parent.height*0.08
            family:"NanumBarunGothic"
            bold: false
        }
        anchors{
            top: randModeCheckBox.bottom
            left: optionTitle.left
            topMargin : parent.height*0.07
        }
    }



}

