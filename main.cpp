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
    // 创建crashes目录用于存储dump文件
    // Create crashes directory for storing dump files
    // Note: Use relative path "./crashes" or configure via environment variable
    ExceptionHandler eh(L"./crashes", NULL, callback, NULL,
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
