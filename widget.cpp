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
    *((int*)0) = 10;
    delete ui;
}


void Widget::on_pushButton_released()
{
    ui->label->setText("->");
    QLabel *label=nullptr;
    label->setText("crash");
}

