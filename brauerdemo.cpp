#include "brauerdemo.h"
#include "./ui_brauerdemo.h"

BrauerDemo::BrauerDemo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BrauerDemo)
{
    ui->setupUi(this);
}

BrauerDemo::~BrauerDemo()
{
    delete ui;
}

