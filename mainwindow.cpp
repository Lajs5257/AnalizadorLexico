#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdio>

using namespace std;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
void Relaciona(char a);
int Token(int e);
int Error(int t);
int M[27][32]= {{1,1,3,511,511,1,1,13,14,15,23,26,16,19,21,17,18,12,20,131,129,137,138,139,140,0,0,0,11,9,511,511},
                {1,1,1,2,100,1,1,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100},
                {1,1,1,2,500,1,1,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500,500},
                {101,101,3,101,4,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101},
                {501,501,5,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501},
                {102,102,5,102,102,6,6,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102},
                {502,502,8,502,502,502,502,7,7,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502},
                {503,503,8,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503},
                {103,103,8,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103},
                {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,504,504,10,10,507,504,504},
                {505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,505,104,505,505},
                {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,105,11,11,506},
                {106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,107,106,106,106,106,106,106,106,106,106,106,106,106,106,106},
                {108,108,108,108,108,108,108,110,108,108,108,108,108,108,108,108,108,109,108,108,108,108,108,108,108,108,108,108,108,108,108,108},
                {111,111,111,111,111,111,111,111,113,111,111,111,111,111,111,111,111,112,111,111,111,111,111,111,111,111,111,111,111,111,111,111},
                {114,114,114,114,114,114,114,114,114,116,114,114,114,114,114,114,114,115,114,114,114,114,114,114,114,114,114,114,114,114,114,114},
                {117,117,117,117,117,117,117,117,117,117,117,117,117,117,117,117,117,118,117,117,117,117,117,117,117,117,117,117,117,117,117,117},
                {119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,120,119,119,119,119,119,119,119,119,119,119,119,119,119,119},
                {121,121,121,121,121,121,121,121,121,121,121,121,121,121,121,121,121,122,121,121,121,121,121,121,121,121,121,121,121,121,121,121},
                {512,512,512,512,512,512,512,512,512,512,512,512,512,124,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512,512},
                {513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,513,126,513,513,513,513,513,513,513,513,513,513,513,513,513},
                {127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,128,127,127,127,127,127,127,127,127,127,127,127,127,127,127},
                {508,508,508,508,130,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508},
                {132,132,132,132,132,132,132,132,132,24,132,132,132,132,132,132,132,133,132,132,132,132,132,132,132,132,132,132,132,132,132,132},
                {24,24,24,24,24,24,24,24,24,25,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,510},
                {24,24,24,24,24,24,24,24,24,24,134,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,510},
                {26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,136,26,26,26,26,136}};
string tokenExitoso[]={"Identificador",
                       "Constantes numérica entera",
                       "Constantes numérica real",
                       "Constantes numérica de notación científica",
                       "Constante carácter",
                       "Constante string",
                       "Operador de asignacion",
                       "Operador Relacional",
                       "Operador aritmético",
                       "Operador de asignacion",
                       "Operador aritmético" ,
                       "Operador aritmético" ,
                       "Operador de asignacion",
                       "Operador aritmético" ,
                       "Operador aritmético" ,
                       "Operador de asignacion" ,
                       "Operador aritmético" ,
                       "Operador aritmético" ,
                       "Operador de asignacion" ,
                       "Operador Relacional" ,
                       "Operador Relacional",
                       "Operador Relacional",
                       "Operador Relacional",
                       "Operador lógico",
                       "Operador lógico",
                       "Operador lógico",
                       "Operador Relacional",
                       "Signo de puntacion",
                       "Signo de puntacion",
                       "Signo de puntacion",
                       "Operador aritmético",
                       "Operador de asignacion",
                       "Comentario",
                       "Comentario",
                       "Signo de agrupacion",
                       "Signo de agrupacion",
                       "Signo de agrupacion",
                       "Signo de agrupacion",
                       "Delimitador",
                       "Delimitador",
                       "Delimitador",
                       "Fin del archivo"};
string tokenError[]={"Identificador no puede terminar en '_' ",
                     "Dato numerico  no puede terminar en '.' esta se esperaba otro numero",
                     "Dato numerico  no puede terminar en 'E' o 'e' se esperaba otro numero o algún signo + o -",
                     "Dato numerico  no puede terminar en '+' o '-' se esperaba algun numero",
                     "Constante carácter debe contenter un elemento y terminar en comilla simple",
                     "Constante carácter debe en terminar en comilla simple",
                     "Constante string debe de terminar en  comillas dobles ",
                     "Constante carácter debe de contener al menos un carácter",
                     "Signo de puntacion esperaba un '.'",
                     "El comentario esperaba un '*/' para terminar",
                     "Carácter no reconocido",
                     "Operedor logico esperaba &",
                     "Operedor logico esperaba |"};
string palabrasResevadas[]={"class",
                            "endclass",
                            "int",
                            "float",
                            "char",
                            "string",
                            "bool",
                            "if",
                            "else",
                            "elseif",
                            "endif",
                            "do",
                            "eval",
                            "enddo",
                            "while",
                            "endwhile",
                            "read",
                            "write",
                            "def",
                            "as",
                            "for",
                            "endfor",
                            "private",
                            "public",
                            "protected",
                            "library",
                            "func",
                            "endfunc",
                            "main",
                            "endmain",
                            "true",
                            "false"};
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Tipo de archivo a abrir
    QString filter = "Spes files (*.spes)";
    QString file_name = QFileDialog::getOpenFileName(this, "Abrir archivo", QDir::homePath(), filter);

    QFile file(file_name);

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Advertencia", "Archivo no abierto");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    //Tipo de archivo a guardar
    QString filter = "Spes files (*.spes)";
    QString file_name = QFileDialog::getSaveFileName(this, "Guardar Archivo", QDir::homePath(), filter);
    QFile file(file_name);

    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Advertencia", "Archivo no guardado");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

}

int relaciona(char c)
{
    //Caso numero
    if (c >= '0' && c <= '9'){
        return 2;
    }
    //Caso caracteres conocidos
    switch (c)
    {
        case '_': return 3;
        case '.': return 4;
        case 'E' : return 5;
        case 'e': return 6;
        case '+': return 7;
        case '-': return 8;
        case '*': return 9;
        case '/': return 10;
        case '#': return 11;
        case '%': return 12;
        case '&': return 13;
        case '!': return 14;
        case '<': return 15;
        case '>': return 16;
        case '=': return 17;
        case '|': return 18;
        case ',': return 19;
        case ';': return 20;
        case '[': return 21;
        case ']': return 22;
        case '(': return 23;
        case ')': return 24;
        case '"': return 28;
        case ' ': return 27;
        case '\n': return 26;
        case '\t': return 25;
        case '\0': return 31;
    }
    //Caso letras
    if ((int(c) >= 97 && int(c) <= 122 )|| (int(c) >= 65 && int(c) <= 90))
    {
        return 0;
    }
    //Caso comilla simple
    switch (int(c)) {
        case 39: return 29;
    }
    //Caso diferente
    return 30;
}

int Token(int e)
{
    switch(e)
    {
        case 100: return  0;
        case 101: return  1;
        case 102: return  2;
        case 103: return  3;
        case 104: return  4;
        case 105: return  5;
        case 106: return  6;
        case 107: return  7;
        case 108: return  8;
        case 109: return  9;
        case 110: return  10;
        case 111: return  11;
        case 112: return  12;
        case 113: return  13;
        case 114: return  14;
        case 115: return  15;
        case 116: return  16;
        case 117: return  17;
        case 118: return  18;
        case 119: return  19;
        case 120: return  20;
        case 121: return  21;
        case 122: return  22;
        case 124: return  23;
        case 126: return  24;
        case 127: return  25;
        case 128: return  26;
        case 129: return  27;
        case 130: return  28;
        case 131: return  29;
        case 132: return  30;
        case 133: return  31;
        case 134: return  32;
        case 136: return  33;
        case 137: return  34;
        case 138: return  35;
        case 139: return  36;
        case 140: return  37;
        case 141: return  38;
        case 142: return  39;
        case 143: return  40;
        case 144: return  41;
    }
    return 100;
} //fin de token
int Error(int e) //Esta es la Tabla de Errores
{
    switch (e)
    {
        case 500:	return 0;
        case 501:	return 1;
        case 502:	return 2;
        case 503:	return 3;
        case 504:	return 4;
        case 505:	return 5;
        case 506:	return 6;
        case 507:	return 7;
        case 508:	return 8;
        case 510:	return 9;
        case 511:	return 10;
        case 512:	return 11;
        case 513:	return 12;
    }
    return 100;
} // fin de error



void MainWindow::on_btnAnaliza_clicked()
{
    int edo, col;
    char car;
    int cont_cadena = 0;
    QString a = ui->plainTextEdit->toPlainText();
    string cadena =a.toUtf8().constData();
    char *cstr = &cadena[cont_cadena];
    string resultado = "";
    string cadenaResultante,identificador;
    QString r;
    int T=0;
    bool AnalisisCorrecto=true;
        while ( cont_cadena <= (a.length()))
        {
            //Se reinician variables
            edo = 0;
            cadenaResultante="",identificador="";
            while (edo <= 26)
            {
                car = (char)cstr[cont_cadena];
                col = relaciona (car);

                edo = M[edo][col];
                //Filtro para evitar que agregrue a las cadenas delimitadores
                if(edo!=100 &&car!='\n'&&car!='\b'&&car!='\t'&&car!=' '&&car!='\0')
                {
                    cadenaResultante=cadenaResultante+""+car+"";
                }
                else if(edo==9 &&car!='\b')
                {
                    cadenaResultante=cadenaResultante+""+car+"";
                }else if(edo==11)
                {
                    cadenaResultante=cadenaResultante+""+car+"";
                }

                if(edo<27){
                    cont_cadena++;

                }
                if(edo>100){
                    cont_cadena=cont_cadena--;
                }
            }
            r =QString::fromStdString(cadenaResultante);
            resultado+=cadenaResultante;
            if (edo >= 100 && edo <= 144)
            {
                //Respaldamos el valor de nuestra cadena antes de asiganrle el resultado de su token correspondiente
                identificador=cadenaResultante;
                T =Token(edo);
                cadenaResultante = tokenExitoso[T]; //Obtiene la cadena correspondiente al estado al que llego
                //Analisis para detectar si el identificador pertenece a las palabras reservadas
                if(edo==100){
                    for(int rPR=0;rPR<32;rPR++){
                        if(identificador.compare(palabrasResevadas[rPR])==0)
                        {
                            cadenaResultante="Palabra Reservada";
                            rPR=33;
                        }
                    }

                }
            }
            else
            {
                T =Error(edo);
                cadenaResultante = tokenError[T]; //Obtiene la cadena correspondiente al estado al que llego
                AnalisisCorrecto=false;
                cont_cadena=a.size();
            }
            resultado+=" -> "+cadenaResultante+"\n";
            cont_cadena++;
            if(!AnalisisCorrecto){
                resultado+=" - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"
                           "      Analisis Finalizado se encontraron \n"
                           "                        Errores\n"
                           " - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                r =QString::fromStdString(resultado);
                ui->plainTextEdit_2->setPlainText(r);
                break;
            }
            else if(AnalisisCorrecto&&cont_cadena>=a.length()){
                resultado+=" - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"
                           "      Analisis Finalizado Correctamente\n"
                           " - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
                r =QString::fromStdString(resultado);
                ui->plainTextEdit_2->setPlainText(r);
                break;
            }
            r =QString::fromStdString(resultado);
            ui->plainTextEdit_2->setPlainText(r);

    }
}

