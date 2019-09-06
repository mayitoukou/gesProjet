#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

#include "domainemodel.h"
#include "typeassocmodel.h"
#include "associationmodel.h"
#include "partenairemodel.h"
#include "projetmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    DomaineModel domaineModel;
    TypeAssocModel typeAssocModel;
    AssociationModel associationModel;
    PartenaireModel partenaireModel;
    ProjetModel projetModel;

    QQmlApplicationEngine engine;

    QQmlContext * context = engine.rootContext();
    context->setContextProperty("domaineModel", &domaineModel);
    context->setContextProperty("typeAssocModel", &typeAssocModel);
    context->setContextProperty("associationModel", &associationModel);
    context->setContextProperty("partenaireModel", &partenaireModel);
    context->setContextProperty("projetModel", &projetModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
