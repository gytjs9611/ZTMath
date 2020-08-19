import QtQuick 2.0
import QtQuick.Controls 2.4

Rectangle {
    property int questionId
    property string questionString
    property bool complete : operation.complete
    property bool answerMode : page.answerMode

//    color:"lightpink"
    id: root

    Text{
        id: index
        text: {
            if(questionId<10){
                "00"+questionId
            }
            else if(questionId<100){
                "0"+questionId
            }
            else{
                questionId
            }
        }
        width:parent.width*0.2
        height:parent.height
        color:"#176AFF"
        font{
            family:"NanumBarunGothic"
            pixelSize: this.height*0.3
            bold: true
        }
        anchors{
            left:root.left
            verticalCenter: parent.verticalCenter
        }
        verticalAlignment: Text.AlignVCenter

    }

    Text{
        id: question
        text: questionString
        width : parent.width*0.7
        height: parent.height
        font{
            family:"NanumBarunGothic"
            pixelSize: this.height*0.22
            bold: false
        }
        anchors{
            left: index.right
            verticalCenter: parent.verticalCenter
            leftMargin: parent.width* 0.07
        }
        verticalAlignment: Text.AlignVCenter

    }

    function setQuestionString(){
        questionString = operation.getQuestNum1(questionId)
        switch(operation.getOperator(questionId)){
        case 1:
            questionString += "＋"
            break
        case 2:
            questionString += '－'
            break
        case 3:
            questionString += '×'
            break
        case 4:
            questionString += '÷'
            break
        }
        questionString += operation.getQuestNum2(questionId)
    }

    function setAnswerString(){
        questionString = operation.getAnswer(questionId)
    }

    onCompleteChanged: {
        setQuestionString()
    }

    onQuestionIdChanged: {
        if(complete && !answerMode){
            setQuestionString()
        }
        if(complete && answerMode){
            setAnswerString()
        }

    }

    onAnswerModeChanged: {
        if(answerMode){
            setAnswerString()
        }
        else{
            setQuestionString()
        }

    }


}
