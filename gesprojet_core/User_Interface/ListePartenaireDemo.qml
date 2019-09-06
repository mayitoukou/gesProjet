import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1
import QtQuick.Controls 1.3 as Controls
import "."



Item {
    id: listAssoc

    property int index: partenaireTable.currentRow

    View {
        id: view
        anchors {
            fill: parent
            margins: dp(32)
        }

        elevation: 1
        radius: dp(2)

        Label {
            id: titleLabel

            anchors {
                fill: parent
                leftMargin: dp(100)
            }

            style: "title"
            text: "Liste des Partenaires"
        }

        Column {
            id: column
            anchors.fill: parent
            anchors.topMargin: dp(50)
            anchors.bottomMargin: dp(16)

            TableView {
                id: partenaireTable
                width: parent.width
                height: parent.height

                TableViewColumn {
                    role: "name"
                    title: "Nom"
                    width: 100
                }
                TableViewColumn {
                    role: "sigle"
                    title: "Sigle"
                    width: 100
                }
                TableViewColumn {
                    role: "adresse"
                    title: "Adresse"
                    width: 200
                }


                TableViewColumn {
                    role: "telephone"
                    title: "Telephone"
                    width: 100
                }

                TableViewColumn {
                    role: "email"
                    title: "Email"
                    width: 200
                }

                TableViewColumn {
                    role: "scan_doc"
                    title: "Scan_doc"
                    width: 100
                }

               model: partenaireModel
               onClicked: {
                   partenaireTable.currentRow = index
                   actionSheet.open()
               }

            }

        }

        StackView {
            id: stackView
            anchors.fill: parent
        }


        // Bottom Sheet

        BottomActionSheet {
            id: actionSheet

            title: "Action!"

            actions: [

                Action {
                    iconName: "content/create"
                    name: "Rename"
                    onTriggered: {
                        //editAssoc.open()
                    }
                },

                Action {
                    iconName: "action/delete"
                    name: "Delete"
                    onTriggered: partenaireModel.removeRows(index, 1, 0)
                }
            ]
        }

    }
}
