#include "setting_widget.h"
#include <QDebug>

Setting_Widget::Setting_Widget(QWidget *parent) :
    QWidget(parent)
{
    ojb_num=0;
    this->resize(400,200);
    this->setWindowTitle("设置");
    this->setStyleSheet("background-color:rgb(211,211,211);");  //设置整个窗口的背景颜色；
    this->setWindowIcon(QIcon(":/images/2.ico"));

    QFont font("ZYSong", 15);

    main_layout=new QVBoxLayout(this);

    first_line_layout=new QHBoxLayout(this);
    label_obj_num=new QLabel("标记目标数：",this);
    label_obj_num->setFixedSize(130,40);
    label_obj_num->setFont(font);
    label_obj_num->setAlignment(Qt::AlignCenter);

    lineEdit_obj_num=new QLineEdit(this);
    lineEdit_obj_num->setFixedSize(150,40);
    lineEdit_obj_num->setFont(font);

    sure_button=new QPushButton("确定",this);
    sure_button->setFixedSize(100,40);
    sure_button->setStyleSheet("color:white;background-color: gray;");

    first_line_layout->addWidget(label_obj_num);
    first_line_layout->addWidget(lineEdit_obj_num);
    first_line_layout->addWidget(sure_button);

    main_layout->addLayout(first_line_layout);

    connect(sure_button,SIGNAL(clicked()),this,SLOT(sure_num()));

}

Setting_Widget::~Setting_Widget()
{
    if(!line_edit_vec.empty()){
        for(auto each:line_edit_vec){
            delete each;
        }
        line_edit_vec.clear();
    }
}

void Setting_Widget::sure_num()
{
    QFont font("ZYSong", 15);
    this->resize(400,45*(ojb_num+1)+200);
    QString num_text=lineEdit_obj_num->text();
    ojb_num=num_text.toInt();
    for(int i=0;i<ojb_num;++i){
        QHBoxLayout *temp_layout=new QHBoxLayout(this);
        QLabel *label_temp=new QLabel(this);
        label_temp->setFixedSize(150,40);
        label_temp->setFont(font);
        label_temp->setText("第"+QString::number(i+1)+"个目标名称：");
        label_temp->setAlignment(Qt::AlignCenter);

        QLineEdit *line_edit_temp=new QLineEdit(this);
        line_edit_temp->setFixedSize(200,40);
        line_edit_temp->setFont(font);
        line_edit_temp->setAlignment(Qt::AlignCenter);
        line_edit_vec.push_back(line_edit_temp);

        temp_layout->addWidget(label_temp);
        temp_layout->addWidget(line_edit_temp);
        main_layout->addLayout(temp_layout);
    }

    QHBoxLayout *over_button_layout=new QHBoxLayout(this);
    over_button=new QPushButton("应用",this);
    over_button->setFixedSize(100,40);
    over_button->setStyleSheet("color:white;background-color: gray;");
    over_button_layout->setSpacing(1);
    over_button_layout->addWidget(over_button);
    main_layout->addLayout(over_button_layout);

//    connect(over_button,SIGNAL(clicked()),this,SLOT(overButtonSlot()));
    connect(over_button,SIGNAL(clicked()), this, SLOT(overButtonSlot()));

    //   connect(over_button,SIGNAL(clicked()),,SLOT());
}

void Setting_Widget::overButtonSlot()
{
    vec_obv_version.clear();
    for(auto each:line_edit_vec){
        vec_obv_version.push_back(each->text());
    }
    emit(test(ojb_num,vec_obv_version));
}
