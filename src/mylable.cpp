#include "mylable.h"

myLable::myLable(QWidget *parent) : QLabel(parent)
{
    mos_x = 0;
    mos_y = 0;
    start_x = 0;
    start_y = 0;
    pushed = false;
}

void myLable::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red));

    if(pushed){
        painter.drawRect(start_x, start_y, mos_x-start_x, mos_y - start_y);
    }

    if(!draw_point_vec.empty()){
        for(auto i : draw_point_vec){
            painter.drawRect(i.x,i.y,i.w,i.h);
        }
    }

    update();
}

void myLable::mousePressEvent(QMouseEvent *event)
{
    start_x = event->x();
    start_y = event->y();
    pushed = true;
}

void myLable::mouseMoveEvent(QMouseEvent *event)
{
    if (pushed == true) {
        mos_x = event->x();
        mos_y = event->y();
    }
}

void myLable::mouseReleaseEvent(QMouseEvent *event)
{
    pushed = false;
    draw_point draw_temp(start_x, start_y, mos_x-start_x, mos_y - start_y);
    draw_point_vec.emplace_back(draw_temp);
}
