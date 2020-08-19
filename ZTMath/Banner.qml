import QtQuick 2.0

Rectangle {
    property string mainText
    property string subText
    property bool subTextVisible
    property int mainTextSize : this.height*0.8
    property int subTextSize : this.height*0.5
    property bool mainTextBold : true
    property bool subTextBold : true
    Text {
        id: mainTitle
        text: mainText
        font.family: "NanumGothic"
        font.pixelSize: mainTextSize
        font.bold: mainTextBold
        anchors{
            left:parent.left
            leftMargin: parent.width*0.01
        }
    }
    Text {
        id: subTitle
        text: subText
        font.family: "NanumGothic"
        font.pixelSize: subTextSize
        font.bold: subTextBold
        anchors{
            left:mainTitle.right
            bottom:mainTitle.bottom
            leftMargin: parent.width*0.01
        }
        visible:subTextVisible
    }
}
