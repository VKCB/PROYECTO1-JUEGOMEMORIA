#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QTcpSocket;
class QTcpServer;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void coneccionCliente();
    void leerDatos();

private:
    Ui::Widget *ui;
    QTcpSocket *socketServidor;
    QTcpServer *servidor;
};
#endif // WIDGET_H
