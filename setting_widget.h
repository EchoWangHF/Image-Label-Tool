#ifndef SETTING_WIDGET_H
#define SETTING_WIDGET_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>

class Setting_Widget : public QWidget
{
    Q_OBJECT

public:
    Setting_Widget(QWidget *parent = nullptr);
    ~Setting_Widget();

    int ojb_num;
    QVector<QString> vec_obv_version;

private:
     QPushButton *over_button;
     QHBoxLayout *first_line_layout;
     QLabel *label_obj_num;
     QLineEdit *lineEdit_obj_num;
     QPushButton *sure_button;

     QVBoxLayout *main_layout;

     QVector<QLineEdit *>line_edit_vec;

public slots:
     void sure_num();
     void overButtonSlot();

signals:
     void test(int,QVector<QString>);
};

#endif // SETTING_WIDGET_H
