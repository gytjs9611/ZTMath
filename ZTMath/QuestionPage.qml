import QtQuick 2.0
import QtQuick.Controls 2.4

Item {
   QuestBanner{
//       color:"lightgray"
       id: questBanner
       width:parent.width*0.17
       height:parent.height*0.07
       anchors{
           top: parent.top
           left: parent.left
           topMargin: parent.height*0.1
           leftMargin: parent.height*0.08
       }
   }
   PageStatePanel{
//       color:"lightgray"
       id: pageStatePanel
       width: parent.width*0.4
       height:questBanner.height
       anchors{
           top:questBanner.top
           right:parent.right
           rightMargin:parent.height*0.08
       }
   }
   QuestContentsPanel{
//       color: "lightgray"
       id: questContentsPanel
       width:parent.width*0.91
       height:parent.height*0.7
       anchors{
           top:questBanner.bottom
           horizontalCenter:parent.horizontalCenter
           topMargin: parent.height*0.03
       }
   }



}
