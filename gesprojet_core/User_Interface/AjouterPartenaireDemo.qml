import QtQuick 2.4
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1
import Material 0.2
import Material.ListItems 0.1 as ListItem
import Material.Extras 0.1


Item {


    function hideField()  {
        sigle.text = ""
        name.text = ""
        adresse.text = ""
        telephone.text = ""
        email.text = ""
        scan_doc.text = ""
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
                text: "Ajout Partenaire"
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
                        id: name
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width

                        placeholderText: "name"
                    }

                    TextField {
                        id:sigle
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width

                        placeholderText: "Sigle"
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
                        id: adresse
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width

                        placeholderText: "Adresse"
                    }

                    TextField {
                        id:telephone
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width

                        placeholderText: "Telephone"
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
                        id:email
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width

                        placeholderText: "Email"
                    }

                    TextField {
                        id: scan_doc
                        Layout.alignment: Qt.AlignVCenter
                        Layout.preferredWidth: 0.4 * parent.width

                        placeholderText: "scan_doc"
                    }
                }
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
                    text: "Valider"
                    textColor: Theme.primaryColor
                    onClicked: {
                        partenaireModel.add(name.text, sigle.text, adresse.text, telephone.text, email.text, scan_doc.text);
                        hideField();
                    }
                }
            }
        }
    }
}
