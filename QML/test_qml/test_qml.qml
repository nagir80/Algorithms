import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Rectangle {
width: 300
height: 150
signal mousePositionChanged(real x, real y)
onMousePositionChanged:
    txt.text = "<h1>X:" + x + "; Y:" + y + "</h1>"

    Text {
        id: txt
        text: "<h1>Move the Mouse</h1>"
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onMousePositionChanged:
            parent.mousePositionChanged(mouseX, mouseY)
    }
}
