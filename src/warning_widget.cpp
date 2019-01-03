#include "warning_widget.h"

warning_widget::warning_widget(QString str,QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400, 180);
    this->setWindowTitle("Warning");
    this->setWindowIcon(QIcon(":/images/3.ico"));
    this->setStyleSheet("background-color:rgb(211,211,211);");  //设置整个窗口的背景颜色；

    QVBoxLayout *mainlayout = new QVBoxLayout(this);

    label_image = new QLabel(this);
    //label_image->setStyleSheet("background-image:url(image\\3.ico)");
    QPixmap pix(":/images/3.ico");
    label_image->setPixmap(pix);

    QFont font_text("ZYSong", 20);
    label_text = new QLabel(this);
    label_text->setText(str);
    label_text->setFont(font_text);

    QLabel *label_temp = new QLabel(this);

    QGridLayout *uplayout = new QGridLayout(this);
    uplayout->addWidget(label_image, 0, 0, Qt::AlignCenter);
    uplayout->addWidget(label_text, 0, 1, Qt::AlignCenter);
    uplayout->addWidget(label_temp, 0, 2, Qt::AlignCenter);

    QFont font("ZYSong", 15);
    button_ok = new QPushButton("确定");
    button_ok->setFixedSize(120, 40);
    button_ok->setStyleSheet("color:white;background-color: gray;");
    button_ok->setFont(font);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(Ok_button()));

    QHBoxLayout *downlayout = new QHBoxLayout(this);
    downlayout->addWidget(button_ok);

    mainlayout->addLayout(uplayout);
    mainlayout->addLayout(downlayout);
}

//warning_widget::~warning_widget()
//{
//    qDebug()<<"析构函数";
//}

void warning_widget::Ok_button()
{
    emit (signals_delete());
//    this->close();
}
