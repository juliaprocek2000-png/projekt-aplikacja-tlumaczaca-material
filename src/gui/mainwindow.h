#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "OllamaClient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleSend(); 

private:
    Ui::MainWindow *ui;
    OllamaClient *client;
    QString chatHistory;
    QTimer *statusTimer;
    int dotCount = 0;
};
#endif