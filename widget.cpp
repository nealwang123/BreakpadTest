#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    // 执行此句发生异常时，会自动生成dump文件
    // Note: Uncomment below line to test crash dump generation
    // *((int*)0) = 10;
    delete ui;
}


void Widget::on_pushButton_released()
{
    ui->label->setText("->");
    // Note: Uncomment below lines to test crash dump generation
    // QLabel *label=nullptr;
    // label->setText("crash");
}

