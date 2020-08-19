import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4

Rectangle {
    property string title
    property string operator
    property string checkColor : "lightgray"
    property string slideColor : "gray"
    property bool checked
    property int num
    property int diff1
    property int diff2

    function setSliderValue(n){
        numSlideBar.value = n
    }


    onCheckedChanged: {
        console.log(checked)
        firstNum.enabled = checked
        secondNum.enabled = checked
        numSlideBar.enabled = checked
        if(checked){
            checkBox.checkState = Qt.Checked
            checkColor = "black"
            slideColor = "#3865FD"
        }
        else{
            checkBox.checkState = Qt.Unchecked
            checkColor = "lightgray"
            slideColor = "gray"
        }
    }


    CheckBox {
        id: checkBox
        height: parent.height*0.25
        anchors{
            left : parent.left
            leftMargin:parent.width*0.01
            verticalCenter: parent.verticalCenter
        }
        onClicked: {
            switch(operator){
                case '＋':
                    plus.setSelected(checkState==Qt.Checked);
                    break;
                case '－':
                    minus.setSelected(checkState==Qt.Checked);
                    break;
                case '×':
                    mult.setSelected(checkState==Qt.Checked);
                    break;
                case '÷':
                    div.setSelected(checkState==Qt.Checked);
                    break;
            }

        }

    }
    Text{
        id: checkTitle
        text:title
        width: parent.width*0.08
        font.pixelSize: parent.height*0.25
        font.bold: false
        font.family:"NanumBarunGothic"
        color: checkColor
        anchors{
            left:checkBox.right
            leftMargin:parent.width*0.01
            verticalCenter: parent.verticalCenter
        }
    }



    ComboBox{
        id: firstNum
        width:parent.width*0.17
        anchors{
            left:checkTitle.right
            leftMargin: parent.width*0.04
            verticalCenter: parent.verticalCenter
        }
        model:["1자리수", "2자리수", "3자리수", "4자리수"]
        enabled: checked
        currentIndex: diff1-1
        onActivated: {
            switch(operator){
                case '＋':
                    plus.setDifficulty1(currentIndex+1)
                    plus.setDifficulty2(secondNum.currentIndex+1)
                    break
                case '－':
                    minus.setDifficulty1(currentIndex+1)
                    minus.setDifficulty2(secondNum.currentIndex+1)
                    break
                case '×':
                    mult.setDifficulty1(currentIndex+1)
                    mult.setDifficulty2(secondNum.currentIndex+1)
                    break
                case '÷':
                    div.setDifficulty1(currentIndex+1)
                    div.setDifficulty2(secondNum.currentIndex+1)
                    break
            }
        }

    }
    Text{
        id: operatorText
        text: parent.operator
        horizontalAlignment: Text.AlignHCenter
        font.family:"NanumBarunGothic"
        font.pixelSize: 40
        color:checkColor
        width:18
        anchors{
            left:firstNum.right
            leftMargin: parent.width*0.01
            verticalCenter: parent.verticalCenter
        }
    }
    ComboBox{
        id: secondNum
        width:parent.width*0.17
        anchors{
            left:operatorText.right
            leftMargin: parent.width*0.01
            verticalCenter: parent.verticalCenter
        }
        model:["1자리수", "2자리수", "3자리수", "4자리수"]
        enabled: checked
        currentIndex: diff2-1
        onActivated: {
            switch(operator){
                case '＋':
                    plus.setDifficulty1(firstNum.currentIndex+1)
                    plus.setDifficulty2(currentIndex+1)
                    break
                case '－':
                    minus.setDifficulty1(firstNum.currentIndex+1)
                    minus.setDifficulty2(currentIndex+1)
                    break
                case '×':
                    mult.setDifficulty1(firstNum.currentIndex+1)
                    mult.setDifficulty2(currentIndex+1)
                    break
                case '÷':
                    div.setDifficulty1(firstNum.currentIndex+1)
                    div.setDifficulty2(currentIndex+1)
                    break
            }
        }
    }

    Slider{
        id: numSlideBar
        width:parent.width*0.32
        anchors{
            left:secondNum.right
            leftMargin: parent.width*0.04
            verticalCenter: parent.verticalCenter
        }
        background: Rectangle {
                id: sliderBackground
                x: numSlideBar.leftPadding
                y: numSlideBar.topPadding + numSlideBar.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: numSlideBar.availableWidth
                height: parent.parent.height*0.2
                radius: 3
                color: "lightgray"

                Rectangle {
                    id : customSlider
                    width: numSlideBar.visualPosition * parent.width
                    height: parent.height
                    color: slideColor
                    radius: 3
                }
        }
        handle: Rectangle {
            x: numSlideBar.leftPadding + numSlideBar.visualPosition * (numSlideBar.availableWidth - width)
            y: numSlideBar.topPadding + numSlideBar.availableHeight / 2 - height / 2
            implicitWidth: sliderBackground.height*1.5
            implicitHeight: this.implicitWidth
            radius: this.implicitWidth/2
            color: numSlideBar.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }


        from:0
        value : operation.getNumOfQuestion()
        to:100
        stepSize: 10
        onValueChanged: {
            switch(operator){
            case '＋':
                plus.setNumOfQuestion(value)
                break
            case '－':
                minus.setNumOfQuestion(value)
                break
            case '×':
                mult.setNumOfQuestion(value)
                break
            case '÷':
                div.setNumOfQuestion(value)
                break
            }
        }
        enabled:checked



    }


    Text{
        id:sliderValue
        text:numSlideBar.value
        font.pixelSize: parent.height/6
        font.family:"NanumBarunGothic"
        color: checkColor
        anchors{
            right:parent.right
            rightMargin: parent.width*0.02
            verticalCenter: parent.verticalCenter
        }
    }
}
