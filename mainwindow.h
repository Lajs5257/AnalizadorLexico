#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btnAnaliza_clicked();

    void on_btnAnaliza_2_clicked();

    void on_btnAnaliza_3_clicked();

    // - - - - - - -- - - - semantico - - - - - - - - - - -
    void generarCuadruplo();
    void estatutoAsig(QString Token, QString TokenTexto);
    void Semantico();
    void cuadrupoSaltoFalso();
    void cuadrupoSaltoVerdadero();
    void cuadruploSaltoIncondicional();
    void llenarSaltoTope();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
