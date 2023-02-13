QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp mainwindow.cpp \
    ../calculator/calculation.c \
    ../calculator/validation.c \
    ../calculator/parcer.c \
    ../calculator/stack.c \
    ../calculator/credit.c \
    ../calculator/deposit.c \
    creditcalc.cpp \
    depositcalc.cpp \
    qcustomplot.cpp

HEADERS += mainwindow.h \
    ../calculator/headers/calculation.h \
    ../calculator/headers/validation.h \
    ../calculator/headers/parcer.h \
    ../calculator/headers/stack.h \
    ../calculator/headers/credit.h \
    ../calculator/headers/deposit.h \
    creditcalc.h \
    depositcalc.h \
    qcustomplot.h

FORMS += mainwindow.ui \
    creditcalc.ui \
    depositcalc.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourse.qrc
