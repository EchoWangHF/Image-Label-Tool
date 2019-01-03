#ifndef WARNING_WIDGET_H
#define WARNING_WIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QGridLayout>
#include<QLabel>
#include<QDebug>

class warning_widget : public QWidget
{
    Q_OBJECT
public:
    explicit warning_widget(QWidget *parent = nullptr);
//    virtual ~warning_widget();
    void setText(QString str);

private:
    QPushButton * button_ok;
    QLabel *label_image;
    QLabel *label_text;

public slots :
    void Ok_button();

signals:
};

#endif // WARNING_WIDGET_H
