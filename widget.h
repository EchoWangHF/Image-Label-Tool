#ifndef WIDGET_H
#define WIDGET_H

#include<QWidget>
#include<QPushButton>
#include<QLabel>
#include<QString>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QStyleFactory>
#include<QFrame>
#include<QTextEdit>
#include<QLineEdit>
#include<QPalette>
#include<QStackedWidget>
#include<QVector>
#include<assert.h>
#include"setting_widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    QPushButton *opendir;
    QPushButton *previous;
    QPushButton *next;
    QPushButton *setting;
    QPushButton *save;
    QLabel *signNumber;
    QLabel *signObject;
    QLabel *ImageNum;
    QTextEdit *version;

    QStackedWidget * label_stack;

    QLabel *imgVision;

    QVBoxLayout *left_layout;
    QVBoxLayout *right_layout;
    QHBoxLayout *main_layout;

    QHBoxLayout *right_bootom_layout;
    QVBoxLayout *right_top_2_layout;
    QVBoxLayout *right_mid_2_layout;
    QVBoxLayout *right_top_layout;
    QVBoxLayout *right_mid_layout;
    QVBoxLayout *right_temp_layout;

    Setting_Widget *SW;

    int image_num;
    int sign_object_num;
    QVector<QString> vec_sign_obj;

private slots:
    void start_setting();
    void return_lineText();
};

#endif // WIDGET_H
