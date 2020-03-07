#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include<QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void enterEvent(QEvent *ev) override;
    void leaveEvent(QEvent *ev) override;




signals:

};

#endif // MYLABEL_H
