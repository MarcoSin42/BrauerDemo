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

}

BrauerDemo::~BrauerDemo()
{
    delete ui;
}

/**
 * @brief BrauerDemo::drawCircle Draws a circle
 * @param x horizontal offset (px)
 * @param y vertical offset (px)
 * @param r radius (px)
 */
void BrauerDemo::drawCircle(int x, int y, int r)
{
    scene->addEllipse(x, y, r, r, outlinePen, Qt::green);
}

void BrauerDemo::drawCassOvals()
{

}

double real_root(double t, double a, double K)
{
    return 0.0;
}

