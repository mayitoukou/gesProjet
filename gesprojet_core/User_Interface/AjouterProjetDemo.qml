import QtQuick 2.4
import QtQuick.Layouts 1.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1

Item {
    property int associationId
    property int partenaireId

    function hideField()  {
        titre.text = ""
        description.text =""
        dateDebut.text =""
        dateFin.text =""
        objectif.text =""
        nom_chef.text =""
        prenom_chef.text =""
        telephone.text = ""
        email.text = ""
        contient.text =""
        pays.text =""
        region.text =""
        localite.text =""
        cout.text =""
    }

    View {
        anchors.fill: parent
        anchors.margins: dp(32)
        width: dp(350)
        height: column.implicitHeight + dp(32)

        elevation: 1
        radius: dp(2)

        ColumnLayout {
            id: column

            anchors {
                fill: parent
                topMargin: dp(16)
                bottomMargin: dp(16)
            }

            Label {
                id: titleLabel

                anchors {
                    fill: parent
                    leftMargin:  dp(100)
                }

                style: "title"
                text: "Ajout Projet"
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: dp(8)
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/settings"
                }

                Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width

                    TextField {
                        id: titre
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Titre"
                    }

                    TextField {
                        id: description
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "description"
                    }
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width

                    TextField {
                        id: dateDebut
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "date début"
                    }

                    TextField {
                        id: dateFin
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "date fin"
                    }
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "communication/email"
                }

                Icon {
                    anchors.centerIn: parent
                    name: ""
                }

                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width

                    TextField {
                        id: objectif
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Objectif"
                    }

                    TextField {
                        id: nom_chef
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Nom Chef projet"
                    }

                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width                   

                    TextField {
                        id: prenom_chef
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Prenom Chef projet"
                    }

                    TextField {
                        id: telephone
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Numéro de teléphone"
                    }
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width                    

                    TextField {
                        id: email
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Email Chef projet"
                    }

                    TextField {
                        id: contient
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Continent"
                    }
                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }
                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width                   

                    TextField {
                        id: pays
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Pays"
                    }

                    TextField {
                        id: region
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Region"
                    }

                }
            }

            ListItem.Standard {
                action: Icon {
                    anchors.centerIn: parent
                    name: "action/account_circle"
                }

                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width                    

                    TextField {
                        id: localite
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Localité"
                    }

                    TextField {
                        id: cout
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width
                        placeholderText: "Côut"
                    }
                }
            }



            ListItem.Standard {
                content: RowLayout {
                    anchors.centerIn: parent
                    width: parent.width

                    Text {
                        id: partenaire
                        text: qsTr("Partenaire")
                    }

                    MenuField {
                        id: textPartenaire
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.3 * parent.width
                        model: partenaireModel
                        textRole: "name"
                        onSelectedIndexChanged: {
                            partenaireId = partenaireModel.dataId(selectedIndex)
                        }
                    }

                    Text {
                        id: textAssociation
                        text: qsTr("Association")
                    }

                    MenuField {
                        id: association
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.3 * parent.width
                        model: associationModel
                        textRole: "nom"
                        onSelectedIndexChanged: {
                            associationId = associationModel.dataId(selectedIndex)
                        }
                    }

                }
            }

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: dp(8)
            }

            RowLayout {
                Layout.alignment: Qt.AlignRight
                spacing: dp(8)

                anchors {
                    right: parent.right
                    margins: dp(16)
                }

                Button {
                    text: "Annuler"
                    textColor: Theme.primaryColor
                    onClicked: hideField()
                }

                Button {
                    text: "Enregistrer"
                    textColor: Theme.primaryColor
                    onClicked: projetModel.add(titre.text, description.text, dateDebut.text, dateFin.text, objectif.text, nom_chef.text, prenom_chef.text,
                                                                            telephone.text, email.text, contient.text, pays.text, region.text, localite.text, cout.text, partenaireId, associationId)
                }
            }
        }
    }
}
