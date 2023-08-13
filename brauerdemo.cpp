#include "brauerdemo.h"
#include "./ui_brauerdemo.h"
#include "math_utils.h"
#include <QStringBuilder>

const int CORNER_OFFSET = 50;

BrauerDemo::BrauerDemo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BrauerDemo)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    outlinePen = new QPen(Qt::black);

    // This part below drove me insane trying to get this behaviour.
    ui->graphView->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    ui->graphView->setScene(scene);

    w = ui->graphView->width();
    h = ui->graphView->height();

    qDebug("w: %d | h: %d", w, h);

    outlinePen->setWidth(2);


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
    // qDebug("w: %d | h: %d asdas", w, h);
    scene->addEllipse(x, y, r, r, *outlinePen, Qt::green);
}

/**
 * @brief BrauerDemo::update Redraws the entire scene, usually is called when window is resized
 */
void BrauerDemo::update()
{
    scene->clear();
    ui->graphView->update();

    scene->setSceneRect(ui->graphView->sceneRect());
    w = ui->graphView->width();
    h = ui->graphView->height();

    qDebug("I've been resized! w: %d | h: %d asdas", w, h);
    drawAxis();
}

void BrauerDemo::resizeEvent(QResizeEvent *event)
{
    update();
}

/**
 * @brief BrauerDemo::drawAxis Draws the axis, is called whenever the scene is redrawn, ex resized window
 */
void BrauerDemo::drawAxis()
{
    vec y_axis = linspace(h - CORNER_OFFSET,0,10);
    vec x_axis = linspace(CORNER_OFFSET,w,10);
    int x,y;

    scene->addLine(0, h - CORNER_OFFSET, w, h - CORNER_OFFSET, *outlinePen);
    scene->addLine(CORNER_OFFSET, 0, CORNER_OFFSET, h, *outlinePen);

    for (int i = 0; i < y_axis.size(); ++i)
    {
        x = x_axis[i];
        y = y_axis[i];

        scene->addLine(x, h - CORNER_OFFSET/2, x, h - 3*CORNER_OFFSET/2, *outlinePen);
        scene->addLine(CORNER_OFFSET/2, y, 3*CORNER_OFFSET/2, y, *outlinePen);

    }
}

void BrauerDemo::drawCassOvals()
{

}

