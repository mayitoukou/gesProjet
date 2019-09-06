#-------------------------------------------------
#
# Project created by QtCreator 2018-09-15T01:33:35
#
#-------------------------------------------------

QT       += sql
CONFIG      +=c++11

QT       -= gui

TARGET = gesprojet
TEMPLATE = lib

DEFINES += GESPROJET_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        association.cpp \
    domaine.cpp \
    type_association.cpp \
    partenaire.cpp \
    projet.cpp \
    databasemanager.cpp \
    domainedao.cpp \
    typeassocdao.cpp \
    partenairedao.cpp \
    associationdao.cpp \
    projetdao.cpp \
    domainemodel.cpp \
    typeassocmodel.cpp \
    associationmodel.cpp \
    partenairemodel.cpp \
    projetmodel.cpp

HEADERS += \
        association.h \
        gesprojet_global.h \ 
    domaine.h \
    type_association.h \
    partenaire.h \
    projet.h \
    databasemanager.h \
    domainedao.h \
    dao.h \
    typeassocdao.h \
    partenairedao.h \
    associationdao.h \
    projetdao.h \
    domainemodel.h \
    typeassocmodel.h \
    associationmodel.h \
    partenairemodel.h \
    projetmodel.h


