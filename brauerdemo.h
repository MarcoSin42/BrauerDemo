#ifndef BRAUERDEMO_H
#define BRAUERDEMO_H

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
    double real_root(double t, double a, double K);

};
#endif // BRAUERDEMO_H
