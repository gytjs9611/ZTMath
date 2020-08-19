import QtQuick 2.0

Rectangle {
    property int sum
    function setQuestionNum(){
        sum = 0
        if(plus.selected && plus.num){
            sum+=plus.num
        }
        if(minus.selected && minus.num){
            sum+=minus.num
        }
        if(mult.selected && mult.num){
            sum+=mult.num
        }
        if(div.selected && div.num){
            sum+=div.num
        }
        operation.setNumOfQuestion(sum)
    }

    function createQuestion(){
        operation.mallocQuestion()
        if(plus.selected){
            plus.createQuestion()
        }
        if(minus.selected){
            minus.createQuestion()
        }
        if(mult.selected){
            mult.createQuestion()
        }
        if(div.selected){
            div.createQuestion()
        }
        operation.combineQuestion(operation.randOption, plus, minus, mult, div)
    }

    CommonButton {
        id: initButton
        width: parent.width*0.485
        height: this.width/3
        buttonText: "초기화"
        buttonColor : "#474A52"
        buttonPressedColor: "#34373D"


        anchors{
            top:parent.top
            left:parent.left
        }
        onCommonButtonClicked: {
            if(!page.errorState){
                plus.init()
                minus.init()
                mult.init()
                div.init()
                selectPanel.initNumValue()
            }
        }
    }
    CommonButton {
        id: completebutton
        width: parent.width*0.485
        height: this.width/3
        buttonText: "완료"
        anchors{
            top:initButton.top
            left:initButton.right
            leftMargin:parent.width*0.03
        }
        onCommonButtonClicked: {
            setQuestionNum()
            if(operation.num){
                page.setErrorState(false)
                page.setTotalPage(Math.ceil(operation.num/20)) // rounding up
                page.setAnswerTotalPage(Math.ceil(operation.num/20))
//                console.log(page.totalPage)
                operation.mallocQuestion()
                createQuestion()
                page.setCurrentPage(1) // move to page 1
            }
            else{
                page.setErrorMainMsg("경고!");
                page.setErrorSubMsg("최소 하나 이상의 개체를 선택하세요.");
                page.setErrorState(true) // error window
            }
        }
    }

}
