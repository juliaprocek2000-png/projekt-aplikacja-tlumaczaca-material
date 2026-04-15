#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);///tworzenie aplikacji obiektu
    MainWindow w;
    w.show();///okno widoczne na ekranie
    return a.exec(); ///uruchomienie głownej pętli 
}