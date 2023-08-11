#ifndef BRAUERDEMO_H
#define BRAUERDEMO_H

#include <armadillo>

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QResizeEvent>
#include <QDebug>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class BrauerDemo; }
QT_END_NAMESPACE

class BrauerDemo : public QWidget
{
    Q_OBJECT

public:
    BrauerDemo(QWidget *parent = nullptr);
    ~BrauerDemo();

protected:
    void resizeEvent(QResizeEvent *event) override;
    //void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::BrauerDemo *ui;

    QGraphicsScene *scene;
    QPen *outlinePen;

    int w, h, unit;

    void drawCircle(int x, int y, int r);
    void drawCassOvals();
    void drawAxis();
    void update();

};
#endif // BRAUERDEMO_H
