#include "brauerdemo.h"
#include "./ui_brauerdemo.h"
#include "math_utils.h"
#include <QStringBuilder>
#include <QGraphicsItem>
#include <QPainter>

const int CORNER_OFFSET = 50;
const int N_TICKS = 20;

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
    cx_mat a = rand_cxmat(5);
    cx_vec radii = off_diag_sum(a);
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
    vec y_axis = linspace(h - CORNER_OFFSET,0 + 40,N_TICKS+1);
    vec x_axis = linspace(CORNER_OFFSET    ,w - 40,N_TICKS+1);

    vec t_marks = linspace(-N_TICKS / 2   , N_TICKS / 2, N_TICKS + 1);

    int x,y;
    // Move X-axis tick marks up
    // Move Y-axis tick marks to the left
    scene->addLine(CORNER_OFFSET, h - CORNER_OFFSET, w, h - CORNER_OFFSET, *outlinePen); // X Axis
    scene->addLine(CORNER_OFFSET, 0, CORNER_OFFSET, h - CORNER_OFFSET, *outlinePen); // Y Axis

    QGraphicsTextItem *text;
    for (int i = 0; i < y_axis.size(); ++i)
    {
        x = x_axis[i];
        y = y_axis[i];
        if (i != 0) {
            scene->addLine(x, h - CORNER_OFFSET - CORNER_OFFSET/4, x, h - CORNER_OFFSET + CORNER_OFFSET/4, *outlinePen);
            scene->addLine(CORNER_OFFSET - CORNER_OFFSET/4, y, CORNER_OFFSET + CORNER_OFFSET/4, y, *outlinePen);
        }

        // Drawing demarkations on the x axis
        text = new QGraphicsTextItem;
        text->setPos(x - 10, h - CORNER_OFFSET + 15);
        text->setPlainText(QString::number(t_marks[i]));
        text->setDefaultTextColor(Qt::black);

        scene->addItem(text);

        // Drawing demarkations  on the y axis
        text = new QGraphicsTextItem;
        text->setPos(CORNER_OFFSET/2 - 15, y - 15);
        text->setPlainText(QString::number(t_marks[i]));
        text->setDefaultTextColor(Qt::black);

        scene->addItem(text);

    }

}

void BrauerDemo::drawCassOvals()
{

}

