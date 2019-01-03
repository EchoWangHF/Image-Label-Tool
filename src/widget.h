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
#include<QFileDialog>
#include<QDebug>
#include<QDir>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include<vector>
#include"mylable.h"
#include<QTreeWidget>
#include<QXmlStreamWriter>
#include<QFile>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void keyPressEvent(QKeyEvent *event);
private:
    QPushButton *opendir;
    QPushButton *previous;
    QPushButton *next;
    QPushButton *setting;
    QPushButton *save;
    QPushButton *remove;
    QLabel *signNumber;
    QLabel *signObject;
    QLabel *ImageNum;
    QLabel *isTag;
    QTextEdit *version;

    QStackedWidget * label_stack;

//    QLabel *imgVision;
    myLable *imgVision;

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

    //int image_num;
    int sign_object_num;
    QVector<QString> vec_sign_obj;

    QFileDialog *opendir_file;
    QString file_dir;
    QFileInfoList list;
    int index;
    QImage *img;

    QString XML_file_save_path;

    void readImage(QString img_path);
    bool ImageisTag();
    void write_xml();
    void read_xml();

//    QPainter *painter;

private slots:
    void start_setting();
    void return_lineText();
    void opendier_slots();
    void previous_button_slots();
    void next_button_slots();
    void remove_button_slots();
    void save_buttion_slots();
signals:
    void read_dir_over();
};

#endif // WIDGET_H
