import QtQuick 2.0

Rectangle {
    property int startId
    property bool isLeft


    id: root

    Column{
        id: leftSide
        width: root.width*0.48
        height: root.height
        anchors{
            left:root.left
            top: root.top
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
                id: questionItem
                width: leftSide.width
                height: leftSide.height/5
                questionId: startId+index

            }

        }
    }


    Column{
        id: rightSide
        width: root.width*0.48
        height: root.height
        anchors{
            left:leftSide.right
            top: root.top
            leftMargin: root.width*0.018
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
                width: rightSide.width
                height: rightSide.height/5
                questionId: startId+index+5
            }
        }
    }

}
