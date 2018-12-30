#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    image_num=0;
    sign_object_num=0;
//    vec_sign_obj={};
    this->setWindowTitle("图片标记软件");
//    this->setFixedSize(1200,800);
    this->resize(1000,700);  //控制大小，但是大小可以调节；
    this->setStyle(QStyleFactory::create("Fusion"));

    main_layout=new QHBoxLayout(this);
    left_layout=new QVBoxLayout(this);
    right_layout=new QVBoxLayout(this);

//begin *******************左边界面设计部分***********************
    QHBoxLayout *left_top_layout=new QHBoxLayout(this);
    opendir=new QPushButton("添加文件",this);
//    opendir->resize(this->width()/200,this->height()/100);
    opendir->setFixedSize(80,40);
    opendir->setStyleSheet("color:white;background-color: gray;");
    left_top_layout->addWidget(opendir);


    QVBoxLayout *left_mid_layout=new QVBoxLayout(this);
    previous=new QPushButton("上一张",this);
    previous->setFixedSize(80,40);
    previous->setStyleSheet("color:white;background-color: gray;");

    next=new QPushButton("下一张",this);
    next->setFixedSize(80,40);
    next->setStyleSheet("color:white;background-color: gray;");
    left_mid_layout->addWidget(previous);
    left_mid_layout->addWidget(next);

    QHBoxLayout *left_bottom_layout=new QHBoxLayout(this);
    setting=new QPushButton("设置",this);
    setting->setFixedSize(80,40);
//    setting->setStyleSheet("border:1px groove gray;border-radius:2px;color:white;background-color: gray;");
    setting->setStyleSheet("color:white;background-color: gray;");
    left_bottom_layout->addWidget(setting);

    left_layout->addLayout(left_top_layout);
    left_layout->addLayout(left_mid_layout);
    left_layout->addLayout(left_bottom_layout);

//end **********************************************************
    QHBoxLayout *mid_layout=new QHBoxLayout(this);
    imgVision=new QLabel(this);
    imgVision->setFrameStyle(QFrame::Box | QFrame::Raised);
    imgVision->resize(int(this->width()*0.8),int(this->height()*0.9));
    mid_layout->addWidget(imgVision);


//begin *******************右边界面设计部分***********************
    QFont font("ZYSong", 15);

    right_top_2_layout=new QVBoxLayout(this);
    ImageNum=new QLabel(this);
    ImageNum->setFixedSize(200,40);
    ImageNum->setText("已标记张数："+QString::number(image_num));
    ImageNum->setFont(font);
    right_top_2_layout->addWidget(ImageNum);

    right_mid_2_layout=new QVBoxLayout(this);

    right_top_layout=new QVBoxLayout(this);
    signNumber=new QLabel(this);
    signNumber->setFixedSize(200,40);
    signNumber->setText("标记目标数："+QString::number(sign_object_num));
    signNumber->setFont(font);
    right_top_layout->addWidget(signNumber);

    right_mid_layout=new QVBoxLayout(this);
    signObject=new QLabel(this);
    signObject->setFixedSize(200,40);
    signObject->setText("标记目标内容：");
    signObject->setFont(font);

    right_temp_layout=new QVBoxLayout(this);
    assert(sign_object_num==vec_sign_obj.size());
    QFont font_temp("ZYSong", 12);
    for(int i=0;i<sign_object_num;++i){
        QLabel *temp=new QLabel(this);
        temp->setFixedSize(200,30);
        temp->setText(vec_sign_obj.at(i));
        temp->setFont(font);
        right_temp_layout->addWidget(temp);
    }

    right_mid_layout->addWidget(signObject);
    right_mid_layout->addLayout(right_temp_layout);

    right_mid_2_layout->addLayout(right_top_layout);
    right_mid_2_layout->addLayout(right_mid_layout);

    right_bootom_layout=new QHBoxLayout(this);
    save=new QPushButton("保存",this);
    save->setFixedSize(80,40);
    save->setStyleSheet("color:white;background-color: gray;");
//    right_bootom_layout->addStretch(0);
    right_bootom_layout->addWidget(save);

    right_layout->addLayout(right_top_2_layout);
    right_layout->addLayout(right_mid_2_layout);
    right_layout->addLayout(right_bootom_layout);
//end **********************************************************

    main_layout->addLayout(left_layout);
    main_layout->setSpacing(10);
    main_layout->addLayout(mid_layout);
    main_layout->setSpacing(10);
    main_layout->addLayout(right_layout);

    SW=new Setting_Widget();

    connect(setting,SIGNAL(clicked()),this,SLOT(start_setting()));
    connect(SW,SIGNAL(test(int,QVector<QString>)), this, SLOT(return_lineText()));
}

Widget::~Widget()
{
    delete SW;
}

void Widget::start_setting(){
//    Setting_Widget *SW=new Setting_Widget();
//    SW->show();
    SW->show();
}

void Widget::return_lineText()
{
    sign_object_num=SW->ojb_num;
    vec_sign_obj=SW->vec_obv_version;

    signNumber->setText("标记目标数："+QString::number(sign_object_num));

//    right_temp_layout=new QVBoxLayout(this);
    assert(sign_object_num==vec_sign_obj.size());
    QFont font_temp("ZYSong", 15);
    for(int i=0;i<sign_object_num;++i){
        QLabel *temp=new QLabel(this);
        temp->setFixedSize(200,30);
        temp->setText(vec_sign_obj.at(i));
        temp->setFont(font_temp);
        right_temp_layout->addWidget(temp);
    }


    SW->hide();
}
