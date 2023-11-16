#include "volume.h"
#include "ui_volume.h"

volume::volume(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::volume)
{
    ui->setupUi(this);

}

volume::~volume()
{
    delete ui;
}

void volume::on_pushButton_clicked()
{
    QString value = ui->textEdit->toPlainText();
    SparkDemo demo;
    QString answer = demo.call(value);
    this->ui->textEdit_2->setText(answer);
}

void volume::on_toolButton_clicked()
{
    QWidget::close();
}
