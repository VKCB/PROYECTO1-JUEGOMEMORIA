#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTcpSocket>
#include<iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(actualizarEstado()));
    // conectar los botones con el metodo
    connect(ui->Carta01, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta02, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta03, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta04, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta05, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta06, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta07, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta08, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta09, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta10, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta11, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta12, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta13, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta14, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta15, SIGNAL(clicked()),this,SLOT(cartaVista()));
    connect(ui->Carta16, SIGNAL(clicked()),this,SLOT(cartaVista()));
    socketCliente=new QTcpSocket(this);


    iniciarJuego();
}

// Metodo para iniciar el juego
void MainWindow::iniciarJuego(){
    juegoIniciado = false;
    puntaje = 0;
    ui->lblPuntos->setText(QString::number(puntaje));
    parejasFaltantes = 8;
    time.setHMS(0,1,0);
    ui->tiempo->setText(time.toString("m:ss"));
    timer->start(1000);
    mezclar();
    repartir();
    ui->frame->setEnabled(true);
    QList<QPushButton*> botones = ui->centralwidget->findChildren<QPushButton*>();
    foreach(QPushButton*c, botones){
        //Habilitar tarjetas forma individual
        c->setEnabled(true);
        c->setStyleSheet("#"+c->objectName()+"{}");
    }


}
// Metodos para definir el tiempo de juego

void MainWindow::actualizarTiempo(){ //Actualizar tiempo en pantalla

    time=time.addMSecs(-1);
    ui->tiempo->setText(time.toString("m:ss"));
}

void MainWindow::actualizarEstado(){ // Define las cosas que se realizan cada seg
    actualizarTiempo();
    definirResultado();

}
// Resultados del juego
void MainWindow::definirResultado(){
    cajaMensaje.setWindowTitle("Juego Terminado");
    cajaMensaje.setIcon(QMessageBox::Information);
    cajaMensaje.setStandardButtons(QMessageBox::Yes);
    cajaMensaje.setStandardButtons(QMessageBox::No);
    cajaMensaje.setDefaultButton(QMessageBox::Yes); // Declara el boton por defecto
    cajaMensaje.setEscapeButton(QMessageBox::No);

    if (parejasFaltantes==0){
        timer->stop();
        cajaMensaje.setText("FELICIDADES GANASTE!! Puntaje Final:"+QString::number(puntaje)+
                            "\n¿Quieres volver a Jugar?");
        if (QMessageBox::Yes == cajaMensaje.exec()){
            iniciarJuego();

        }
        else{
            QCoreApplication::quit();// Para que se cierre el programa si se selecciona No

        }

    }
    else{
        if (time.toString()=="00:00:00"){
            timer->stop();
            ui->frame->setEnabled(false);// No se puedan seleccionar cartas cuando aparece el mensaje
            cajaMensaje.setText("PERDISTE!! ¿Quieres volver a Jugar?");
            if (QMessageBox::Yes == cajaMensaje.exec()){
                iniciarJuego();

        }
           else{
               QCoreApplication::quit();
            }

    }
 }
}
// Cartas elegidas
void MainWindow::cartaVista(){

    cartaActual= qobject_cast<QPushButton*>(sender());
    mostrarImagen();
    cartaActual->setEnabled(false);// Desabilita el boton
    if(!juegoIniciado){
        cartaAnterior=cartaActual;
        juegoIniciado= true;
    }
    else{
        definirResultadoPreliminar();
        juegoIniciado=false; // Volver a rotar las cartas
    }
}

// Se utiliza cada vez que se hace click en las cartas
void MainWindow::definirResultadoPreliminar(){
    if (reparto[cartaActual->objectName()]== reparto[cartaAnterior->objectName()]){
        puntaje+=15;//Incrementa puntaje
        ui->lblPuntos->setText(QString::number(puntaje));
        parejasFaltantes--;
        definirResultadoPreliminar();

    }
    else {
        puntaje-=5;
        ui->puntaje->setText(QString::number(puntaje));
        ui->frame->setEnabled(false);// deshabilitar volver cartas
        QTimer::singleShot(1000, this, SLOT(reiniciarCartas()));
    }
}

void MainWindow::reiniciarCartas(){

    cartaActual->setStyleSheet("#"+cartaActual->objectName()+"{}");
    cartaAnterior->setStyleSheet("#"+cartaAnterior->objectName()+"{}");
    cartaActual->setEnabled(true);
    cartaAnterior->setEnabled(true);
    ui->frame->setEnabled(true);
}
// Enseñar las cartas
void MainWindow::mostrarImagen(){
    QString nombre_carta=cartaActual->objectName();
    QString img=reparto[nombre_carta];
    cartaActual->setStyleSheet("#"+nombre_carta+"{ background-image: url(://"+ img ) ;
}

void MainWindow::mezclar(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(cartas.begin(),cartas.end(),std::default_random_engine(seed));// Es el que dice que elementos queremos mezclar

}
void MainWindow::repartir(){
    auto iterador=cartas.begin();
    for (int i=1; i<=8; i++){
        QString file_name="0"+QString::number(i)+".png";
        reparto[(*iterador)]=file_name;
        iterador++;
        reparto[(*iterador)]=file_name; // Para que genere una segunda carta en el mapa
        iterador++;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    socketCliente->connectToHost("localHost",9872);
    if (socketCliente->waitForConnected(5000)){
        cout<<"se conecto correctamente"<<endl;

    }else{
        cout<<"error"<<endl;
    }
}

