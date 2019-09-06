TEMPLATE = subdirs

SUBDIRS += \
    gesprojet \
    User_Interface

User_Interface.depends = gesprojet
