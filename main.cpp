#include "widget.h"

#include <QApplication>
//#include "QBreakpadHandler.h"
// crash handler
#ifdef Q_OS_WIN
#include "breakpad/src/client/windows/handler/exception_handler.h"

using namespace google_breakpad;

static bool callback(const wchar_t *dump_path, const wchar_t *id,
    void *, EXCEPTION_POINTERS *,
    MDRawAssertionInfo *,
    bool succeeded) {
    if (succeeded)
        qWarning("Dump file created in %s, dump guid is %ws\n", dump_path, id);
    else
        qWarning("Dump failed\n");
    return succeeded;
}
#endif
int main(int argc, char *argv[])
{
    #ifdef Q_OS_WIN
    // 我测试的时候用的固定的路径，这个目录需要预先创建好，否则会创建dump失败.
    ExceptionHandler eh(L"D:/ws/BreakpadTest/crashes", NULL, callback, NULL,
        ExceptionHandler::HANDLER_ALL);
    #endif
    QApplication a(argc, argv);
//    QBreakpadInstance.setDumpPath("crashes");
////此处添加能生成dmp
//    int *p = 0;
//    *p = 100;
    Widget w;
    w.show();
////此处添加不能生成dmp
//    int *p = 0;
//    *p = 100;
    return a.exec();
}
