import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 900
    height: 700
    rotation: 0
    z: 0
    scale: 1

    property alias imageElevator1: imageElevator1
    property alias imageElevator2: imageElevator2
    property alias imageElevator3: imageElevator3
    property alias imageShaft1: imageShaft1
    property alias imageShaft2: imageShaft2
    property alias imageShaft3: imageShaft3
    property alias imagePassenger: imagePassenger

    RowLayout
    {
        width: 895
        height: 487
        scale: 1
        spacing: 5
        anchors.centerIn: parent
        Image
        {
            id: imageShaft1
            x: 25
            y: 50
            width: 161
            height: 396
            scale: 0.6
            transformOrigin: Item.Center
            rotation: 0
            fillMode: Image.Stretch
            source: "szyb.png"
        }

        Image
        {
            id: imageShaft2
            x: 25
            y: 50
            width: 161
            height: 396
            scale: 0.6
            transformOrigin: Item.Center
            rotation: 0
            fillMode: Image.Stretch
            source: "szyb.png"
        }

        Image
        {
            id: imageShaft3
            x: 25
            y: 51
            width: 161
            height: 396
            scale: 0.6
            transformOrigin: Item.Center
            rotation: 0
            fillMode: Image.Stretch
            source: "szyb.png"
        }
    }

    Image
    {
        id: imagePassenger
        x: 317
        y: 18
        width: 100
        height: 100
        scale: 0.2
        source: "passenger.png"
    }

    Image
    {
        id: imageElevator1
        x: 62
        y: 228
        width: 175
        height: 31
        source: "elevator.png"
        objectName: "imageElevator1"
    }

    Image
    {
        id: imageElevator2
        x: 662
        y: 228
        width: 175
        height: 31
        source: "elevator.png"
        objectName: "imageElevator2"
    }

    Image
    {
        id: imageElevator3
        x: 362
        y: 228
        width: 175
        height: 31
        source: "elevator.png"
        objectName: "imageElevator3"
    }


}
