#ifndef BRAUERDEMO_H
#define BRAUERDEMO_H

#include <QWidget>

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
};
#endif // BRAUERDEMO_H
