#include "busdetail.hpp"
#include "ui_busdetail.h"

BusDetail::BusDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusDetail)
{
    ui->setupUi(this);
}

BusDetail::~BusDetail()
{
    delete ui;
}
