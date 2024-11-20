QT += core network gui

CONFIG += debug_and_release warn_on
CONFIG += thread exceptions rtti stl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO
# link qBreakpad library
include($$PWD/qBreakpad.pri)

#INCLUDEPATH += $$PWD/breakpad/src
#INCLUDEPATH +=$$PWD/breakpad/src/client/windows
#SOURCES += \
#    breakpad/src/client/windows/crash_generation/client_info.cc \
#    breakpad/src/client/windows/crash_generation/crash_generation_client.cc \
#    breakpad/src/client/windows/crash_generation/crash_generation_server.cc \
#    breakpad/src/client/windows/crash_generation/minidump_generator.cc \
#    breakpad/src/client/windows/handler/exception_handler.cc \
#    breakpad/src/common/windows/guid_string.cc

#HEADERS += \
#    breakpad/src/client/windows/crash_generation/client_info.h \
#    breakpad/src/client/windows/crash_generation/crash_generation_client.h \
#    breakpad/src/client/windows/crash_generation/crash_generation_server.h \
#    breakpad/src/client/windows/crash_generation/minidump_generator.h \
#    breakpad/src/client/windows/handler/exception_handler.h \
#    breakpad/src/common/windows/guid_string.h
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
