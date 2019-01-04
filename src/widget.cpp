#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    sign_object_num=0;
    index=-1;

    this->setWindowTitle("Images Label");
    this->setWindowIcon(QIcon(":/images/app.ico"));
    this->setStyleSheet("background-color:rgb(211,211,211);");  //设置整个窗口的背景颜色；
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
    previous=new QPushButton("上一张(A)",this);
    previous->setFixedSize(80,40);
    previous->setStyleSheet("color:white;background-color: gray;");

    next=new QPushButton("开始标记(D)",this);
    next->setFixedSize(80,40);
    next->setStyleSheet("color:white;background-color: gray;");
//    next->setShortcut(Qt::Key_D);
    left_mid_layout->addWidget(next);
    left_mid_layout->addWidget(previous);

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
    QFont font("ZYSong", 15);
    QHBoxLayout *mid_layout=new QHBoxLayout(this);

    WidgetVision=new QFrame(this);
    WidgetVision->setFrameStyle(QFrame::Box | QFrame::Raised);
    WidgetVision->resize(int(this->width()*0.8),int(this->height()*0.9));
    frame_layout=new QGridLayout(WidgetVision);

//    imgVision=nullptr;
    imgVision=new myLable(this);
    imgVision->hide();
    frame_layout->addWidget(imgVision);
    connect(this,SIGNAL(remove_draw_signal()),imgVision,SLOT(remove_draw_slots()));

    mid_layout->addWidget(WidgetVision);


//begin *******************右边界面设计部分***********************

    right_top_2_layout=new QVBoxLayout(this);
    ImageNum=new QLabel(this);
    ImageNum->setFixedSize(200,40);
    ImageNum->setText("已标记张数："+QString::number(0));
    ImageNum->setFont(font);

    isTag=new QLabel(this);
    isTag->setFixedSize(200,40);
    isTag->setFont(font);
    right_top_2_layout->addWidget(ImageNum);
    right_top_2_layout->addWidget(isTag);

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

    signVersion=new QLabel(this);
    signVersion->setFont(font);
    signVersion->hide();

    right_mid_layout->addWidget(signObject);
    right_mid_layout->addWidget(signVersion);

    right_mid_2_layout->addLayout(right_top_layout);
    right_mid_2_layout->addLayout(right_mid_layout);

    right_bootom_layout=new QHBoxLayout(this);
    remove=new QPushButton("撤销(W)",this);
    remove->setFixedSize(60,40);
    remove->setStyleSheet("color:white;background-color: gray;");

    save=new QPushButton("保存(S)",this);
    save->setFixedSize(60,40);
    save->setStyleSheet("color:white;background-color: gray;");

    right_bootom_layout->addWidget(remove);
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

//    SW=new Setting_Widget();

    WW=new warning_widget();
    WW->hide();


    connect(setting,SIGNAL(clicked()),this,SLOT(start_setting()));
    connect(opendir,SIGNAL(clicked()),this,SLOT(opendier_slots()));
    connect(previous,SIGNAL(clicked()),this,SLOT(previous_button_slots()));
    connect(next,SIGNAL(clicked()),this,SLOT(next_button_slots()));
    connect(remove,SIGNAL(clicked()),this,SLOT(remove_button_slots()));
    connect(save,SIGNAL(clicked()),this,SLOT(save_buttion_slots()));
}

Widget::~Widget()
{
    delete SW;
    delete imgVision;
    delete WW;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
        previous_button_slots();
        break;
    case Qt::Key_D:
        next_button_slots();
        break;
    case Qt::Key_W:
        remove_button_slots();
        break;
    case Qt::Key_S:
        save_buttion_slots();
        break;
    default:
        break;

    }

}

void Widget::start_setting(){
    SW=new Setting_Widget();
    SW->show();
    connect(SW,SIGNAL(test(int,QVector<QString>)), this, SLOT(return_lineText()));
}

void Widget::return_lineText()
{
    sign_object_num=SW->ojb_num;
    vec_sign_obj=SW->vec_obv_version;

    signNumber->setText("标记目标数："+QString::number(sign_object_num));

    signVersion->setFixedSize(200,40*(sign_object_num));

    QString text_version="";
    for(int i=0;i<sign_object_num;++i){
        text_version+=(vec_sign_obj.at(i)+"\n");
    }
    //qDebug()<<text_version;
    signVersion->setText(text_version);
    signVersion->show();

    delete SW;
}

void Widget::opendier_slots()
{
    index=-1;
    opendir_file=new QFileDialog(this);
    opendir_file->setWindowTitle("打开文件夹");
    opendir_file->setDirectory(".");  //设置默认文件路径
//    opendir_file->setNameFilter(tr("Images(*.png *.jpg *.jpeg *.bmp)")); //设置文件过滤器
//    opendir_file->setFileMode(QFileDialog::ExistingFiles);
    opendir_file->setViewMode(QFileDialog::Detail);

    file_dir=opendir_file->getExistingDirectory();
    delete  opendir_file;

    QDir dir(file_dir);
    if(!dir.exists()){
        imgVision->setText("出错，请重新选择文件夹");
        return;
    }

    dir.setFilter(QDir::Files);
    list=dir.entryInfoList();
}

void Widget::previous_button_slots()
{
    bool tag=save_buttion_slots();

    if(index<=0){
//        qDebug()<<"\a";
        warning_wid("已经是第一张了");
        return;
    }

    if(tag){
        index--;
    }

    ImageNum->setText("标记目标数："+QString::number(index+1));
    QString img_path=file_dir+"/"+list.at(index).fileName();
    readImage(img_path);
    if(ImageisTag()){
        isTag->setText("已标记");
    }else{
        isTag->setText("未标记");
    }
}

void Widget::next_button_slots()
{

    bool tag=save_buttion_slots();

    if(sign_object_num==0||sign_object_num!=vec_sign_obj.size()){
        warning_wid("设置出错，请检查！");
        return;
    }

    if(list.size()==0){
        return;
    }

    if(index>=list.size()){
        warning_wid("已经是最后一张图片了！");
        return;
    }

    if(tag){
        index++;
    }

    ImageNum->setText("标记目标数："+QString::number(index+1));
    if(index==0){
        next->setText("下一张(D)");
    }

    QString img_path=file_dir+"/"+list.at(index).fileName();
    readImage(img_path);
    if(ImageisTag()){
        isTag->setText("已标记");
    }else{
        isTag->setText("未标记");
    }
}

void Widget::remove_button_slots()
{
    if(imgVision!=nullptr){
        emit(remove_draw_signal());
    }
}

bool Widget::save_buttion_slots()
{
    if(imgVision==nullptr){
        return true;
    }

    vec_draw=imgVision->get_vec_draw();
    imgVision->clear_vec_draw();
//    delete imgVision;
    if(!vec_draw.empty()){
        if(int(vec_draw.size())!=sign_object_num){
//            qDebug()<<"hehehhehehehehe";
            warning_wid("标记目标数不正确！");
            vec_draw.clear();
            return false;
        }
        QDir dir;
        dir.cd(file_dir);
        if(!dir.exists("annotation")){
            dir.mkdir("annotation");
        }
        XML_file_save_path=file_dir+"/annotation";
        write_xml();
        vec_draw.clear();
        return true;
    }
    else{
        return true;
    }
}

void Widget::readImage(QString img_path)
{

    img=new QImage;
    imgVision->show();
    if(!img->load(img_path)){
        imgVision->setText("不是图片，请点击下一张");
    }else{
        imgVision->setFixedSize(img->size());
        imgVision->setPixmap(QPixmap::fromImage(*img));
    }
    delete img;
    return;
}

bool Widget::ImageisTag()
{
    QString image_name=list.at(index).fileName();
    QString image_path=file_dir;

    QString xml_name=image_name+".xml";
    QString xml_path=image_path+"/annotation";

    QString file_path_name=xml_path+"/"+xml_name;
    QFileInfo fi(file_path_name);
    if(fi.isFile()){
        return true;
    }else{
        return false;
    }
}

void Widget::write_xml()
{
    if(vec_draw.size()!=sign_object_num){
        warning_wid("标记目标数不正确！");
        return;
    }
    QString xml_name=XML_file_save_path+"/"+list.at(index).fileName()+".xml";
    QFile file(xml_name);
    if (!file.open(QFile::WriteOnly | QFile::Text)) { // 只写模式打开文件
            qDebug() << QString("Cannot write file %1(%2).").arg(xml_name).arg(file.errorString());
            return;
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("Anontations");

//    assert(imgVision->draw_point_vec.size()==sign_object_num);
    for(unsigned int i=0;i<sign_object_num;++i){
        writer.writeStartElement(vec_sign_obj.at(i));
        writer.writeTextElement("x",QString::number(vec_draw.at(i).x));
        writer.writeTextElement("y",QString::number(vec_draw.at(i).y));
        writer.writeTextElement("w",QString::number(vec_draw.at(i).w));
        writer.writeTextElement("h",QString::number(vec_draw.at(i).h));
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    file.close();
}

void Widget::warning_wid(QString str)
{
    WW->setText(str);
}
