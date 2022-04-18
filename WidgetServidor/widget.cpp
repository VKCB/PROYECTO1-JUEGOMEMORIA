#include "widget.h"
#include "ui_widget.h"
#include<QTcpSocket>
#include<QTcpServer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    socketServidor=new QTcpSocket(this);
    servidor=new QTcpServer(this);
    servidor->listen(QHostAddress::Any,9872);
    connect(servidor,SIGNAL(newConnection()),this,SLOT(coneccionCliente()));




}
void Widget:: coneccionCliente(){
    socketServidor=servidor->nextPendingConnection();
    connect(socketServidor,SIGNAL(readyRead()),this,SLOT(leerDatos()));

}
void Widget::leerDatos(){

}

Widget::~Widget()
{
    delete ui;
}

