#ifndef GESPROJET_GLOBAL_H
#define GESPROJET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GESPROJET_LIBRARY)
#  define GESPROJETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GESPROJETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GESPROJET_GLOBAL_H
