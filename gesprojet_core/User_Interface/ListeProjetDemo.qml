import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1

Item {
    View {
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
            text: "Liste des Projets"
        }


        Column {
            id: column
            anchors.fill: parent
            anchors.topMargin: dp(50)
            anchors.bottomMargin: dp(16)

            TableView {
                id: associationTable
                width: parent.width
                height: parent.height

                TableViewColumn {
                    role: "code"
                    title: "Code"
                    width: 100
                }
                TableViewColumn {
                    role: "nom"
                    title: "Nom"
                    width: 100
                }
                TableViewColumn {
                    role: "adresse"
                    title: "Adresse"
                    width: 100
                }
                TableViewColumn {
                    role: "telephone"
                    title: "Telephone"
                    width: 100
                }
                TableViewColumn {
                    role: "code_postal"
                    title: "Code Postal"
                    width: 100
                }
                TableViewColumn {
                    role: "email"
                    title: "Email"
                    width: 200
                }
                TableViewColumn {
                    role: "domaine"
                    title: "Domaine"
                    width: 100
                }
                TableViewColumn {
                    role: "type_assoc"
                    title: "Type Association"
                    width: 200
                }
               model: projetModel

            }

        }
    }
}
