import QtQuick 2.0
import QtQuick.Controls 2.2


Rectangle{
    id: background
//    color:"lightgray"
    property int commonWidth : this.width
    property int commonHeight : this.height/5

    function initNumValue(){
        plusObject.setSliderValue(plus.num)
        minusObject.setSliderValue(minus.num)
        multObject.setSliderValue(mult.num)
        divObject.setSliderValue(div.num)
    }

    TypePanel {
        id: typePanel
        width:commonWidth
        height:commonHeight
        anchors{
            horizontalCenter: parent.horizontalCenter
            top:parent.top
        }
    }

    SelectObject{
        id:plusObject
        title:"덧셈"
        operator:"＋"
        width:commonWidth
        height:commonHeight
        anchors{
            horizontalCenter: parent.horizontalCenter
            top:typePanel.bottom

        }
        checked : plus.selected
        num : plus.num
        diff1 : plus.diff1
        diff2 : plus.diff2
    }
    SelectObject{
        id:minusObject
        title:"뺄셈"
        operator: "－"
        width:commonWidth
        height:commonHeight
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: plusObject.bottom

        }
        checked : minus.selected
        num : minus.num
        diff1 : minus.diff1
        diff2 : minus.diff2
    }
    SelectObject{
        id:multObject
        title:"곱셈"
        operator: "×"
        width:commonWidth
        height:commonHeight
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: minusObject.bottom
        }
        checked : mult.selected
        num : mult.num
        diff1 : mult.diff1
        diff2 : mult.diff2
    }
    SelectObject{
        id:divObject
        title:"나눗셈"
        operator: "÷"
        width:commonWidth
        height:commonHeight
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: multObject.bottom
        }
        checked : div.selected
        num : div.num
        diff1 : div.diff1
        diff2 : div.diff2
    }


}

