 import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtGraphicalEffects 1.12


Window {
    visible: true
    width: 1280
    height: 720
    title: qsTr("JokJang's ZT Math")
    property int pageIndex : page.currentPage
    property bool isError : page.errorState
    property bool isAnswer : page.answerMode

    Rectangle{
        id: container
        anchors.fill : parent

        MainPage{
            id: mainPage
            width:parent.width
            height:parent.height
            visible: {
                if(pageIndex){
                    false
                }
                else{
                    true
                }
            }
        }

        QuestionPage{
            id:questPage
            width:parent.width
            height:parent.height
            visible: {
                if(pageIndex){
                    true
                }
                else{
                    false
                }
            }
        }



    }



   BrightnessContrast{
       id: brightControl
       anchors.fill: container
       source: container
   }

   AnswerPage{
       id: answerPager
       visible: page.answerMode
       width: parent.width*0.9
       height: parent.height*0.8
   }

   ErrorPage{
       id: errorPage
       visible:isError
       errorText: page.errorMainMsg
       explainText: page.errorSubMsg
   }

   onIsErrorChanged: {
       if(isError){
            brightControl.brightness = -0.3
       }
       else if(!isAnswer){
           brightControl.brightness = 0
       }

   }
   onIsAnswerChanged: {
       if(isAnswer){
           brightControl.brightness = -0.3
       }
       else{
           brightControl.brightness = 0
       }
   }


}
