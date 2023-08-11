#ifndef BRAUERDEMO_H
#define BRAUERDEMO_H

#include <armadillo>

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class BrauerDemo; }
QT_END_NAMESPACE

class BrauerDemo : public QWidget
{
    Q_OBJECT

public:
    BrauerDemo(QWidget *parent = nullptr);
    ~BrauerDemo();


private:
    Ui::BrauerDemo *ui;
    void drawCircle(int x, int y, int r);
    void drawCassOvals();
<<<<<<< HEAD
=======

>>>>>>> origin/main
};
#endif // BRAUERDEMO_H
