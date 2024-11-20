message("BREAKPAD_crash_handler_attached")


INCLUDEPATH += $$PWD/qBreakpad/include

HEADERS += \
    $$PWD/qBreakpad/QBreakpadHandler.h \
    $$PWD/qBreakpad/QBreakpadHttpUploader.h

LIBS += \
    -L$$PWD/qBreakpad/release -lqBreakpad
