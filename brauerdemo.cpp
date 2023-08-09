#include "brauerdemo.h"
#include "./ui_brauerdemo.h"

QGraphicsScene *scene;
QPen outlinePen(Qt::black);

BrauerDemo::BrauerDemo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BrauerDemo)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphView->setScene(scene);


    outlinePen.setWidth(2);

    scene->addRect(100, 0, 80, 100, outlinePen, Qt::blue);

    drawCircle(100, 100, 40);
}

BrauerDemo::~BrauerDemo()
{
    delete ui;
}

void BrauerDemo::drawCircle(int x, int y, int r)
{
    scene->addEllipse(x, y, r, r, outlinePen, Qt::green);
}

