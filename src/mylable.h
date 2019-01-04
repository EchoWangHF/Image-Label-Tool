#ifndef MYLABLE_H
#define MYLABLE_H

#include <QWidget>
#include<QLabel>
#include<vector>
#include<QPainter>
#include<QPaintEvent>
#include<QMouseEvent>

struct draw_point{
    int x;
    int y;
    int w;
    int h;
    draw_point(int s_x,int s_y,int w_len,int h_len):x(s_x),y(s_y),w(w_len),h(h_len){}
};

class myLable : public QLabel{
    Q_OBJECT
public:
    explicit myLable(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event) override;
    std::vector<draw_point> get_vec_draw();
    void clear_vec_draw();
private:
    std::vector<draw_point> draw_point_vec;
    int mos_x,mos_y,start_x, start_y;
    bool pushed;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:
    void remove_draw_slots();
};

#endif // MYLABLE_H
