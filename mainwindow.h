#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QVector>
#include <QHash>
#include <QString>
#include <random>
#include <QPushButton>
#include<QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//Variables
    QTimer *timer=new QTimer(); // Permite repetir la accion
    QTime time;// Objeto que representa el reloj
    int parejasFaltantes;
    QMessageBox cajaMensaje;
    QVector<QString> cartas{"Carta01","Carta02","Carta03","Carta04","Carta05","Carta06","Carta07","Carta08","Carta09","Carta10",
                           "Carta11","Carta12","Carta13","Carta14","Carta15","Carta16"};
    QHash <QString, QString> reparto;
    int puntaje;
    bool juegoIniciado;
    QPushButton* cartaAnterior;
    QPushButton* cartaActual;


//Metodos
private slots:
    void actualizarEstado();
    void actualizarTiempo();
    void definirResultadoPreliminar();
    void definirResultado();
    void iniciarJuego();
    void cartaVista();
    void mezclar();
    void repartir();
    void mostrarImagen();
    void reiniciarCartas();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;// controla la interfaz grafica
    QTcpSocket *socketCliente;
};
#endif // MAINWINDOW_H
